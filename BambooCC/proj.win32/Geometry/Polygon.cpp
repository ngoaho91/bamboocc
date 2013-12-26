#include "Polygon.h"
namespace Geometry
{
	/*------------------------------------------------
	// class SimplePolygon
	// 29th JUL 2013
	// describe a polygon, convex or concave, no hole
	------------------------------------------------*/
	SimplePolygon::SimplePolygon()
		:QuadObject(0,0,20,20)
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
		while(it != this->end())
		{
			node = *(it++);
			if(node->X() > max_x) max_x = node->X();
			if(node->X() < min_x) min_x = node->X();
			if(node->Y() > max_y) max_y = node->Y();
			if(node->Y() < min_y) min_y = node->Y();
		}
		SetBoundingBox(min_x, min_y, max_x, max_y);
	}
	bool SimplePolygon::IsConvexNode(SimplePolygon::iterator it, bool outer)
	{
		SimplePolygon::iterator it1 = it + 1;
		SimplePolygon::iterator it2 = it - 1;
		Node* current = *it;
		Node* next;
		Node* prev;
		if (it1 == this->end())
		{
			next = *(this->begin());
		}
		else
		{
			next = *it1;
		}
		if (it == this->begin())
		{
			prev = *(this->end()-1);
		}
		else
		{
			prev = *it2;
		}
		IsConvex(prev, current, next, outer);
		return true;
	}
	
	/*------------------------------------------------
	 NAME: PointInPolygon
	 DATE: 29th JUL 2013
	 TASK: test point is in polygon
	 - edge = edge
	 - polygon = polygon
	 - consider_touch = consider point at border of the polygon as in
	-------------------------------------------------*/
	bool PointInPolygon(Node* node, SimplePolygon* polygon, bool consider_touch)
	{
		if(polygon->size() < 4) return false;
		int x = node->X();
		int y = node->Y();
		bool c = false;
		Rectangle* bb = polygon->GetBoundingBox();
		if(!bb->TestPointInside(x,y))
			return c;
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while(it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			int ax = node_a->X();
			int ay = node_a->Y();
			int bx = node_b->X();
			int by = node_b->Y();
			int min_x, min_y, max_x, max_y;
			if(ax > bx)
			{
				min_x = bx;
				max_x = ax;
			}
			else
			{
				min_x = ax;
				max_x = bx;
			}
			if(ay > by)
			{
				min_y = by;
				max_y = ay;
			}
			else
			{
				min_y = ay;
				max_y = by;
			}
			// obvious case
			if(consider_touch)
			{
				if(min_x > x) continue;
				if(max_x < x) continue;
				if(max_y < y) continue;
			}
			else
			{
				if(min_x >= x) continue;
				if(max_x <= x) continue;
				if(max_y <= y) continue;
			}
			if(min_y > y)
			{
				c = !c;
				continue;
			}
			// special case, need to calculate
			int dx = bx - ax;
			int dy = by - ay;
			int cy = ay + (float)dy/dx*(x - ax);
			if(consider_touch)
			{
				if(cy > y)
				{
					c = !c;
				}
			}
			else
			{
				if(cy >= y)
				{
					c = !c;
				}
			}
		}
		return c;
	}
	/*------------------------------------------------
	// function PolygonSegmentIntersect
	// 29th JUL 2013
	// test edge is intersect polygon
	// - edge = edge
	// - polygon = polygon
	// - consider_touch = consider edge touch polygon as intersect
	//-------------------------------------------------*/
	bool PolygonSegmentIntersect(Edge* edge, SimplePolygon* polygon, bool consider_touch, bool consider_cover)
	{
		{
			Rectangle* bb1 = polygon->GetBoundingBox();
			Rectangle* bb2 = edge->GetBoundingBox();
			if(!bb1->Collide(bb2, consider_touch))
				return false;
		}
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->GetNodeA();
		Node* node_d = edge->GetNodeB();
		int cx = node_c->X();
		int cy = node_c->Y();
		int dx = node_d->X();
		int dy = node_d->Y();
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while(it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			int ax = node_a->X();
			int ay = node_a->Y();
			int bx = node_b->X();
			int by = node_b->Y();
			int min_x, min_y, max_x, max_y;
			if(ax > bx)
			{
				min_x = bx;
				max_x = ax;
			}
			else
			{
				min_x = ax;
				max_x = bx;
			}
			if(ay > by)
			{
				min_y = by;
				max_y = ay;
			}
			else
			{
				min_y = ay;
				max_y = by;
			}
			Rectangle* bb2 = new Rectangle(min_x, min_y, max_x, max_y);
			if(bb1->Collide(bb2, consider_touch))
			{
				bool result = SegmentSegmentIntersect(ax, ay, bx, by, 
					cx, cy, dx, dy, consider_touch);
				if(result) return true;
			}
		}
		int mid_x = (cx+dx)*0.5;
		int mid_y = (cy+dy)*0.5;
		bool mid_in = PointInPolygon(new Node(mid_x, mid_y),polygon, consider_touch);
		if(mid_in) return true;
		return false;
	}
	/*------------------------------------------------
	// function PolygonSegmentWithin
	// 29th JUL 2013
	// test edge is within polygon
	// - edge = edge
	// - polygon = cover polygon
	// - consider_touch = consider edge touch polygon as within
	//-------------------------------------------------*/
	bool PolygonSegmentWithin(Edge* edge, SimplePolygon* polygon, bool consider_touch)
	{
		{
			Rectangle* bb1 = polygon->GetBoundingBox();
			Rectangle* bb2 = edge->GetBoundingBox();
			if(!bb1->Collide(bb2, !consider_touch))
				return false;
		}
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->GetNodeA();
		Node* node_d = edge->GetNodeB();
		int cx = node_c->X();
		int cy = node_c->Y();
		int dx = node_d->X();
		int dy = node_d->Y();
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while(it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			int ax = node_a->X();
			int ay = node_a->Y();
			int bx = node_b->X();
			int by = node_b->Y();
			int min_x, min_y, max_x, max_y;
			if(ax > bx)
			{
				min_x = bx;
				max_x = ax;
			}
			else
			{
				min_x = ax;
				max_x = bx;
			}
			if(ay > by)
			{
				min_y = by;
				max_y = ay;
			}
			else
			{
				min_y = ay;
				max_y = by;
			}
			Rectangle* bb2 = new Rectangle(min_x, min_y, max_x, max_y);
			if(bb1->Collide(bb2, !consider_touch))
			{
				bool result = SegmentSegmentIntersect(ax, ay, bx, by, 
					cx, cy, dx, dy, !consider_touch);
				if(result) return false;
			}
		}
		int mid_x = (cx+dx)*0.5;
		int mid_y = (cy+dy)*0.5;
		bool mid_in = PointInPolygon(new Node(mid_x, mid_y),polygon, !consider_touch);
		if(mid_in) return true;
		return false;
	}
	/*------------------------------------------------
	// class Polygon
	// 29th JUL 2013
	// describe a polygon, convex or concave, has hole
	------------------------------------------------*/
	Polygon::Polygon()
		:QuadObject(0,0,20,20)
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
		if(bb == 0) return;
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
	bool PointInPolygon(Node* node, Polygon* polygon, bool consider_touch)
	{
		{
			SimplePolygon* outer = polygon->GetOuter();
			bool result = PointInPolygon(node, outer, consider_touch);
			if(!result) return false;
		}
		{
			SimplePolygons inners = polygon->GetInners();
			SimplePolygons::iterator it = inners.begin();
			while(it != inners.end())
			{
				SimplePolygon* inner = *it;
				bool result = PointInPolygon(node, inner, consider_touch);
				if(result) return false;
			}
		}
		return true;
	}
	bool PolygonSegmentIntersect(Edge* edge, Polygon* polygon, bool consider_touch)
	{
		{
			SimplePolygon* outer = polygon->GetOuter();
			bool result = PolygonSegmentIntersect(edge, outer, consider_touch);
			if(!result) return false;
		}
		{
			SimplePolygons inners = polygon->GetInners();
			SimplePolygons::iterator it = inners.begin();
			while(it != inners.end())
			{
				SimplePolygon* inner = *it;
				bool result = PolygonSegmentWithin(edge, inner, consider_touch);
				if(result)
				{
					return false;
				}
			}
		}
		return true;
	}
}