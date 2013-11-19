#ifndef PFNewScene_h
#define PFNewScene_h

#include "cocos2d.h"
#include "keyboard_dispatcher/CCInputListener.h"
#include "../PathEngine/PathFinderNew.h"
using namespace cocos2d;
using namespace PathEngine;
class PFNewScene : public cocos2d::CCLayerColor, public cocos2d::CCInputListener
{
private:
	CCSprite *mouseSprite;
	PathFinderNew* pathFinder;
	vertex vertex_begin;
	vertex vertex_end;
	vector<vertex> path;
public:
	virtual bool init();
	PFNewScene();
	~PFNewScene();
	static cocos2d::CCScene* scene();
	bool onMouseEvent(const cocos2d::CCMouseEvent& evt);
	bool onKeyEvent(const cocos2d::CCKeyEvent& evt);
	CREATE_FUNC(PFNewScene);
};
#endif