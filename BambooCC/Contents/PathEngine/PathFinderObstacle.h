#ifndef PATHFINDEROBS_H
#define PATHFINDEROBS_H
#include "Geometry/Node.h"
#include "Geometry/Polygon.h"
#include "Geometry/QuadTree.h"
#include "Geometry/GeometryConstant.h"
#include "Path.h"
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
		: public Polygon
	{
	private:
		ConvexHull* m_ConvexHull;
		Shortcut** m_ShortcutMap;
	public:
		Obstacle();
		Obstacle(Polygon* polygon);
		~Obstacle();
		void SetPolygon(Polygon* polygon);
		Path FindPath(Node* from, Node* to);
	private:
		void Graham();
		void BuildShortcutMap();
		double GetLength(unsigned int from, unsigned int to);
	};
}
#endif