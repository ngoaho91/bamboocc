#ifndef AOESkill_h
#define AOESkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class DamageField;
	class AOESkill:
		public FightSkill
	{
	private:
	public:
		AOESkill();
		~AOESkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	public:
		void onLevelUp();
		void onCast(int x, int y);
		void onDeath(DamageField* field);
		void onDamage(DamageField* field, Actor* actor);
	};
}
#endif