#include "Missile.h"
#include "../PathEngine/PathFinderActor.h"
#include "../PathEngine/PathFinderWorld.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace FightEngine
{
	Missile::Missile()
		:QuadObject(0,0,20,20)
	{
		m_ObjectType = QOT_MISSILE;
		m_Follow = false;
		m_Destroying = false;
		m_Destroyed = false;
		m_LifeTime = 200;
		m_DestroyTime = 10;
		m_Render = new MissileRender();
		m_Render->LoadXml("skill/missile/47-/47-.xml");
		m_Scope = FS_FOE;
	}
	Missile::~Missile()
	{
	}
	void Missile::Step()
	{
		float x = m_FightPositionX + m_SpeedX;
		float y = m_FightPositionY + m_SpeedY;
		bool inside = PathEngine::World::instance()->AvailableXY(x,y);
		if(!inside)
		{
			return Destroy();
		}
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
				if(actor->IsThrough()) continue;
				if(!ShouldCollide(actor)) continue;
				Geometry::Rectangle* actor_aabb = actor->GetFightBoundingBox();
				Geometry::Rectangle* this_aabb = this->GetBoundingBox();
				bool collide = actor_aabb->Collide(this_aabb);
				if(collide)
				{
					return DoCollide(actor);
				}
			}
			parentTree = parentTree->GetParent();
		}
		SetPosition(x,y);
		QuadObject::SetPosition(m_FightPositionX, m_FightPositionY);
	}
	bool Missile::ShouldCollide(Actor* actor)
	{
		// check missile scope, actor flag, ...
		return true;
	}
	void Missile::DoCollide(Actor* actor)
	{

	}
	void Missile::Destroy()
	{
		m_ParentSkill->onMissileDeath(this);
		m_Destroying = true;
	}
	void Missile::InstantDestroy()
	{
		m_Destroyed = true;
		m_Render->InstantDestroy();
	}
	void Missile::Update()
	{
		if(m_Destroyed) return;
		Step();
		if(m_Destroying)
		{
			m_DestroyTime--;
			if(m_DestroyTime==0)
			{
				m_Destroyed = true;
				m_Render->InstantDestroy();
			}
		}
		else
		{
			m_LifeTime--;
			if(m_LifeTime==0)
			{
				Destroy();
			}
		}
	}
	void Missile::SetFollow(bool value)
	{
		m_Follow = value;
	}
	void Missile::SetFollowObject(Actor* object)
	{
		m_FollowObject = object;
	}
	void Missile::SetOwner(Actor* owner)
	{
		m_Owner = owner;
	}
	void Missile::SetSkill(MissileSkill* skill)
	{
		m_ParentSkill = skill;
	}
	void Missile::SetPosition(int x, int y)
	{
		m_FightPositionX = x;
		m_FightPositionY = y;
		m_Render->SetPositionXY(x,y);
		m_Render->SetPositionZ(MAP_INF-y);
	}
	void Missile::SetAngle(float value)
	{
		m_Angle = value;
		if(m_Angle > PI)
			m_Angle -= _2PI;
		if(m_Angle < -PI)
			m_Angle += _2PI;
		m_SpeedX = m_Speed * cos(m_Angle);
		m_SpeedY = m_Speed * sin(m_Angle);
		int last = m_FaceDirection;
		if(m_Angle >= - _PI_8 && m_Angle < _PI_8)
		{
			m_FaceDirection = 6;
		}
		else if(m_Angle >= _PI_8 && m_Angle < _3PI_8)
		{
			m_FaceDirection = 5;
		}
		else if(m_Angle >= _3PI_8 && m_Angle < _5PI_8)
		{
			m_FaceDirection = 4;
		}
		else if(m_Angle >= _5PI_8 && m_Angle < _7PI_8)
		{
			m_FaceDirection = 3;
		}
		else if((m_Angle >= _7PI_8 && m_Angle <= PI) || 
			(m_Angle < - _7PI_8 && m_Angle >= -PI))
		{
			m_FaceDirection = 2;
		}
		else if(m_Angle >= - _7PI_8 && m_Angle < - _5PI_8)
		{
			m_FaceDirection = 1;
		}
		else if(m_Angle >= - _5PI_8 && m_Angle < - _3PI_8)
		{
			m_FaceDirection = 0;
		}
		else if(m_Angle >= - _3PI_8 && m_Angle < _PI_8)
		{
			m_FaceDirection = 7;
		}
		if(m_FaceDirection == last) return;
		m_Render->SetDirection(m_FaceDirection);
	}
	void Missile::SetAngleFromVertex(int x1, int y1, int x2, int y2)
	{
		float dx = x2-x1;
		float dy = y2-y1;
		float angle = atan2(dy, dx);
		SetAngle(angle);
	}
	void Missile::SetSpeed(float value)
	{
		m_Speed = value;
		m_SpeedX = m_Speed * cos(m_Angle);
		m_SpeedY = m_Speed * sin(m_Angle);
	}
}