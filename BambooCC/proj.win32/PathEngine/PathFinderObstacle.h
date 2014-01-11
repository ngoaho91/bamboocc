#ifndef PATHFINDEROBS_H
#define PATHFINDEROBS_H
#include "Geometry/Node.h"
#include "Geometry/Polygon.h"
#include "Geometry/QuadTree.h"
#include "Geometry/GeometryConstant.h"
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	struct Shortcut
	{
		unsigned short next;
		unsigned int length;
	};
	class Obstacle
		: public QuadObject
	{
	public:
		Nodes m_Nodes;
		Polygon* m_Polygon;
		Shortcut** m_ShortcutMap;
		int m_MapLength;
	public:
		Obstacle();
		Obstacle(SimplePolygon* polygon);
		void SetPolygon(SimplePolygon* polygon);
		void Graham(SimplePolygon* polygon);
		void BuildShortcutMap(int n, int m);
		Nodes PathIntersect(Node* a, Node* b);
		Nodes FindPath(Node* a, Node* b);
	};
}
#endif