#include "Buff.h"
namespace FightEngine
{
	Buff::Buff()
	{
	}
	Buff::~Buff()
	{
	}
	void Buff::AddItem(BuffItem item)
	{
		m_Items.push_back(item);
	}
	BuffItem Buff::GetItems(int index)
	{
		return m_Items[index];
	}
	int Buff::GetItemCount()
	{
		return m_Items.size();
	}
	void Buff::SetCaster(Actor* caster)
	{
		m_Caster = caster;
	}
	Actor* Buff::GetCaster()
	{
		return m_Caster;
	}
	const char* Buff::GetEffectFile()
	{
		return m_EffectFile;
	}
}