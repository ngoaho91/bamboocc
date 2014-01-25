#ifndef MissileSkill_h
#define MissileSkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class Missile;
	class MissileSkill
		:public FightSkill
	{
	private:
		const char* m_MissileFile;
		float m_MissileSpeed;
		float m_MissileLifeTime;
		float m_AngleOffset;
		Damage* m_Damage;
		Buff* m_Buff;
	public:
		MissileSkill();
		~MissileSkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	public:
		void onLevelUp();
		void onCast(int x, int y);
		void onMissileDeath(Missile* missile);
		void onMissileTravel(Missile* missile);
		void onDamage(Missile* missile, Actor* actor);
	};
}
#endif