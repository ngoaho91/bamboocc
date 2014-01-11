#ifndef PathFinderPolygon_h
#define PathFinderPolygon_h
#include "Edge.h"
#include "Rectangle.h"
#include "QuadTree.h"
#define QOT_POLYGON 1
namespace Geometry
{
	
	class SimplePolygon
		:public QuadObject, public vector<Node*>
	{
	public:
		SimplePolygon();
		~SimplePolygon();
		void CalculateAABB();
		bool PointInsideBB(Node* node);
		SimplePolygon::iterator GetNext(SimplePolygon::iterator it);
		SimplePolygon::iterator GetPrevious(SimplePolygon::iterator it);
	};
	typedef vector<SimplePolygon*> SimplePolygons;
	class ConvexHull
		:public SimplePolygon
	{
	public:
		ConvexHull();
		~ConvexHull();
	};
	typedef vector<ConvexHull*> ConvexHulls;
	class Polygon
		:public QuadObject
	{
	private:
		SimplePolygon* m_Outer;
		SimplePolygons m_Inners;
	public:
		Polygon();
		~Polygon();
		void CalculateAABB();
		void SetOuter(SimplePolygon* polygon);
		void AddInner(SimplePolygon* polygon);
		SimplePolygon* GetOuter(){ return m_Outer;}
		SimplePolygons GetInners(){ return m_Inners;}
	};
	typedef vector<Polygon*> Polygons;
}
#endif