#include "CharacterRender.h"
namespace RigEngine
{
	CharacterRender::CharacterRender()
	{
		m_Sprite = CCSprite::create();
		m_Sprite->retain();
		m_ParentNode = 0;
	}
	CharacterRender::~CharacterRender()
	{
	}
	void CharacterRender::SetPositionXY(int x, int y)
	{
		m_Sprite->setPosition(ccp(x-160,y-70));
	}
	void CharacterRender::SetPositionZ(int z)
	{
		m_Sprite->getParent()->reorderChild(m_Sprite,z);
	}
	void CharacterRender::SetParentNode(CCNode* parent)
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
	void CharacterRender::AddChild(RigPartRender* render)
	{
		m_Sprite->addChild(render->m_Sprite);
	}
}