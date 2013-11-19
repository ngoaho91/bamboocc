#ifndef DamageRay_h
#define DamageRay_h
#include "../Geometry/QuadObject.h"
#include "../Geometry/QuadTree.h"
#include "FightActor.h"
#include "DamageRayRender.h"
#include "RaySkill.h"
#include "FightMaterial.h"
#define QOT_RAY 8
using namespace Geometry;
namespace FightEngine
{
	class DamageRay
		: public QuadObject
	{
	private:
		Actor* m_Owner;
		RaySkill* m_ParentSkill;
		Damage* m_Damage;
		Buff* m_Buff;
		FightScope m_Scope;
		float m_FightPositionX;
		float m_FightPositionY;
		float m_Angle;
		float m_Length;
		DamageRayRender* m_Render;
	private:
		int m_LifeTime;
		int m_DestroyTime;
		bool m_Destroying;
		bool m_Destroyed;
	public:
		DamageRay();
		~DamageRay();
		DamageRayRender* GetRender(){return m_Render;}
	public:
		void SetOwner(Actor* actor);
		void SetSkill(RaySkill* skill);
		void SetPosition(int x, int y);
		void SetAngle(float value);
		void SetAngleFromVertex(int x1, int y1, int x2, int y2);
		void SetLength(float value);
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