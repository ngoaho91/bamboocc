#include "PathFinderActor.h"
#include "PathFinderWorld.h"
#define WALL_EVADING_TIME 5
#define ACTOR_EVADING_TIME 5
#include <iostream>
using namespace std;
namespace PathEngine
{
	Actor::Actor(int width, int height):
		QuadObject(0, 0, width, height)
	{
		m_ObjectType = QOT_PATHACTOR;
		m_PositionX = 0;
		m_PositionY = 0;
		m_Through = false;
		m_LocalGoal = 0;
		m_Free = true;
		m_Lost = false;
		m_EvadingActor = false;
		m_EvadingObject = 0;
		m_EvadingTime = 0;
		m_EvadingWall = false;
		m_LookingToGoal = false;
		m_LookedToGoal = true;
		m_Speed = 3;
		m_Angle = 0;
		m_SpeedX = 3;
		m_SpeedY = 0;
		m_TurnSpeed = PI/8;
	}
	Actor::~Actor()
	{
	}
	void Actor::SetPosition(int x, int y)
	{
		QuadObject::SetPosition(x, y);
		m_PositionX = x;
		m_PositionY = y;
		m_Free = true;
		m_LookingToGoal = false;
		m_EvadingActor = false;
		m_EvadingWall = false;
	}
	void Actor::GoTo(int x, int y)
	{
		if(x == m_PositionX && y == m_PositionY) return;
		m_FinalSolution.clear();
		bool inside = World::instance()->AvailableXY(m_PositionX,m_PositionY);
		if(!inside)
		{
			m_Lost = true;
		}
		m_FinalSolution = World::instance()->
			FindPath(m_PositionX, m_PositionY, x, y);
		if(m_FinalSolution.size() == 0)
		{
			EvadeWall();
			while(m_EvadingWall)
			{
				CheckWall();
				// TODO: implement an algorithm that find a new position 
				// for actor if it hanging on a wall
			}
			Step();
		}
		else
		{
			m_Free = false;
			m_LookingToGoal = false;
			NextGoal();
			LookAtGoal();
		}
	}
	void Actor::GoNear(int x, int y, int range)
	{
		m_FinalSolution.clear();
		m_FinalSolution = World::instance()->
			FindPathNear(m_PositionX, m_PositionY, x, y, range);
		if(m_FinalSolution.size() == 0)
		{
			m_Free = true;
		}
		else
		{
			m_Free = false;
			m_LookingToGoal = false;
			NextGoal();
			LookAtGoal();
		}
	}
	void Actor::ActualStep(int x, int y)
	{
		m_PositionX = x;
		m_PositionY = y;
		if(abs(m_PositionX - m_LocalGoal->X) < abs(m_SpeedX))
		{
			m_PositionX = m_LocalGoal->X;
		}
		if(abs(m_PositionY - m_LocalGoal->Y) < abs(m_SpeedY))
		{
			m_PositionY = m_LocalGoal->Y;
		}
		QuadObject::SetPosition(m_PositionX, m_PositionY);
		cout<<this<<" move"<<endl;
		if(m_PositionX == m_LocalGoal->X && m_PositionY == m_LocalGoal->Y)
		{
			return NextGoal();
		}
	}
	void Actor::Step()
	{
		if(m_Free) return;
		if(m_Through)
		{
			float x = m_PositionX + m_SpeedX;
			float y = m_PositionY + m_SpeedY;
			return ActualStep(x,y);
		}
		CheckWall();
		CheckActor();
		LookAtGoal();
		if(m_EvadingActor || m_EvadingWall) return;
		if(m_LookingToGoal) return;
		float x = m_PositionX + m_SpeedX;
		float y = m_PositionY + m_SpeedY;
		m_PositionX = x;
		m_PositionY = y;
		if(abs(m_PositionX - m_LocalGoal->X) < abs(m_SpeedX))
		{
			m_PositionX = m_LocalGoal->X;
		}
		if(abs(m_PositionY - m_LocalGoal->Y) < abs(m_SpeedY))
		{
			m_PositionY = m_LocalGoal->Y;
		}
		QuadObject::SetPosition(m_PositionX, m_PositionY);
		cout<<this<<" move"<<endl;
		if(m_PositionX == m_LocalGoal->X && m_PositionY == m_LocalGoal->Y)
		{
			return NextGoal();
		}
	}
	void Actor::LookAtGoal()
	{
		if(m_EvadingWall || m_EvadingActor) return;
		if(m_LookedToGoal) return;
		if(m_EvadingTime > 0)
		{
			m_EvadingTime--;
			cout<<"wait time "<<m_EvadingTime<<endl;
			return;
		}
		if(!m_LookingToGoal)
		{
			RefreshGoalAngle();
			m_LookingToGoal = true;
		}
		cout<<this<<" head to goal"<<endl;
		bool greater = m_GoalAngle > m_Angle;
		double distance = m_GoalAngle - m_Angle;
		bool long_distance = distance > PI;
		if(long_distance)
		{
			greater = !greater;
			distance -= _2PI;
		}
		if(greater)
		{
			RotateCCW();
		}
		else
		{
			RotateCW();
		}
		if(abs(distance) <= m_TurnSpeed)
		{
			m_Angle = m_GoalAngle;
			m_LookedToGoal = true;
			m_LookingToGoal = false;
			RefreshSpeed();
			CheckWall();
		}
	}
	void  Actor::CheckActor()
	{
		if(m_EvadingWall) return;
		if(m_EvadingActor)
		{
			float x = m_PositionX + m_SpeedX;
			float y = m_PositionY + m_SpeedY;
			QuadObject::SetPosition(x, y);
			Rectangle* actor_aabb = m_EvadingObject->GetBoundingBox();
			Rectangle* this_aabb = this->GetBoundingBox();
			bool collide = actor_aabb->Collide(this_aabb);
			QuadObject::SetPosition(m_PositionX, m_PositionY);
			if(collide)
			{
				m_LookingToGoal = false;
				RotateCCW();
			}
			else
			{
				m_Lost = true;
				m_EvadingActor = false;
				cout<<"evade finish, wait "<<ACTOR_EVADING_TIME<<" frames until head to goal"<<endl;
				m_EvadingTime = ACTOR_EVADING_TIME;
				CheckWall();
			}
		}
		else
		{
			float x = m_PositionX + m_SpeedX;
			float y = m_PositionY + m_SpeedY;
			QuadObject::SetPosition(x, y);
			QuadTree* parentTree = m_ParentNode;
			while(parentTree)
			{
				vector<QuadObject*> objects = parentTree->GetObjects();
				vector<QuadObject*>::iterator it = objects.begin();
				for(;it != objects.end();it++)
				{
					QuadObject* quad = *it;
					if(quad == this) continue;
					Actor* actor = (Actor*)quad;
					if(actor->m_Through) continue;
					Rectangle* actor_aabb = actor->GetBoundingBox();
					Rectangle* this_aabb = this->GetBoundingBox();
					bool collide = actor_aabb->Collide(this_aabb);
					if(collide)
					{
						actor->EvadeActor(this);
						return EvadeActor(actor);
					}
				}
				parentTree = parentTree->GetParent();
			}
			QuadObject::SetPosition(m_PositionX, m_PositionY);
		}
		
	}
	void Actor::EvadeActor(Actor* other)
	{
		Rectangle* other_aabb = other->GetBoundingBox();
		if(other_aabb->TestPointInside(m_LocalGoal->X, m_LocalGoal->Y))
		{
			NextGoal();
		}
		m_EvadingObject = other;
		cout<<this<<" evade "<<other<<endl;
		m_Lost = true;
		m_EvadingActor = true;
		m_LookedToGoal = false;
		RotateCW();
	}
	void Actor::CheckWall()
	{
		if(!m_Lost) return;
		if(m_EvadingWall)
		{
			RotateCCW();
			m_EvadingTime--;
			if(m_EvadingTime == 0)
			{
				float x = m_PositionX + m_SpeedX;
				float y = m_PositionY + m_SpeedY;
				bool inside = World::instance()->AvailableXY(x,y);
				if(!inside)
				{
					m_LookingToGoal = false;
					EvadeWall();
				}
				else
				{
					m_EvadingWall = false;
					QuadObject::SetPosition(x,y);
					CheckActor();
					if(!m_EvadingActor)
					{
						m_PositionX = x;
						m_PositionY = y;
						
						FindLocalSolution();
					}
					QuadObject::SetPosition(m_PositionX,m_PositionY);
				}
			}
		}
		else
		{
			float x = m_PositionX + m_SpeedX;
			float y = m_PositionY + m_SpeedY;
			bool inside = World::instance()->AvailableXY(x,y);
			if(!inside)
			{
				EvadeWall();
			}
		}
	}
	void Actor::EvadeWall()
	{
		cout<<this<<" evading wall"<<endl;
		m_Lost = true;
		m_EvadingWall = true;
		m_LookedToGoal = false;
		m_EvadingTime = WALL_EVADING_TIME;
	}
	void Actor::FindLocalSolution()
	{
		if(m_FinalSolution.size() == 0)
		{
			return GoTo(m_LocalGoal->X, m_LocalGoal->Y);
		}
		Node* next = m_FinalSolution.back();
		m_FinalSolution.pop_back();
		vector<Node*> solution = World::instance()->FindPath(
			m_PositionX, m_PositionY, next->X, next->Y);
		if(solution.size() == 0)
		{
			Node* node = m_FinalSolution.front();
			GoTo(node->X, node->Y);
		}
		else
		{
			vector<Node*>::iterator it = solution.begin();
			for(;it != solution.end();it++)
			{
				m_FinalSolution.push_back(*it);
			}
			m_Free = false;
			m_LookedToGoal = false;
			NextGoal();
			LookAtGoal();
		}
	}
	void Actor::NextGoal()
	{
		if(m_FinalSolution.size() == 0)
		{
			m_Free = true;
			return;
		}
		m_LocalGoal = m_FinalSolution.back();
		m_FinalSolution.pop_back();
		if(m_LocalGoal->X == m_PositionX && m_LocalGoal->Y == m_PositionY)
		{
			NextGoal();
		}
		else
		{
			m_EvadingTime = 0;
			m_Lost = false;
			m_LookedToGoal = false;
			RefreshGoalAngle();
		}
	}
	void Actor::RefreshGoalAngle()
	{
		float dx = m_LocalGoal->X - m_PositionX;
		float dy = m_LocalGoal->Y - m_PositionY;
		m_GoalAngle = atan2(dy, dx);
		m_LookedToGoal = false;
	}
	void Actor::RotateCW()
	{
		m_Angle -= m_TurnSpeed;
		RefreshSpeed();
	}
	void Actor::RotateCCW()
	{
		m_Angle += m_TurnSpeed;
		RefreshSpeed();
	}
	void Actor::RefreshSpeed()
	{
		if(m_Angle > PI)
			m_Angle -= _2PI;
		if(m_Angle < -PI)
			m_Angle += _2PI;
		m_SpeedX = m_Speed * cos(m_Angle);
		m_SpeedY = m_Speed * sin(m_Angle);
		/*double deg = m_Angle/PI180;
		double rad = m_Angle/PI;
		cout<<"current angle(degree): "<<deg<<endl;
		cout<<"current angle(radian): "<<rad<<" PI"<<endl;
		cout<<"cos("<<deg<<")="<<m_SpeedX/3<<"-> speed x = "<<m_SpeedX<<endl;
		cout<<"sin("<<deg<<")="<<m_SpeedY/3<<"-> speed y = "<<m_SpeedY<<endl;
		cout<<"----------------------------------\n";*/
	}
	void Actor::UpdateIdle()
	{
		if(m_LookedToGoal) return;
		if(!m_LookingToGoal)
		{
			m_LookingToGoal = true;
		}
		cout<<this<<" head to goal"<<endl;
		bool greater = m_GoalAngle > m_Angle;
		double distance = m_GoalAngle - m_Angle;
		bool long_distance = distance > PI;
		if(long_distance)
		{
			greater = !greater;
			distance -= _2PI;
		}
		if(greater)
		{
			RotateCCW();
		}
		else
		{
			RotateCW();
		}
		if(abs(distance) <= m_TurnSpeed)
		{
			m_Angle = m_GoalAngle;
			m_LookedToGoal = true;
			m_LookingToGoal = false;
			RefreshSpeed();
		}
	}
}