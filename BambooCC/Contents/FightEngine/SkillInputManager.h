#ifndef SkillInputManager_h
#define SkillInputManager_h
#include "FightSkill.h"
namespace FightEngine
{
	class SkillInputManager
	{
	private:
		SkillTarget		m_Target;
		TargetData		m_TargetData;
		FightScope		m_Scope;
	public:
		SkillInputManager();
		~SkillInputManager();
	public:
		void LeftClick();
		void RightClick();
	public:
		void SetSkillTarget(SkillTarget target);
		void SetFightScope(FightScope scope);
		TargetData GetTargetData();
	};
}
#endif