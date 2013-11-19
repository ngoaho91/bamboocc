#ifndef ElementRender_h
#define ElementRender_h
#include "cocos2d.h"
using namespace cocos2d;
using namespace std;
namespace TileEngine
{
	struct ElementSprite
	{
		CCSprite*		sprite;
		short			offsetX, 
						offsetY;
	};
	class ElementRender
	{
	private:
		CCNode*						m_ParentNode;
		vector<ElementSprite>		m_Sprites;
		short						m_AnchorX, m_AnchorY;
		short						m_PositionX, m_PositionY;
	public:
		ElementRender();
		~ElementRender();
		void SetParentNode(CCNode* parent);
		void SetPosition(int x, int y);
		void SetAnchor(int anchor_x, int anchor_y);
		void AddSprite(const char* textureFile, int anchor_x, int anchor_y, int offset_x, int offset_y);
	};
}
#endif