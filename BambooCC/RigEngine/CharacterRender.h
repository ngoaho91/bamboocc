#ifndef CharacterRender_h
#define CharacterRender_h
#include "cocos2d.h"
#include "RigPartRender.h"
namespace RigEngine
{
	class CharacterRender
	{
		friend class Character;
	private:
		CCSprite* m_Sprite;
		CCNode* m_ParentNode;
	public:
		CharacterRender();
		~CharacterRender();
		void SetPositionXY(int x, int y);
		void SetPositionZ(int z);
		void SetParentNode(CCNode* parent);
		void AddChild(RigPartRender* render);
	};
}
#endif