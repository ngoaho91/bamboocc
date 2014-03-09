#ifndef Trap_h
#define Trap_h
#include "../Geometry/QuadObject.h"
#include "../Geometry/QuadTree.h"
#include "TrapRender.h"
#include "TrapSkill.h"
#include "FightMaterial.h"
#define QOT_TRAP 7
using namespace Geometry;
namespace FightEngine
{
	class Trap
		: public QuadObject
	{
	private:
		Actor* m_Owner;
		TrapSkill* m_ParentSkill;
		FightScope m_Scope;
		Damage* m_Damage;
		Buff* m_Buff;
		float m_FightPositionX;
		float m_FightPositionY;
		TrapRender* m_Render;
	private:
		int m_LifeTime;
		int m_DestroyTime;
		bool m_Destroying;
		bool m_Destroyed;
	public:
		Trap();
		~Trap();
		TrapRender* GetRender(){return m_Render;}
	public:
		void SetOwner(Actor* actor);
		void SetSkill(TrapSkill* skill);
		void SetPosition(int x, int y);
		void Update();
		bool ShouldCollide(Actor* actor);
		void DoCollide(Actor* actor);
	public:
		void Destroy();
		void InstantDestroy();
		bool Destroying(){ return m_Destroying;}
		bool Destroyed(){ return m_Destroyed;}
	};
}
#endif