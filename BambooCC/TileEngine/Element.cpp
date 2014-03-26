#include "Element.h"
#include "..\pugiXML\pugixml.hpp"
#include "..\Utilities.h"
namespace TileEngine
{
	Element::Element()
	{
		m_Render = new ElementRender();
	}
	Element::~Element()
	{
	}
	void Element::LoadXml(const char* path)
	{
		pugi::xml_document element_file;
		pugi::xml_parse_result result = element_file.load_file(path);
		if(!result)
		{
			return;
		}
		char* folderPath = Utilities::getParentFolder(path);
		pugi::xml_node rootTAG = element_file.child("element");
		{
			float ax, ay, w, h;
			ax = rootTAG.attribute("anchor_x").as_float();
			ay = rootTAG.attribute("anchor_y").as_float();
			w = rootTAG.attribute("width").as_float();
			h = rootTAG.attribute("height").as_float();
			ay = h-ay;
			m_Render->SetAnchor(ax,ay);
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
			m_Render->AddSprite(texture_path.c_str(),anchor_x,anchor_y,offset_x,offset_y);
		}
	}
	void Element::SetAnchor(int anchor_x, int anchor_y)
	{
		m_Render->SetAnchor(anchor_x,anchor_y);
	}
	void Element::AddSprite(const char* texturePath, 
		int anchor_x, int anchor_y, int offset_x, int offset_y)
	{
		m_Render->AddSprite(texturePath,anchor_x,anchor_y,offset_x,offset_y);
	}
	void Element::SetPosition(short x, short y)
	{
		m_PositionX = x;
		m_PositionY = y;
		m_Render->SetPosition(x,y);
	}
}