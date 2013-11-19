#ifndef TilemapLoader_h
#define TilemapLoader_h
#include "TileMap.h"
#include "Element.h"
#include "..\pugiXML\pugixml.hpp"
namespace TileEngine
{
	class TilemapLoader
	{
	private:
		vector<Element*>	mListElement;
		Tilemap*			mTileMap;
	public:
		TilemapLoader();
		~TilemapLoader();
		void LoadXml();
	};
}
#endif