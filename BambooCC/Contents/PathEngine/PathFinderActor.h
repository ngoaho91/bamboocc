#ifndef PathFinderActor_h
#define PathFinderActor_h
#include <vector>
#include <math.h>
#include "Geometry/Node.h"
#include "Geometry/QuadTree.h"
#include "Geometry/GeometryConstant.h"
using namespace std;
using namespace Geometry;
#define QOT_PATHACTOR 2
namespace PathEngine
{
	enum TurnDirection
	{
		TD_CLOCKWISE = 0,
		TD_COUNTERCW = 1
	};
	enum ActorState
	{
		MS_STANDING = 0,// STANDING STILL
		MS_WAITING = 1,// WANT TO MOVE BUT CANT MOVE, LET'S WAIT FOR SOME MIRACLE
		MS_PULLING = 2,// PULLING OTHER(S) TO OPEN PATH
		MS_BEINGPULL = 3,// BEING PULLED BY OTHER
		MS_MOVING = 4,// MOVING, AS THE PATH GUIDE
		MS_BLINDMOVING = 5// MOVING, BUT NOT SURE ABOUT THE PATH
	};
	class Actor
		: public QuadObject
	{
	protected:
		Node*			m_Position;
		double			m_Size;
		double			m_Speed;
		Vector*			m_SpeedVector;
		double			m_Angle;
		double			m_TurnSpeed;
		Node*			m_LocalGoal;
		Nodes			m_FinalSolution;
		bool			m_Through;
		ActorState		m_State;
	public:
		Actor(double size);
		Actor();
		~Actor();
		void SetPosition(int x, int y);
	private:
		Node* PredictPosition(int step);
		TurnDirection TurnAwayOf(Actor* other);
	};
	
}
#endif