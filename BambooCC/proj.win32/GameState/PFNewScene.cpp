#include "PFNewScene.h"

PFNewScene::PFNewScene()
{
	CCInputDispatcher::Instance().addListener(this, 1);
	ShowCursor(0);
}
PFNewScene::~PFNewScene()
{
	CCInputDispatcher::Instance().removeListener(this);
	ShowCursor(1);
}

CCScene* PFNewScene::scene()
{
	CCScene * scene = NULL;
	scene = CCScene::create();
	if(!scene) return 0;
	PFNewScene *layer = PFNewScene::create();
	if(!layer) return scene;
	scene->addChild(layer);
	return scene;
}
bool PFNewScene::init()
{
	if(!CCLayerColor::initWithColor(ccc4(0, 128, 255, 255))) return false;
	{
		mouseSprite = CCSprite::create("gui/mouse_up.png");
		mouseSprite->setAnchorPoint(ccp(0,1));
		this->addChild(mouseSprite,99999);
	}
	{
		pathFinder = new PathFinderNew();
		pathFinder->SelfTest();
		this->addChild(pathFinder->GetRender());
	}
	return true;
}

bool PFNewScene::onMouseEvent(const CCMouseEvent& evt)
{
	switch(evt.state)
	{
	case CCMouse::Press:
		if(evt.button == CCMouse::LeftButton)
		{
			vertex_begin = make_pair<double, double>(evt.x/50.0, evt.y/50.0);
		}
		else if(evt.button == CCMouse::RightButton)
		{
			vertex_end = make_pair<double, double>(evt.x/50.0, evt.y/50.0);
		}
		path.clear();
		pathFinder->FindPath(vertex_begin.first, vertex_begin.second, 
			vertex_end.first, vertex_end.second, &path);
		pathFinder->GetRender()->SetPath(path);
		break;
	case CCMouse::Release:

		break;
	case CCMouse::Move:
		
		mouseSprite->setPosition(ccp(evt.x,evt.y));
		/*vertex_end = make_pair<double, double>(evt.x/50.0, evt.y/50.0);
		path.clear();
		pathFinder->FindPath(vertex_begin.first, vertex_begin.second, 
			vertex_end.first, vertex_end.second, &path);
		pathFinder->GetRender()->SetPath(path);*/
		break;
	default:
		break;
	}
	return false;
}
bool PFNewScene::onKeyEvent(const CCKeyEvent& evt)
{
	switch(evt.state)
	{
	case CCKey::Press:

		break;
	case CCKey::Release:

		break;
	default:
		break;
	}
	return false;
}