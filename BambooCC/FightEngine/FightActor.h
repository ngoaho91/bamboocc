#ifndef FightActor_h
#define FightActor_h
#include "cocos2d.h"
#include "../PathEngine/PathEngine.h"
#include "../RigEngine/Character.h"
#include "../Geometry/Rectangle.h"
#include "Vector2.h"
#include "FightActorRender.h"
#include "FightMaterial.h"
#include "Buff.h"
#include "FightSkill.h"
#include "PassiveSkill.h"
#define QOT_FIGHTACTOR 3
namespace FightEngine
{
	class Actor
	{
	private:
		int m_Angle;// TODO: need to work on, if you know what to do
		// -----------------------------
		Geometry::Rectangle*	m_FightBoundingBox;
		float					m_FightPositionX;
		float					m_FightPositionY;
		int						m_FaceDirection;
		RigEngine::Character*	m_Character;
		ActorRender*			m_Render;
		char*					m_Name;
		ElementSeries			m_Series;
		// ------------------------------
		double					m_ATKAnimationTime;
		double					m_ATKCRITAnimationTime;
		double					m_CASTAnimationTime;
		double					m_HURTAnimationTime;
		void					UpdateAnimation();
		cc_timeval*				m_LastATKTime;
		cc_timeval*				m_LastATKCRITTime;
		cc_timeval*				m_LastCASTTime;
		cc_timeval*				m_LastHURTTime;
	public:
		Actor();
		~Actor();
		ActorRender*			GetRender()				{ return m_Render; }
		void					ResetRender();
		RigEngine::Character*	GetCharacter()			{ return m_Character; }
		Vector2*				GetPosition()			{ return new Vector2(m_FightPositionX,m_FightPositionY);}
		Geometry::Rectangle*	GetFightBoundingBox()	{ return m_FightBoundingBox;}
		Vector2*				GetFrontPoint(float range_distance, float angle_distance);
		void					SetPosition(int x, int y);
		void					Step();
		void					Update();
		void					RefreshFaceDirection();
		void					LookAt(int x, int y);
		void					Stop();
		void					PlayAttack();
		void					PlayAttackCrit();
		void					PlayCast();
		void					PlayHurt();
	private:
		float m_B_HP, m_P_HP;
		float m_B_HPRegen, m_P_HPRegen;
		float m_B_MP, m_P_MP;
		float m_B_MPRegen, m_P_MPRegen;
		float m_B_SP, m_P_SP;
		float m_B_SPRegen, m_P_SPRegen;
		float m_B_Damage, m_P_Damage;

		float m_B_Strength, m_P_Strength;
		float m_B_Agility, m_P_Agility;
		float m_B_Dexterity, m_P_Dexterity;
		float m_B_Inteligent, m_P_Inteligent;

		float m_B_LightningAbsor, m_P_LightningAbsor;
		float m_B_PoisonAbsor, m_P_PoisonAbsor;
		float m_B_IceAbsor, m_P_IceAbsor;
		float m_B_FireAbsor, m_P_FireAbsor;
		float m_B_PhysicsAbsor, m_P_PhysicsAbsor;

		float m_B_MoveSpeed, m_P_MoveSpeed;
		float m_B_AttackSpeed, m_P_AttackSpeed;// time between 2 attack
		float m_B_BaseAttackTime, m_P_BaseAttackTime;// time between prepair to attack and attack
		float m_B_Accurate, m_P_Accurate;
		float m_B_Evasion, m_P_Evasion;
	public:
		float	GetBaseHP()						{ return m_B_HP;}
		void	SetBaseHP(float value)			{ m_B_HP = value;}
		float	GetPlusHP()						{ return m_P_HP;}
		void	SetPlusHP(float value)			{ m_P_HP = value;}
		float	GetBaseMP()						{ return m_B_MP;}
		void	SetBaseMP(float value)			{ m_B_MP = value;}
		float	GetPlusMP()						{ return m_P_MP;}
		void	SetPlusMP(float value)			{ m_P_MP = value;}
		float	GetBaseHPRegen()				{ return m_B_HPRegen;}
		void	SetBaseHPRegen(float value)		{ m_B_HPRegen = value;}
		float	GetPlusHPRegen()				{ return m_P_HPRegen;}
		void	SetPlusHPRegen(float value)		{ m_P_HPRegen = value;}
		float	GetBaseMPRegen()				{ return m_B_MPRegen;}
		void	SetBaseMPRegen(float value)		{ m_B_MPRegen = value;}
		float	GetPlusMPRegen()				{ return m_P_MPRegen;}
		void	SetPlusMPRegen(float value)		{ m_P_MPRegen = value;}
		float	GetBaseDamage()					{ return m_B_Damage;}
		void	SetBaseDamage(float value)		{ m_B_Damage = value;}
		float	GetPlusDamage()					{ return m_P_Damage;}
		void	SetPlusDamage(float value)		{ m_P_Damage = value;}
		float	GetBaseStrength()				{ return m_B_Strength;}
		void	SetBaseStrength(float value)	{ m_B_Strength = value;}
		float	GetPlusStrength()				{ return m_P_Strength;}
		void	SetPlusStrength(float value)	{ m_P_Strength = value;}
		float	GetBaseDexterity()				{ return m_B_Dexterity;}
		void	SetBaseDexterity(float value)	{ m_B_Dexterity = value;}
		float	GetPlusDexterity()				{ return m_P_Dexterity;}
		void	SetPlusDexterity(float value)	{ m_P_Dexterity = value;}
		float	GetBaseAgility()				{ return m_B_Agility;}
		void	SetBaseAgility(float value)		{ m_B_Agility = value;}
		float	GetPlusAgility()				{ return m_P_Agility;}
		void	SetPlusAgility(float value)		{ m_P_Agility = value;}
		float	GetBaseInteligent()				{ return m_B_Inteligent;}
		void	SetBaseInteligent(float value)	{ m_B_Inteligent = value;}
		float	GetPlusInteligent()				{ return m_P_Inteligent;}
		void	SetPlusInteligent(float value)	{ m_P_Inteligent = value;}
		float	GetBaseLightningAbsor()				{ return m_B_LightningAbsor;}
		void	SetBaseLightningAbsor(float value)	{ m_B_LightningAbsor = value;}
		float	GetPlusLightningAbsor()				{ return m_P_LightningAbsor;}
		void	SetPlusLightningAbsor(float value)	{ m_P_LightningAbsor = value;}
		float	GetBasePoisonAbsor()				{ return m_B_PoisonAbsor;}
		void	SetBasePoisonAbsor(float value)		{ m_B_PoisonAbsor = value;}
		float	GetPlusPoisonAbsor()				{ return m_P_PoisonAbsor;}
		void	SetPlusPoisonAbsor(float value)		{ m_P_PoisonAbsor = value;}
		float	GetBaseIceAbsor()					{ return m_B_IceAbsor;}
		void	SetBaseIceAbsor(float value)		{ m_B_IceAbsor = value;}
		float	GetPlusIceAbsor()					{ return m_P_IceAbsor;}
		void	SetPlusIceAbsor(float value)		{ m_P_IceAbsor = value;}
		float	GetBaseFireAbsor()					{ return m_B_FireAbsor;}
		void	SetBaseFireAbsor(float value)		{ m_B_FireAbsor = value;}
		float	GetPlusFireAbsor()					{ return m_P_FireAbsor;}
		void	SetPlusFireAbsor(float value)		{ m_P_FireAbsor = value;}
		float	GetBasePhysicsAbsor()				{ return m_B_PhysicsAbsor;}
		void	SetBasePhysicsAbsor(float value)	{ m_B_PhysicsAbsor = value;}
		float	GetPlusPhysicsAbsor()				{ return m_P_PhysicsAbsor;}
		void	SetPlusPhysicsAbsor(float value)	{ m_P_PhysicsAbsor = value;}
		float	GetBaseMoveSpeed()					{ return m_B_MoveSpeed;}
		void	SetBaseMoveSpeed(float value)		{ m_B_MoveSpeed = value;}
		float	GetPlusMoveSpeed()					{ return m_P_MoveSpeed;}
		void	SetPlusMoveSpeed(float value)		{ m_P_MoveSpeed = value;}
		float	GetBaseAttackSpeed()				{ return m_B_AttackSpeed;}
		void	SetBaseAttackSpeed(float value)		{ m_B_AttackSpeed = value;}
		float	GetPlusAttackSpeed()				{ return m_P_AttackSpeed;}
		void	SetPlusAttackSpeed(float value)		{ m_P_AttackSpeed = value;}
		float	GetBaseBaseAttackTime()				{ return m_B_BaseAttackTime;}
		void	SetBaseBaseAttackTime(float value)	{ m_B_BaseAttackTime = value;}
		float	GetPlusBaseAttackTime()				{ return m_P_BaseAttackTime;}
		void	SetPlusBaseAttackTime(float value)	{ m_P_BaseAttackTime = value;}
		float	GetBaseAccurate()					{ return m_B_Accurate;}
		void	SetBaseAccurate(float value)		{ m_B_Accurate = value;}
		float	GetPlusAccurate()					{ return m_P_Accurate;}
		void	SetPlusAccurate(float value)		{ m_P_Accurate = value;}
		float	GetBaseEvasion()					{ return m_B_Evasion;}
		void	SetBaseEvasion(float value)			{ m_B_Evasion = value;}
		float	GetPlusEvasion()					{ return m_P_Evasion;}
		void	SetPlusEvasion(float value)			{ m_P_Evasion = value;}
	private:
		vector<Buff*>			m_Buffs;
		vector<FightSkill*>		m_FightSkills;
		vector<PassiveSkill*>	m_PassiveSkills;
	public:
		void					AddBuff(Buff* buff);
		int						GetBuffCount();
		Buff*					GetBuff(int index);
		void					CalculateBuffs();
		void					AddFightSkill(FightSkill* skill);
		void					AddPassiveSkill(PassiveSkill* skill);
		int						GetFightSkillCount();
		FightSkill*				GetFightSkill(int index);
		int						GetPassiveSkillCount();
		PassiveSkill*			GetPassiveSkill(int index);
	};
}
#endif