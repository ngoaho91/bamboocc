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

		float m_cellSize;
		float m_cellHeight;
		float m_agentHeight;
		float m_agentRadius;
		float m_agentMaxClimb;
		float m_agentMaxSlope;
		float m_regionMinSize;
		float m_regionMergeSize;
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
		// navigation mesh
		void SetMesh(InputGeom* geom);
		bool Build();
		void AddObstacle(const float* pos);
		void RemoveObstacle(const float* sp, const float* sq);
		void ClearAllObstacle();
		void Update(const float dt);
		// crowd tool
		void AddAgent(const float* p);
		void HitTestAgent(const float* s, const float* p);
		void RemoveAgent(const int idx);
		void UpdateAgentParams();
		void UpdateCrowd(const float dt);
	}
}