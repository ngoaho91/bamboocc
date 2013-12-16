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
	};
	typedef vector<SimplePolygon*> SimplePolygons;
	bool PointInPolygon(Node* node, SimplePolygon* polygon, bool consider_touch = false);
	bool PolygonSegmentIntersect(Edge* edge, SimplePolygon* polygon, bool consider_touch = false, bool consider_cover = true);
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
	bool PointInPolygon(Node* node, Polygon* polygon, bool consider_touch = false);
	bool PolygonSegmentIntersect(Edge* edge, Polygon* polygon, bool consider_touch = false);
	
}
#endif