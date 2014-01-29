#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "GameState\HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}
AppDelegate::~AppDelegate()
{
}
bool AppDelegate::applicationDidFinishLaunching()
{
	CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA4444);
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
	//pDirector->enableRetinaDisplay(true);
    pDirector->setDisplayStats(true);
    pDirector->setAnimationInterval(1.0 / 60);
	CCScene *pScene = HelloWorld::scene();
    pDirector->runWithScene(pScene);
    return true;
}
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
}
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
}
