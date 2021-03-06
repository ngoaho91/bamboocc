// compile command:
// tolua++ -o tolua_fight.cpp -H tolua_fight.h -n fight FightEngine_Prototype.h
// tolua_begin
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
	class FightSkill
	{
		FightSkill();
		~FightSkill();
		void SetTargetData(TargetData target);
		virtual void Cast();
		virtual void LevelUp();
		void SetCaster(Actor* caster){ m_Caster = caster;}
		Actor* GetCaster(){ return m_Caster;}
		const char* GetName(){ return m_Name;}
		int GetLevel(){ return m_Level;}
		int GetManaCost(){ return m_ManaCost;}
		int GetHealthCost(){ return m_HealthCost;}
	};
	class RaySkill:
		public FightSkill
	{
		RaySkill();
		~RaySkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	};
	class TrapSkill:
		public FightSkill
	{
		TrapSkill();
		~TrapSkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	};
	class AOESkill:
		public FightSkill
	{
		AOESkill();
		~AOESkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	};
	class MissileSkill
		:public FightSkill
	{
		MissileSkill();
		~MissileSkill();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
		virtual void Cast();
	};
	
	class AuraSkill
		:public FightSkill
	{
		AuraSkill();
		~AuraSkill();
		virtual void Cast();
		virtual void LoadXml(const char* xmlFile);
		virtual void LevelUp();
	};
	class PassiveSkill
	{
		PassiveSkill();
		~PassiveSkill();
		void LoadXml(const char* xmlFile);
		void LevelUp();
	};
	class World
	{
		static int WIDTH;
		static int HEIGHT;
		static World* instance();
		void AddMissile(MissileSkill* skill, int x1, int y1, int x2, int y2, float speed);
		void AddTrap(TrapSkill* skill, int x, int y);
		void AddDamageField(AOESkill* skill, int x, int y, int range);
		void AddDamageRay(RaySkill* skill, int x1, int y1, int x2, int y2, float length);
		void ChainMissileSkill(FightSkill* parent, int x, int y);
		void ChainTrapSkill(FightSkill* parent, int x, int y);
		void ChainAOESkill(FightSkill* parent, int x, int y);
		void ChainRaySkill(FightSkill* parent, int x1, int y1, int x2, int y2);
	};
	enum ElementSeries
	{
		ES_METAL,
		ES_PLANT,
		ES_ICE,
		ES_FIRE,
		ES_EARTH
	};
	enum FightScope
	{
		FS_FRIEND,
		FS_FOE,
		FS_NEUTRAL,
		FS_ALL,
		FS_NOT_NEUTRAL,
		FS_NOT_FRIEND,
		FS_NOT_FOE
	};
	enum FightWeapon
	{
		FW_FREE,
		FW_BLOW,// quyền pháp
		FW_CLAW, // trảo pháp
		FW_PALM,// chưởng pháp
		FW_FINGER,// chỉ pháp
		FW_SWORD,// kiếm pháp
		FW_DOUBLE_SWORD,// song kiếm
		FW_BLADE,// đao pháp
		FW_DOUBLE_BLADE,// song đao
		FW_CLUB,// chùy pháp
		FW_DOUBLE_CLUB,// song chùy
		FW_AXE,// phủ pháp
		FW_DOUBLE_AXE,// song phủ
		FW_STAFF,// bổng pháp/côn pháp
		FW_LANCE,// mâu pháp
		FW_DAGGER// phi đao
	};
	class Missile
	{
		Missile();
		~Missile();
		void SetOwner(Actor* actor);
		void SetSkill(MissileSkill* skill);
		void SetFollow(bool value);
		void SetFollowObject(Actor* object);
		void SetPosition(int x, int y);
		void SetAngle(float value);
		void SetAngleFromVertex(int x1, int y1, int x2, int y2);
		void SetSpeed(float value);
		void Destroy();
		void InstantDestroy();
		bool Destroying();
		bool Destroyed();
	};
	class Trap
	{
		Trap();
		~Trap();
		void SetOwner(Actor* actor);
		void SetSkill(TrapSkill* skill);
		void SetPosition(int x, int y);
		void Destroy();
		void InstantDestroy();
		bool Destroying();
		bool Destroyed();
	};
	class DamageField
	{
		DamageField();
		~DamageField();
		void SetOwner(Actor* actor);
		void SetSkill(AOESkill* skill);
		void SetPosition(int x, int y);
		void Destroy();
		void InstantDestroy();
		bool Destroying();
		bool Destroyed();
	};
	class DamageRay
	{
		DamageRay();
		~DamageRay();
		void SetOwner(Actor* actor);
		void SetSkill(RaySkill* skill);
		void SetPosition(int x, int y);
		void SetAngle(float value);
		void SetAngleFromVertex(int x1, int y1, int x2, int y2);
		void SetLength(float value);
		void Destroy();
		void InstantDestroy();
		bool Destroying();
		bool Destroyed();
	};
	enum DamageStyle
	{
		DS_INTERNAL,
		DS_EXTERNAL,
		DS_PURE
	};
	struct DamageItem
	{
		DamageStyle Style;
		ElementSeries Series;
		float Value;
	};
	class Damage
	{
		Damage();
		~Damage();
		void SetCaster(Actor* caster);
		Actor* GetCaster();
		void AddItem(DamageItem item);
		void SetCaster(Actor* caster);
	};
	enum BuffStyleDetail
	{
		BSD_MOVE_SPEED,
		BSD_ATTACK_SPEED,
		BSD_ACCURATE,
		BSD_EVASION,
		BSD_HP_REGEN,
		BSD_MP_REGEN,
		BSD_STRENGTH,
		BSD_AGILITY,
		BSD_DEXTERITY,
		BSD_INTELIGENT,
		BSD_LIGHTNING_ABSOR,
		BSD_POISON_ABSOR,
		BSD_ICE_ABSOR,
		BSD_FIRE_ABSOR,
		BSD_PHYSICS_ABSOR
	};
	enum BuffStyle
	{
		BS_NEGATIVE,
		BS_POSITIVE,
		BS_UNDEFINED
	};
	enum BuffCalculation
	{
		BC_CASTER,
		BC_TARGET,
		BC_PERNALTY
	};
	enum BuffCalculationMethod
	{
		BCM_PERCENT,
		BCM_VALUE
	};
	enum BuffCalculationDetail
	{
		BCD_HP_BASE,
		BCD_MP_BASE,
		BCD_MOVESPEED_BASE,
		BCD_ATTACKSPEED_BASE,
		BCD_STRENGTH_BASE,
		BCD_AGILITY_BASE,
		BCD_DEXTERITY_BASE,
		BCD_INTELIGENT_BASE
	};

	struct BuffItem
	{
		BuffStyleDetail Detail;
		BuffStyle Style;
		float Value;

		BuffCalculation Calculation;
		BuffCalculationMethod CalculationMethod;
		BuffCalculationDetail CalculationDetail;
		float CalculationValue;

		bool Stackable;
		int MaxStack;
	};
	class Buff
	{
		Actor* GetCaster();
		void SetCaster(Actor* caster);
		void AddItem(BuffItem item);
	};
	class Charge
	{
		Charge();
		~Charge();
		const char* GetName();
		void SetName(const char* value);
		int GetCount();
		int GetMax();
		void SetMax(int value);
		void Increase();
		void Decrease();
	};
	class Actor
	{
		Actor();
		~Actor();
		void LookAt(int x, int y);
		void Stop();
		void PlayAttack();
		void PlayAttackCrit();
		void PlayCast();
		void PlayHurt();
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
	};
	class Vector2
	{
		Vector2(int x, int y);
		Vector2();
		~Vector2();
		int GetX();
		int GetY();
		void SetX(int x);
		void SetY(int y);
	};
}
// tolua_end