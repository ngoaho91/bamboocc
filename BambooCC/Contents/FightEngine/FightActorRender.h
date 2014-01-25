#ifndef FightActorRender_h
#define FightActorRender_h
#include "../RigEngine/CharacterRender.h"
#include "cocos2d.h"
using namespace RigEngine;
namespace FightEngine
{
	class ActorRender
	{
	private:
		CharacterRender* m_CharacterRender;
		CCSprite* m_HPSprite;
		CCSprite* m_MPSprite;
		CCSprite* m_NameSprite;
		CCSprite* m_SeriesSprite;
		CCSprite* m_SelectedSprite;
	public:
		ActorRender();
		~ActorRender();
		void SetCharacterRender(CharacterRender* render);
		void SetParentNode(CCNode* parent);
		void SetPositionXY(int x, int y);
		void SetPositionZ(int z);
		void SetHPPercent(float percent);
		void SetMPPercent(float percent);
		void SetName(const char* name);
		void SetShowName(bool value);
		void SetShowHP(bool value);
		void SetShowMP(bool value);
		void SetVisible(bool value);
	};
}
#endif