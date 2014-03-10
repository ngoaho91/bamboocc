#include "OpenPolygon.h"
namespace Geometry
{
	OpenPolygon::OpenPolygon()
	{
	}
	OpenPolygon::OpenPolygon(Polygon* polygon)
	{
		Polygon::iterator it = polygon->begin();
		for(;it!=polygon->end();it++)
		{
			this->push_back(*it);
		}
		ResetPortal();
	}
	OpenPolygon::~OpenPolygon()
	{
	}
	void OpenPolygon::ResetPortal()
	{
		const unsigned int size = this->size();
		m_Portal = new bool[size];
		memset(m_Portal, false, sizeof(m_Portal));
	}
	
}