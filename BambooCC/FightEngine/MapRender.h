#ifndef MapRender_h
#define MapRender_h
#include "cocos2d.h"
#include "../TileEngine/TileMap.h"
#include "../TileEngine/Element.h"
using namespace cocos2d;
using namespace TileEngine;
namespace FightEngine
{
	class MapRender
	{
		friend class Map;
	private:
		CCNode*					m_ParentNode;
		vector<ElementRender*>	m_Elements;
		TilemapRender*			m_Tilemap;
	public:
		MapRender();
		~MapRender();
		void SetParentNode(CCNode* parent);
		void Focus(float x, float y);
		void MouseToMap(int mouse_x, int mouse_y, int* map_x, int* map_y);
	};
}
#endif