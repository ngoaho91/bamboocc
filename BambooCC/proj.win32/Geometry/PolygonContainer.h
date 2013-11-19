#ifndef PolygonContainer_h
#define PolygonContainer_h
#include "QuadTree.h"
#include "Polygon.h"
namespace Geometry
{
	class PolygonContainer
		:public QuadTree
	{
	public:
		PolygonContainer(int width, int height);
		~PolygonContainer();
		bool QueryPointInPolygon(Node* node, bool consider_touch = false);
		bool QueryPolygonSegmentIntersect(Edge* edge, bool consider_touch = false);
	};
}
#endif