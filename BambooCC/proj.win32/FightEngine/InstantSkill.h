#ifndef InstantSkill_h
#define InstantSkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class InstantSkill:
		public FightSkill
	{
	public:
		DirectSkill();
		~DirectSkill();
		virtual void LoadXml(const char* xmlFile);
	public:
		void onCast(Actor* target);
		void onDamage(Actor* actor);
		void onDeath(Actor* actor);
	};
}
#endif