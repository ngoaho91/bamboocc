#ifndef TrapSkill_h
#define TrapSkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class Trap;
	class TrapSkill:
		public FightSkill
	{
	private:
	public:
		TrapSkill();
		~TrapSkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	public:
		void onLevelUp();
		void onCast(int x, int y);
		void onDeath(Trap* trap);
		void onDamage(Trap* trap, Actor* actor);
		void onTriggered(Trap* trap, Actor* actor);
		void onActive(Trap* trap);
	};
}
#endif