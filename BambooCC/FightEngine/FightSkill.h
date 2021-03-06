#ifndef FightSkill_h
#define FightSkill_h
#include "Buff.h"
#include "Damage.h"
#include "FightMaterial.h"
// since lua writen in c, we need to include lua header this way
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}
namespace FightEngine
{
	enum SkillTarget
	{
		ST_FOE,
		ST_FRIEND,
		ST_NEUTRAL,
		ST_NOT_FOE,
		ST_NOT_FRIEND,
		ST_NOT_NEUTRAL,
		ST_POINT,
		ST_AVAILABLE_POINT,
		ST_2POINT,
		ST_2AVAILABLE_POINT,
		ST_INSTANT
	};
	struct TargetData
	{
		Actor* Target;
		int X1;
		int Y1;
		int X2;
		int Y2;
		TargetData()
		{
			X1 = Y1 = X2 = Y2 = 0;
			Target = 0;
		}
	};
	class Actor;
	class FightSkill
	{
	protected:
		SkillTarget		m_Target;
		TargetData		m_TargetData;
		FightScope		m_Scope;
		FightWeapon		m_Weapon;
		int				m_Level;
		int				m_ManaCost;
		int				m_HealthCost;
		Actor*			m_Caster;
		const char*		m_Name;
		const char*		m_LuaScript;
	public:
		FightSkill();
		~FightSkill();
		void SetTargetData(TargetData target);
		virtual void Cast();
		virtual void LevelUp();
	public:
		void SetCaster(Actor* caster){ m_Caster = caster;}
		Actor* GetCaster(){ return m_Caster;}
		const char* GetName(){ return m_Name;}
		int GetLevel(){ return m_Level;}
		int GetManaCost(){ return m_ManaCost;}
		int GetHealthCost(){ return m_HealthCost;}
	};
}
#endif