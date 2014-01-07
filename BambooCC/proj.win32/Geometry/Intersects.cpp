#include "Intersects.h"
#include <algorithm>
namespace Geometry
{
	IntersectResult SegmentSegmentIntersect(Edge* edge1, Edge* edge2)
	{
		Rectangle* bb1 = edge1->GetBoundingBox();
		Rectangle* bb2 = edge2->GetBoundingBox();
		if (!bb1->Collide(bb2, true)) return IR_SEPERATE;
		Node *a = edge1->GetNodeA();
		Node *b = edge1->GetNodeB();
		Node *c = edge2->GetNodeA();
		Node *d = edge2->GetNodeB();
		return SegmentSegmentIntersect(a->X(), a->Y(), b->X(), b->Y(),
			c->X(), c->Y(), d->X(), d->Y());
	}
	IntersectResult SegmentSegmentIntersect(int ax, int ay, int bx, int by,
		int cx, int cy, int dx, int dy)
	{
		float denominator = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
		if (denominator == 0)
		{
			return IR_SEPERATE;
		}
		float numerator1 = (ay - cy) * (dx - cx) - (ax - cx) * (dy - cy);
		float numerator2 = (ay - cy) * (bx - ax) - (ax - cx) * (by - ay);
		float r = numerator1 / denominator;
		float s = numerator2 / denominator;
		if (r == 0 || r == 1 || s == 0 || s == 1)
		{
			return IR_TOUCH;
		}
		if ((r > 0 && r < 1) && (s > 0 && s < 1))
		{
			return IR_INTERSECT;
		}
		return IR_SEPERATE;
	}
	
	/*------------------------------------------------
	NAME: PointInPolygon
	DATE: 29th JUL 2013
	TASK: test point is in polygon
	- edge = edge
	- polygon = polygon
	- consider_touch = consider point at border of the polygon as in
	-------------------------------------------------*/
	IntersectResult PointInPolygon(Node* node, SimplePolygon* polygon)
	{
		if (polygon->size() < 4) return IR_SEPERATE;
		double x = node->X();
		double y = node->Y();
		Rectangle* bb = polygon->GetBoundingBox();
		if (!bb->TestPointInside(x, y))
			return IR_SEPERATE;
		bool c = false;
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while (it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			double ax = node_a->X();
			double ay = node_a->Y();
			double bx = node_b->X();
			double by = node_b->Y();
			double min_x, min_y, max_x, max_y;
			min_x = min(ax, bx);
			max_x = max(ax, bx);
			min_x = min(ay, by);
			max_x = max(ay, by);
			// obvious case
			if (min_x > x) continue;
			if (max_x < x) continue;
			if (max_y < y) continue;
			if (min_y > y)
			{
				c = !c;
				continue;
			}
			// normal case, need to calculate
			double dx = bx - ax;
			double dy = by - ay;
			double cy = ay + dy / dx*(x - ax);
			if (cy == y) return IR_TOUCH;
			if (cy > y)
			{
				c = !c;
			}
		}
		return c ? IR_INTERSECT : IR_SEPERATE;
	}
	/*------------------------------------------------
	// function PolygonSegmentIntersect
	// 29th JUL 2013
	// test edge is intersect polygon
	// - edge = edge
	// - polygon = polygon
	// - consider_touch = consider edge touch polygon as intersect
	//-------------------------------------------------*/
	IntersectResult PolygonSegmentIntersect(Edge* edge, SimplePolygon* polygon)
	{
		{
			Rectangle* bb1 = polygon->GetBoundingBox();
			Rectangle* bb2 = edge->GetBoundingBox();
			if (!bb1->Collide(bb2, true))
				return IR_SEPERATE;
		}
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->GetNodeA();
		Node* node_d = edge->GetNodeB();
		Edge* edge_cd = new Edge(node_c, node_d);
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while (it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			Edge* edge_ab = new Edge(node_a, node_b);
			edge_ab->Calculate();
			Rectangle* bb2 = edge_ab->GetBoundingBox();
			if (bb1->Collide(bb2, true))
			{
				IntersectResult result = SegmentSegmentIntersect(edge_ab, edge_cd);
				if (result != IR_SEPERATE) return result;
			}
		}
		return IR_SEPERATE;
	}
	IntersectResult PointInPolygon(Node* node, Polygon* polygon)
	{
		{
			SimplePolygon* outer = polygon->GetOuter();
			IntersectResult result = PointInPolygon(node, outer);
			if (result != IR_INTERSECT) return result;
		}
		{
			SimplePolygons inners = polygon->GetInners();
			SimplePolygons::iterator it = inners.begin();
			while (it != inners.end())
			{
				SimplePolygon* inner = *it;
				IntersectResult result = PointInPolygon(node, inner);
				if (result == IR_SEPERATE) continue;
				if (result == IR_TOUCH) return IR_TOUCH;
				if (result == IR_INTERSECT) return IR_SEPERATE;
			}
		}
		return IR_INTERSECT;
	}
	IntersectResult PolygonSegmentIntersect(Edge* edge, Polygon* polygon)
	{
		{
			SimplePolygon* outer = polygon->GetOuter();
			IntersectResult result = PolygonSegmentIntersect(edge, outer);
			if (result != IR_SEPERATE) return result;
			result = PointInPolygon(edge->GetNodeA(), outer);
			if (result == IR_SEPERATE) return IR_SEPERATE;
		}
		{
			SimplePolygons inners = polygon->GetInners();
			SimplePolygons::iterator it = inners.begin();
			while (it != inners.end())
			{
				SimplePolygon* inner = *it;
				IntersectResult result = PolygonSegmentIntersect(edge, inner);
				if (result != IR_SEPERATE) return result;
				result = PointInPolygon(edge->GetNodeA(), inner);
				if (result == IR_INTERSECT) return IR_SEPERATE;
			}
			return IR_INTERSECT;
		}
	}
	//TODO: improve algorithm, now T(2(n+1))
	IntersectResult PolygonSegmentWithin(Edge* edge, Polygon* polygon)
	{
		bool touch_outer;
		{
			SimplePolygon* outer = polygon->GetOuter();
			IntersectResult result = PolygonSegmentIntersect(edge, outer);
			touch_outer = result == IR_TOUCH;
			if (result == IR_SEPERATE)
			{
				result = PointInPolygon(edge->GetNodeA(), outer);
				if (result == IR_SEPERATE) return IR_SEPERATE;
			}
			else if (result == IR_INTERSECT) return IR_INTERSECT;
		}
		{
			SimplePolygons inners = polygon->GetInners();
			SimplePolygons::iterator it = inners.begin();
			while (it != inners.end())
			{
				SimplePolygon* inner = *it;
				IntersectResult result = PolygonSegmentIntersect(edge, inner);
				if (result != IR_SEPERATE) return result;
				result = PointInPolygon(edge->GetNodeA(), inner);
				if (result != IR_SEPERATE) return result;
			}
		}
		return touch_outer?IR_TOUCH:IR_INTERSECT;
	}
}