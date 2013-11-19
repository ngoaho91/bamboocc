#include "RigPart.h"
#include <sstream>

namespace RigEngine
{
	RigPart::RigPart(RigPartName part_name, Gender gender, char* name)
	{
		m_RigPartName = part_name;
		m_Name = name;
		m_Gender = gender;
		m_Render = new RigPartRender();
	}
	void RigPart::ResetRender()
	{
		string path = GetFilePath();
		//cout<<"RigPart::ResetRender path="<<path<<endl;
		m_Render->SetXmlPath(path.c_str());
	}
	string RigPart::GetFilePath()
	{
		char* source = "EQUIP/";
		ostringstream path;
		path<<source;
		switch(m_RigPartName)
		{
		case RP_CHARACTER_CLOTH:
			if(m_Gender==MALE)
			{
				path<<"character_male_cloth";
			}
			else
			{
				path<<"character_female_cloth";
			}
			break;
		case RP_CHARACTER_HANDL:
			if(m_Gender==MALE)
			{
				path<<"character_male_handl";
			}
			else
			{
				path<<"character_female_handl";
			}
			break;
		case RP_CHARACTER_HANDR:
			if(m_Gender==MALE)
			{
				path<<"character_male_handr";
			}
			else
			{
				path<<"character_female_handr";
			}
			break;
		case RP_CHARACTER_HEAD:
			if(m_Gender==MALE)
			{
				path<<"character_male_head";
			}
			else
			{
				path<<"character_female_head";
			}
			break;
		case RP_WEAPON_ONE:
			if(m_Gender==MALE)
			{
				path<<"weapon_male_one";
			}
			else
			{
				path<<"weapon_female_one";
			}
			break;
		case RP_WEAPON_TWO:
			if(m_Gender==MALE)
			{
				path<<"weapon_male_two";
			}
			else
			{
				path<<"weapon_female_two";
			}
			break;
		case RP_WEAPON_DUALL:
			if(m_Gender==MALE)
			{
				path<<"weapon_male_duall";
			}
			else
			{
				path<<"weapon_female_duall";
			}
			break;
		case RP_WEAPON_DUALR:
			if(m_Gender==MALE)
			{
				path<<"weapon_male_dualr";
			}
			else
			{
				path<<"weapon_female_dualr";
			}
			break;
		case RP_HORSE_HEAD:
			path<<"horse_head";
			break;
		case RP_HORSE_BACK:
			path<<"horse_back";
			break;
		case RP_HORSE_TAIL:
			path<<"horse_tail";
			break;
		default:
			if(m_Gender==MALE)
			{
				path<<"character_male_cloth";
			}
			else
			{
				path<<"character_female_cloth";
			}
			break;
		}
		path<<"/"<<m_Name<<"/"<<m_Name<<".xml";
		return path.str();
	}
	void RigPart::SetGender(Gender gender)
	{
		if (m_Gender != gender)
		{
			m_Gender = gender;
		}
	}
	void RigPart::SetName(char* name)
	{
		if(m_Name != name)
		{
			m_Name = name;
		}
	}

	void RigPart::SetAction(short action)
	{
		if(m_ActionID != action)
		{
			m_ActionID = action;
		}
		m_Render->SetActionID(m_ActionID);
	}
	void RigPart::SetDirection(short direction)
	{
		m_DirectionID = direction;
		m_Render->SetDirection(m_DirectionID);
	}
	void RigPart::SetAnimationTime(short actionID, float time)
	{
		m_Render->SetAnimationTime(actionID,time);
	}
}