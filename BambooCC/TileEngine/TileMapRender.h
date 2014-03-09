#ifndef TilemapRender_h
#define TilemapRender_h
#include "cocos2d.h"
#include "vector"
using namespace std;
using namespace cocos2d;
namespace TileEngine
{
	class TilemapRender
	{
		friend class Tilemap;
	private:
		string			m_SetID;
		int				m_MapWidth;
		int				m_MapHeight;
		short**			m_MatrixID;
		CCSprite***		m_MatrixAB;
		CCSprite*		m_SpriteB;
		CCSprite*		m_SpriteAB;
		CCNode*			m_ParentNode;
		void			setTile(int x, int y, int id);
		void			generateBackground();
	public:
						TilemapRender(int width, int height);
						~TilemapRender();
		void			SetParentNode(CCNode* parent);
		void			Resize(int width, int height);
		int				GetWidth(){ return m_MapWidth;}
		int				GetHeight(){ return m_MapHeight;}
		void			SetTileset(const char* setName);
	};
}
#endif