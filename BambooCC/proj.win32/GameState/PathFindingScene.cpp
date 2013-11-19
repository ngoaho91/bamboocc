#include "CreateScene.h"
#include "PathFindingScene.h"
#include <algorithm>
// this is a test
#include "PathEngine/PathFinder.h"
using namespace PathEngine;

using namespace cocos2d;

PathFindingScene::PathFindingScene()
{
	CCInputDispatcher::Instance().addListener(this, 1);
	ShowCursor(0);
}
PathFindingScene::~PathFindingScene()
{
	CCInputDispatcher::Instance().removeListener(this);
	ShowCursor(1);
}
void PathFindingScene::TestPathFinder()
{
	int len = 6;
	mesh = new PathEngine::Mesh(1000,1000);
	
	if(1){
		vector<Node*> v;
		v.push_back(new Node(160,60));
		v.push_back(new Node(160,180));
		v.push_back(new Node(220,180));
		v.push_back(new Node(220,240));
		v.push_back(new Node(160,240));
		v.push_back(new Node(160,360));
		v.push_back(new Node(220,360));
		v.push_back(new Node(220,300));
		v.push_back(new Node(340,300));
		v.push_back(new Node(340,360));
		v.push_back(new Node(280,360));
		v.push_back(new Node(280,420));
		v.push_back(new Node(340,420));
		v.push_back(new Node(340,480));
		v.push_back(new Node(220,480));
		v.push_back(new Node(220,420));
		v.push_back(new Node(160,420));
		v.push_back(new Node(160,540));
		v.push_back(new Node(640,540));
		v.push_back(new Node(640,420));
		v.push_back(new Node(580,420));
		v.push_back(new Node(580,480));
		v.push_back(new Node(460,480));
		v.push_back(new Node(460,420));
		v.push_back(new Node(520,420));
		v.push_back(new Node(520,360));
		v.push_back(new Node(460,360));
		v.push_back(new Node(460,300));
		v.push_back(new Node(580,300));
		v.push_back(new Node(580,360));
		v.push_back(new Node(640,360));
		v.push_back(new Node(640,240));
		v.push_back(new Node(580,240));
		v.push_back(new Node(580,180));
		v.push_back(new Node(640,180));
		v.push_back(new Node(640,60));
		v.push_back(new Node(580,60));
		v.push_back(new Node(580,120));
		v.push_back(new Node(520,120));
		v.push_back(new Node(520,60));
		v.push_back(new Node(460,60));
		v.push_back(new Node(460,180));
		v.push_back(new Node(520,180));
		v.push_back(new Node(520,240));
		v.push_back(new Node(280,240));
		v.push_back(new Node(280,180));
		v.push_back(new Node(340,180));
		v.push_back(new Node(340,60));
		v.push_back(new Node(280,60));
		v.push_back(new Node(280,120));
		v.push_back(new Node(220,120));
		v.push_back(new Node(220,60));
		reverse(v.begin(),v.end());
		mesh->AddPolygon(v);
		World::instance()->GetMesh()->AddPolygon(v);
	}
	if(0){
		vector<Node*> v1;
		v1.push_back(new Node(176,271));
		v1.push_back(new Node(282,216));
		v1.push_back(new Node(379,267));
		v1.push_back(new Node(276,322));
		mesh->AddPolygon(v1);
		World::instance()->GetMesh()->AddPolygon(v1);
		vector<Node*> v2;
		v2.push_back(new Node(460,128));
		v2.push_back(new Node(571,72));
		v2.push_back(new Node(658,114));
		v2.push_back(new Node(550,179));
		mesh->AddPolygon(v2);
		World::instance()->GetMesh()->AddPolygon(v2);
	}
	mesh->BuildVisiGraph();
	finder =  new PathEngine::PathFinder(mesh);
	start = new Node(0,0);
	end = new Node(0,0);
	// draw the result
	pathRender->SetMesh(mesh);
	World::instance()->GetMesh()->BuildVisiGraph();
	actor = new PathEngine::Actor(20,20);
	World::instance()->AddActor(actor);
	actor->SetPosition(0,0);
	mob = new PathEngine::Actor(20,20);
	World::instance()->AddActor(mob);
	mob->SetPosition(0,0);
	schedule(schedule_selector(PathFindingScene::update));
}
void PathFindingScene::update(float dt)
{
	actor->Step();
	actorSprite->
		setPosition(ccp(actor->GetPositionX(),actor->GetPositionY()));
	actorSprite->setRotation(actor->GetAngle()/PI*-180);
	mob->Step();
	mobSprite->
		setPosition(ccp(mob->GetPositionX(),mob->GetPositionY()));
	mobSprite->setRotation(mob->GetAngle()/PI*-180);
}

bool PathFindingScene::onMouseEvent(const CCMouseEvent& evt) {
    switch(evt.state) {
        case CCMouse::Press:
			if(evt.button == CCMouse::LeftButton)
			{
				start = new Node(evt.x,evt.y);
				//pathRender->SetPath(finder->FindPath(start, end));
				actor->SetPosition(evt.x, evt.y);
			}
			else if(evt.button == CCMouse::RightButton)
			{
				end = new Node(evt.x,evt.y);
				//actor->SetPosition(start->X, start->Y);
				actor->GoTo(evt.x, evt.y);
				//pathRender->SetPath(finder->FindPath(start, end));
			}
			else if(evt.button == CCMouse::MiddleButton)
			{
				//end = new Node(evt.x,evt.y);
				mob->SetPosition(evt.x, evt.y);
				mob->GoTo(start->X, start->Y);
				//pathRender->SetPath(finder->FindPath(start, end));
			}
            break;
        case CCMouse::Release:
            break;
		case CCMouse::Move:
			//printf("mouse move!\n");
			mouseSprite->setPosition(ccp(evt.x,evt.y));
			//end = new Node(evt.x,evt.y);
			//pathRender->SetPath(finder->FindPath(start, end));
			break;
        default:
            break;
    }
    return false;
}

bool PathFindingScene::onKeyEvent(const CCKeyEvent& evt) {
	switch (evt.state) {
		case CCKey::Press:
			{
				if(evt.key == CCKey::F2)
				{
					pathRender->ToggleDrawGraph();
				}
				else if(evt.key == CCKey::F3)
				{
					pathRender->ToggleDrawVisibility();
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

CCScene* PathFindingScene::scene()
{
	CCScene * scene = NULL;
	// 'scene' is an autorelease object
	scene = CCScene::create();
	if(!scene) return 0;
	// 'layer' is an autorelease object
	PathFindingScene *layer = PathFindingScene::create();
	if(!layer) return scene;
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool PathFindingScene::init()
{
	// path render
	pathRender = new PathEngine::PathRender();
	if(!pathRender) return false;
	//pathRender->SetDrawVisibility(false);
	this->addChild(pathRender,2);
	TestPathFinder();
	//return true;
	// sprite init
	bool bRet = false;
	if(! CCLayer::init()) return bRet;
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	{
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(PathFindingScene::menuCloseCallback));
		if(! pCloseItem) return bRet;
		pCloseItem->setPosition(ccp(size.width - 20, 20));

		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		if(!pMenu) return bRet;
		this->addChild(pMenu, 1);
	}
	{
		pLabel = CCLabelTTF::create("Scene PATHFINDING\nF2: Toggle Graph\nF3: Toggle Visibility Graph", "Code Bold", 22);
		if(! pLabel) return bRet;
		pLabel->setPosition(ccp(size.width - 150, size.height - 60));
		this->addChild(pLabel, 1);
	}
	{
		mouseSprite = CCSprite::create("gui/mouse_up.png");
		mouseSprite->setAnchorPoint(ccp(0,1));
		this->addChild(mouseSprite,2);
		actorSprite = CCSprite::create("gui/path_finder_actor.png");
		actorSprite->setAnchorPoint(ccp(0.5,0.5));
		this->addChild(actorSprite,2);
		mobSprite = CCSprite::create("gui/path_finder_actor.png");
		mobSprite->setAnchorPoint(ccp(0.5,0.5));
		this->addChild(mobSprite,2);
	}

	bRet = true;

	return bRet;
}

void PathFindingScene::menuCloseCallback(CCObject* pSender)
{
    CCScene *pScene = CreateScene::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}
