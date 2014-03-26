#include "DamageRayRender.h"
#include "../Utilities.h"
#include "../pugiXML/pugixml.hpp"
namespace FightEngine
{
	DamageRayRender::DamageRayRender()
	{
		m_Sprite = CCSprite::create();
		m_Sprite->setAnchorPoint(ccp(0,1));
		m_Sprite->retain();
		m_ParentNode = 0;
	}
	DamageRayRender::~DamageRayRender()
	{
	}
	void DamageRayRender::LoadXml(const char* path)
	{
		pugi::xml_document animation_file;
		pugi::xml_parse_result result = animation_file.load_file(path);
		if(!result)
		{
			return;
		}
		// TODO: load damage ray file here, may be a particle effect 
	}
	void DamageRayRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode != parent)
		{
			if(m_ParentNode)
			{
				m_ParentNode->removeChild(m_Sprite,false);
				parent->addChild(m_Sprite);
			}
			else
			{
				parent->addChild(m_Sprite);
			}
			m_ParentNode = parent;
		}
	}
	void DamageRayRender::SetPositionXY(int x, int y)
	{
		m_Sprite->setPosition(ccp(x-160,y-70));
	}
	void DamageRayRender::SetPositionZ(int z)
	{
		m_Sprite->getParent()->reorderChild(m_Sprite,z);
	}
	void DamageRayRender::SetVisible(bool value)
	{
		m_Sprite->setVisible(value);
	}
	void DamageRayRender::InstantDestroy()
	{
		
	}
}