#ifndef PATHFINDINGSCENE_H
#define PATHFINDINGSCENE_H

#include "cocos2d.h"
#include "keyboard_dispatcher/CCInputListener.h"
#include "PathEngine/PathRender.h"
#include "PathEngine/PathFinderActor.h"
#include "PathEngine/PathFinderWorld.h"
using namespace PathEngine;
using namespace Geometry;
using namespace cocos2d;
class PathFindingScene : public cocos2d::CCLayer, public cocos2d::CCInputListener
{
private:
	CCLabelTTF* pLabel;
	CCSprite *mouseSprite;
	PathEngine::PathRender *pathRender;
	PathEngine::PathFinder *finder;
	PathEngine::Mesh *mesh;
	Node *start;
	Node *end;
	Actor* actor;
	Actor* mob;
	CCSprite *actorSprite;
	CCSprite *mobSprite;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void update(float dt);
	PathFindingScene();
	~PathFindingScene();
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
	void TestPathFinder();

	bool onMouseEvent(const cocos2d::CCMouseEvent& evt);
    bool onKeyEvent(const cocos2d::CCKeyEvent& evt);
	void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(PathFindingScene);
};

#endif  // __CREATE_SCENE_H__