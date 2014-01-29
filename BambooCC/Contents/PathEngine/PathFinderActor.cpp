#include "PathFinderActor.h"
#include "PathFinderWorld.h"
#define WALL_EVADING_TIME 5
#define ACTOR_EVADING_TIME 5
#include <iostream>
using namespace std;
namespace PathEngine
{
	Actor::Actor():
		QuadObject()
	{
		m_ObjectType = QOT_PATHACTOR;
		m_Position;
		m_Size = 10;
		m_SpeedVector = new Vector(0.0, 0.0);
		m_Angle = 0;
		m_TurnSpeed = PI/8;
		m_LocalGoal = 0;
		m_Through = false;
		m_State = MS_STANDING;
		m_Speed = 3;
		m_TurnSpeed = PI/8;
	}
	Actor::~Actor()
	{
	}
	void Actor::SetPosition(int x, int y)
	{
		QuadObject::SetPosition(x, y);
		// ect
	}
	Node* Actor::PredictPosition(int step)
	{
		Node* ret;
		// etc
		return ret;
	}
	TurnDirection Actor::TurnAwayOf(Actor* other)
	{
		return TD_CLOCKWISE;
	}
}