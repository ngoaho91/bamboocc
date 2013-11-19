#ifndef FightWorld_h
#define FightWorld_h
#include "../Geometry/QuadTree.h"
#include "FightWorldRender.h"
#include "MissileSkill.h"
#include "TrapSkill.h"
#include "AOESkill.h"
#include "RaySkill.h"
using namespace Geometry;
namespace FightEngine
{
	class World
		: public QuadTree
	{
	private:
		static World*		m_Instance;
	public:
		static World*		instance();
		static int			WIDTH;
		static int			HEIGHT;
	private:
		FightWorldRender* m_Render;
	public:
		World();
		~World();
		FightWorldRender* GetRender();
		void Update();
	public:
		void AddMissile(MissileSkill* skill, int x1, int y1, int x2, int y2, float speed);
		void AddTrap(TrapSkill* skill, int x, int y);
		void AddDamageField(AOESkill* skill, int x, int y, int range);
		void AddDamageRay(RaySkill* skill, int x1, int y1, int x2, int y2, float length);
		void ChainMissileSkill(FightSkill* parent, int x, int y);
		void ChainTrapSkill(FightSkill* parent, int x, int y);
		void ChainAOESkill(FightSkill* parent, int x, int y);
		void ChainRaySkill(FightSkill* parent, int x1, int y1, int x2, int y2);
	};
}
#endif