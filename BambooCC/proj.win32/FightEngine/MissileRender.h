#ifndef MissileRender_h
#define MissileRender_h
#include "cocos2d.h"
#include <vector>
using namespace std;
USING_NS_CC;
namespace FightEngine
{
	class MissileRender
	{
	private:
		CCNode* m_ParentNode;
		CCSprite* m_Sprite;
		vector<CCAction*> m_Actions;
		CCTexture2D* m_Texture;
	public:
		MissileRender();
		~MissileRender();
		void LoadXml(const char* path);
		void SetParentNode(CCNode* parent);
		void SetPositionXY(int x, int y);
		void SetPositionZ(int z);
		void SetDirection(int value);
		void SetVisible(bool value);
	public:
		void InstantDestroy();
	};
}
#endif