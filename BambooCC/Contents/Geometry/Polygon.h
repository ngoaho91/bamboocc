#ifndef Polygon_h
#define Polygon_h
#include "Rectangle.h"
#include "QuadTree.h"
#include "Node.h"
#define QOT_POLYGON 1
namespace Geometry
{
	
	class Polygon
		:public QuadObject, public Nodes
	{
	public:
		Polygon();
		~Polygon();
		void CalculateAABB();
		bool PointInsideBB(Node* node);
		Polygon::iterator GetNext(Polygon::iterator it);
		Polygon::iterator GetPrevious(Polygon::iterator it);
	};
	typedef vector<Polygon*> Polygons;
	class ConvexHull
		:public Polygon
	{
	public:
		ConvexHull();
		ConvexHull(Polygon* polygon);
		~ConvexHull();
	};
	typedef vector<ConvexHull*> ConvexHulls;
	
}
#endif