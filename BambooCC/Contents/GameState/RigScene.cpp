#include "CreateScene.h"
#include "RigScene.h"
#include <algorithm>

using namespace cocos2d;
using namespace RigEngine;

RigScene::RigScene()
{
	CCInputDispatcher::Instance().addListener(this, 1);
	ShowCursor(0);
}
RigScene::~RigScene()
{
	CCInputDispatcher::Instance().removeListener(this);
	ShowCursor(1);
}
bool RigScene::onMouseEvent(const CCMouseEvent& evt) {
    switch(evt.state) {
        case CCMouse::Press:
			if(evt.button == CCMouse::LeftButton)
			{
			}
			else if(evt.button == CCMouse::RightButton)
			{
			}
            break;
        case CCMouse::Release:
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

bool RigScene::onKeyEvent(const CCKeyEvent& evt) {
	switch (evt.state) {
		case CCKey::Press:
			{
				if(evt.key == CCKey::F5)
				{
					system("cls");
					CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
				}
				if(evt.key == CCKey::M)
				{
					mMonkPlayer->SetHorseState(HS_NOHORSE);
				}
				else if(evt.key == CCKey::B)
				{
					mMonkPlayer->SetHorse("horse1");
					mMonkPlayer->SetHorseState(HS_RIDEHORSE);
				}
				if(evt.key == CCKey::C)
				{
					mMonkPlayer->SetTwoHandWeapon("lance1");
					mMonkPlayer->SetWeaponState(WS_TWOHAND_WEAPON);
				}
				else if(evt.key == CCKey::V)
				{
					mMonkPlayer->SetOneHandWeapon("blade3");
					mMonkPlayer->SetWeaponState(WS_ONEHAND_WEAPON);
				}
				if(evt.key == CCKey::Up)
				{
					if(direction < 7)
					{
						renderTiger->SetDirection(++direction);
					}
					else
					{
						renderTiger->SetDirection(direction = 0);
					}
				}
				else if(evt.key == CCKey::Down)
				{
					if(direction > 0)
					{
						renderTiger->SetDirection(--direction);
					}
					else
					{
						renderTiger->SetDirection(direction = 7);
					}
				}
				else if(evt.key == CCKey::Left)
				{
					if(action > 1)
					{
						renderTiger->SetActionID(--action);
					}
					else
					{
						renderTiger->SetActionID(action = 6);
					}
				}
				else if(evt.key == CCKey::Right)
				{
					if(action < 6)
					{
						renderTiger->SetActionID(++action);
					}
					else
					{
						renderTiger->SetActionID(action = 1);
					}
				}
				break;
			}
		case CCKey::Release:
			{
				break;
			}
		default:
			break;
	}
    return false;
}

CCScene* RigScene::scene()
{
	CCScene * scene = NULL;
	// 'scene' is an autorelease object
	scene = CCScene::create();
	if(!scene) return 0;
	// 'layer' is an autorelease object
	RigScene *layer = RigScene::create();
	if(!layer) return scene;
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}
bool RigScene::initMouseCursor()
{
	mouseSprite = CCSprite::create("gui/mouse_up.png");
	if(!mouseSprite) return false;
	mouseSprite->setAnchorPoint(ccp(0,1));
	this->addChild(mouseSprite,2);
	return true;
}
bool RigScene::initSceneName()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	pLabel = CCLabelTTF::create("Scene RIG", "Arial", 24);
	if(! pLabel) return false;
	pLabel->setPosition(ccp(size.width - 150, size.height - 20));
	this->addChild(pLabel, 1);
	return true;
}
bool RigScene::initQuitButton()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(RigScene::menuCloseCallback));
	if(! pCloseItem) return false;
	pCloseItem->setPosition(ccp(size.width - 20, 20));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	if(!pMenu) return false;
	this->addChild(pMenu, 1);
	return true;
}
// on "init" you need to initialize your instance
bool RigScene::init()
{
	if(!CCLayerColor::initWithColor(ccc4(0, 128, 255, 255))) return false;
	if(!initMouseCursor()) return false;
	//if(!initSceneName()) return false;
	//if(!initQuitButton()) return false;
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	// tiger
	renderTiger = new RigPartRender(
		"NPC/fight/boss_gaibang2/boss_gaibang2.xml"
		);
	renderTiger->SetActionID(1);
	renderTiger->SetDirection(0);

	renderTiger->SetParentNode(this);
	direction = 0;
	action = 0;
	// !BUG: fix memory bug when create object
	// found a reason !!!! because RigPartRender for character part used many animation
	// i store it every object, so it cost very much ram
	// ! Bug killed at 2nd FEB 2013
	for(int i = 0; i< 200; i++)
	{
		RigPartRender* render = new RigPartRender(
			"NPC/fight/boss_gaibang2/boss_gaibang2.xml"
			);
		render->SetActionID(1);
		render->SetDirection(0);
		render->SetParentNode(this);
		render->SetPositionXY(60*(i%8)+150,i/8*60-50);
		render->SetPositionZ(1);
	}
	
	mMonkPlayer = new Character();
	mMonkPlayer->SetFullCloth("tianwang3");
	mMonkPlayer->SetHead("tianwang3");
	mMonkPlayer->SetDualWeapon("blade1");
	mMonkPlayer->ResetRender();
	
	mMonkPlayer->SetWeaponState(WS_DUAL_WEAPON);
	mMonkPlayer->SetHorseState(HS_NOHORSE);
	mMonkPlayer->SetActionState(AS_ATTACK);
	mMonkPlayer->SetDirection(D_DOWNRIGHT);
	mMonkPlayer->SetPosition(420,70);
	mMonkPlayer->GetRender()->SetParentNode(this);
	mMonkPlayer->GetRender()->SetPositionZ(1);
	for(int i = 0; i< 50; i++)
	{
		Character*	mPlayer;
		mPlayer = new Character();
		mPlayer->SetFullCloth("tianwang3");
		mPlayer->SetHead("tianwang3");
		mPlayer->SetDualWeapon("blade1");
		mPlayer->ResetRender();
		mPlayer->SetActionState(AS_ATTACK);
		mPlayer->SetWeaponState(WS_DUAL_WEAPON);
		mPlayer->SetHorseState(HS_NOHORSE);
		mPlayer->SetDirection(D_DOWNRIGHT);
		mPlayer->SetPosition(i/15*80-120,i%15*50-50);
		mPlayer->GetRender()->SetParentNode(this);
		mPlayer->GetRender()->SetPositionZ(1);
		
	}
	return true;
}

void RigScene::menuCloseCallback(CCObject* pSender)
{
    CCScene *pScene = CreateScene::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}
