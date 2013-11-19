#include <algorithm>
#include "Map.h"
#include "../pugiXML/pugixml.hpp"
#include "../Utilities/Utilities.h"
#include "../PathEngine/PathFinderWorld.h"
namespace FightEngine
{
	Map::Map(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		m_NavMesh = new PathEngine::Mesh(width, height);
		m_Tilemap = new Tilemap(1,1);
		m_Render = new MapRender();
		m_Render->m_Tilemap = m_Tilemap->GetRender();
		system("cls");
		return;
		{// this for testing only
			vector<Node*> v;
			v.push_back(new Node(160,60));
			v.push_back(new Node(160,180));
			v.push_back(new Node(220,180));
			v.push_back(new Node(220,240));
			v.push_back(new Node(160,240));
			v.push_back(new Node(160,360));
			v.push_back(new Node(220,360));
			v.push_back(new Node(220,300));
			v.push_back(new Node(340,300));
			v.push_back(new Node(340,360));
			v.push_back(new Node(280,360));
			v.push_back(new Node(280,420));
			v.push_back(new Node(340,420));
			v.push_back(new Node(340,480));
			v.push_back(new Node(220,480));
			v.push_back(new Node(220,420));
			v.push_back(new Node(160,420));
			v.push_back(new Node(160,540));
			v.push_back(new Node(640,540));
			v.push_back(new Node(640,420));
			v.push_back(new Node(580,420));
			v.push_back(new Node(580,480));
			v.push_back(new Node(460,480));
			v.push_back(new Node(460,420));
			v.push_back(new Node(520,420));
			v.push_back(new Node(520,360));
			v.push_back(new Node(460,360));
			v.push_back(new Node(460,300));
			v.push_back(new Node(580,300));
			v.push_back(new Node(580,360));
			v.push_back(new Node(640,360));
			v.push_back(new Node(640,240));
			v.push_back(new Node(580,240));
			v.push_back(new Node(580,180));
			v.push_back(new Node(640,180));
			v.push_back(new Node(640,60));
			v.push_back(new Node(580,60));
			v.push_back(new Node(580,120));
			v.push_back(new Node(520,120));
			v.push_back(new Node(520,60));
			v.push_back(new Node(460,60));
			v.push_back(new Node(460,180));
			v.push_back(new Node(520,180));
			v.push_back(new Node(520,240));
			v.push_back(new Node(280,240));
			v.push_back(new Node(280,180));
			v.push_back(new Node(340,180));
			v.push_back(new Node(340,60));
			v.push_back(new Node(280,60));
			v.push_back(new Node(280,120));
			v.push_back(new Node(220,120));
			v.push_back(new Node(220,60));
			reverse(v.begin(),v.end());
			m_NavMesh->AddPolygon(v);
			m_NavMesh->BuildVisiGraph();
			m_Render->m_PathRender->SetMesh(m_NavMesh);
		}
	}
	Map::~Map()
	{
	}
	void Map::ResetRender()
	{
		m_Tilemap->ResetRender();
	}
	void Map::LoadXml(const char* xmlFile)
	{
		pugi::xml_document element_file;
		pugi::xml_parse_result result = element_file.load_file(xmlFile);
		if(!result)
		{
			return;
		}
		char* folderPath = Utilities::getParentFolder(xmlFile);
		pugi::xml_node rootTAG = element_file.child("map");
		pugi::xml_node elementsTAG = rootTAG.first_child();
		pugi::xml_node tilesTAG = elementsTAG.next_sibling();
		int width = tilesTAG.attribute("width").as_int();
		int height = tilesTAG.attribute("height").as_int();
		{// load tiles
			int width = tilesTAG.attribute("width").as_int();
			int height = tilesTAG.attribute("height").as_int();
			const char* tileset = tilesTAG.attribute("tileset").as_string();
			Resize(width, height);
			SetTileset(tileset);
			int count = tilesTAG.attribute("count").as_int();
			pugi::xml_node tileTAG = tilesTAG.first_child();
			for(;tileTAG; tileTAG = tileTAG.next_sibling())
			{
				int x = tileTAG.attribute("x").as_int();
				int y = tileTAG.attribute("y").as_int();
				int id = tileTAG.attribute("id").as_int();
				SetTileID(x,y,id);
			}
		}
		{// load elements
			int count = elementsTAG.attribute("count").as_int();
			pugi::xml_node elementTAG = elementsTAG.first_child();
			int h64 = height*64;
			for(;elementTAG; elementTAG = elementTAG.next_sibling())
			{
				const char* file = elementTAG.attribute("file").as_string();
				int x = elementTAG.attribute("x").as_int();
				int y = elementTAG.attribute("y").as_int();
				AddElement(file,x,h64-y);
			}
		}
		
		BuildVisiGraph();
		ResetRender();
	}
	void Map::Resize(int width, int height)
	{
		m_Tilemap->Resize(width,height);
	}
	void Map::SetTileset(const char* setName)
	{
		m_Tilemap->SetTileset(setName);
	}
	void Map::AddElement(const char* xmlFile, int x, int y)
	{
		Element* element = new Element();
		element->SetPosition(x,y);
		m_Elements.push_back(element);
		element->GetRender()->SetParentNode(m_Render->m_ParentNode);
		m_Render->m_Elements.push_back(element->GetRender());
		pugi::xml_document element_file;
		pugi::xml_parse_result result = element_file.load_file(xmlFile);
		if(!result)
		{
			return;
		}
		char* folderPath = Utilities::getParentFolder(xmlFile);
		pugi::xml_node rootTAG = element_file.child("element");
		{
			float ax, ay, w, h;
			ax = rootTAG.attribute("anchor_x").as_float();
			ay = rootTAG.attribute("anchor_y").as_float();
			w = rootTAG.attribute("width").as_float();
			h = rootTAG.attribute("height").as_float();
			ay = h-ay;
			element->SetAnchor(ax,ay);
		}
		pugi::xml_node spritesTAG = rootTAG.first_child();
		pugi::xml_node spriteTAG = spritesTAG.first_child();
		for(;spriteTAG; spriteTAG = spriteTAG.next_sibling())
		{
			int offset_x = spriteTAG.attribute("offset_x").as_int();
			int offset_y = spriteTAG.attribute("offset_y").as_int();
			int anchor_x = spriteTAG.attribute("anchor_x").as_int();
			int anchor_y = spriteTAG.attribute("anchor_y").as_int();
			string texture_path = folderPath;
			texture_path += spriteTAG.attribute("texture").as_string();
			element->AddSprite(texture_path.c_str(),anchor_x,anchor_y,offset_x,offset_y);
		}
		pugi::xml_node polygonsTAG = spritesTAG.next_sibling();
		pugi::xml_node polygonTAG = polygonsTAG.first_child();
		for(;polygonTAG; polygonTAG = polygonTAG.next_sibling())
		{
			vector<Node*> v;
			pugi::xml_node vertexTAG = polygonTAG.first_child();
			for(;vertexTAG;vertexTAG = vertexTAG.next_sibling())
			{
				int vx = vertexTAG.attribute("x").as_int();
				int vy = vertexTAG.attribute("y").as_int();
				v.push_back(new Node(x+vx,y-vy));
			}
			m_NavMesh->AddPolygon(v);
			PathEngine::World::instance()->GetMesh()->AddPolygon(v);
		}
	}
	vector<Element*> Map::GetElements()
	{
		return m_Elements;
	}
	vector<Element*>* Map::GetElementsPointer()
	{
		return &m_Elements;
	}
	void Map::BuildVisiGraph()
	{
		m_NavMesh->BuildVisiGraph();
		m_Render->m_PathRender->SetMesh(m_NavMesh);
		PathEngine::World::instance()->GetMesh()->BuildVisiGraph();
	}
	void Map::RemoveElement(Element* element)
	{
	}
	void Map::SetTileA(int x, int y)
	{
		m_Tilemap->SetTileA(x,y);
	}
	void Map::SetTileB(int x, int y)
	{
		m_Tilemap->SetTileB(x,y);
	}
	void Map::SetTileID(int x, int y, int id)
	{
		m_Tilemap->SetTileID(x,y,id);
	}
}