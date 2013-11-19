#ifndef _Action_H_
#define _Action_H_
namespace RigEngine
{
	class Action
	{
	public:
		int ID, FrameCount, ClothID, OneHandWeaponID, 
			TwoHandWeaponID, DualWeaponID, HorseID;
		Action()
		{
			ID = 1;
			FrameCount = 18;
			ClothID = 1;
			OneHandWeaponID = 0;
			TwoHandWeaponID = 0;
			DualWeaponID = 0;
			HorseID = 0;
		}
		Action( int id,int frame,int cloth,int oneHand,int twoHand,int dualWeapon,int horse )
		{
			ID = id;
			FrameCount = frame;
			ClothID = cloth;
			OneHandWeaponID = oneHand;
			TwoHandWeaponID = twoHand;
			DualWeaponID = dualWeapon;
			HorseID = horse;
		}

		// F = female, M = male, O = one hand(weapon), T = two hand, D = double, W = weapon

		// 38 male action

		static inline Action* AttackM() { return new Action(1, 18, 1, 0, 0, 0, 0); }
		static inline Action* AttackOWCritM() { return new Action(2, 16, 2, 1, 0, 0, 0); }
		static inline Action* AttackOWM() { return new Action(3, 14, 3, 2, 0, 0, 0); }
		static inline Action* AttackTWCritM() { return new Action(4, 12, 4, 0, 1, 0, 0); }
		static inline Action* AttackTWM() { return new Action(5, 12, 5, 0, 2, 0, 0); }
		static inline Action* AttackDWCritM() { return new Action(6, 16, 6, 0, 0, 1, 0); }
		static inline Action* AttackDWM() { return new Action(7, 12, 7, 0, 0, 2, 0); }
		static inline Action* FallM() { return new Action(8, 12, 8, 0, 0, 0, 0); }
		static inline Action* FallOWM() { return new Action(9, 11, 9, 3, 0, 0, 0); }
		static inline Action* FallTWM() { return new Action(10, 15, 10, 0, 3, 0, 0); }
		static inline Action* FallDWM() { return new Action(11, 18, 11, 0, 0, 3, 0); }

		static inline Action* HurtM() { return new Action(40, 9, 19, 0, 0, 0, 0); }
		static inline Action* HurtOWM() { return new Action(41, 8, 20, 11, 0, 0, 0); }
		static inline Action* HurtTWM() { return new Action(42, 7, 21, 0, 11, 0, 0); }
		static inline Action* HurtDWM() { return new Action(43, 12, 22, 0, 0, 11, 0); }
		static inline Action* JumpM() { return new Action(44, 20, 23, 0, 0, 0, 0); }
		static inline Action* ThrowDaggerM() { return new Action(45, 16, 24, 0, 0, 0, 0); }
		static inline Action* CastM() { return new Action(46, 12, 25, 0, 0, 0, 0); }
		static inline Action* CastOWM() { return new Action(47, 12, 26, 12, 0, 0, 0); }
		static inline Action* CastTWM() { return new Action(48, 13, 27, 0, 12, 0, 0); }
		static inline Action* CastDWM() { return new Action(49, 16, 28, 0, 0, 12, 0); }

		static inline Action* RunM() { return new Action(54, 11, 30, 0, 0, 0, 0); }
		static inline Action* RunOWM() { return new Action(55, 11, 31, 14, 0, 0, 0); }
		static inline Action* RunTWM() { return new Action(56, 11, 32, 0, 14, 0, 0); }
		static inline Action* RunDWM() { return new Action(57, 11, 33, 0, 0, 14, 0); }
		static inline Action* IdleM() { return new Action(58, 15, 34, 0, 0, 0, 0); }
		static inline Action* IdleOWM() { return new Action(59, 15, 35, 15, 0, 0, 0); }
		static inline Action* IdleTWM() { return new Action(60, 15, 35, 0, 15, 0, 0); }
		static inline Action* IdleDWM() { return new Action(61, 15, 35, 0, 0, 15, 0); }
		static inline Action* FightIdleM() { return new Action(62, 11, 36, 0, 0, 0, 0); }
		static inline Action* FightIdleOWM() { return new Action(63, 11, 37, 17, 0, 0, 0); }
		static inline Action* FightIdleTWM() { return new Action(64, 11, 38, 0, 17, 0, 0); }
		static inline Action* FightIdleDWM() { return new Action(65, 11, 39, 0, 0, 17, 0); }
		static inline Action* WalkM() { return new Action(66, 15, 40, 0, 0, 0, 0); }
		static inline Action* WalkOWM() { return new Action(67, 15, 41, 18, 0, 0, 0); }
		static inline Action* WalkTWM() { return new Action(68, 15, 42, 0, 18, 0, 0); }
		static inline Action* WalkDWM() { return new Action(69, 15, 43, 0, 0, 18, 0); }
		static inline Action* ZenM() { return new Action(70, 9, 44, 0, 0, 0, 0); }

		// 38 female action

		static inline Action* AttackF() { return new Action(1, 12, 1, 0, 0, 0, 0); }
		static inline Action* AttackOWCritF() { return new Action(2, 13, 2, 1, 0, 0, 0); }
		static inline Action* AttackOWF() { return new Action(3, 13, 3, 2, 0, 0, 0); }
		static inline Action* AttackTWCritF() { return new Action(4, 13, 4, 0, 1, 0, 0); }
		static inline Action* AttackTWF() { return new Action(5, 12, 5, 0, 2, 0, 0); }
		static inline Action* AttackDWCritF() { return new Action(6, 16, 6, 0, 0, 1, 0); }
		static inline Action* AttackDWF() { return new Action(7, 12, 7, 0, 0, 2, 0); }
		static inline Action* FallF() { return new Action(8, 13, 8, 0, 0, 0, 0); }
		static inline Action* FallOWF() { return new Action(9, 15, 9, 3, 0, 0, 0); }
		static inline Action* FallTWF() { return new Action(10, 10, 10, 0, 3, 0, 0); }
		static inline Action* FallDWF() { return new Action(11, 10, 11, 0, 0, 3, 0); }

		static inline Action* HurtF() { return new Action(40, 8, 19, 0, 0, 0, 0); }
		static inline Action* HurtOWF() { return new Action(41, 8, 20, 11, 0, 0, 0); }
		static inline Action* HurtTWF() { return new Action(42, 6, 21, 0, 11, 0, 0); }
		static inline Action* HurtDWF() { return new Action(43, 6, 22, 0, 0, 11, 0); }
		static inline Action* JumpF() { return new Action(44, 14, 23, 0, 0, 0, 0); }
		static inline Action* ThrowDaggerF() { return new Action(45, 12, 24, 0, 0, 0, 0); }
		static inline Action* CastF() { return new Action(46, 12, 25, 0, 0, 0, 0); }
		static inline Action* CastOWF() { return new Action(47, 10, 26, 12, 0, 0, 0); }
		static inline Action* CastTWF() { return new Action(48, 12, 27, 0, 12, 0, 0); }
		static inline Action* CastDWF() { return new Action(49, 10, 28, 0, 0, 12, 0); }

		static inline Action* RunF() { return new Action(54, 12, 30, 0, 0, 0, 0); }
		static inline Action* RunOWF() { return new Action(55, 12, 31, 14, 0, 0, 0); }
		static inline Action* RunTWF() { return new Action(56, 12, 32, 0, 14, 0, 0); }
		static inline Action* RunDWF() { return new Action(57, 12, 33, 0, 0, 14, 0); }
		static inline Action* IdleF() { return new Action(58, 10, 34, 0, 0, 0, 0); }
		static inline Action* IdleOWF() { return new Action(59, 8, 35, 15, 0, 0, 0); }
		static inline Action* IdleTWF() { return new Action(60, 8, 35, 0, 15, 0, 0); }
		static inline Action* IdleDWF() { return new Action(61, 8, 35, 0, 0, 15, 0); }
		static inline Action* FightIdleF() { return new Action(62, 8, 36, 0, 0, 0, 0); }
		static inline Action* FightIdleOWF() { return new Action(63, 12, 37, 17, 0, 0, 0); }
		static inline Action* FightIdleTWF() { return new Action(64, 8, 38, 0, 17, 0, 0); }
		static inline Action* FightIdleDWF() { return new Action(65, 8, 39, 0, 0, 17, 0); }
		static inline Action* WalkF() { return new Action(66, 12, 40, 0, 0, 0, 0); }
		static inline Action* WalkOWF() { return new Action(67, 12, 41, 18, 0, 0, 0); }
		static inline Action* WalkTWF() { return new Action(68, 12, 42, 0, 18, 0, 0); }
		static inline Action* WalkDWF() { return new Action(69, 12, 43, 0, 0, 18, 0); }
		static inline Action* ZenF() { return new Action(70, 12, 44, 0, 0, 0, 0); }

		// 32 horse action, when ride horse, male & fem are the same

		static inline Action* AttackHorseCrit() { return new Action(12, 12, 12, 0, 0, 0, 1); }
		static inline Action* AttackHorseOWCrit() { return new Action(13, 12, 12, 4, 0, 0, 1); }
		static inline Action* AttackHorseTWCrit() { return new Action(14, 12, 12, 0, 4, 0, 1); }
		static inline Action* AttackHorseDWCrit() { return new Action(15, 12, 12, 0, 0, 4, 1); }
		static inline Action* AttackHorse() { return new Action(16, 14, 13, 0, 0, 0, 2); }
		static inline Action* AttackHorseOW() { return new Action(17, 14, 13, 5, 0, 0, 2); }
		static inline Action* AttackHorseTW() { return new Action(18, 14, 13, 0, 5, 0, 2); }
		static inline Action* AttackHorseDW() { return new Action(19, 14, 13, 0, 0, 5, 2); }
		static inline Action* FallHorse() { return new Action(20, 14, 14, 0, 0, 0, 3); }
		static inline Action* FallHorseOW() { return new Action(21, 14, 14, 6, 0, 0, 3); }
		static inline Action* FallHorseTW() { return new Action(22, 14, 14, 0, 6, 0, 3); }
		static inline Action* FallHorseDW() { return new Action(23, 14, 14, 0, 0, 6, 3); }
		static inline Action* HurtHorse() { return new Action(24, 6, 15, 0, 0, 0, 4); }
		static inline Action* HurtHorseOW() { return new Action(25, 6, 15, 7, 0, 0, 4); }
		static inline Action* HurtHorseTW() { return new Action(26, 6, 15, 0, 7, 0, 4); }
		static inline Action* HurtHorseDW() { return new Action(27, 6, 15, 0, 0, 7, 4); }
		static inline Action* CastHorse() { return new Action(28, 12, 16, 0, 0, 0, 5); }
		static inline Action* CastHorseOW() { return new Action(29, 12, 16, 8, 0, 0, 5); }
		static inline Action* CastHorseTW() { return new Action(30, 12, 16, 0, 8, 0, 5); }
		static inline Action* CastHorseDW() { return new Action(31, 12, 16, 0, 0, 8, 5); }
		static inline Action* RunHorse() { return new Action(32, 10, 17, 0, 0, 0, 6); }
		static inline Action* RunHorseOW() { return new Action(33, 10, 17, 9, 0, 0, 6); }
		static inline Action* RunHorseTW() { return new Action(34, 10, 17, 0, 9, 0, 6); }
		static inline Action* RunHorseDW() { return new Action(35, 10, 17, 0, 0, 9, 6); }
		static inline Action* WalkHorse() { return new Action(36, 12, 18, 0, 0, 0, 7); }
		static inline Action* WalkHorseOW() { return new Action(37, 12, 18, 10, 0, 0, 7); }
		static inline Action* WalkHorseTW() { return new Action(38, 12, 18, 0, 10, 0, 7); }
		static inline Action* WalkHorseDW() { return new Action(39, 12, 18, 0, 0, 10, 7); }

		static inline Action* IdleHorse() { return new Action(50, 14, 29, 0, 0, 0, 8); }
		static inline Action* IdleHorseOW() { return new Action(51, 14, 29, 13, 0, 0, 8); }
		static inline Action* IdleHorseTW() { return new Action(52, 14, 29, 0, 13, 0, 8); }
		static inline Action* IdleHorseDW() { return new Action(53, 14, 29, 0, 0, 13, 8); }
	};
}
#endif