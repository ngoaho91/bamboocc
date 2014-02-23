#ifndef Intersects_h
#define Intersects_h
#include "Node.h"
#include "Segment.h"
#include "Polygon.h"
#include "OpenPolygon.h"
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
		Segment* s1, 
		Segment* s2);
	IntersectResult SegmentSegmentIntersect(
		int ax, int ay, int bx, int by, 
		int cx, int cy, int dx, int d);
	IntersectResult PointInPolygon(Node* node, Polygon* polygon);
	IntersectResult PointInPolygon(Node* node, ConvexHull* polygon);
	template <class TYPE>
	IntersectResult PolygonSegmentIntersect(Segment* s, TYPE* polygon);
	IntersectResult PortalSegmentIntersect(Segment* edge, OpenPolygon* polygon);
}
#endif