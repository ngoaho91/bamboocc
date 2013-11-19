#ifndef RaySkill_h
#define RaySkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class DamageRay;
	class RaySkill:
		public FightSkill
	{
	public:
		RaySkill();
		~RaySkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	public:
		void onLevelUp();
		void onCast(int bx, int by, int ex, int ey);
		void onDeath(DamageRay* ray);
		void onDamage(DamageRay* ray, Actor* actor);
		void onActive(DamageRay* ray);
	};
}
#endif