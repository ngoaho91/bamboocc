#include "PathFinder.h"
#include <algorithm>
#include <iostream>
using namespace std;

namespace PathEngine
{
	PathFinder::PathFinder()
	{
	}

	PathFinder::~PathFinder()
	{
	}
	bool PathFinder::IsConvex(Node* prev, Node* current, Node* next, bool outer)
	{
		float cross = ((current->X() - prev->X()) * (next->Y() - current->Y())) - 
			((current->Y() - prev->Y()) * (next->X() - current->X()));
		bool convex = outer ? cross < 0 : cross > 0;
		return convex;
	}
	int PathFinder::GetLength(Node* u, Node* v)
	{
		double dx = v->X() - u->X();
		double dy = v->Y() - u->Y();
		double length = sqrt(dx*dx + dy*dy);
		return length;
	}
	int PathFinder::GetLength(int u, int v)
	{
		//return GetLength()
		return 0;
	}
	void PathFinder::AddSinglePolygon(Geometry::Polygon* poly)
	{
	}
	void PathFinder::SinglePolygonToMatrix(SimplePolygon* poly, bool outer)
	{
	}
}