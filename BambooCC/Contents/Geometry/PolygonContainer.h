#ifndef PolygonContainer_h
#define PolygonContainer_h
#include "QuadTree.h"
#include "Polygon.h"
#include "Intersects.h"
namespace Geometry
{
	class PolygonContainer
		:public QuadTree
	{
	public:
		PolygonContainer(int width, int height);
		~PolygonContainer();
		IntersectResult QueryPointInPolygon(Node* node);
		IntersectResult QueryPolygonSegmentIntersect(Segment* edge);
	};
}
#endif