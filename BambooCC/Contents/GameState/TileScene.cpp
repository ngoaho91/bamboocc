#include "TileScene.h"
#include "../PathEngine/PathFinderWorld.h"
#include "../FightEngine/FightWorld.h"
TileScene::TileScene()
{
	CCInputDispatcher::Instance().addListener(this, 1);
	//ShowCursor(0);
}
TileScene::~TileScene()
{
	CCInputDispatcher::Instance().removeListener(this);
	//ShowCursor(1);
}

CCScene* TileScene::scene()
{
	CCScene * scene = NULL;
	scene = CCScene::create();
	TileScene *layer = TileScene::create();
	scene->addChild(layer);
	return scene;
}
bool TileScene::init()
{
	if(!CCLayerColor::initWithColor(ccc4(0, 128, 255, 255))) return false;
	{
		mouseSprite = CCSprite::create("gui/mouse_up.png");
		mouseSprite->setAnchorPoint(ccp(0,1));
		mouseSprite->setVisible(false);
		this->addChild(mouseSprite,99999);
	}
	{
		map = new FightEngine::Map(1280,1280);
		map->LoadXml("hello_map.xml");
		map->GetRender()->SetParentNode(this);
	}
	// add fight actor
	{
		actor = new FightEngine::Actor();
		actor->ResetRender();
		actor->GetRender()->SetParentNode(this);
		actor->GetRender()->SetPositionZ(100000);
		actor->SetPosition(10,10);
		PathEngine::World::instance()->AddActor(actor);
		if(false){// test weapon change
			actor->GetCharacter()->SetDualWeapon("blade2");
			actor->GetCharacter()->SetWeaponState(WS_DUAL_WEAPON);
			actor->GetCharacter()->SetHorseState(HS_NOHORSE);
			actor->GetCharacter()->SetActionState(AS_ATTACK);
			actor->GetCharacter()->SetDirection(D_DOWNRIGHT);
		}
	}
	skill = new MissileSkill();
	skill->SetCaster(actor);
	FightEngine::World::instance()->GetRender()->SetParentNode(this);
	schedule(schedule_selector(TileScene::update));
	return true;
}
void TileScene::update(float dt)
{
	actor->Update();
	Vector2* pos = actor->GetPosition();
	map->GetRender()->Focus(pos->GetX(),pos->GetY());
	FightEngine::World::instance()->Update();
}
bool TileScene::onMouseEvent(const CCMouseEvent& evt)
{
	switch(evt.state)
	{
	case CCMouse::Press:
		if(evt.button == CCMouse::LeftButton)
		{
			int x,y;
			map->GetRender()->MouseToMap(evt.x,evt.y,&x,&y);
			actor->GoTo(x,y);
		}
		else if(evt.button == CCMouse::RightButton)
		{
			int x,y;
			map->GetRender()->MouseToMap(evt.x,evt.y,&x,&y);
			TargetData data;
			data.X1 = x;
			data.Y1 = y;
			skill->SetTargetData(data);
			skill->Cast();
			//FightEngine::World::instance()->AddTrap(0,data.X2,data.Y2);
		}
		break;
	case CCMouse::Release:
		break;
	case CCMouse::Move:
		mouseSprite->setPosition(ccp(evt.x,600-evt.y));
		break;
	default:
		break;
	}
	return false;
}
bool TileScene::onKeyEvent(const CCKeyEvent& evt)
{
	switch(evt.state)
	{
	case CCKey::Press:
		if(evt.key == CCKey::Up)
		{
			float x, y;
			this->getPosition(&x,&y);
			this->setPositionY(y-3);
			if(0){
			float ex,ey,ez;
			this->getCamera()->getEyeXYZ(&ex,&ey,&ez);
			this->getCamera()->setEyeXYZ(ex,ey+0.00000001,ez);
			//this->getCamera()->getCenterXYZ(&ex,&ey,&ez);
			//this->getCamera()->setCenterXYZ(ex,ey+0.0000001,ez);
			}
		}
		else if(evt.key == CCKey::Down)
		{
			float x, y;
			this->getPosition(&x,&y);
			this->setPositionY(y+3);
			if(0){float ex,ey,ez;
			this->getCamera()->getEyeXYZ(&ex,&ey,&ez);
			this->getCamera()->setEyeXYZ(ex,ey-0.00000001,ez);
			//this->getCamera()->getCenterXYZ(&ex,&ey,&ez);
			//this->getCamera()->setCenterXYZ(ex,ey-0.0000001,ez);
			}
		}
		else if(evt.key == CCKey::Left)
		{
			float x, y;
			this->getPosition(&x,&y);
			this->setPositionX(x+3);
			if(0){float ex,ey,ez;
			this->getCamera()->getEyeXYZ(&ex,&ey,&ez);
			this->getCamera()->setEyeXYZ(ex-0.00000001,ey,ez);
			//this->getCamera()->getCenterXYZ(&ex,&ey,&ez);
			//this->getCamera()->setCenterXYZ(ex,ey-0.0000001,ez);
			}
		}
		else if(evt.key == CCKey::Right)
		{
			float x, y;
			this->getPosition(&x,&y);
			this->setPositionX(x-3);
			if(0){float ex,ey,ez;
			this->getCamera()->getEyeXYZ(&ex,&ey,&ez);
			this->getCamera()->setEyeXYZ(ex+0.00000001,ey,ez);
			//this->getCamera()->getCenterXYZ(&ex,&ey,&ez);
			//this->getCamera()->setCenterXYZ(ex,ey-0.0000001,ez);
			}
		}
		break;
	case CCKey::Release:

		break;
	default:
		break;
	}
	return false;
}