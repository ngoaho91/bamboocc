#include "DamageField.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace FightEngine
{
	DamageField::DamageField()
		:QuadObject(0,0,20,20)
	{
		m_ObjectType = QOT_FIELD;
		m_Destroying = false;
		m_Destroyed = false;
		m_LifeTime = 200;
		m_DestroyTime = 10;
		m_Render = new DamageFieldRender();
		//m_Render->LoadXml("skill/missile/47-/47-.xml");
		m_Scope = FS_FOE;
	}
	DamageField::~DamageField()
	{
	}
	bool DamageField::ShouldCollide(Actor* actor)
	{
		// check missile scope, actor flag, ...
		return true;
	}
	void DamageField::DoCollide(Actor* actor)
	{

	}
	void DamageField::Destroy()
	{
		m_ParentSkill->onDeath(this);
		m_Destroying = true;
	}
	void DamageField::InstantDestroy()
	{
		m_Destroyed = true;
		m_Render->InstantDestroy();
	}
	void DamageField::Update()
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
	void DamageField::SetOwner(Actor* owner)
	{
		m_Owner = owner;
	}
	void DamageField::SetSkill(AOESkill* skill)
	{
		m_ParentSkill = skill;
	}
	void DamageField::SetPosition(int x, int y)
	{
		m_FightPositionX = x;
		m_FightPositionY = y;
		m_Render->SetPositionXY(x,y);
		m_Render->SetPositionZ(MAP_INF-y);
	}
	void DamageField::SetRange(float value)
	{
		m_Range = value;
	}
}