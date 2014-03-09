#include "PathEngine.h"
#include "DetourNavMeshBuilder.h"
#include "DetourCommon.h"
#include "DetourTileCache.h"
#include "RecastAlloc.h"
#include "RecastAssert.h"
#include "fastlz.h"

namespace PathEngine
{
	static const int MAX_LAYERS = 32;
	static const int EXPECTED_LAYERS_PER_TILE = 4;
	enum SamplePolyAreas
	{
		SAMPLE_POLYAREA_GROUND,
		SAMPLE_POLYAREA_WATER,
		SAMPLE_POLYAREA_ROAD,
		SAMPLE_POLYAREA_DOOR,
		SAMPLE_POLYAREA_GRASS,
		SAMPLE_POLYAREA_JUMP,
	};
	enum SamplePolyFlags
	{
		SAMPLE_POLYFLAGS_WALK		= 0x01,		// Ability to walk (ground, grass, road)
		SAMPLE_POLYFLAGS_SWIM		= 0x02,		// Ability to swim (water).
		SAMPLE_POLYFLAGS_DOOR		= 0x04,		// Ability to move through doors.
		SAMPLE_POLYFLAGS_JUMP		= 0x08,		// Ability to jump.
		SAMPLE_POLYFLAGS_DISABLED	= 0x10,		// Disabled polygon
		SAMPLE_POLYFLAGS_ALL		= 0xffff	// All abilities.
	};

	struct TileCacheData
	{
		unsigned char* data;
		int dataSize;
	};
	struct RasterizationContext
	{
		rcHeightfield* solid;
		unsigned char* triareas;
		rcHeightfieldLayerSet* lset;
		rcCompactHeightfield* chf;
		TileCacheData tiles[MAX_LAYERS];
		int ntiles;
		RasterizationContext() :
		solid(0),triareas(0),lset(0),chf(0),ntiles(0)
		{
			memset(tiles, 0, sizeof(TileCacheData)*MAX_LAYERS);
		}

		~RasterizationContext()
		{
			rcFreeHeightField(solid);
			delete [] triareas;
			rcFreeHeightfieldLayerSet(lset);
			rcFreeCompactHeightfield(chf);
			for (int i = 0; i < MAX_LAYERS; ++i)
			{
				dtFree(tiles[i].data);
				tiles[i].data = 0;
			}
		}

	};

	struct FastLZCompressor : public dtTileCacheCompressor
	{
		virtual int maxCompressedSize(const int bufferSize)
		{
			return (int)(bufferSize* 1.05f);
		}

		virtual dtStatus compress(const unsigned char* buffer, const int bufferSize,
			unsigned char* compressed, const int /*maxCompressedSize*/, int* compressedSize)
		{
			*compressedSize = fastlz_compress((const void *const)buffer, bufferSize, compressed);
			return DT_SUCCESS;
		}

		virtual dtStatus decompress(const unsigned char* compressed, const int compressedSize,
			unsigned char* buffer, const int maxBufferSize, int* bufferSize)
		{
			*bufferSize = fastlz_decompress(compressed, compressedSize, buffer, maxBufferSize);
			return *bufferSize < 0 ? DT_FAILURE : DT_SUCCESS;
		}
	};

	struct MeshProcess : public dtTileCacheMeshProcess
	{
		InputGeom* m_geom;

		inline MeshProcess() : m_geom(0)
		{
		}

		inline void init(InputGeom* geom)
		{
			m_geom = geom;
		}

		virtual void process(struct dtNavMeshCreateParams* params,
			unsigned char* polyAreas, unsigned short* polyFlags)
		{
			// Update poly flags from areas.
			for (int i = 0; i < params->polyCount; ++i)
			{
				if (polyAreas[i] == DT_TILECACHE_WALKABLE_AREA)
					polyAreas[i] = SAMPLE_POLYAREA_GROUND;

				if (polyAreas[i] == SAMPLE_POLYAREA_GROUND ||
					polyAreas[i] == SAMPLE_POLYAREA_GRASS ||
					polyAreas[i] == SAMPLE_POLYAREA_ROAD)
				{
					polyFlags[i] = SAMPLE_POLYFLAGS_WALK;
				}
				else if (polyAreas[i] == SAMPLE_POLYAREA_WATER)
				{
					polyFlags[i] = SAMPLE_POLYFLAGS_SWIM;
				}
				else if (polyAreas[i] == SAMPLE_POLYAREA_DOOR)
				{
					polyFlags[i] = SAMPLE_POLYFLAGS_WALK | SAMPLE_POLYFLAGS_DOOR;
				}
			}

			// Pass in off-mesh connections.
			if (m_geom)
			{
				params->offMeshConVerts = m_geom->getOffMeshConnectionVerts();
				params->offMeshConRad = m_geom->getOffMeshConnectionRads();
				params->offMeshConDir = m_geom->getOffMeshConnectionDirs();
				params->offMeshConAreas = m_geom->getOffMeshConnectionAreas();
				params->offMeshConFlags = m_geom->getOffMeshConnectionFlags();
				params->offMeshConUserID = m_geom->getOffMeshConnectionId();
				params->offMeshConCount = m_geom->getOffMeshConnectionCount();	
			}
		}
	};

	static int RasterizeTileLayers(
		BuildContext* ctx, InputGeom* geom, const int tx, const int ty, 
		const rcConfig& cfg, TileCacheData* tiles, const int maxTiles)
	{
		if (!geom || !geom->getMesh() || !geom->getChunkyMesh()) return 0;

		FastLZCompressor comp;
		RasterizationContext rc;

		const float* verts = geom->getMesh()->getVerts();
		const int nverts = geom->getMesh()->getVertCount();
		const rcChunkyTriMesh* chunkyMesh = geom->getChunkyMesh();

		// Tile bounds.
		const float tcs = cfg.tileSize * cfg.cs;

		rcConfig tcfg;
		memcpy(&tcfg, &cfg, sizeof(tcfg));

		tcfg.bmin[0] = cfg.bmin[0] + tx*tcs;
		tcfg.bmin[1] = cfg.bmin[1];
		tcfg.bmin[2] = cfg.bmin[2] + ty*tcs;
		tcfg.bmax[0] = cfg.bmin[0] + (tx+1)*tcs;
		tcfg.bmax[1] = cfg.bmax[1];
		tcfg.bmax[2] = cfg.bmin[2] + (ty+1)*tcs;
		tcfg.bmin[0] -= tcfg.borderSize*tcfg.cs;
		tcfg.bmin[2] -= tcfg.borderSize*tcfg.cs;
		tcfg.bmax[0] += tcfg.borderSize*tcfg.cs;
		tcfg.bmax[2] += tcfg.borderSize*tcfg.cs;

		// Allocate voxel heightfield where we rasterize our input data to.
		rc.solid = rcAllocHeightfield();
		if (!rc.solid) return 0;
		if (!rcCreateHeightfield(ctx, *rc.solid, tcfg.width, tcfg.height, 
			tcfg.bmin, tcfg.bmax, tcfg.cs, tcfg.ch))
			return 0;

		// Allocate array that can hold triangle flags.
		// If you have multiple meshes you need to process, allocate
		// and array which can hold the max number of triangles you need to process.
		rc.triareas = new unsigned char[chunkyMesh->maxTrisPerChunk];
		if (!rc.triareas) return 0;

		float tbmin[2], tbmax[2];
		tbmin[0] = tcfg.bmin[0];
		tbmin[1] = tcfg.bmin[2];
		tbmax[0] = tcfg.bmax[0];
		tbmax[1] = tcfg.bmax[2];
		int cid[512];// TODO: Make grow when returning too many items.
		const int ncid = rcGetChunksOverlappingRect(chunkyMesh, tbmin, tbmax, cid, 512);
		if (!ncid) return 0; // empty

		for (int i = 0; i < ncid; ++i)
		{
			const rcChunkyTriMeshNode& node = chunkyMesh->nodes[cid[i]];
			const int* tris = &chunkyMesh->tris[node.i*3];
			const int ntris = node.n;

			memset(rc.triareas, 0, ntris*sizeof(unsigned char));
			rcMarkWalkableTriangles(ctx, tcfg.walkableSlopeAngle,
				verts, nverts, tris, ntris, rc.triareas);

			rcRasterizeTriangles(ctx, verts, nverts, tris, 
				rc.triareas, ntris, *rc.solid, tcfg.walkableClimb);
		}

		// Once all geometry is rasterized, we do initial pass of filtering to
		// remove unwanted overhangs caused by the conservative rasterization
		// as well as filter spans where the character cannot possibly stand.
		rcFilterLowHangingWalkableObstacles(ctx, tcfg.walkableClimb, *rc.solid);
		rcFilterLedgeSpans(ctx, tcfg.walkableHeight, tcfg.walkableClimb, *rc.solid);
		rcFilterWalkableLowHeightSpans(ctx, tcfg.walkableHeight, *rc.solid);


		rc.chf = rcAllocCompactHeightfield();
		if (!rc.chf) return 0;
		if (!rcBuildCompactHeightfield(ctx, tcfg.walkableHeight, 
			tcfg.walkableClimb, *rc.solid, *rc.chf))
			return 0;

		// Erode the walkable area by agent radius.
		if (!rcErodeWalkableArea(ctx, tcfg.walkableRadius, *rc.chf)) return 0;

		// (Optional) Mark areas.
		const ConvexVolume* vols = geom->getConvexVolumes();
		for (int i  = 0; i < geom->getConvexVolumeCount(); ++i)
		{
			rcMarkConvexPolyArea(ctx, vols[i].verts, vols[i].nverts,
				vols[i].hmin, vols[i].hmax,
				(unsigned char)vols[i].area, *rc.chf);
		}

		rc.lset = rcAllocHeightfieldLayerSet();
		if (!rc.lset) return 0;
		if (!rcBuildHeightfieldLayers(ctx, *rc.chf, tcfg.borderSize, 
			tcfg.walkableHeight, *rc.lset)) return 0;

		rc.ntiles = 0;
		for (int i = 0; i < rcMin(rc.lset->nlayers, MAX_LAYERS); ++i)
		{
			TileCacheData* tile = &rc.tiles[rc.ntiles++];
			const rcHeightfieldLayer* layer = &rc.lset->layers[i];

			// Store header
			dtTileCacheLayerHeader header;
			header.magic = DT_TILECACHE_MAGIC;
			header.version = DT_TILECACHE_VERSION;

			// Tile layer location in the navmesh.
			header.tx = tx;
			header.ty = ty;
			header.tlayer = i;
			dtVcopy(header.bmin, layer->bmin);
			dtVcopy(header.bmax, layer->bmax);

			// Tile info.
			header.width = (unsigned char)layer->width;
			header.height = (unsigned char)layer->height;
			header.minx = (unsigned char)layer->minx;
			header.maxx = (unsigned char)layer->maxx;
			header.miny = (unsigned char)layer->miny;
			header.maxy = (unsigned char)layer->maxy;
			header.hmin = (unsigned short)layer->hmin;
			header.hmax = (unsigned short)layer->hmax;

			dtStatus status = dtBuildTileCacheLayer(&comp, &header, layer->heights, layer->areas, layer->cons,
				&tile->data, &tile->dataSize);
			if (dtStatusFailed(status)) return 0;
		}

		// Transfer ownsership of tile data from build context to the caller.
		int n = 0;
		for (int i = 0; i < rcMin(rc.ntiles, maxTiles); ++i)
		{
			tiles[n++] = rc.tiles[i];
			rc.tiles[i].data = 0;
			rc.tiles[i].dataSize = 0;
		}

		return n;
	}


	void NavMesh::SetMesh(InputGeom* geom)
	{
		m_geom = geom;
		dtFreeTileCache(m_tileCache);
		m_tileCache = 0;

		dtFreeNavMesh(m_navMesh);
		m_navMesh = 0;
	}
	bool NavMesh::Build()
	{
		dtStatus status;
		if (!m_geom || !m_geom->getMesh()) return false;
		m_tmproc->init(m_geom);
		// Init cache
		const float* bmin = m_geom->getMeshBoundsMin();
		const float* bmax = m_geom->getMeshBoundsMax();
		int gw = 0, gh = 0;
		rcCalcGridSize(bmin, bmax, m_cellSize, &gw, &gh);
		const int ts = (int)m_tileSize;
		const int tw = (gw + ts-1) / ts;
		const int th = (gh + ts-1) / ts;
		// Generation params.
		rcConfig cfg;
		memset(&cfg, 0, sizeof(cfg));
		cfg.cs = m_cellSize;
		cfg.ch = m_cellHeight;
		cfg.walkableSlopeAngle = m_agentMaxSlope;
		cfg.walkableHeight = (int)ceilf(m_agentHeight / cfg.ch);
		cfg.walkableClimb = (int)floorf(m_agentMaxClimb / cfg.ch);
		cfg.walkableRadius = (int)ceilf(m_agentRadius / cfg.cs);
		cfg.maxEdgeLen = (int)(m_edgeMaxLen / m_cellSize);
		cfg.maxSimplificationError = m_edgeMaxError;
		cfg.minRegionArea = (int)rcSqr(m_regionMinSize);		// Note: area = size*size
		cfg.mergeRegionArea = (int)rcSqr(m_regionMergeSize);	// Note: area = size*size
		cfg.maxVertsPerPoly = (int)m_vertsPerPoly;
		cfg.tileSize = (int)m_tileSize;
		cfg.borderSize = cfg.walkableRadius + 3; // Reserve enough padding.
		cfg.width = cfg.tileSize + cfg.borderSize*2;
		cfg.height = cfg.tileSize + cfg.borderSize*2;
		cfg.detailSampleDist = m_detailSampleDist < 0.9f ? 0 : m_cellSize * m_detailSampleDist;
		cfg.detailSampleMaxError = m_cellHeight * m_detailSampleMaxError;
		rcVcopy(cfg.bmin, bmin);
		rcVcopy(cfg.bmax, bmax);
		// Tile cache params.
		dtTileCacheParams tcparams;
		memset(&tcparams, 0, sizeof(tcparams));
		rcVcopy(tcparams.orig, bmin);
		tcparams.cs = m_cellSize;
		tcparams.ch = m_cellHeight;
		tcparams.width = (int)m_tileSize;
		tcparams.height = (int)m_tileSize;
		tcparams.walkableHeight = m_agentHeight;
		tcparams.walkableRadius = m_agentRadius;
		tcparams.walkableClimb = m_agentMaxClimb;
		tcparams.maxSimplificationError = m_edgeMaxError;
		tcparams.maxTiles = tw*th*EXPECTED_LAYERS_PER_TILE;
		tcparams.maxObstacles = 128;

		dtFreeTileCache(m_tileCache);

		m_tileCache = dtAllocTileCache();
		if (!m_tileCache) return false;
		status = m_tileCache->init(&tcparams, m_talloc, m_tcomp, m_tmproc);
		if (dtStatusFailed(status)) return false;

		dtFreeNavMesh(m_navMesh);

		m_navMesh = dtAllocNavMesh();
		if (!m_navMesh) return false;

		dtNavMeshParams params;
		memset(&params, 0, sizeof(params));
		rcVcopy(params.orig, m_geom->getMeshBoundsMin());
		params.tileWidth = m_tileSize*m_cellSize;
		params.tileHeight = m_tileSize*m_cellSize;
		params.maxTiles = m_maxTiles;
		params.maxPolys = m_maxPolysPerTile;

		status = m_navMesh->init(&params);
		if (dtStatusFailed(status)) return false;

		status = m_navQuery->init(m_navMesh, 2048);
		if (dtStatusFailed(status)) return false;

		for (int y = 0; y < th; ++y)
		{
			for (int x = 0; x < tw; ++x)
			{
				TileCacheData tiles[MAX_LAYERS];
				memset(tiles, 0, sizeof(tiles));
				int n = rasterizeTileLayers(m_ctx, m_geom, x, y, cfg, tiles, MAX_LAYERS);
				for (int i = 0; i < n; ++i)
				{
					TileCacheData* tile = &tiles[i];
					status = m_tileCache->addTile(tile->data, tile->dataSize, DT_COMPRESSEDTILE_FREE_DATA, 0);
					if (dtStatusFailed(status))
					{
						dtFree(tile->data);
						tile->data = 0;
						continue;
					}
				}
			}
		}
		for (int y = 0; y < th; ++y)
			for (int x = 0; x < tw; ++x)
				m_tileCache->buildNavMeshTilesAt(x,y, m_navMesh);
	}
	void NavMesh::AddObstacle(const float* pos)
	{
		if (!m_tileCache)
			return;
		dtObstacleRef ref = hitTestObstacle(m_tileCache, sp, sq);
		m_tileCache->removeObstacle(ref);
	}
	void NavMesh::RemoveObstacle(const float* sp, const float* sq)
	{
		if (!m_tileCache)
			return;
		dtObstacleRef ref = hitTestObstacle(m_tileCache, sp, sq);
		m_tileCache->removeObstacle(ref);
	}
	void NavMesh::ClearAllObstacle()
	{
		if (!m_tileCache)
			return;
		for (int i = 0; i < m_tileCache->getObstacleCount(); ++i)
		{
			const dtTileCacheObstacle* ob = m_tileCache->getObstacle(i);
			if (ob->state == DT_OBSTACLE_EMPTY) continue;
			m_tileCache->removeObstacle(m_tileCache->getObstacleRef(ob));
		}
	}
	void Update(const float dt)
	{
		if (!m_navMesh)
			return;
		if (!m_tileCache)
			return;
		m_tileCache->update(dt, m_navMesh);
	}
}