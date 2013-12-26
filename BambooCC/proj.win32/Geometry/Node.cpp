#include "Node.h"
namespace Geometry
{
	bool IsConvex(Node* prev, Node* current, Node* next, bool outer)
	{
		float cross = ((current->X() - prev->X()) * (next->Y() - current->Y())) -
			((current->Y() - prev->Y()) * (next->X() - current->X()));
		bool convex = outer ? cross < 0 : cross > 0;
		return convex;
	}
	double GetLength(Node* u, Node* v)
	{
		double dx = v->X() - u->X();
		double dy = v->Y() - u->Y();
		double length = sqrt(dx*dx + dy*dy);
		return length;
	}
}