#include "Polygon.h"
#include <algorithm>
namespace Geometry
{
	/*------------------------------------------------
	// class SimplePolygon
	// 29th JUL 2013
	// describe a polygon, convex or concave, no hole
	------------------------------------------------*/
	SimplePolygon::SimplePolygon()
		:QuadObject()
	{
		m_ObjectType = QOT_POLYGON;
	}
	SimplePolygon::~SimplePolygon()
	{
	}
	void SimplePolygon::CalculateAABB()
	{
		int min_x, min_y, max_x, max_y;
		Nodes::iterator it = this->begin();
		Node* node = *(it++);
		min_x = max_x = node->X();
		min_y = max_y = node->Y();
		while (it != this->end())
		{
			node = *(it++);
			if (node->X() > max_x) max_x = node->X();
			if (node->X() < min_x) min_x = node->X();
			if (node->Y() > max_y) max_y = node->Y();
			if (node->Y() < min_y) min_y = node->Y();
		}
		SetBoundingBox(min_x, min_y, max_x, max_y);
	}
	bool SimplePolygon::PointInsideBB(Node* node)
	{
		return m_BoundingBox->TestPointInside(node->X(), node->Y());
	}
	SimplePolygon::iterator SimplePolygon::GetNext(SimplePolygon::iterator it)
	{
		SimplePolygon::iterator it1 = it + 1;
		if (it1 == this->end()) return this->begin();
		return it;
	}
	SimplePolygon::iterator SimplePolygon::GetPrevious(SimplePolygon::iterator it)
	{
		SimplePolygon::iterator it1 = it - 1;
		if (it1 == this->begin()) return this->end() - 1;
		return it;
	}
	/*------------------------------------------------
	// class ConvexHull
	// 11st JAN 2014
	// describe a convex hull
	------------------------------------------------*/
	ConvexHull::ConvexHull()
	{
		
	}
	ConvexHull::ConvexHull(SimplePolygon* polygon)
	{
		SimplePolygon::iterator it = polygon->begin();
		Node* first = *it;
		Node* last = *it++;
		this->push_back(last);
		for (; it != this->end();it++)
		{
			Node* node = *it;
			Node* next = *(polygon->GetNext(it));
			Node* prev = last;
			if (GetConvex(prev, node, next) == CR_CONVEX) continue;
			this->push_back(node);
			last = node;
		}
	}
	ConvexHull::~ConvexHull()
	{

	}
	/*------------------------------------------------
	// class Polygon
	// 29th JUL 2013
	// describe a polygon, convex or concave, has hole
	------------------------------------------------*/
	Polygon::Polygon()
		:QuadObject()
	{
		m_ObjectType = QOT_POLYGON;
		m_Outer = 0;
	}
	Polygon::~Polygon()
	{
	}
	void Polygon::CalculateAABB()
	{
		Rectangle* bb = m_Outer->GetBoundingBox();
		if (bb == 0) return;
		SetBoundingBox(bb);
	}
	void Polygon::SetOuter(SimplePolygon* polygon)
	{
		m_Outer = polygon;
	}
	void Polygon::AddInner(SimplePolygon* polygon)
	{
		m_Inners.push_back(polygon);
	}
}