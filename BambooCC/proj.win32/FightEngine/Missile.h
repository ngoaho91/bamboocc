#ifndef Missile_h
#define Missile_h
#include "../Geometry/QuadObject.h"
#include "../Geometry/QuadTree.h"
#include "../Geometry/GeometryConstant.h"
#include "FightActor.h"
#include "MissileRender.h"
#include "MissileSkill.h"
#include "FightMaterial.h"
#define QOT_MISSILE 4
using namespace Geometry;
namespace FightEngine
{
	class Missile
		: public QuadObject
	{
	private:
		Actor* m_Owner;
		MissileSkill* m_ParentSkill;
		Damage* m_Damage;
		Buff* m_Buff;
		FightScope m_Scope;
		bool m_Follow;
		Actor* m_FollowObject;
		float m_FightPositionX;
		float m_FightPositionY;
		float m_SpeedX;
		float m_SpeedY;
		int m_FaceDirection;
		float m_Speed;
		float m_Angle;
		MissileRender* m_Render;
	private:
		int m_LifeTime;
		int m_DestroyTime;
		bool m_Destroying;
		bool m_Destroyed;
	public:
		Missile();
		~Missile();
		MissileRender* GetRender(){return m_Render;}
	public:
		void SetOwner(Actor* actor);
		void SetSkill(MissileSkill* skill);
		void SetFollow(bool value);
		void SetFollowObject(Actor* object);
		void SetPosition(int x, int y);
		void SetAngle(float value);
		void SetAngleFromVertex(int x1, int y1, int x2, int y2);
		void SetSpeed(float value);
		void Step();
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