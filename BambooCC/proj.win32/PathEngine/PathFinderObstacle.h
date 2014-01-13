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
		double length;
	};
	class Obstacle
		: public SimplePolygon
	{
	public:
		ConvexHull* m_ConvexHull;
		Shortcut** m_ShortcutMap;
	public:
		Obstacle();
		Obstacle(SimplePolygon* polygon);
		void SetPolygon();
		void Graham();
		void BuildShortcutMap();
		Nodes FindPath(Node* from, Node* to);
		double GetLength(int from, int to);
	};
}
#endif