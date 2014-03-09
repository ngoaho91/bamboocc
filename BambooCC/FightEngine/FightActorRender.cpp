#include "FightActorRender.h"
namespace FightEngine
{
	ActorRender::ActorRender()
	{
		
	}
	ActorRender::~ActorRender()
	{
	}
	void ActorRender::SetCharacterRender(CharacterRender* render)
	{
		m_CharacterRender = render;
	}
	void ActorRender::SetParentNode(CCNode* parent)
	{
		m_CharacterRender->SetParentNode(parent);
	}
	void ActorRender::SetPositionXY(int x, int y)
	{
		m_CharacterRender->SetPositionXY(x,y);
	}
	void ActorRender::SetPositionZ(int z)
	{
		m_CharacterRender->SetPositionZ(z);
	}
	void ActorRender::SetHPPercent(float percent)
	{
	}
	void ActorRender::SetMPPercent(float percent)
	{
	}
	void ActorRender::SetName(const char* name)
	{
	}
	void ActorRender::SetShowName(bool value)
	{
		m_NameSprite->setVisible(value);
		m_SeriesSprite->setVisible(value);
	}
	void ActorRender::SetShowHP(bool value)
	{
		m_HPSprite->setVisible(value);
	}
	void ActorRender::SetShowMP(bool value)
	{
		m_MPSprite->setVisible(value);
	}
	void ActorRender::SetVisible(bool value)
	{
	}
}