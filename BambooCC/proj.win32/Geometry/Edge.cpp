#include "Edge.h"
#include <math.h>
#include <algorithm>
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
		double min_x, min_y, max_x, max_y;
		min_x = min(first->X(), second->X());
		min_y = min(first->Y(), second->Y());
		max_x = max(first->X(), second->X());
		max_y = max(first->Y(), second->Y());
		m_BoundingBox = new Rectangle(min_x, min_y, max_x, max_y);
	}
	double Edge::GetLength()
	{
		if(m_Length == -1)
		{
			double dx = second->X() - first->X();
			double dy = second->Y() - first->Y();
			m_Length = sqrt(dx*dx+dy*dy);
		}
		return m_Length;
	}
	double PointSegmentDistance(Edge* edge, Node* p)
	{
		Vector* v = new Vector(edge->GetNodeB(), edge->GetNodeA());
		Vector* w = new Vector(p, edge->GetNodeA());
		double c1 = DotProduct(w, v);
		if (c1 <= 0)
		{
			return Distance(p, edge->GetNodeA());
		}
		double c2 = DotProduct(v, v);
		if (c2 <= c1)
		{
			return Distance(p, edge->GetNodeB());
		}
		double b = c1 / c2;
		v->Multiply(b);
		Node* pb = new Node(p->X(), p->Y());
		pb->Apply(v);
		return Distance(p, pb);
	}
}