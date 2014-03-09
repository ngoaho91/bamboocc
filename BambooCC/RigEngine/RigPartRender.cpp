#include "RigPartRender.h"
#include "../Utilities/Utilities.h"
#include "../pugiXML/pugixml.hpp"
#include <sstream>
namespace RigEngine
{
	RigPartRender::RigPartRender()
	{
		m_Sprite = CCSprite::create();
		m_Sprite->setAnchorPoint(ccp(0,1));
		m_Sprite->retain();
		m_ActionID = 0;
		m_DirectionID = 0;
		m_CurrentGroup = -1;
		m_XmlPath = "";
		m_ParentNode = 0;
		m_GroupCount = 0;
	}
	RigPartRender::RigPartRender(const char* fileName)
	{
		m_Sprite = CCSprite::create();
		m_Sprite->setAnchorPoint(ccp(0,1));
		m_Sprite->retain();
		m_ActionID = 0;
		m_DirectionID = 0;
		m_CurrentGroup = -1;
		m_XmlPath = "";
		m_ParentNode = 0;
		m_GroupCount = 0;
		SetXmlPath(fileName);
	}
	RigPartRender::~RigPartRender()
	{
		
	}
	void RigPartRender::unloadAll()
	{
		for(int i = 0;i < m_GroupCount;i++)
		{
			unloadGroup(i);
		}
		m_Actions.clear();
		m_LoadedActions.clear();
		m_Textures.clear();
		m_LoadedTextures.clear();
		m_TexturePaths.clear();
		m_ActionGroup.clear();
	}
	void RigPartRender::SetParentNode(CCNode* parent)
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
	void RigPartRender::SetPositionXY(int x, int y)
	{
		m_Sprite->setPosition(ccp(x,y));
	}
	void RigPartRender::SetPositionZ(int z)
	{
		m_Sprite->getParent()->reorderChild(m_Sprite,z);
	}
	void RigPartRender::SetXmlPath(const char* path)
	{
		if(strcmp(m_XmlPath.c_str(),path)==0) return;
		unloadAll();
		m_XmlPath = path;
		// load xml
		//cout<<"Load XML - path="<<path<<endl;
		pugi::xml_document animation_file;
		pugi::xml_parse_result result = animation_file.load_file(path);
		if(!result)
		{
			return;
		}
		char* folder_path = Utilities::getParentFolder(path);
		pugi::xml_node rootTAG = animation_file.child("animation");
		// parse xml
		pugi::xml_node sequencesTAG = rootTAG.child("sequences");
		int sequenceCount = sequencesTAG.attribute("count").as_int();
		int sequenceCount8 = sequenceCount*8;
		m_Actions.resize(sequenceCount8);
		m_LoadedActions.resize(sequenceCount8);
		m_Textures.resize(sequenceCount8);
		m_LoadedTextures.resize(sequenceCount8);
		m_TexturePaths.resize(sequenceCount8);
		m_ActionGroup.resize(sequenceCount);
		m_GroupCount = 0;
		pugi::xml_node sequenceTAG = sequencesTAG.first_child();
		for(;sequenceTAG;sequenceTAG = sequenceTAG.next_sibling())
		{
			int index = sequenceTAG.attribute("id").as_int()-1;
			int g = sequenceTAG.attribute("group").as_int();
			if(g > m_GroupCount) m_GroupCount = g;
			int groupIndex = g-1;
			int index8 = index*8;
			m_ActionGroup[index] = groupIndex;
			pugi::xml_node directionTAG = sequenceTAG.first_child();
			for(;directionTAG;directionTAG = directionTAG.next_sibling())
			{
				int directionIndex = directionTAG.attribute("id").as_int();
				int realIndex = index8+directionIndex;
				m_TexturePaths[realIndex] = folder_path;
				m_TexturePaths[realIndex] += directionTAG.attribute("texture").as_string();
			}
		}
	}
	
	void RigPartRender::unloadGroup(int groupID)
	{
		if(groupID == -1) return;
		m_Sprite->setTexture(0);
		for(unsigned int i=0;i<m_ActionGroup.size();i++)
		{
			int group = m_ActionGroup[i];
			if(group != groupID) continue;
			int i8 = i*8;
			for(int j = 0;j<8;j++)
			{
				int i8j = i8+j;
				CCTexture2D* texture = m_Textures[i8j];
				CCRepeatForever* action = (CCRepeatForever*)m_Actions[i8j];
				if(!action) continue;
				CCAnimate* animate = (CCAnimate*)action->getInnerAction();
				CCAnimation* animation = animate->getAnimation();
				CCObject* object;
				CCARRAY_FOREACH(animation->getFrames(),object)
				{
					CCAnimationFrame* aniFrame = (CCAnimationFrame*)object;
					CCSpriteFrame* frame = aniFrame->getSpriteFrame();
					frame->setTexture(0);
				}
				CC_SAFE_RELEASE(m_Actions[i8j]);
				m_Actions[i8j] = 0;
				m_LoadedActions[i8j] = false;
				m_LoadedTextures[i8j] = false;
				if(!texture) continue;
				if(texture->retainCount() == 1)
				{
					CCTextureCache::sharedTextureCache()->removeTexture(texture);
					system("cls");
					CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
				}
			}
		}
	}
	
	void RigPartRender::loadAction(int actionID)
	{
		for(int j=0;j<8;j++)
		{
			int i8j = actionID*8+j;
			if(!m_LoadedTextures[i8j])
			{
				m_Textures[i8j] = CCTextureCache::sharedTextureCache()->
					addImage(m_TexturePaths[i8j].c_str());
				m_Textures[i8j]->setAliasTexParameters();
				m_LoadedTextures[i8j] = true;
			}
			if(!m_LoadedActions[i8j])
			{
				m_Sprite->setTexture(0);
				pugi::xml_document animation_file;
				pugi::xml_parse_result result = animation_file.load_file(m_XmlPath.c_str());
				if(!result)
				{
					return;
				}
				pugi::xml_node rootTAG = animation_file.child("animation");
				pugi::xml_node sequencesTAG = rootTAG.child("sequences");
				char* sid = Utilities::toChar(actionID+1);
				pugi::xml_node sequenceTAG = sequencesTAG.
					find_child_by_attribute("sequence","id",sid);
				char* did = Utilities::toChar(j);
				pugi::xml_node directionTAG = sequenceTAG.
					find_child_by_attribute("direction","id",did);
				CCAnimation* animation = CCAnimation::create();
				animation->setDelayPerUnit(0.08f);
				pugi::xml_node frameTAG = directionTAG.first_child();
				for(;frameTAG;frameTAG = frameTAG.next_sibling())
				{
					int rect_x		= frameTAG.attribute("rect_x").as_int();
					int rect_y		= frameTAG.attribute("rect_y").as_int();
					int rect_w		= frameTAG.attribute("rect_w").as_int();
					int rect_h		= frameTAG.attribute("rect_h").as_int();
					int offset_x	= frameTAG.attribute("offset_x").as_int();
					int offset_y	= frameTAG.attribute("offset_y").as_int();
					CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(
						m_Textures[i8j],
						CCRectMake(rect_x, rect_y, rect_w, rect_h),
						false,
						ccp(offset_x,256-offset_y),
						CCSizeMake(rect_w, rect_h)
						);
					animation->addSpriteFrame(frame);
				}
				CCAction* action = CCRepeatForever::create(CCAnimate::create(animation));
				action->retain();
				m_Actions[i8j] = action;
				m_LoadedActions[i8j] = true;
			}
		}
		int i8j = m_ActionID*8+m_DirectionID;
		m_Sprite->stopAllActions();
		m_Sprite->runAction(m_Actions[i8j]);
	}
	void RigPartRender::SetDirection(short directionID)
	{
		m_DirectionID = directionID;
		if(m_CurrentGroup == -1) return;
		int i8j = m_ActionID*8+m_DirectionID;
		m_Sprite->stopAllActions();
		m_Sprite->runAction(m_Actions[i8j]);
	}
	void RigPartRender::SetActionID(short actionID)
	{
		if(actionID == 0)
		{
			m_Sprite->setVisible(false);
			m_Sprite->stopAllActions();
			if(m_CurrentGroup == -1) return;
			unloadGroup(m_CurrentGroup);
			m_CurrentGroup = -1;
			return;
		}
		m_Sprite->setVisible(true);
		m_ActionID = actionID - 1;
		int newGroup = m_ActionGroup[m_ActionID];
		if(newGroup != m_CurrentGroup)
		{
			unloadGroup(m_CurrentGroup);
			m_CurrentGroup = newGroup;
			loadAction(m_ActionID);
		}
		else
		{
			loadAction(m_ActionID);
		}
	}
	void RigPartRender::SetAnimationTime(short actionID, float time)
	{
		if(m_Actions.size()==0) return;
		int i8 = actionID*8;
		CCRepeatForever* action = (CCRepeatForever*)m_Actions[i8];
		if(!action) return;
		CCAnimate* animate = (CCAnimate*)action->getInnerAction();
		CCAnimation* animation = animate->getAnimation();
		float delay = time/animation->getFrames()->count();
		animation->setDelayPerUnit(delay);
		for(int j=0;j<8;j++)
		{
			int i8j = i8+j;
			action = (CCRepeatForever*)m_Actions[i8j];
			if(!action) continue;
			animate = (CCAnimate*)action->getInnerAction();
			animate->getAnimation()->setDelayPerUnit(delay);
		}
	}
}