#include "FightSkill.h"
namespace FightEngine
{
	FightSkill::FightSkill()
	{

	}
	FightSkill::~FightSkill()
	{
		
	}
	void FightSkill::Cast()
	{
	}
	void FightSkill::LevelUp()
	{
		m_Level++;
	}
	void FightSkill::SetTargetData(TargetData target)
	{
		m_TargetData = target;
	}
}