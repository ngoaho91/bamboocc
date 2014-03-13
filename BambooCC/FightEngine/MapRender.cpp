#include "MapRender.h"
namespace FightEngine
{
	MapRender::MapRender()
	{
	}
	MapRender::~MapRender()
	{
	}
	void MapRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode != parent)
		{
			vector<ElementRender*>::iterator it;
			for(it = m_Elements.begin();it< m_Elements.end();it++)
			{
				ElementRender* element = (*it);
				element->SetParentNode(parent);
			}
			m_Tilemap->SetParentNode(parent);
			//m_PathRender->SetParentNode(parent);
			//m_ParentNode = parent;
		}
	}
	void MapRender::Focus(float x, float y)
	{
		CCLayer* layer = (CCLayer*)m_ParentNode;
		layer->setPosition(ccp(400-x,300-y));
	}
	void MapRender::MouseToMap(int mouse_x, int mouse_y, int* map_x, int* map_y)
	{
		CCLayer* layer = (CCLayer*)m_ParentNode;
		float x, y;
		layer->getPosition(&x,&y);
		*map_x = mouse_x - x;
		*map_y = mouse_y - y;
	}
}