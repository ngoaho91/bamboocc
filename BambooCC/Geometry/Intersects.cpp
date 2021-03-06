#include "Intersects.h"
#include <algorithm>
namespace Geometry
{
	/*------------------------------------------------
	NAME: SegmentSegmentIntersect
	DATE: 11st JAN 2014
	TASK: return ralation of 2 segment, seperate, touch, or intersect
	-------------------------------------------------*/
	IntersectResult SegmentSegmentIntersect(Segment* s1, Segment* s2)
	{
		Rectangle* bb1 = s1->GetBoundingBox();
		Rectangle* bb2 = s2->GetBoundingBox();
		if (!bb1->Collide(bb2, true)) return IR_SEPERATE;
		Node *a = s1->A();
		Node *b = s1->B();
		Node *c = s2->A();
		Node *d = s2->B();
		return SegmentSegmentIntersect(a->X(), a->Y(), b->X(), b->Y(),
			c->X(), c->Y(), d->X(), d->Y());
	}
	/*------------------------------------------------
	NAME: SegmentSegmentIntersect
	DATE: 11st JAN 2014
	TASK: return ralation of 2 segment, seperate, touch, or intersect
	-------------------------------------------------*/
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
	-------------------------------------------------*/
	IntersectResult PointInPolygon(Node* node, Polygon* polygon)
	{
		if (!polygon->PointInsideBB(node)) return IR_SEPERATE;
		double x = node->X();
		double y = node->Y();
		bool c = false;
		Nodes::iterator it = polygon->begin();
		for (; it != polygon->end();it++)
		{
			Node* node_a = *it;
			Node* node_b = *(polygon->GetNext(it));
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
		return c ? IR_WITHIN : IR_SEPERATE;
	}
	/*------------------------------------------------
	NAME: PointInPolygon
	DATE: 11st JAN 2014
	TASK: test point is in polygon
	-------------------------------------------------*/
	IntersectResult PointInPolygon(Node* node, ConvexHull* polygon)
	{
		if (!polygon->PointInsideBB(node)) return IR_SEPERATE;
		Nodes::iterator it = polygon->begin();
		for (; it != polygon->end();it++)
		{
			Node* node_a = *it;
			Node* node_b = *(polygon->GetNext(it));
			ConvexResult ret = GetConvex(node_a, node, node_b);
			if (ret == CR_STRAIGHT)
			{
				if (NodeSegmentDistance(
					new Segment(node_a, node_b),
					node) == 0)
				{
					return IR_TOUCH;
				}
				else
				{
					return IR_SEPERATE;
				}
			}
			else if (ret == CR_CONVEX)
			{
				return IR_SEPERATE;
			}
		}
		return IR_WITHIN;
	}
	/*------------------------------------------------
	// NAME: PolygonSegmentIntersect
	// DATE: 29th JUL 2013
	// TASK: test edge is intersect polygon
	//-------------------------------------------------*/
	template<class TYPE>
	IntersectResult PolygonSegmentIntersect(Segment* edge, TYPE* polygon)
	{
		{
			Rectangle* bb1 = polygon->GetBoundingBox();
			Rectangle* bb2 = edge->GetBoundingBox();
			if (!bb1->Collide(bb2, true))
				return IR_SEPERATE;
		}
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->A();
		Node* node_d = edge->B();
		Segment* edge_cd = new Segment(node_c, node_d);
		Nodes::iterator it = polygon->begin();
		IntersectResult ret = IR_SEPERATE;
		int index = 0;
		for (; it != polygon->end();it++,index++)
		{
			if(typeid(polygon) == typeid(OpenPolygon*))
				if(polygon->IsPortal(index)) continue;
			Node* node_a = *it;
			Node* node_b = *(polygon->GetNext(it));
			Segment* edge_ab = new Segment(node_a, node_b);
			edge_ab->Calculate();
			Rectangle* bb2 = edge_ab->GetBoundingBox();
			if (bb1->Collide(bb2, true))
			{
				IntersectResult result = SegmentSegmentIntersect(edge_ab, edge_cd);
				if (result == IR_INTERSECT) return IR_INTERSECT;
				if (result == IR_TOUCH)
				{
					if (node_c->Equal(node_a) || node_d->Equal(node_a))
					{
						ret = IR_TOUCH;
					}
					// CAD straight
					else if (GetConvex(node_c, node_a, node_d) == CR_STRAIGHT)
					{
						Node* node_z = *(polygon->GetPrevious(it));
						// Z and B in 2 different plane seperated by CD
						if (GetConvex(node_c, node_z, node_d) != GetConvex(node_c, node_b, node_d))
						{
							return IR_INTERSECT;
						}
						else
						{
							ret = IR_TOUCH;
						}
					}
					else
					{
						ret = IR_TOUCH;
					}
				}
			}
		}
		return ret;
	}
	IntersectResult PortalSegmentIntersect(Segment* edge, OpenPolygon* polygon)
	{
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->A();
		Node* node_d = edge->B();
		Segment* edge_cd = new Segment(node_c, node_d);
		Nodes::iterator it = polygon->begin();
		IntersectResult ret = IR_SEPERATE;
		int index = 0;
		for (; it != polygon->end();it++,index++)
		{
			if(!polygon->IsPortal(index)) continue;
			Node* node_a = *it;
			Node* node_b = *(polygon->GetNext(it));
			Segment* edge_ab = new Segment(node_a, node_b);
			edge_ab->Calculate();
			Rectangle* bb2 = edge_ab->GetBoundingBox();
			if (bb1->Collide(bb2, true))
			{
				IntersectResult result = SegmentSegmentIntersect(edge_ab, edge_cd);
				if (result == IR_INTERSECT) return IR_INTERSECT;
				if (result == IR_TOUCH)
				{
					if (node_c->Equal(node_a) || node_d->Equal(node_a))
					{
						ret = IR_TOUCH;
					}
					// CAD straight
					else if (GetConvex(node_c, node_a, node_d) == CR_STRAIGHT)
					{
						Node* node_z = *(polygon->GetPrevious(it));
						// Z and B in 2 different plane seperated by CD
						if (GetConvex(node_c, node_z, node_d) != GetConvex(node_c, node_b, node_d))
						{
							return IR_INTERSECT;
						}
						else
						{
							ret = IR_TOUCH;
						}
					}
					else
					{
						ret = IR_TOUCH;
					}
				}
			}
		}
		return ret;
	}
}