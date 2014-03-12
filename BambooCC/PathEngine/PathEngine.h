#include <string.h>
#include "InputGeom.h"
#include "PerfTimer.h"
#include "Recast.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include "DetourTileCache.h"
#include "DetourCrowd.h"

struct LinearAllocator;
struct FastLZCompressor;
struct MeshProcess;
namespace PathEngine
{
	class BuildContext : public rcContext
	{
		TimeVal m_startTime[RC_MAX_TIMERS];
		int m_accTime[RC_MAX_TIMERS];

		static const int MAX_MESSAGES = 1000;
		const char* m_messages[MAX_MESSAGES];
		int m_messageCount;
		static const int TEXT_POOL_SIZE = 8000;
		char m_textPool[TEXT_POOL_SIZE];
		int m_textPoolSize;

	public:
		BuildContext();
		virtual ~BuildContext();

		/// Dumps the log to stdout.
		void dumpLog(const char* format, ...);
		/// Returns number of log messages.
		int getLogCount() const;
		/// Returns log message text.
		const char* getLogText(const int i) const;

	protected:	
		/// Virtual functions for custom implementations.
		///@{
		virtual void doResetLog();
		virtual void doLog(const rcLogCategory /*category*/, const char* /*msg*/, const int /*len*/);
		virtual void doResetTimers();
		virtual void doStartTimer(const rcTimerLabel /*label*/);
		virtual void doStopTimer(const rcTimerLabel /*label*/);
		virtual int doGetAccumulatedTime(const rcTimerLabel /*label*/) const;
		///@}
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
		// crowd tool
		void InitCrowd();
		void AddAgent(const float* p);
		int HitTestAgent(const float* s, const float* p);
		void RemoveAgent(const int idx);
		void UpdateCrowd(const float dt);
		void MoveAgent(int id, const float* p);
		void ForceAgent(int id, const float* p);
	};
}