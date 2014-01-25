#ifndef BuffEffect_h
#define BuffEffect_h
#include <vector>
using namespace std;
namespace FightEngine
{
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
	class Actor;
	class Buff
	{
	private:
		Actor* m_Caster;
		vector<BuffItem> m_Items;
		const char* m_EffectFile;
	public:
		Buff();
		~Buff();
		void			AddItem(BuffItem item);
		BuffItem		GetItems(int index);
		int				GetItemCount();
		void			SetCaster(Actor* caster);
		Actor*			GetCaster();
		const char*		GetEffectFile();
	};
}
#endif