#include "PathFinderWorld.h"
namespace PathEngine
{
	World::World()
		:QuadObject()
	{

	}
	World::World(Geometry::Polygon* polygon)
	{

	}
	World::~World()
	{

	}
	void World::SetBoundary(ConvexHull* polygon)
	{
		m_Boundary = polygon;
		SetBoundingBox(polygon->GetBoundingBox());
	}
	void World::AddObstacle(Obstacle* obstacle)
	{
		m_Obstacles->Insert(obstacle);
	}
	void RemoveObstacle(Obstacle* obstacle)
	{
	}
	void World::AddActor(Actor* actor)
	{

	}
	void World::RemoveActor(Actor* actor)
	{

	}
	IntersectResult World::PointInside(Node* node)
	{
		return PointInPolygon(node, m_Boundary);
	}
	IntersectResult World::PointIntersect(Node* node)
	{
		return m_Obstacles->QueryPointInPolygon(node);
	}
}