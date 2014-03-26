#include "MissileSkill.h"
#include "../Utilities.h"
#include "../pugiXML/pugixml.hpp"
#include "FightActor.h"
#include "FightWorld.h"
namespace FightEngine
{
	MissileSkill::MissileSkill()
	{
		LoadXml("skill/wu_zhang_shan.xml");
	}
	MissileSkill::~MissileSkill()
	{
	}
	void MissileSkill::LoadXml(const char* xmlFile)
	{
		pugi::xml_document animation_file;
		pugi::xml_parse_result result = animation_file.load_file(xmlFile);
		if(!result)
		{
			return;
		}
		char* folder_path = Utilities::getParentFolder(xmlFile);
		pugi::xml_node rootTAG = animation_file.child("missile_skill");
		{
			m_Name = rootTAG.attribute("name").as_string();
			m_LuaScript = rootTAG.attribute("script").as_string();
			int scope = rootTAG.attribute("scope").as_int();
			m_Scope = (FightScope)scope;
			int weapon = rootTAG.attribute("weapon").as_int();
			m_Weapon = (FightWeapon)weapon;
		}
		pugi::xml_node missileTAG = rootTAG.first_child();
		{
			m_MissileFile = missileTAG.attribute("file").as_string();
			m_MissileSpeed = missileTAG.attribute("speed").as_float();
			m_MissileLifeTime = missileTAG.attribute("life_time").as_float();
			m_AngleOffset = missileTAG.attribute("angle_offset").as_float();
		}
		pugi::xml_node damagesTAG = missileTAG.next_sibling();
		{
			m_Damage = new Damage();
			m_Damage->SetEffectFile(damagesTAG.attribute("effect").as_string());
			pugi::xml_node damageTAG = damagesTAG.first_child();
			while(damageTAG)
			{
				DamageItem item;
				item.Style = (DamageStyle)damageTAG.attribute("style").as_int();
				item.Series = (ElementSeries)damageTAG.attribute("series").as_int();
				item.Value = damageTAG.attribute("value").as_int();
				m_Damage->AddItem(item);
				damageTAG = damageTAG.next_sibling();
			}
		}
		// TODO: load buff
	}
	void MissileSkill::LevelUp()
	{
		m_Level++;
		onLevelUp();
	}
	void MissileSkill::Cast()
	{
		FightSkill::Cast();
		onCast(m_TargetData.X1,m_TargetData.Y1);
	}
	void MissileSkill::onLevelUp()
	{
		
	}
	void MissileSkill::onCast(int x, int y)
	{
		m_Caster->GetCharacter()->SetActionState(AS_ATTACK);
		m_Caster->LookAt(x,y);
		m_Caster->PlayAttack();
		
	}
	void MissileSkill::onMissileDeath(Missile* missile)
	{
		// TODO: use CCLuaEngine to execute script
	}
	void MissileSkill::onMissileTravel(Missile* missile)
	{
		// TODO: this is draft, need to work on
		
	}
	void MissileSkill::onDamage(Missile* missile, Actor* actor)
	{
		// TODO: this is draft, need to work on
		
	}
}