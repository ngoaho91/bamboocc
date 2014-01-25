#ifndef PathFinderWorld_h
#define PathFinderWorld_h
#include "PathFinderObstacle.h"
#include "PathFinderActor.h"
#include "Geometry/PolygonContainer.h"
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	
	class World
		:public QuadObject
	{
	private:
		ConvexHull*			m_Boundary;
		PolygonContainer*	m_Obstacles;
		//ActorContainer*	m_Actors;
	public:
		World();
		World(Geometry::Polygon* polygon);
		~World();
		void SetBoundary(ConvexHull* polygon);
		void AddObstacle(Obstacle* obstacle);
		void RemoveObstacle(Obstacle* obstacle);
		void AddActor(Actor* actor);
		void RemoveActor(Actor* actor);
		IntersectResult PointInside(Node* node);
		IntersectResult PointIntersect(Node* node);
	};
	class WorldManager
		:public QuadTree
	{

	};
}
#endif