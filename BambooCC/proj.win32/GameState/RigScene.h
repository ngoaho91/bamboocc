#ifndef RIGSCENE_H
#define RIGSCENE_H

#include "cocos2d.h"
#include "keyboard_dispatcher/CCInputListener.h"
#include "RigEngine/Character.h"
using namespace RigEngine;

class RigScene : public cocos2d::CCLayerColor, public cocos2d::CCInputListener
{
private:
	cocos2d::CCLabelTTF* pLabel;
	cocos2d::CCSprite *mouseSprite;
	RigPartRender* renderTiger;
	Character*	mMonkPlayer;
	int direction;
	int action;
	bool initMouseCursor();
	bool initSceneName();
	bool initQuitButton();
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	
	RigScene();
	~RigScene();
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

	bool onMouseEvent(const cocos2d::CCMouseEvent& evt);
    bool onKeyEvent(const cocos2d::CCKeyEvent& evt);
	void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(RigScene);
};

#endif  // __CREATE_SCENE_H__