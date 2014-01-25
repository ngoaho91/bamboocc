#include "AuraSkill.h"
#include "../Utilities/Utilities.h"
#include "../pugiXML/pugixml.hpp"
#include "FightActor.h"
#include "FightWorld.h"
namespace FightEngine
{
	//===========================LUA SECTION===========================================
	//===========================C++ SECTION===========================================
	AuraSkill::AuraSkill()
	{
	}
	AuraSkill::~AuraSkill()
	{
	}
	void AuraSkill::LoadXml(const char* xmlFile)
	{
	}
	void AuraSkill::LevelUp()
	{
		m_Level++;
		onLevelUp();
	}
	void AuraSkill::Cast()
	{
	}
	void AuraSkill::onLevelUp()
	{
	}
	void AuraSkill::onActive()
	{
	}
	void AuraSkill::onMove()
	{
	}
	void AuraSkill::onDeactive()
	{
	}
}