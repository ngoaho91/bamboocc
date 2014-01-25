#include "TrapRender.h"
#include "../Utilities/Utilities.h"
#include "../pugiXML/pugixml.hpp"
namespace FightEngine
{
	TrapRender::TrapRender()
	{
		m_Texture = 0;
		m_Sprite = CCSprite::create();
		m_Sprite->setAnchorPoint(ccp(0,1));
		m_Sprite->retain();
		m_ParentNode = 0;
	}
	TrapRender::~TrapRender()
	{
	}
	void TrapRender::LoadXml(const char* path)
	{
		pugi::xml_document animation_file;
		pugi::xml_parse_result result = animation_file.load_file(path);
		if(!result)
		{
			return;
		}
		pugi::xml_node rootTAG = animation_file.child("animation");
		{
			const char* folder_path = Utilities::getParentFolder(path);
			const char* texture = rootTAG.attribute("texture").as_string();
			string texture_path;
			texture_path += folder_path;
			texture_path += texture;
			m_Texture = CCTextureCache::sharedTextureCache()->
				addImage(texture_path.c_str());
			m_Texture->setAliasTexParameters();
		}
		{
			pugi::xml_node framesTAG = rootTAG.child("frames");
			int frame_count = framesTAG.attribute("count").as_int();
			pugi::xml_node frameTAG = framesTAG.first_child();
			CCAnimation* animation = CCAnimation::create();
			animation->setDelayPerUnit(0.08f);
			for(int j = 0;j<frame_count;j++)
			{
				int rect_x, rect_y, rect_w, rect_h, offset_x, offset_y;
				rect_x = frameTAG.attribute("rect_x").as_int();
				rect_y = frameTAG.attribute("rect_y").as_int();
				rect_w = frameTAG.attribute("rect_w").as_int();
				rect_h = frameTAG.attribute("rect_h").as_int();
				offset_x = frameTAG.attribute("offset_x").as_int();
				offset_y = frameTAG.attribute("offset_y").as_int();
				CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(
					m_Texture,
					CCRectMake(rect_x, rect_y, rect_w, rect_h),
					false,
					ccp(offset_x,256-offset_y),
					CCSizeMake(rect_w, rect_h)
					);
				animation->addSpriteFrame(frame);
				frameTAG = frameTAG.next_sibling();
			}
			CCAction* action = CCRepeatForever::create(CCAnimate::create(animation));
			action->retain();
			m_Actions.push_back(action);
		}
		// only have 1 action here
		m_Sprite->runAction(m_Actions[0]);
	}
	void TrapRender::SetParentNode(CCNode* parent)
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
	void TrapRender::SetPositionXY(int x, int y)
	{
		m_Sprite->setPosition(ccp(x-160,y-70));
	}
	void TrapRender::SetPositionZ(int z)
	{
		m_Sprite->getParent()->reorderChild(m_Sprite,z);
	}
	void TrapRender::SetVisible(bool value)
	{
		m_Sprite->setVisible(value);
	}
	void TrapRender::InstantDestroy()
	{
		m_Sprite->setTexture(0);
		vector<CCAction*>::iterator it = m_Actions.begin();
		for(;it != m_Actions.end();it++)
		{
			CCAction* action = *it;
			CCRepeatForever* repeat = (CCRepeatForever*)action;
			if(!repeat) continue;
			CCAnimate* animate = (CCAnimate*)repeat->getInnerAction();
			CCAnimation* animation = animate->getAnimation();
			CCObject* object;
			CCARRAY_FOREACH(animation->getFrames(),object)
			{
				CCAnimationFrame* aniFrame = (CCAnimationFrame*)object;
				CCSpriteFrame* frame = aniFrame->getSpriteFrame();
				frame->setTexture(0);
			}
			CC_SAFE_RELEASE(action);
			*it = 0;
			if(!m_Texture) continue;
			if(m_Texture->retainCount() == 1)
			{
				CCTextureCache::sharedTextureCache()->removeTexture(m_Texture);
				system("cls");
				CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
			}
		}
		m_ParentNode->removeChild(m_Sprite,true);
	}
}