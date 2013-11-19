#include "ElementRender.h"
#include "..\pugiXML\pugixml.hpp"
#include "..\Utilities\Utilities.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace TileEngine
{
	ElementRender::ElementRender()
	{
		m_ParentNode = 0;
	}
	ElementRender::~ElementRender()
	{
	}
	void ElementRender::SetPosition(int x, int y)
	{
		if(x == m_PositionX && y == m_PositionY) return;
		m_PositionX = x;
		m_PositionY = y;
		if(!m_ParentNode) return;
		vector<ElementSprite>::iterator it;
		for(it = m_Sprites.begin();it< m_Sprites.end();it++)
		{
			ElementSprite part = (*it);
			int x = part.offsetX+m_PositionX;
			int y = part.offsetY+m_PositionY;
			part.sprite->setPosition(ccp(x, y));
			part.sprite->getParent()->reorderChild(part.sprite,MAP_INF-y);
		}
	}
	void ElementRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode != parent)
		{
			if(m_ParentNode)
			{
				vector<ElementSprite>::iterator it;
				for(it = m_Sprites.begin();it< m_Sprites.end();it++)
				{
					ElementSprite part = (*it);
					parent->addChild(part.sprite,
						part.offsetY+m_PositionY);
					m_ParentNode->removeChild(part.sprite,false);
				}
			}
			else
			{
				vector<ElementSprite>::iterator it;
				for(it = m_Sprites.begin();it< m_Sprites.end();it++)
				{
					ElementSprite part = (*it);
					parent->addChild(part.sprite,
						MAP_INF-(part.offsetY+m_PositionY));
				}
			}
			m_ParentNode = parent;
		}
	}
	void ElementRender::SetAnchor(int anchor_x, int anchor_y)
	{
		if(m_AnchorX == anchor_x && m_AnchorY == anchor_y) return;
		m_AnchorX = anchor_x;
		m_AnchorY = anchor_y;
	}
	void ElementRender::AddSprite(const char* textureFile, 
		int anchor_x, int anchor_y,
		int offset_x, int offset_y)
	{
		ElementSprite elementSprite;
		CCSprite* sprite;
		offset_y = -offset_y;

		sprite = CCSprite::create(textureFile);

		int h = sprite->getTextureRect().size.height;
		int w = sprite->getTextureRect().size.width;
		anchor_y = h - anchor_y;

		elementSprite.offsetX = offset_x;
		elementSprite.offsetY = offset_y;
		sprite->setAnchorPoint(ccp((float)anchor_x/w, (float)anchor_y/h));
		sprite->setPosition(ccp(offset_x+m_PositionX, offset_y+m_PositionY));
		elementSprite.sprite = sprite;
		m_Sprites.push_back(elementSprite);
		if(m_ParentNode)
			m_ParentNode->addChild(sprite,
			MAP_INF-(offset_y+m_PositionY));
	}
	
}