#ifndef Tilemap_h
#define Tilemap_h
#include "string"
#include "vector"
#include "TilemapRender.h"
using namespace std;
namespace TileEngine
{
	class TileInfo
	{
		friend class Tilemap;
	private:
		bool upL;
		bool upR;
		bool downL;
		bool downR;
		int	random(int n) { return (double)rand()/(RAND_MAX+1)*n;}
	public:
		TileInfo();
		int GetID();
		void SetID(int id);
		void SetUpL(bool value){ upL = value;}
		void SetUpR(bool value){ upR = value;}
		void SetDownL(bool value){ downL = value;}
		void SetDownR(bool value){ downR = value;}
	};
	class Tilemap
	{
	private:
		bool**			m_MatrixA;
		short**			m_MatrixAB;
		int				m_MapWidth;
		int				m_MapHeight;
		TilemapRender*	m_Render;
		void			CalculateTransition(int x, int y);
	public:
						Tilemap(int width, int height);
						~Tilemap();
		TilemapRender*	GetRender(){ return m_Render;}
		void			ResetRender();
	public:
		void            Resize(int width, int height);
		short           GetTileID(int x, int y){ return m_MatrixAB[x][y];}
		void            SetTileID(int x, int y, short id){ m_MatrixAB[x][y] = id;}
		void			SetTileA(int x, int y);
		void			SetTileB(int x, int y);
		bool            GetTileA(int x, int y){ return m_MatrixA[x][y];}
		void            SetTileA(int x, int y, bool value){ m_MatrixA[x][y] = value;}
		void			SetTileset(const char* setName);
		int				GetWidth(){ return m_MapWidth;}
		int				GetHeight(){ return m_MapHeight;}
		
		
	};
}
#endif