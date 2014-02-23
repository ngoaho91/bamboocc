#ifndef REGIONCONTAINER_H
#define REGIONCONTAINER_H
#include "PathFinderRegion.h"
namespace PathEngine
{
	class RegionContainer
		:public QuadTree
	{
	public:
		RegionContainer(int width, int height);
		~RegionContainer();
		IntersectResult QueryPointInPolygon(Node* node);
		IntersectResult QueryPolygonSegmentIntersect(Segment* edge);
	};
}
#endif