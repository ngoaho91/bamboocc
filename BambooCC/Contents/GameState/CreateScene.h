#ifndef __CREATE_SCENE_H__
#define __CREATE_SCENE_H__

#include "cocos2d.h"
#include "keyboard_dispatcher/CCInputListener.h"
using namespace cocos2d;

class CreateScene : public cocos2d::CCLayer, public cocos2d::CCInputListener
{
private:
	CCLabelTTF* pLabel;
	CCSprite *mouseSprite;
	CCSprite *maleSprite;
	CCSprite *femaleSprite;
	CCAction *maleJin;
	CCAction *femaleJin;
	bool init5Button();
	bool init2Character();
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	CreateScene();
	~CreateScene();
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

	bool onMouseEvent(const cocos2d::CCMouseEvent& evt);
    bool onKeyEvent(const cocos2d::CCKeyEvent& evt);
    
    // a selector callback
    void ButtonJinCallback(CCObject* pSender);
	void ButtonMoCallback(CCObject* pSender);
	void ButtonSuiCallback(CCObject* pSender);
	void ButtonHuaCallback(CCObject* pSender);
	void ButtonTuCallback(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(CreateScene);
};

#endif  // __CREATE_SCENE_H__