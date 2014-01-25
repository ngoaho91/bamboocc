#include "HelloWorldScene.h"
#include "CreateScene.h"
using namespace cocos2d;

CCScene* HelloWorld::scene()
{
	CCScene * scene = NULL;
	// 'scene' is an autorelease object
	scene = CCScene::create();
	if(! scene) return 0;

	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::create();
	if(!layer) return scene;

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	bool bRet = false;
	//////////////////////////////////////////////////////////////////////////
	// super init first
	//////////////////////////////////////////////////////////////////////////

	if(! CCLayer::init()) return bRet;

	//////////////////////////////////////////////////////////////////////////
	// add your codes below...
	//////////////////////////////////////////////////////////////////////////

	// 1. Add a menu item with "X" image, which is clicked to quit the program.

	// Create a "close" menu item with close icon, it's an auto release object.
	CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(HelloWorld::menuCloseCallback));
	if(! pCloseItem) return bRet;

	// Place the menu item bottom-right conner.
	pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

	// Create a menu with the "close" menu item, it's an auto release object.
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	if(!pMenu) return bRet;

	// Add the menu to HelloWorld layer as a child layer.
	this->addChild(pMenu, 1);

	// 2. Add a label shows "Hello World".

	// Create a label and initialize with string "Hello World".
	CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
	if(! pLabel) return bRet;

	// Get window size and place the label upper. 
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	pLabel->setPosition(ccp(size.width / 2, size.height - 50));

	// Add the label to HelloWorld layer as a child layer.
	this->addChild(pLabel, 1);

	// 3. Add add a splash screen, show the cocos2d splash image.
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");
	if(! pSprite) return bRet;

	// Place the sprite on the center of the screen
	pSprite->setPosition(ccp(size.width/2, size.height/2));

	// Add the sprite to HelloWorld layer as a child layer.
	this->addChild(pSprite, 0);

	bRet = true;

	return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    //CCDirector::sharedDirector()->end();
	CCScene *pScene = CreateScene::scene();
    CCDirector::sharedDirector()->replaceScene(pScene);
}

