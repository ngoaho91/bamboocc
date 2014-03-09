#include "Tilemap.h"
namespace TileEngine
{
	TileInfo::TileInfo()
	{
		downR = false;
		upR = false;
		downL = false;
		upL = false;
	}
	int TileInfo::GetID()
	{
		int id;
		if(downL)// 1
		{
			if(downR)// 1 3
			{
				if(upL)// 1 3 7
				{
					if(upR)// 1 3 7 9
						id = 5;
					else// 1 3 7 
						id = 16;
				}
				else// 1 3
				{
					if(upR)// 1 3 9
						id = 18;
					else// 1 3
						id = random(1)==0?2:17;
				}
			}
			else// 1
			{
				if(upL)// 1 7
				{
					if(upR)// 1 7 9
						id = 10;
					else // 1 7
						id = random(1)==0?6:13;
				}
				else// 1
				{
					if(upR)// 1 9
						id = 20;
					else// 1
						id = 3;
				}
			}
		}
		else// null
		{
			if(downR)// 3
			{
				if(upL)// 3 7
				{
					if(upR)// 3 7 9
						id = 12;
					else// 3 7 
						id = 19;
				}
				else// 3
				{
					if(upR)// 3 9
						id = random(1)==0?4:15;
					else// 3
						id = 1;
				}
			}
			else// null
			{
				if(upL)// 7
				{
					if(upR)// 7 9
						id = random(1)==0?8:11;
					else // 7
						id = 9;
				}
				else// null
				{
					if(upR)// 9
						id = 7;
					else// null
						id = 14;
				}
			}
		}
		return id;
	}
	void TileInfo::SetID(int id)
	{
		downR = false;
		upR = false;
		downL = false;
		upL = false;
		switch(id)
		{
		case 1:
			downR = true;
			break;
		case 2:
		case 17:
			downR = true;
			downL = true;
			break;
		case 3:
			downL = true;
			break;
		case 4:
		case 15:
			downR = true;
			upR = true;
			break;
		case 5:
			downR = true;
			upR = true;
			downL = true;
			upL = true;
			break;
		case 6:
		case 13:
			downL = true;
			upL = true;
			break;
		case 7:
			upR = true;
			break;
		case 8:
		case 11:
			upR = true;
			upL = true;
			break;
		case 9:
			upL = true;
			break;
		case 10:
			upR = true;
			downL = true;
			upL = true;
			break;
		case 12:
			downR = true;
			upR = true;
			upL = true;
			break;
		case 14:
			break;
		case 16:
			downR = true;
			downL = true;
			upL = true;
			break;
		case 18:
			downR = true;
			upR = true;
			downL = true;
			break;
		case 19:
			downR = true;
			upL = true;
			break;
		case 20:
			downL = true;
			upR = true;
			break;
		}
	}
	Tilemap::Tilemap(int width, int height)
	{
		m_MapWidth = width;
		m_MapHeight = height;
		m_MatrixA = new bool*[width];
		m_MatrixAB = new short*[width];
		for(int i=0;i<width;i++)
		{
			m_MatrixA[i] = new bool[height];
			m_MatrixAB[i] = new short[height];
			for(int j=0;j<height;j++)
			{
				m_MatrixA[i][j] = 0;
				m_MatrixAB[i][j] = 14;
			}
		}
		m_Render = new TilemapRender(width,height);
	}
	Tilemap::~Tilemap()
	{
	}
	void Tilemap::ResetRender()
	{
		for(int i = 0;i< m_MapWidth; i++)
		{
			for(int j = 0;j< m_MapHeight; j++)
			{
				m_Render->setTile(i,j,m_MatrixAB[i][j]);
			}
		}
	}
	void Tilemap::Resize(int width, int height)
	{
		bool** pA;
		short**	pAB;
		pA = new bool*[width];
		pAB = new short*[width];
		for(int i=0;i<width;i++)
		{
			pA[i] = new bool[height];
			pAB[i] = new short[height];
			for(int j=0;j<height;j++)
			{
				if(i<m_MapWidth && j< m_MapHeight)
				{
					pA[i][j] = m_MatrixA[i][j];
					pAB[i][j] = m_MatrixAB[i][j];
				}
				else
				{
					pA[i][j] = 0;
					pAB[i][j] = 14;
				}
			}
		}
		for(int i=0;i<m_MapWidth;i++)
		{
			delete m_MatrixA[i];
			delete m_MatrixAB[i];
		}
		m_MatrixA = pA;
		m_MatrixAB = pAB;
		m_MapWidth = width;
		m_MapHeight = height;
		m_Render->Resize(width,height);
	}
	void Tilemap::SetTileA(int x, int y)
	{
		m_MatrixA[x][y] = 1;
		m_MatrixAB[x][y] = 5;
		CalculateTransition(x-1,y+1);
		CalculateTransition(x-1,y);
		CalculateTransition(x-1,y-1);
		CalculateTransition(x,y+1);
		CalculateTransition(x,y-1);
		CalculateTransition(x+1,y+1);
		CalculateTransition(x+1,y);
		CalculateTransition(x+1,y-1);
	}
	void Tilemap::CalculateTransition(int x, int y)
	{
		if(m_MatrixA[x][y])
			return;
		TileInfo corner1, corner2, corner3, corner4,
			corner6, corner7, corner8, corner9;
		corner1.SetID(m_MatrixAB[x-1][y+1]);
		corner2.SetID(m_MatrixAB[x][y+1]);
		corner3.SetID(m_MatrixAB[x+1][y+1]);
		corner4.SetID(m_MatrixAB[x-1][y]);
		corner6.SetID(m_MatrixAB[x+1][y]);
		corner7.SetID(m_MatrixAB[x-1][y-1]);
		corner8.SetID(m_MatrixAB[x][y-1]);
		corner9.SetID(m_MatrixAB[x+1][y-1]);
		// matA = [0,1]; matB = [0,20];
		TileInfo info;
		if(corner7.downR || corner4.upR || corner8.downL) info.SetUpL(true);
		if(corner8.downR || corner9.downL || corner6.upL) info.SetUpR(true);
		if(corner6.downL || corner3.upL || corner2.upR) info.SetDownR(true);
		if(corner4.downR || corner1.upR || corner2.upL) info.SetDownL(true);
		int id = info.GetID();
		m_MatrixAB[x][y] = id;
	}
	void Tilemap::SetTileB(int x, int y)
	{
		for (int i = x-1; i <= x+1;i++)
		{
			for (int j = y-1; j <= y+1;j++)
			{
				m_MatrixA[i][j] = 0;
				m_MatrixAB[i][j] = 14;
			}
		}
		for (int i = x-2; i <= x+2; i++)
		{
			for (int j = y-2; j <= y+2; j++)
			{
				CalculateTransition(i,j);
			}
		}
	}
	void Tilemap::SetTileset(const char* setName)
	{
		m_Render->SetTileset(setName);
	}
}