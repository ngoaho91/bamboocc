#ifndef Damage_h
#define Damage_h
#include <vector>
#include "FightMaterial.h"
using namespace std;
namespace FightEngine
{
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
	class Actor;
	class Damage
	{
	private:
		Actor* m_Caster;
		vector<DamageItem> m_Items;
		const char* m_EffectFile;
	public:
		Damage();
		~Damage();
		vector<DamageItem>		GetItems(){ return m_Items;}
		vector<DamageItem>*		GetItemsPointer(){ return &m_Items;}
		void					AddItem(DamageItem item){ m_Items.push_back(item);}
		Actor*					GetCaster(){ return m_Caster;}
		void					SetCaster(Actor* caster){ m_Caster = caster;}
		const char*				GetEffectFile(){ return m_EffectFile;}
		void					SetEffectFile(const char* file){ m_EffectFile = file;}
	};
}
#endif