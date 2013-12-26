#include "QuadObject.h"
#include "QuadTree.h"
namespace Geometry
{
	QuadObject::QuadObject()
	{
		m_ParentNode = 0;
	}
	QuadObject::QuadObject(int min_x, int min_y, int max_x, int max_y)
	{
		SetBoundingBox(min_x, min_y, max_x, max_y);
		m_ParentNode = 0;
	}
	QuadObject::~QuadObject()
	{
	}
	void QuadObject::SetParentNode(QuadTree* parent)
	{
		m_ParentNode = parent;
	}
	void QuadObject::SetBoundingBox(Rectangle* rect)
	{
		m_BoundingBox = rect;
	}
	void QuadObject::SetBoundingBox(int min_x, int min_y, int max_x, int max_y)
	{
		m_BoundingBox = new Rectangle(min_x,min_y,max_x,max_y);
	}
	void QuadObject::SetPosition(int x, int y)
	{
		int w = m_BoundingBox->GetWidth();
		int h = m_BoundingBox->GetHeight();
		m_BoundingBox->SetMinX(x);
		m_BoundingBox->SetMinY(y);
		m_BoundingBox->SetMaxX(x+w);
		m_BoundingBox->SetMaxY(y+w);
		if(m_ParentNode)
		{
			m_ParentNode->UpdateObject(this);
		}
	}
}