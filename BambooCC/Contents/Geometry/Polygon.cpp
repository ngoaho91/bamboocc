#include "Polygon.h"
#include <algorithm>
namespace Geometry
{
	/*------------------------------------------------
	// class Polygon
	// 29th JUL 2013
	// describe a polygon, convex or concave, no hole
	------------------------------------------------*/
	Polygon::Polygon()
		:QuadObject()
	{
		m_ObjectType = QOT_POLYGON;
	}
	Polygon::~Polygon()
	{
	}
	void Polygon::CalculateAABB()
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
	bool Polygon::PointInsideBB(Node* node)
	{
		return m_BoundingBox->TestPointInside(node->X(), node->Y());
	}
	Polygon::iterator Polygon::GetNext(Polygon::iterator it)
	{
		Polygon::iterator it1 = it + 1;
		if (it1 == this->end()) return this->begin();
		return it;
	}
	Polygon::iterator Polygon::GetPrevious(Polygon::iterator it)
	{
		Polygon::iterator it1 = it - 1;
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
	ConvexHull::ConvexHull(Polygon* polygon)
	{
		Polygon::iterator it = polygon->begin();
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
}