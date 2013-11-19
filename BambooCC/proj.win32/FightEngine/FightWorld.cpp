#include "FightWorld.h"
#include "Missile.h"
#include "Trap.h"
#include "DamageField.h"
#include "DamageRay.h"
#include <queue>
using namespace std;
namespace FightEngine
{
	World* World::m_Instance = 0;
	int World::WIDTH = 1000;
	int	World::HEIGHT = 1000;
	World* World::instance()
	{
		if(!m_Instance) m_Instance = new World();
		return m_Instance;
	}
	World::World()
		:QuadTree(WIDTH,HEIGHT)
	{
		m_Render = new FightWorldRender();
	}
	World::~World()
	{
	}
	FightWorldRender* World::GetRender()
	{
		return m_Render;
	}
	void World::AddMissile(MissileSkill* skill, 
		int x1, int y1, int x2, int y2, float speed)
	{
		Missile* missile = new Missile();
		m_Render->AddMissile(missile->GetRender());
		missile->SetPosition(x1,y1);
		missile->SetAngleFromVertex(x1,y1,x2,y2);
		missile->SetSpeed(speed);
		missile->SetSkill(skill);
		missile->SetOwner(skill->GetCaster());
		QuadTree::Insert(missile);
	}
	void World::AddTrap(TrapSkill* skill, 
		int x, int y)
	{
		Trap* trap = new Trap();
		m_Render->AddTrap(trap->GetRender());
		trap->SetPosition(x,y);
		trap->SetSkill(skill);
		trap->SetOwner(skill->GetCaster());
		QuadTree::Insert(trap);
	}
	void World::AddDamageField(AOESkill* skill, 
		int x, int y, int range)
	{
		DamageField* field = new DamageField();
		m_Render->AddDamageField(field->GetRender());
		field->SetPosition(x,y);
		field->SetRange(range);
		field->SetOwner(skill->GetCaster());
		QuadTree::Insert(field);
	}
	void World::AddDamageRay(RaySkill* skill, 
		int x1, int y1, int x2, int y2, float length)
	{
		DamageRay* ray = new DamageRay();
		m_Render->AddDamageRay(ray->GetRender());
		ray->SetPosition(x1,y1);
		ray->SetAngleFromVertex(x1,y1,x2,y2);
		ray->SetLength(length);
		ray->SetSkill(skill);
		ray->SetOwner(skill->GetCaster());
		QuadTree::Insert(ray);
	}
	void World::ChainMissileSkill(FightSkill* parent, int x, int y)
	{
		MissileSkill* chain = new MissileSkill();
		chain->SetCaster(parent->GetCaster());
		TargetData data;
		data.X1 = x;
		data.Y1 = y;
		chain->SetTargetData(data);
		chain->Cast();
	}
	void World::ChainTrapSkill(FightSkill* parent, int x, int y)
	{
		TrapSkill* chain = new TrapSkill();
		chain->SetCaster(parent->GetCaster());
		TargetData data;
		data.X1 = x;
		data.Y1 = y;
		chain->SetTargetData(data);
		chain->Cast();
	}
	void World::ChainAOESkill(FightSkill* parent, int x, int y)
	{
		AOESkill* chain = new AOESkill();
		chain->SetCaster(parent->GetCaster());
		TargetData data;
		data.X1 = x;
		data.Y1 = y;
		chain->SetTargetData(data);
		chain->Cast();
	}
	void World::ChainRaySkill(FightSkill* parent, int x1, int y1, int x2, int y2)
	{
		RaySkill* chain = new RaySkill();
		chain->SetCaster(parent->GetCaster());
		TargetData data;
		data.X1 = x1;
		data.Y1 = y1;
		data.X2 = x2;
		data.Y2 = y2;
		chain->SetTargetData(data);
		chain->Cast();
	}
	void World::Update()
	{
		queue<QuadTree*> q;
		q.push(this);
		while(!q.empty())
		{
			QuadTree* tree = q.front();
			q.pop();
			if(tree->SubNode(0))
			{
				q.push(tree->SubNode(0));
				q.push(tree->SubNode(1));
				q.push(tree->SubNode(2));
				q.push(tree->SubNode(3));
			}
			QuadObjects* objects = tree->GetObjectsPointer();
			QuadObjectIterator it = objects->begin();
			while(it!= objects->end())
			{
				QuadObject* object = *it;
				int qot = object->GetObjectType();
				if(qot == QOT_FIGHTACTOR)
				{
					Actor* actor = (Actor*)object;
					actor->Update();
					//if(actor->Disposed()) it = objects->erase(it); else it++;
					it++;
				}
				else if(qot == QOT_MISSILE)
				{
					Missile* missile = (Missile*)object;
					missile->Update();
					//if(missile->Disposed()) it = objects->erase(it); else it++;
					it++;
				}
				else if(qot == QOT_TRAP)
				{
					Trap* trap = (Trap*)object;
					trap->Update();
					//if(missile->Disposed()) it = objects->erase(it); else it++;
					it++;
				}
				else
				{
					it++;
				}
			}
		}
	}
}