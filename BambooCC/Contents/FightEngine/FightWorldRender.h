#ifndef FightWorldRender_h
#define FightWorldRender_h
#include "cocos2d.h"
#include "MissileRender.h"
#include "TrapRender.h"
#include "DamageFieldRender.h"
#include "DamageRayRender.h"
USING_NS_CC;
namespace FightEngine
{
	class FightWorldRender
	{
	private:
		CCNode* m_ParentNode;
		vector<MissileRender*> m_Missiles;
		vector<TrapRender*> m_Traps;
		vector<DamageFieldRender*> m_Fields;
		vector<DamageRayRender*> m_Rays;
	public:
		FightWorldRender();
		~FightWorldRender();
		void SetParentNode(CCNode* parent);
		void AddMissile(MissileRender* missile);
		void AddTrap(TrapRender* trap);
		void AddDamageField(DamageFieldRender* field);
		void AddDamageRay(DamageRayRender* ray);
	};
}
#endif