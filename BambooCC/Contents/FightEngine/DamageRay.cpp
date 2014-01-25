#include "DamageRay.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace FightEngine
{
	DamageRay::DamageRay()
		:QuadObject(0,0,20,20)
	{
		m_ObjectType = QOT_RAY;
		m_Destroying = false;
		m_Destroyed = false;
		m_LifeTime = 200;
		m_DestroyTime = 10;
		m_Render = new DamageRayRender();
		//m_Render->LoadXml("skill/missile/47-/47-.xml");
		m_Scope = FS_FOE;
	}
	DamageRay::~DamageRay()
	{
	}
	bool DamageRay::ShouldCollide(Actor* actor)
	{
		// check missile scope, actor flag, ...
		return true;
	}
	void DamageRay::DoCollide(Actor* actor)
	{

	}
	void DamageRay::Destroy()
	{
		m_ParentSkill->onDeath(this);
		m_Destroying = true;
	}
	void DamageRay::InstantDestroy()
	{
		m_Destroyed = true;
		m_Render->InstantDestroy();
	}
	void DamageRay::Update()
	{
		if(m_Destroyed) return;
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
	void DamageRay::SetOwner(Actor* owner)
	{
		m_Owner = owner;
	}
	void DamageRay::SetSkill(RaySkill* skill)
	{
		m_ParentSkill = skill;
	}
	void DamageRay::SetPosition(int x, int y)
	{
		m_FightPositionX = x;
		m_FightPositionY = y;
		m_Render->SetPositionXY(x,y);
		m_Render->SetPositionZ(MAP_INF-y);
	}
	void DamageRay::SetAngle(float value)
	{
		m_Angle = value;
		if(m_Angle > PI)
			m_Angle -= _2PI;
		if(m_Angle < -PI)
			m_Angle += _2PI;
	}
	void DamageRay::SetAngleFromVertex(int x1, int y1, int x2, int y2)
	{
		float dx = x2-x1;
		float dy = y2-y1;
		float angle = atan2(dy, dx);
		SetAngle(angle);
	}
	void DamageRay::SetLength(float value)
	{
		m_Length = value;
	}
}