#include "InputGeom.h"
#include "Recast.h"
#include "DetourNavMesh.h"

namespace PathEngine
{
	class Agent;
	class Obstacle;
	class Terrain;
	class NavMesh
	{
	private:
		InputGeom* m_geom;
		dtNavMesh* m_navMesh;
		dtNavMeshQuery* m_navQuery;
		dtCrowd* m_crowd;

		unsigned char m_navMeshDrawFlags;

		float m_cellSize;
		float m_cellHeight;
		float m_agentHeight;
		float m_agentRadius;
		float m_agentMaxClimb;
		float m_agentMaxSlope;
		float m_regionMinSize;
		float m_regionMergeSize;
		bool m_monotonePartitioning;
		float m_edgeMaxLen;
		float m_edgeMaxError;
		float m_vertsPerPoly;
		float m_detailSampleDist;
		float m_detailSampleMaxError;
		BuildContext* m_ctx;
	private:
		struct LinearAllocator* m_talloc;
		struct FastLZCompressor* m_tcomp;
		struct MeshProcess* m_tmproc;
		class dtTileCache* m_tileCache;
		int m_maxTiles;
		int m_maxPolysPerTile;
		float m_tileSize;
	public:
		NavMesh(){}
		~NavMesh(){}
		void SetMesh(InputGeom* geom);
		bool Build();
	}
}