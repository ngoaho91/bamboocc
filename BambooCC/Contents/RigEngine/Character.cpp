#include "Character.h"
#ifndef MAP_INF
#define MAP_INF 2000000
#endif
namespace RigEngine
{
	Character::Character()
	{
		m_Action = new Action();
		m_Cloth = new RigPart(RP_CHARACTER_CLOTH);
		m_HandL = new RigPart(RP_CHARACTER_HANDL);
		m_HandR = new RigPart(RP_CHARACTER_HANDR);
		m_Head = new RigPart(RP_CHARACTER_HEAD);
		m_OneHandWeapon = new RigPart(RP_WEAPON_ONE);
		m_TwoHandWeapon = new RigPart(RP_WEAPON_TWO);
		m_DualWeaponL = new RigPart(RP_WEAPON_DUALL);
		m_DualWeaponR = new RigPart(RP_WEAPON_DUALR);
		m_HorseHead = new RigPart(RP_HORSE_HEAD);
		m_HorseBack = new RigPart(RP_HORSE_BACK);
		m_HorseTail = new RigPart(RP_HORSE_TAIL);
		m_Direction = 0;
		m_PositionX = 0;
		m_PositionY = 0;
		m_Render = new CharacterRender();
		m_Render->AddChild(m_HorseHead->m_Render);
		m_Render->AddChild(m_HorseBack->m_Render);
		m_Render->AddChild(m_HorseTail->m_Render);

		m_Render->AddChild(m_Cloth->m_Render);
		m_Render->AddChild(m_HandL->m_Render);
		m_Render->AddChild(m_HandR->m_Render);
		m_Render->AddChild(m_Head->m_Render);
		//m_Render->AddChild(m_Cape->m_Render);

		m_Render->AddChild(m_OneHandWeapon->m_Render);
		m_Render->AddChild(m_TwoHandWeapon->m_Render);
		m_Render->AddChild(m_DualWeaponL->m_Render);
		m_Render->AddChild(m_DualWeaponR->m_Render);
	}
	Character::~Character()
	{
	}
	void Character::ResetRender()
	{
		
	}
	void Character::SetPosition(int x, int y)
	{
		if(x == m_PositionX && y == m_PositionY) return;
		m_PositionX = x;
		m_PositionY = y;
		m_Render->SetPositionXY(x,y);
		m_Render->SetPositionZ(MAP_INF-y);
	}
	void Character::SetActionState(ActionState state)
	{
		if(m_ActionInfo.actionState == state) return;
		m_ActionInfo.actionState = state;
		SetAction(m_ActionInfo);
	}
	void Character::SetWalkState(WalkState state)
	{ 
		if(m_ActionInfo.walkState == state) return;
		m_ActionInfo.walkState = state;
		SetAction(m_ActionInfo);
	}
	void Character::SetWeaponState(WeaponState state)
	{
		if(m_ActionInfo.weaponState == state) return;
		m_ActionInfo.weaponState = state;
		SetAction(m_ActionInfo);
	}
	void Character::SetHorseState(HorseState state)
	{
		if(m_ActionInfo.horseState == state) return;
		m_ActionInfo.horseState = state;
		SetAction(m_ActionInfo);
	}
	void Character::SetFullCloth(char* name)
	{
		SetCloth(name);
		SetHandL(name);
		SetHandR(name);
	}
	
	void Character::SetDualWeapon(char* name)
	{
		SetDualWeaponL(name);
		SetDualWeaponR(name);
	}
	void Character::SetHorse(char* name)
	{
		SetHorseH(name);
		SetHorseB(name);
		SetHorseT(name);
	}
	void Character::SetCloth(char* name)
	{
		m_Cloth->SetName(name);
		m_Cloth->ResetRender();
	}
	void Character::SetHandL(char* name)
	{
		m_HandL->SetName(name);
		m_HandL->ResetRender();
	}
	void Character::SetHandR(char* name)
	{
		m_HandR->SetName(name);
		m_HandR->ResetRender();
	}
	void Character::SetHead(char* name)
	{
		m_Head->SetName(name);
		m_Head->ResetRender();
	}
	void Character::SetOneHandWeapon(char* name)
	{
		m_OneHandWeapon->SetName(name);
		m_OneHandWeapon->ResetRender();
	}
	void Character::SetTwoHandWeapon(char* name)
	{
		m_TwoHandWeapon->SetName(name);
		m_TwoHandWeapon->ResetRender();
	}
	void Character::SetDualWeaponL(char* name)
	{
		m_DualWeaponL->SetName(name);
		m_DualWeaponL->ResetRender();
	}
	void Character::SetDualWeaponR(char* name)
	{
		m_DualWeaponR->SetName(name);
		m_DualWeaponR->ResetRender();
	}
	void Character::SetHorseH(char* name)
	{
		m_HorseHead->SetName(name);
		m_HorseHead->ResetRender();
	}
	void Character::SetHorseT(char* name)
	{
		m_HorseTail->SetName(name);
		m_HorseTail->ResetRender();
	}
	void Character::SetHorseB(char* name)
	{
		m_HorseBack->SetName(name);
		m_HorseBack->ResetRender();
	}
	void Character::SetAction(Action* action)
	{
		if(m_Action->ID == action->ID) return;
		m_Action = action;

		m_Cloth->SetAction(m_Action->ClothID);
		m_HandL->SetAction(m_Action->ClothID);
		m_HandR->SetAction(m_Action->ClothID);
		m_Head->SetAction(m_Action->ClothID);

		m_OneHandWeapon->SetAction(m_Action->OneHandWeaponID);
		m_TwoHandWeapon->SetAction(m_Action->TwoHandWeaponID);
		m_DualWeaponL->SetAction(m_Action->DualWeaponID);
		m_DualWeaponR->SetAction(m_Action->DualWeaponID);

		m_HorseHead->SetAction(m_Action->HorseID);
		m_HorseTail->SetAction(m_Action->HorseID);
		m_HorseBack->SetAction(m_Action->HorseID);

		SetDirection(m_Direction);

		refreshOrder();
	}

	void Character::SetAction(int actionID)
	{
		if(m_Action->ID == actionID) return;
		switch(actionID)
		{
		case	1: { m_Action = (m_Gender==MALE)?(Action::AttackM()):(Action::AttackF()); break; }
		case	2: { m_Action = (m_Gender==MALE)?(Action::AttackOWCritM()):(Action::AttackOWCritF()); break; }
		case	3: { m_Action = (m_Gender==MALE)?(Action::AttackOWM()):(Action::AttackOWF()); break; }
		case	4: { m_Action = (m_Gender==MALE)?(Action::AttackTWCritM()):(Action::AttackTWCritF()); break; }
		case	5: { m_Action = (m_Gender==MALE)?(Action::AttackTWM()):(Action::AttackTWF()); break; }
		case	6: { m_Action = (m_Gender==MALE)?(Action::AttackDWCritM()):(Action::AttackDWCritF()); break; }
		case	7: { m_Action = (m_Gender==MALE)?(Action::AttackDWM()):(Action::AttackDWF()); break; }
		case	8: { m_Action = (m_Gender==MALE)?(Action::FallM()):(Action::FallF()); break; }
		case	9: { m_Action = (m_Gender==MALE)?(Action::FallOWM()):(Action::FallOWF()); break; }
		case	10: { m_Action = (m_Gender==MALE)?(Action::FallTWM()):(Action::FallTWF()); break; }
		case	11: { m_Action = (m_Gender==MALE)?(Action::FallDWM()):(Action::FallDWF()); break; }
		case	40: { m_Action = (m_Gender==MALE)?(Action::HurtM()):(Action::HurtF()); break; }
		case	41: { m_Action = (m_Gender==MALE)?(Action::HurtOWM()):(Action::HurtOWF()); break; }
		case	42: { m_Action = (m_Gender==MALE)?(Action::HurtTWM()):(Action::HurtTWF()); break; }
		case	43: { m_Action = (m_Gender==MALE)?(Action::HurtDWM()):(Action::HurtDWF()); break; }
		case	44: { m_Action = (m_Gender==MALE)?(Action::JumpM()):(Action::JumpF()); break; }
		case	45: { m_Action = (m_Gender==MALE)?(Action::ThrowDaggerM()):(Action::ThrowDaggerF()); break; }
		case	46: { m_Action = (m_Gender==MALE)?(Action::CastM()):(Action::CastF()); break; }
		case	47: { m_Action = (m_Gender==MALE)?(Action::CastOWM()):(Action::CastOWF()); break; }
		case	48: { m_Action = (m_Gender==MALE)?(Action::CastTWM()):(Action::CastTWF()); break; }
		case	49: { m_Action = (m_Gender==MALE)?(Action::CastDWM()):(Action::CastDWF()); break; }
		case	54: { m_Action = (m_Gender==MALE)?(Action::RunM()):(Action::RunF()); break; }
		case	55: { m_Action = (m_Gender==MALE)?(Action::RunOWM()):(Action::RunOWF()); break; }
		case	56: { m_Action = (m_Gender==MALE)?(Action::RunTWM()):(Action::RunTWF()); break; }
		case	57: { m_Action = (m_Gender==MALE)?(Action::RunDWM()):(Action::RunDWF()); break; }
		case	58: { m_Action = (m_Gender==MALE)?(Action::IdleM()):(Action::IdleF()); break; }
		case	59: { m_Action = (m_Gender==MALE)?(Action::IdleOWM()):(Action::IdleOWF()); break; }
		case	60: { m_Action = (m_Gender==MALE)?(Action::IdleTWM()):(Action::IdleTWF()); break; }
		case	61: { m_Action = (m_Gender==MALE)?(Action::IdleDWM()):(Action::IdleDWF()); break; }
		case	62: { m_Action = (m_Gender==MALE)?(Action::FightIdleM()):(Action::FightIdleF()); break; }
		case	63: { m_Action = (m_Gender==MALE)?(Action::FightIdleOWM()):(Action::FightIdleOWF()); break; }
		case	64: { m_Action = (m_Gender==MALE)?(Action::FightIdleTWM()):(Action::FightIdleTWF()); break; }
		case	65: { m_Action = (m_Gender==MALE)?(Action::FightIdleDWM()):(Action::FightIdleDWF()); break; }
		case	66: { m_Action = (m_Gender==MALE)?(Action::WalkM()):(Action::WalkF()); break; }
		case	67: { m_Action = (m_Gender==MALE)?(Action::WalkOWM()):(Action::WalkOWF()); break; }
		case	68: { m_Action = (m_Gender==MALE)?(Action::WalkTWM()):(Action::WalkTWF()); break; }
		case	69: { m_Action = (m_Gender==MALE)?(Action::WalkDWM()):(Action::WalkDWF()); break; }
		case	70: { m_Action = (m_Gender==MALE)?(Action::ZenM()):(Action::ZenF()); break; }
		case	12: { m_Action = Action::AttackHorseCrit()	; break; }
		case	13: { m_Action = Action::AttackHorseOWCrit()	; break; }
		case	14: { m_Action = Action::AttackHorseTWCrit()	; break; }
		case	15: { m_Action = Action::AttackHorseDWCrit()	; break; }
		case	16: { m_Action = Action::AttackHorse()	; break; }
		case	17: { m_Action = Action::AttackHorseOW()	; break; }
		case	18: { m_Action = Action::AttackHorseTW()	; break; }
		case	19: { m_Action = Action::AttackHorseDW()	; break; }
		case	20: { m_Action = Action::FallHorse()	; break; }
		case	21: { m_Action = Action::FallHorseOW()	; break; }
		case	22: { m_Action = Action::FallHorseTW()	; break; }
		case	23: { m_Action = Action::FallHorseDW()	; break; }
		case	24: { m_Action = Action::HurtHorse()	; break; }
		case	25: { m_Action = Action::HurtHorseOW()	; break; }
		case	26: { m_Action = Action::HurtHorseTW()	; break; }
		case	27: { m_Action = Action::HurtHorseDW()	; break; }
		case	28: { m_Action = Action::CastHorse()	; break; }
		case	29: { m_Action = Action::CastHorseOW()	; break; }
		case	30: { m_Action = Action::CastHorseTW()	; break; }
		case	31: { m_Action = Action::CastHorseDW()	; break; }
		case	32: { m_Action = Action::RunHorse()	; break; }
		case	33: { m_Action = Action::RunHorseOW()	; break; }
		case	34: { m_Action = Action::RunHorseTW()	; break; }
		case	35: { m_Action = Action::RunHorseDW()	; break; }
		case	36: { m_Action = Action::WalkHorse()	; break; }
		case	37: { m_Action = Action::WalkHorseOW()	; break; }
		case	38: { m_Action = Action::WalkHorseTW()	; break; }
		case	39: { m_Action = Action::WalkHorseDW()	; break; }
		case	50: { m_Action = Action::IdleHorse()	; break; }
		case	51: { m_Action = Action::IdleHorseOW()	; break; }
		case	52: { m_Action = Action::IdleHorseTW()	; break; }
		case	53: { m_Action = Action::IdleHorseDW()	; break; }
		}
		m_Cloth->SetAction(m_Action->ClothID);
		m_HandL->SetAction(m_Action->ClothID);
		m_HandR->SetAction(m_Action->ClothID);
		m_Head->SetAction(m_Action->ClothID);

		m_OneHandWeapon->SetAction(m_Action->OneHandWeaponID);
		m_TwoHandWeapon->SetAction(m_Action->TwoHandWeaponID);
		m_DualWeaponL->SetAction(m_Action->DualWeaponID);
		m_DualWeaponR->SetAction(m_Action->DualWeaponID);

		m_HorseHead->SetAction(m_Action->HorseID);
		m_HorseTail->SetAction(m_Action->HorseID);
		m_HorseBack->SetAction(m_Action->HorseID);

		refreshOrder();
	}

	void Character::SetAction(ActionInfo info)
	{
		if(info.horseState == HS_RIDEHORSE)
		{
			if(info.actionState == AS_ATTACK)
			{
				SetAction(16+(int)info.weaponState);
				// 16 17 18 19
			}
			else if(info.actionState == AS_ATTACK_CRIT)
			{
				SetAction(12+(int)info.weaponState);
				// 12 13 14 15
			}
			else if(info.actionState == AS_CAST)
			{
				SetAction(28+(int)info.weaponState);
				// 28 29 30 31
			}
			else if(info.actionState == AS_FALL)
			{
				SetAction(20+(int)info.weaponState);
				// 20 21 22 23
			}
			else if(info.actionState == AS_HURT)
			{
				SetAction(24+(int)info.weaponState);
				// 24 25 26 27
			}
			else if(info.actionState == AS_IDLE || 
				info.actionState == AS_FIGHTIDLE)
			{
				SetAction(50+(int)info.weaponState);
				// 50 51 52 53
			}
			else if(info.actionState == AS_JUMP)
			{
				SetAction(44);
			}
			else if(info.actionState == AS_MOVE)
			{
				if(info.walkState == WS_RUN)
				{
					SetAction(32+(int)info.weaponState);
					// 32 33 34 35
				}
				else
				{
					SetAction(36+(int)info.weaponState);
					// 36 37 38 39
				}
			}
			else if(info.actionState == AS_THROW_DAGGER)
			{
				SetAction(45);
			}
			else if(info.actionState == AS_ZEN)
			{
				SetAction(70);
			}
		}
		else// no horse
		{
			if(info.actionState == AS_ATTACK)
			{
				SetAction(1+((int)info.weaponState)*2);
				// 1 3 5 7
			}
			else if(info.actionState == AS_ATTACK_CRIT)
			{
				switch (info.weaponState)
				{
				case WS_NO_WEAPON:
					SetAction(1);
					break;
				case WS_ONEHAND_WEAPON:
					SetAction(2);
					break;
				case WS_TWOHAND_WEAPON:
					SetAction(4);
					break;
				case WS_DUAL_WEAPON:
					SetAction(6);
					break;
				}
			}
			else if(info.actionState == AS_CAST)
			{
				SetAction(46+(int)info.weaponState);
				// 46 47 48 49
			}
			else if(info.actionState == AS_FALL)
			{
				SetAction(8+(int)info.weaponState);
				// 8 9 10 11
			}
			else if(info.actionState == AS_HURT)
			{
				SetAction(40+(int)info.weaponState);
				// 40 41 42 43
			}
			else if(info.actionState == AS_IDLE)
			{
				SetAction(58+(int)info.weaponState);
				// 58 59 60 61
			}
			else if(info.actionState == AS_FIGHTIDLE)
			{
				SetAction(62+(int)info.weaponState);
				// 62 63 64 65
			}
			else if(info.actionState == AS_JUMP)
			{
				SetAction(44);
			}
			else if(info.actionState == AS_MOVE)
			{
				
				if(info.walkState == WS_RUN)
				{
					SetAction(54+(int)info.weaponState);
					// 54 55 56 57
				}
				else
				{
					SetAction(66+(int)info.weaponState);
					// 66 67 68 69
				}
			}
			else if(info.actionState == AS_THROW_DAGGER)
			{
				SetAction(45);
			}
			else if(info.actionState == AS_ZEN)
			{
				SetAction(70);
			}
		}
	}


	void Character::SetDirection(int direction)
	{
		m_Direction = direction;

		m_Cloth->SetDirection(m_Direction);
		m_HandL->SetDirection(m_Direction);
		m_HandR->SetDirection(m_Direction);
		m_Head->SetDirection(m_Direction);

		m_OneHandWeapon->SetDirection(m_Direction);
		m_TwoHandWeapon->SetDirection(m_Direction);
		m_DualWeaponL->SetDirection(m_Direction);
		m_DualWeaponR->SetDirection(m_Direction);

		m_HorseHead->SetDirection(m_Direction);
		m_HorseBack->SetDirection(m_Direction);
		m_HorseTail->SetDirection(m_Direction);

		refreshOrder();
	}
	void Character::SetGender(Gender gender)
	{
		if(gender == m_Gender) return;
		m_Gender = gender;
		m_Cloth->SetGender(m_Gender);
		m_HandL->SetGender(m_Gender);
		m_HandR->SetGender(m_Gender);
		m_Head->SetGender(m_Gender);

		m_OneHandWeapon->SetGender(m_Gender);
		m_TwoHandWeapon->SetGender(m_Gender);
		m_DualWeaponL->SetGender(m_Gender);
		m_DualWeaponR->SetGender(m_Gender);

		m_HorseHead->SetGender(m_Gender);
		m_HorseBack->SetGender(m_Gender);
		m_HorseTail->SetGender(m_Gender);
	}
	void Character::SetPositionZ(int c,int h,int l,int r,int w,int wl,int wr,int hh,int hb,int ht)
	{
		m_Cloth->GetRender()->SetPositionZ(c);
		m_HandL->GetRender()->SetPositionZ(l);
		m_HandR->GetRender()->SetPositionZ(r);
		m_Head->GetRender()->SetPositionZ(h);
		m_HorseTail->GetRender()->SetPositionZ(ht);
		m_HorseHead->GetRender()->SetPositionZ(hh);
		m_HorseBack->GetRender()->SetPositionZ(hb);
		m_DualWeaponL->GetRender()->SetPositionZ(wl);
		m_DualWeaponR->GetRender()->SetPositionZ(wr);
		m_OneHandWeapon->GetRender()->SetPositionZ(w);
		m_TwoHandWeapon->GetRender()->SetPositionZ(w);
	}
	void Character::refreshOrder()
	{
		int c = 0,
			h = 0,
			l = 0,
			r = 0,
			wl = 0,
			wr = 0,
			w = 0,
			hh = 0,
			hb = 0,
			ht = 0;
		bool face_down = m_Direction == 0,
			face_left = m_Direction == 1 || m_Direction == 2 || m_Direction == 3,
			face_up = m_Direction == 4,
			face_right = m_Direction == 5 || m_Direction == 6 || m_Direction == 7;
		bool no_weapon = m_Action->OneHandWeaponID == 0 && 
			m_Action->TwoHandWeaponID == 0&&
			m_Action->DualWeaponID == 0,
			single_weapon = m_Action->DualWeaponID == 0,
			double_weapon = m_Action->DualWeaponID != 0;
		bool idle = m_Action->ID == 60;
		if(m_Action->HorseID == 0)// no horse
		{
			if(no_weapon)
			{
				if(face_down){
					c = 0; h = 1; l = 2; r = 3;
				}
				else if(face_left){
					r = 0; c = 1; h = 2; l = 3;
				}
				else if(face_up){
					l = 0; r = 1; c = 2; h = 3;
				}
				else{
					l = 0; c = 1; h = 2; r = 3;
				}
			}
			else if(single_weapon)
			{
				if(face_down)
				{
					if(idle){
						w = 0; c = 1; l = 2; r = 3; h = 4;
					}
					else{
						c = 0; l = 1; r = 2; h = 3; w = 4;
					}
				}
				else if(face_left)
				{
					w = 0; r = 1; c = 2; h = 3; l = 4;
				}
				else if(face_up)
				{
					if(idle){
						l = 0; c = 1; r = 2; h = 3; w = 4;
					}
					else{
						w = 0; l = 1; c = 2; r = 3; h = 4;
					}
				}
				else{
					l = 0; c = 1; h = 2; r = 3; w = 4;
				}
			}
			else// double weapon
			{
				if(face_down){
					c = 0; h = 1; l = 2; wl = 3; r = 4; wr = 5;
				}
				else if(face_left){
					wr = 0; r = 1; c = 2; h = 3; l = 4; wl = 5; 
				}
				else if(face_up){
					wl = 0; l = 1; wr = 2; r = 3; c = 4; h = 5;
				}
				else{
					l = 0; wl = 1; c = 2; h = 3; r = 4; wr = 5;
				}
			}
		}
		else// ride horse
		{
			if(no_weapon)
			{
				if(face_down){
					ht = 0; hb = 1; c = 2; h = 3; l = 4; r = 5; hh = 6;
				}
				else if(face_left){
					r = 0; ht = 1; hh = 2; hb = 3; c = 4; h = 5; l = 6;
				}
				else if(face_up){
					hb = 0; hh = 1; l = 2; r = 3; c = 4; h = 5; ht = 6;
				}
				else{
					ht = 0; hb = 1; l = 2; c = 3; hh = 4; h = 5; r = 6;
				}
			}
			else if(single_weapon)
			{
				if(face_down){
					ht = 0; hb = 1; c = 2; h = 3; w = 4; l = 5; r = 6; hh = 7;
				}
				else if(face_left){
					w = 0; r = 1; ht = 2; hb = 3; hh = 4; c = 5; h = 6; l = 7;
				}
				else if(face_up){
					hh = 0; hb = 1; l = 2; r = 3; c = 4; h = 5; ht = 6; w = 7;
				}
				else{
					ht = 0; hb = 1; l = 2; c = 3; hh = 4; h = 5; r = 6; w = 7;
				}
			}
			else// double weapon
			{
				if(face_down){
					ht = 0;hb = 1;c = 2; h = 3; l = 4; wl = 5; r = 6; wr = 7;hh = 8;
				}
				else if(face_left){
					wr = 0; r = 1; ht = 2;hb = 3;hh = 4;c = 5; h = 6; l = 7; wl = 8;
				}
				else if(face_up){
					hh = 0;hb = 1;wl = 2; l = 3; wr =4; r = 5; c = 6; h = 7;ht = 8;
				}
				else{
					ht = 0;hb = 1;l = 2; wl = 3; c = 4; h = 5; r = 6; hh = 7;wr = 8;
				}
			}
		}
		SetPositionZ(c, h, l, r, w, wl, wr, hh, hb, ht);
	}
	void Character::SetAnimationTimeRUN(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {30,31,32,33,17};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {9,14};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 6;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeWALK(float time)
	{
		// walk one, walk two, walk double, walk horse, walk
		int character_id[5] = {40,41,42,43,18};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {10,18};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 7;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeATK(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {1,2,4,6,12};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {1,4};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 1;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeATKCRIT(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {1,3,5,7,13};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {2,5};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 2;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeHURT(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {19,20,21,22,15};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {7,11};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 4;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeCAST(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {25,26,27,28,16};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {8,12};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 5;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
	void Character::SetAnimationTimeJUMP(float time)
	{
		int character_id = 23;
		m_Cloth->SetAnimationTime(character_id,time);
		m_HandL->SetAnimationTime(character_id,time);
		m_HandR->SetAnimationTime(character_id,time);
		m_Head->SetAnimationTime(character_id,time);
	}
	void Character::SetAnimationTimeFALL(float time)
	{
		// atk, atk one, atk two, atk double, atk horse
		int character_id[5] = {8,9,10,11,14};
		for(int i=0;i<5;i++)
		{
			m_Cloth->SetAnimationTime(character_id[i],time);
			m_HandL->SetAnimationTime(character_id[i],time);
			m_HandR->SetAnimationTime(character_id[i],time);
			m_Head->SetAnimationTime(character_id[i],time);
		}
		// atk, atk horse
		int weapon_id[2] = {3,6};
		for(int i=0;i<2;i++)
		{
			m_OneHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_TwoHandWeapon->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponL->SetAnimationTime(weapon_id[i],time);
			m_DualWeaponR->SetAnimationTime(weapon_id[i],time);
		}
		int horse_id = 3;
		m_HorseHead->SetAnimationTime(horse_id,time);
		m_HorseBack->SetAnimationTime(horse_id,time);
		m_HorseTail->SetAnimationTime(horse_id,time);
	}
}