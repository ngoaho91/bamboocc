#ifndef TileScene_h
#define TileScene_h
#include <vector>
#include "cocos2d.h"
#include "keyboard_dispatcher/CCInputListener.h"
#include "TileEngine/Element.h"
#include "TileEngine/Tilemap.h"
#include "FightEngine/Map.h"
#include "FightEngine/FightActor.h"
#include "FightEngine/Missile.h"
using namespace std;
using namespace cocos2d;
using namespace TileEngine;
using namespace FightEngine;

class TileScene : public cocos2d::CCLayerColor, public cocos2d::CCInputListener
{
private:
	CCSprite *mouseSprite;
	FightEngine::Map* map;
	FightEngine::Actor* actor;
	FightEngine::MissileSkill* skill;
public:
	TileScene();
	~TileScene();
	virtual bool init();
	virtual void update(float dt);
	static cocos2d::CCScene* scene();
	CREATE_FUNC(TileScene);
public:
	bool onMouseEvent(const cocos2d::CCMouseEvent& evt);
	bool onKeyEvent(const cocos2d::CCKeyEvent& evt);
};
#endif