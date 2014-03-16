#include <string.h>
#include "RecastHelper.h"

namespace PathEngine
{
	// TODO: implement these 2 class
	class Agent
	{
	protected:
		dtCrowdAgent* m_AgentRef;
		int m_Angle;
	public:
		Agent(){m_Angle = 0;}
		~Agent(){}
		int* GetPosition();
		void SetPosition(int x, int y){}
		int* GetVelocity();
	};
	class Obstacle
	{
	private:
		//dtObstacleRef 
	};
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
	private:
		AgentTrail m_trails[MAX_AGENTS];
		float m_targetPos[3];
		dtPolyRef m_targetRef;
	public:
		NavMesh();
		~NavMesh();
		// navigation mesh
		void InitMesh();
		void SetMesh(InputGeom* geom);
		bool Build();
		dtObstacleRef HitTestObstacle(const float* sp, const float* sq);
		void AddObstacle(const float* pos);
		void RemoveObstacle(const float* sp, const float* sq);
		void ClearAllObstacle();
		void UpdateMesh(const float dt);
		// crowd control
		void InitCrowd();
		void AddAgent(const float* p);
		int HitTestAgent(const float* s, const float* p);
		void RemoveAgent(const int idx);
		void UpdateCrowd(const float dt);
		void MoveAgent(int id, const float* p);
		void ForceAgent(int id, const float* p);
	};
}