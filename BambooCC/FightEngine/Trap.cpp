#include "Trap.h"
#include "../PathEngine/PathEngine.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace FightEngine
{
	Trap::Trap()
		:QuadObject(0,0,20,20)
	{
		m_ObjectType = QOT_TRAP;
		m_Destroying = false;
		m_Destroyed = false;
		m_LifeTime = 200;
		m_DestroyTime = 10;
		m_Render = new TrapRender();
		m_Render->LoadXml("skill/effect/179-/179-.xml");
		m_Scope = FS_FOE;
	}
	Trap::~Trap()
	{
	}
	
	bool Trap::ShouldCollide(Actor* actor)
	{
		// check missile scope, actor flag, ...
		return true;
	}
	void Trap::DoCollide(Actor* actor)
	{

	}
	void Trap::Destroy()
	{
		m_Destroying = true;
	}
	void Trap::InstantDestroy()
	{
		m_Destroyed = true;
		m_Render->InstantDestroy();
	}
	void Trap::Update()
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
			if(m_LifeTime == 0)
			{
				Destroy();
			}
		}
	}
	
	void Trap::SetOwner(Actor* owner)
	{
		m_Owner = owner;
	}
	void Trap::SetSkill(TrapSkill* skill)
	{
		m_ParentSkill = skill;
	}
	void Trap::SetPosition(int x, int y)
	{
		m_FightPositionX = x;
		m_FightPositionY = y;
		m_Render->SetPositionXY(x,y);
		m_Render->SetPositionZ(MAP_INF-y);
	}
}