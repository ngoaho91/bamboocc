#ifndef Element_h
#define Element_h
#include <vector>
#include <string>
#include "ElementRender.h"

using namespace std;
namespace TileEngine
{
	class Element
	{
	private:
		ElementRender* m_Render;
		short m_PositionX, m_PositionY;
	public:
		Element();
		~Element();
		void LoadXml(const char* path);
		void SetAnchor(int anchor_x, int anchor_y);
		void AddSprite(const char* texturePath, int anchor_x, int anchor_y, int offset_x, int offset_y);
		void SetPosition(short x, short y);
		int GetPositionX(){ return m_PositionX;}
		int GetPositionY(){ return m_PositionY;}
		ElementRender* GetRender(){ return m_Render;}
	};
}
#endif