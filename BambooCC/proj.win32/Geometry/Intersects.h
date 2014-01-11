#ifndef Intersects_h
#define Intersects_h
#include "Node.h"
#include "Edge.h"
#include "Polygon.h"
namespace Geometry
{
	enum IntersectResult
	{
		IR_SEPERATE = 0,
		IR_TOUCH = 1,
		IR_INTERSECT = 2,
		IR_WITHIN = 3
	};
	IntersectResult SegmentSegmentIntersect(
		Edge* edge1, 
		Edge* edge2);
	IntersectResult SegmentSegmentIntersect(
		int ax, int ay, int bx, int by, 
		int cx, int cy, int dx, int d);
	
	IntersectResult PointInPolygon(Node* node, SimplePolygon* polygon);
	IntersectResult PointInPolygon(Node* node, ConvexHull* polygon);
	IntersectResult PolygonSegmentIntersect(Edge* edge, SimplePolygon* polygon);
	IntersectResult PolygonSegmentWithin(Edge* edge, SimplePolygon* polygon);
}
#endif