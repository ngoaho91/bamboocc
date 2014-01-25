#ifndef DamageRayRender_h
#define DamageRayRender_h
#include "cocos2d.h"
#include <vector>
using namespace std;
USING_NS_CC;
namespace FightEngine
{
	class DamageRayRender
	{
	private:
		CCNode* m_ParentNode;
		CCSprite* m_Sprite;
	public:
		DamageRayRender();
		~DamageRayRender();
		void LoadXml(const char* path);
		void SetParentNode(CCNode* parent);
		void SetPositionXY(int x, int y);
		void SetPositionZ(int z);
		void SetVisible(bool value);
	public:
		void InstantDestroy();
	};
}
#endif