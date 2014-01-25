#ifndef Character_h
#define Character_h
#include "RigAction.h"
#include "RigPart.h"
#include "CharacterRender.h"
namespace RigEngine
{
	enum Direction
	{
		D_UP = 4, 
		D_DOWN = 0, 
		D_LEFT = 2, 
		D_RIGHT = 6,
		D_UPLEFT = 3, 
		D_UPRIGHT = 5, 
		D_DOWNLEFT = 1, 
		D_DOWNRIGHT = 7
	};
	enum WalkState
	{
		WS_WALK = 0,
		WS_RUN = 1
	};
	enum HorseState
	{
		HS_NOHORSE = 0,
		HS_RIDEHORSE = 1
	};
	enum WeaponState
	{
		WS_NO_WEAPON = 0, 
		WS_ONEHAND_WEAPON = 1, 
		WS_TWOHAND_WEAPON = 2, 
		WS_DUAL_WEAPON = 3
	};
	enum ActionState
	{
		AS_IDLE = 0, 
		AS_FIGHTIDLE = 1, 
		AS_MOVE = 2, 
		AS_ATTACK = 3, 
		AS_ATTACK_CRIT = 4, 
		AS_CAST = 5, 
		AS_HURT = 6,
		AS_FALL = 7,
		AS_JUMP = 8, 
		AS_THROW_DAGGER = 9, 
		AS_ZEN = 10
	};
	struct ActionInfo
	{
		HorseState horseState;
		WalkState walkState;
		WeaponState weaponState;
		ActionState actionState;
		ActionInfo()
		{
			walkState = WS_RUN;// 0 1
			horseState = HS_NOHORSE;// 0 1
			weaponState = WS_NO_WEAPON;// 0 1 2 3
			actionState = AS_IDLE;// 0 1 2 3 4 5 6 7 8
		}
	};
	class Character
	{
	private:
		CharacterRender*	m_Render;
		int					m_PositionX;
		int					m_PositionY;
		ActionInfo			m_ActionInfo;
		Gender				m_Gender;
		Action*				m_Action;
		int					m_Direction;
	private:
		// body
		RigPart*			m_Cloth;
		RigPart*			m_HandL;
		RigPart*			m_HandR;
		RigPart*			m_Head;
		//RigPart*			m_Cape;
		// weapon
		RigPart*			m_OneHandWeapon;
		RigPart*			m_TwoHandWeapon;
		RigPart*			m_DualWeaponL;
		RigPart*			m_DualWeaponR;
		// horse
		RigPart*			m_HorseHead;
		RigPart*			m_HorseBack;
		RigPart*			m_HorseTail;
	public:
		CharacterRender* GetRender() { return m_Render; }
	public:
		Character();
		~Character();
		void ResetRender();
		void SetPosition(int x, int y);
		void SetActionState(ActionState state);
		void SetWalkState(WalkState state);
		void SetWeaponState(WeaponState state);
		void SetHorseState(HorseState state);
		void SetGender(Gender gender);
		void SetDirection(int direction);
		void SetFullCloth(char* name);
		void SetCloth(char* name);
		void SetHandL(char* name);
		void SetHandR(char* name);
		void SetHead(char* name);
		void SetOneHandWeapon(char* name);
		void SetTwoHandWeapon(char* name);
		void SetDualWeapon(char* name);
		void SetDualWeaponL(char* name);
		void SetDualWeaponR(char* name);
		void SetHorse(char* name);
		void SetHorseH(char* name);
		void SetHorseT(char* name);
		void SetHorseB(char* name);
		//! TODO: set animation time for specific action
		void SetAnimationTimeRUN(float time);
		void SetAnimationTimeWALK(float time);
		void SetAnimationTimeATK(float time);
		void SetAnimationTimeATKCRIT(float time);
		void SetAnimationTimeHURT(float time);
		void SetAnimationTimeCAST(float time);
		void SetAnimationTimeJUMP(float time);
		void SetAnimationTimeFALL(float time);
	public:
		ActionInfo GetActionInfo(){	return m_ActionInfo;}
		int GetPositionX() {return m_PositionX;}
		int GetPositionY() {return m_PositionY;}
	public:
		void SetAction(Action* action);
		void SetAction(int actionID);
		void SetAction(ActionInfo info);
		void SetPositionZ(int,int,int,int,int,int,int,int,int,int);
	private:
		void refreshOrder();
	};
}
#endif