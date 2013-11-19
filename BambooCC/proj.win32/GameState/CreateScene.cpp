#include "CreateScene.h"
#include "HelloWorldScene.h"
#include "..\pugiXML\pugixml.hpp"
#include <algorithm>
#include <string>
// this is a test
#include "PathEngine/PathFinder.h"
using namespace PathEngine;

CreateScene::CreateScene()
{
	CCInputDispatcher::Instance().addListener(this, 1);
	ShowCursor(0);
}
CreateScene::~CreateScene()
{
	CCInputDispatcher::Instance().removeListener(this);
	ShowCursor(1);
}
bool CreateScene::onMouseEvent(const CCMouseEvent& evt) {
    switch(evt.state) {
        case CCMouse::Press:
            printf("mouse button %d pressed!\n", (int)evt.button);
			if(evt.button== CCMouse::RightButton)
			{
				pLabel->setPosition(ccp(evt.x, evt.y));
			}
            break;
        case CCMouse::Release:
            printf("mouse button %d released!\n", (int)evt.button);
            break;
		case CCMouse::Move:
			//printf("mouse move!\n");
			mouseSprite->setPosition(ccp(evt.x,evt.y));
			break;
        default:
            break;
    }
    return false;
}

bool CreateScene::onKeyEvent(const CCKeyEvent& evt) {
	switch (evt.state) {
		case CCKey::Press:
			{
				char str[14] = "Key pressed ";
				str[12] = evt.toCharCode();
				str[13] = 0;
				//pLabel->setString(str);
				break;
			}
		case CCKey::Release:
			{
				char str[15] = "Key released ";
				str[13] = evt.toCharCode();
				str[14] = 0;
				//pLabel->setString(str);
				break;
			}
		default:
			break;
	}
    return false;
}

CCScene* CreateScene::scene()
{
	CCScene * scene = NULL;
	// 'scene' is an autorelease object
	scene = CCScene::create();
	if(!scene) return 0;
	// 'layer' is an autorelease object
	CreateScene *layer = CreateScene::create();
	if(!layer) return scene;
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

bool CreateScene::init5Button()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	{
		CCSprite* pBackground = CCSprite::create("gui/background.jpg");
		if(! pBackground) return false;
		pBackground->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pBackground, 0);
		CCSprite* pNamingBar = CCSprite::create("gui/naming_bar.png");
		if(! pNamingBar) return false;
		pNamingBar->setPosition(ccp(size.width/2, 52));
		this->addChild(pNamingBar, 0);
	}
	{
		CCSprite* pBackground = CCSprite::create("gui/five_element_list.png");
		if(! pBackground) return false;
		pBackground->setPosition(ccp(size.width/2, size.height/2));
		this->addChild(pBackground, 0);

		CCMenuItemImage *pButtonJin = CCMenuItemImage::create(
			"gui/jin_normal.png",
			"gui/jin_click.png",
			this,
			menu_selector(CreateScene::ButtonJinCallback));

		if(! pButtonJin) return false;
		CCMenuItemImage *pButtonMo = CCMenuItemImage::create(
			"gui/mo_normal.png",
			"gui/mo_click.png",
			this,
			menu_selector(CreateScene::ButtonMoCallback));
		if(! pButtonMo) return false;
		CCMenuItemImage *pButtonSui = CCMenuItemImage::create(
			"gui/sui_normal.png",
			"gui/sui_click.png",
			this,
			menu_selector(CreateScene::ButtonSuiCallback));
		if(! pButtonSui) return false;
		CCMenuItemImage *pButtonHua = CCMenuItemImage::create(
			"gui/hua_normal.png",
			"gui/hua_click.png",
			this,
			menu_selector(CreateScene::ButtonHuaCallback));
		if(! pButtonHua) return false;
		CCMenuItemImage *pButtonTu = CCMenuItemImage::create(
			"gui/tu_normal.png",
			"gui/tu_click.png",
			this,
			menu_selector(CreateScene::ButtonTuCallback));
		if(! pButtonTu) return false;

		CCMenu* pElementMenu = CCMenu::create(
			pButtonJin,pButtonMo,pButtonSui,pButtonHua,pButtonTu, NULL);
		pElementMenu->setPosition(ccp(size.width/2, size.height/2-11));

		pElementMenu->alignItemsVerticallyWithPadding(31);
		if(!pElementMenu) return false;
		this->addChild(pElementMenu, 1);
	}
	{
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(CreateScene::menuCloseCallback));
		if(! pCloseItem) return false;
		pCloseItem->setPosition(ccp(size.width - 20, 20));

		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		if(!pMenu) return false;
		this->addChild(pMenu, 1);
	}
	{
		pLabel = CCLabelTTF::create("Scene Create", "Arial", 24);
		if(! pLabel) return false;
		pLabel->setPosition(ccp(size.width - 100, size.height - 20));
		this->addChild(pLabel, 1);
	}
	{
		mouseSprite = CCSprite::create("gui/mouse_up.png");
		mouseSprite->setAnchorPoint(ccp(0,1));
		this->addChild(mouseSprite,2);
	}
	return true;
}
bool CreateScene::init2Character()
{
	{
		pugi::xml_document animation_file;
		char* path = "gui/jin_f.xml";
		pugi::xml_parse_result result = animation_file.load_file(path);
		if(!result)
		{
			return false;
		}
		char* folderPath;
		{
			folderPath = new char[strlen(path)];
			string str = path;
			int i = str.find_last_of('/') + 1;
			strcpy(folderPath,str.substr(0,i).c_str());
			folderPath[i+1] = 0;
		}
		pugi::xml_node rootTAG = animation_file.child("animation");
		pugi::xml_node activeTAG = rootTAG.find_child_by_attribute("sequence","name","active");
		pugi::xml_node frameTAG = activeTAG.first_child();
		CCAnimation* animation = CCAnimation::create();
		animation->setDelayPerUnit(0.08f);
		for(;frameTAG;frameTAG = frameTAG.next_sibling())
		{
			string texturePath;
			texturePath = folderPath;
			texturePath += frameTAG.attribute("texture").as_string();
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->
				addImage(texturePath.c_str());
			int offset_x	= frameTAG.attribute("offset_x").as_int();
			int offset_y	= frameTAG.attribute("offset_y").as_int();
			int rect_w = texture->getContentSize().width;
			int rect_h = texture->getContentSize().height;
			CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(
				texture,
				CCRectMake(0, 0, rect_w, rect_h),
				false,
				ccp(offset_x,600-offset_y),
				CCSizeMake(rect_w, rect_h)
				);
			animation->addSpriteFrame(frame);
		}
		femaleJin = CCRepeatForever::create(CCAnimate::create(animation));
		femaleJin->retain();
	}
	{
		pugi::xml_document animation_file;
		char* path = "gui/jin_m.xml";
		pugi::xml_parse_result result = animation_file.load_file(path);
		if(!result)
		{
			return false;
		}
		char* folderPath;
		{
			folderPath = new char[strlen(path)];
			string str = path;
			int i = str.find_last_of('/') + 1;
			strcpy(folderPath,str.substr(0,i).c_str());
			folderPath[i+1] = 0;
		}
		pugi::xml_node rootTAG = animation_file.child("animation");
		pugi::xml_node activeTAG = rootTAG.find_child_by_attribute("sequence","name","active");
		pugi::xml_node frameTAG = activeTAG.first_child();
		CCAnimation* animation = CCAnimation::create();
		animation->setDelayPerUnit(0.08f);
		for(;frameTAG;frameTAG = frameTAG.next_sibling())
		{
			string texturePath;
			texturePath = folderPath;
			texturePath += frameTAG.attribute("texture").as_string();
			CCTexture2D* texture = CCTextureCache::sharedTextureCache()->
				addImage(texturePath.c_str());
			int offset_x	= frameTAG.attribute("offset_x").as_int();
			int offset_y	= frameTAG.attribute("offset_y").as_int();
			int rect_w = texture->getContentSize().width;
			int rect_h = texture->getContentSize().height;
			CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(
				texture,
				CCRectMake(0, 0, rect_w, rect_h),
				false,
				ccp(offset_x,600-offset_y),
				CCSizeMake(rect_w, rect_h)
				);
			animation->addSpriteFrame(frame);
		}
		maleJin = CCRepeatForever::create(CCAnimate::create(animation));
		maleJin->retain();
	}
	maleSprite = CCSprite::create();
	femaleSprite = CCSprite::create();
	maleSprite->setAnchorPoint(ccp(0,1));
	femaleSprite->setAnchorPoint(ccp(0,1));
	maleSprite->runAction(maleJin);
	femaleSprite->runAction(femaleJin);
	maleSprite->setPosition(ccp(-200,0));
	femaleSprite->setPosition(ccp(200,0));
	this->addChild(maleSprite,1);
	this->addChild(femaleSprite,1);
	CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
	return true;
}
// on "init" you need to initialize your instance
bool CreateScene::init()
{
	if(! CCLayer::init()) return false;
	if(! init5Button()) return false;
	if(! init2Character()) return false;
	return true;
}

void CreateScene::menuCloseCallback(CCObject* pSender)
{
    CCScene *pScene = HelloWorld::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}

void CreateScene::ButtonJinCallback(CCObject* pSender)
{
}
void CreateScene::ButtonMoCallback(CCObject* pSender)
{
}
void CreateScene::ButtonSuiCallback(CCObject* pSender)
{
}
void CreateScene::ButtonHuaCallback(CCObject* pSender)
{
}
void CreateScene::ButtonTuCallback(CCObject* pSender)
{
}