#ifndef DamageField_h
#define DamageField_h
#include "../Geometry/QuadObject.h"
#include "../Geometry/QuadTree.h"
#include "FightActor.h"
#include "DamageFieldRender.h"
#include "AOESkill.h"
#include "FightMaterial.h"
#define QOT_FIELD 6
using namespace Geometry;
namespace FightEngine
{
	class DamageField
		: public QuadObject
	{
	private:
		Actor* m_Owner;
		AOESkill* m_ParentSkill;
		Damage* m_Damage;
		Buff* m_Buff;
		FightScope m_Scope;
		float m_FightPositionX;
		float m_FightPositionY;
		float m_Range;
		DamageFieldRender* m_Render;
	private:
		int m_LifeTime;
		int m_DestroyTime;
		bool m_Destroying;
		bool m_Destroyed;
	public:
		DamageField();
		~DamageField();
		DamageFieldRender* GetRender(){return m_Render;}
	public:
		void SetOwner(Actor* actor);
		void SetSkill(AOESkill* skill);
		void SetPosition(int x, int y);
		void SetRange(float value);
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