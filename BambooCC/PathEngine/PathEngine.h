#include <string.h>
#include "RecastHelper.h"

namespace PathEngine
{
	class NavMesh
	{
	private:
		InputGeom* m_geom;
		dtNavMesh* m_navMesh;
		dtNavMeshQuery* m_navQuery;
		dtCrowd* m_crowd;
	private:
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
		dtTileCache* m_tileCache;

		int m_maxTiles;
		int m_maxPolysPerTile;
		float m_tileSize;
	public:
		dtCrowd* Crowd(){ return m_crowd;}
		dtNavMesh* Mesh(){ return m_navMesh;}
		dtNavMeshQuery* Query(){ return m_navQuery;}
	public:
		NavMesh();
		~NavMesh();
		// navigation mesh
		void InitMesh();
		void SetMesh(InputGeom* geom);
		bool BuildMesh();
		void UpdateMesh(const float dt);
		
		// temp obstacle
		int HitTestObstacle(const float* sp, const float* sq);
		int AddObstacle(const float* pos);
		void RemoveObstacle(const float* sp, const float* sq);
		void ClearAllObstacle();
		
		// crowd control
		void InitCrowd();
		int AddAgent(const float* p);
		int HitTestAgent(const float* s, const float* p);
		void RemoveAgent(const int idx);
		void UpdateCrowd(const float dt);
	};
	class Agent
	{
	protected:
		dtCrowd* m_Crowd;
		const dtCrowdAgent* m_CrowdAgent;
		NavMesh* m_NavMesh;
		float m_Angle;
		int m_AgentID;
		float m_Velocity[3];
		float m_Position[3];
	public:
		Agent(NavMesh* mesh);
		Agent(NavMesh* mesh, int id);
		~Agent();
		void SetID(int id);
		void SyncVelocity();
		void SyncPosition();
		void Move(const float* p);
		void Force(const float* p);
	};
}