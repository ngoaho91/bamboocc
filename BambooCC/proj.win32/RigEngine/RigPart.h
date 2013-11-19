#ifndef RIGPART_H
#define RIGPART_H
#include <string>
#include "RigPartRender.h"
namespace RigEngine
{
	enum RigPartName
	{
		RP_CHARACTER_CLOTH,
		RP_CHARACTER_HANDL,
		RP_CHARACTER_HANDR,
		RP_CHARACTER_HEAD,
		//RP_CHARACTER_CAPE,
		RP_WEAPON_ONE,
		RP_WEAPON_TWO,
		RP_WEAPON_DUALL,
		RP_WEAPON_DUALR,
		RP_HORSE_HEAD,
		RP_HORSE_BACK,
		RP_HORSE_TAIL
	};

	enum Gender
	{
		MALE,
		FEMALE
	};
	class RigPart
	{
	private:
		Gender			m_Gender;
		char*			m_Name;
		RigPartName		m_RigPartName;
		short			m_DirectionID;
		short			m_ActionID;
	public:
		RigPartRender*	m_Render;
	public:
		RigPart(RigPartName part_name=RP_CHARACTER_CLOTH, 
			Gender gender=MALE, char* name="");
		RigPartRender* GetRender(){ return m_Render;}
		void ResetRender();
		string GetFilePath();
		void SetGender(Gender gender);
		void SetName(char* name);
		void SetAction(short action);
		void SetDirection(short direction);
		void SetAnimationTime(short actionID, float time);
		friend class CharacterRender;
	};
}
#endif