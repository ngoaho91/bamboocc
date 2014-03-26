#ifndef Map_h
#define Map_h
#include "../TileEngine/TileMap.h"
#include "../TileEngine/Element.h"
#include "MapRender.h"
using namespace TileEngine;
namespace FightEngine
{
	// TODO: implement these
	class Map
	{
	private:
		vector<Element*>	m_Elements;
		Tilemap*			m_Tilemap;
		MapRender*			m_Render;
		int					m_Width;
		int					m_Height;
	public:
		Map(int width, int height);
		~Map();
		MapRender*			GetRender(){ return m_Render;}
		void				ResetRender();
		void				LoadXml(const char* xmlFile);
	public:
		void				Resize(int width, int height);
		void				AddElement(const char* xmlFile, int x, int y);
		vector<Element*>	GetElements();
		vector<Element*>*	GetElementsPointer();
		void				BuildVisiGraph();
		void				RemoveElement(Element* element);
		void				SetTileset(const char* setName);
		void				SetTileA(int x, int y);
		void				SetTileB(int x, int y);
		void				SetTileID(int x, int y, int id);
	};
}
#endif