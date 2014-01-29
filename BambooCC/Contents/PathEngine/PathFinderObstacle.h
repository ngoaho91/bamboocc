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
	private:
		ConvexHull* m_ConvexHull;
		Shortcut** m_ShortcutMap;
	public:
		Obstacle();
		Obstacle(SimplePolygon* polygon);
		~Obstacle();
		void SetPolygon(SimplePolygon* polygon);
		Nodes FindPath(Node* from, Node* to);
	private:
		void Graham();
		void BuildShortcutMap();
		double GetLength(unsigned int from, unsigned int to);
	};
}
#endif