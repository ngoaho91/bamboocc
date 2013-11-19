#include "FightWorldRender.h"
namespace FightEngine
{
	FightWorldRender::FightWorldRender()
	{
	}
	FightWorldRender::~FightWorldRender()
	{
	}
	void FightWorldRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode != parent)
		{
			{
				vector<MissileRender*>::iterator it;
				for(it = m_Missiles.begin();it< m_Missiles.end();it++)
				{
					MissileRender* element = (*it);
					element->SetParentNode(parent);
				}
			}
			{
				vector<TrapRender*>::iterator it;
				for(it = m_Traps.begin();it< m_Traps.end();it++)
				{
					TrapRender* element = (*it);
					element->SetParentNode(parent);
				}
			}
			{
				vector<DamageFieldRender*>::iterator it;
				for(it = m_Fields.begin();it< m_Fields.end();it++)
				{
					DamageFieldRender* element = (*it);
					element->SetParentNode(parent);
				}
			}
			m_ParentNode = parent;
		}
	}
	void FightWorldRender::AddMissile(MissileRender* missile)
	{
		m_Missiles.push_back(missile);
		missile->SetParentNode(m_ParentNode);
	}
	void FightWorldRender::AddTrap(TrapRender* trap)
	{
		m_Traps.push_back(trap);
		trap->SetParentNode(m_ParentNode);
	}
	void FightWorldRender::AddDamageField(DamageFieldRender* field)
	{
		m_Fields.push_back(field);
		field->SetParentNode(m_ParentNode);
	}
	void FightWorldRender::AddDamageRay(DamageRayRender* ray)
	{
		m_Rays.push_back(ray);
		ray->SetParentNode(m_ParentNode);
	}
}