#ifndef PathFinderActor_h
#define PathFinderActor_h
#include <vector>
#include <math.h>
#include "../Geometry/Node.h"
#include "../Geometry/QuadTree.h"
#include "../Geometry/GeometryConstant.h"
using namespace std;
using namespace Geometry;
#define QOT_PATHACTOR 2
namespace PathEngine
{
	class Actor
		: public QuadObject
	{
	protected:
		float			m_PositionX;
		float			m_PositionY;
		bool			m_Through;
		Node*			m_LocalGoal;
		double			m_GoalAngle;
		vector<Node*>	m_FinalSolution;
		bool			m_Free;
		bool			m_Lost;
		bool			m_EvadingActor;
		Actor*			m_EvadingObject;
		int				m_EvadingTime;
		bool			m_EvadingWall;
		bool			m_LookingToGoal;
		bool			m_LookedToGoal;
		double			m_Speed;
		double			m_SpeedX;
		double			m_SpeedY;
		double			m_Angle;
		double			m_TurnSpeed;
	public:
		Actor(int width, int height);
		~Actor();
		void SetPosition(int x, int y);
		void GoTo(int x, int y);
		void GoNear(int x, int y, int range);
		void ClearPath();
		virtual void Step();
		void UpdateIdle();
		int GetPositionX(){return m_PositionX;}
		int GetPositionY(){return m_PositionY;}
		double GetAngle() { return m_Angle; }
		bool IsThrough(){return m_Through;}
	private:
		void ActualStep(int x, int y);
		void LookAtGoal();
		void CheckActor();
		void EvadeActor(Actor* other);
		void CheckWall();
		void EvadeWall();
		void NextGoal();
		void FindLocalSolution();
	private:
		void RotateCW();
		void RotateCCW();
		void RefreshSpeed();
		void RefreshGoalAngle();
		
	};
	
}
#endif