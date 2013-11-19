#include "Edge.h"
#include <math.h>
namespace Geometry
{
	Edge::Edge()
	{
		first = 0;
		second = 0;
		m_Length = -1;
		m_BoundingBox = 0;
	}
	Edge::~Edge()
	{
	}
	Edge::Edge(Node* a, Node* b)
		:pair<Node*, Node*>(a,b)
	{
	}
	void Edge::Calculate()
	{
		int min_x, min_y, max_x, max_y;
		if(first->X() > second->X())
		{
			max_x = first->X();
			min_x = second->X();
		}
		else
		{
			max_x = second->X();
			min_x = first->X();
		}
		if(first->Y() > second->Y())
		{
			max_y = first->Y();
			min_y = second->Y();
		}
		else
		{
			max_y = second->Y();
			min_y = first->Y();
		}
		m_BoundingBox = new Rectangle(min_x, min_y, max_x, max_y);
	}
	int Edge::GetLength()
	{
		if(m_Length == -1)
		{
			int dx = second->X() - first->X();
			int dy = second->Y() - first->Y();
			m_Length = sqrt((double)(dx*dx+dy*dy));
		}
		return m_Length;
	}
	bool SegmentSegmentIntersect(Edge* edge1, Edge* edge2, bool consider_touch)
	{
		Rectangle* bb1 = edge1->GetBoundingBox();
		Rectangle* bb2 = edge2->GetBoundingBox();
		if(!bb1->Collide(bb2, consider_touch)) return false;
		Node *a = edge1->GetNodeA();
		Node *b = edge1->GetNodeB();
		Node *c = edge2->GetNodeA();
		Node *d = edge2->GetNodeB();
		return SegmentSegmentIntersect(a->X(), a->Y(), b->X(), b->Y(), 
			c->X(), c->Y(), d->X(), d->Y(), consider_touch);
	}
	bool SegmentSegmentIntersect(int ax, int ay, int bx, int by,
		int cx, int cy, int dx, int dy, bool consider_touch)
	{
		float denominator = ((bx - ax) * (dy - cy)) 
			- ((by - ay) * (dx - cx));
		if (denominator == 0)
		{
			return false;
		}
		float numerator1 = ((ay - cy) * (dx - cx)) 
			- ((ax - cx) * (dy - cy));
		float numerator2 = ((ay - cy) * (bx - ax)) 
			- ((ax - cx) * (by - ay));
		float r = numerator1 / denominator;
		float s = numerator2 / denominator;
		if(consider_touch)
		{
			return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
		}
		else
		{
			return (r > 0 && r < 1) && (s > 0 && s < 1);
		}
	}
}