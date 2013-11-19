#ifndef AuraSkill_h
#define AuraSkill_h
#include "FightSkill.h"
namespace FightEngine
{
	class Aura;
	class AuraSkill
		:public FightSkill
	{
	public:
		AuraSkill();
		~AuraSkill();
		virtual void Cast();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
	public:
		void onLevelUp();
		void onActive();
		void onMove();
		void onDeactive();
	};
}
#endif