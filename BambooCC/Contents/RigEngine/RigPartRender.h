#ifndef RIGPARTRENDER_H
#define RIGPARTRENDER_H
#include "cocos2d.h"
#include <vector>
#include <string>
using namespace std;
USING_NS_CC;
namespace RigEngine
{
	class RigPartRender
	{
		friend class CharacterRender;
	private:
		CCNode*					m_ParentNode;
		CCSprite*				m_Sprite;
		vector<CCAction*>		m_Actions;
		vector<bool>			m_LoadedActions;
		vector<CCTexture2D*>	m_Textures;
		vector<bool>			m_LoadedTextures;
		vector<int>				m_ActionGroup;
		vector<string>			m_TexturePaths;
		short m_GroupCount;
		short m_CurrentGroup;
		short m_ActionID;
		short m_DirectionID;
		string m_XmlPath;
	public:
		RigPartRender();
		RigPartRender(const char* fileName);
		~RigPartRender();
		void SetParentNode(CCNode* parent);
		void SetPositionXY(int x, int y);
		void SetPositionZ(int z);
		void SetVisible(bool value);
		void SetXmlPath(const char* path);
		void SetDirection(short direction);
		void SetActionID(short action);
		void SetAnimationTime(short actionID, float time);
	private:
		void loadAction(int actionID);
		void unloadGroup(int groupID);
		void unloadAll();
	};
}
#endif