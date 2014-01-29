#include "PathFinderRegion.h"
namespace PathEngine
{
	Region::Region()
		:SimplePolygon()
	{

	}
	Region::Region(Geometry::SimplePolygon* polygon)
	{

	}
	Region::~Region()
	{

	}
	void Region::SetBoundary(SimplePolygon* polygon)
	{
		SetBoundingBox(polygon->GetBoundingBox());
	}
	void Region::AddObstacle(Obstacle* obstacle)
	{
		m_Obstacles->Insert(obstacle);
	}
	void Region::RemoveObstacle(Obstacle* obstacle)
	{
	}
	void RemoveObstacle(int index)
	{
	}
	void Region::AddActor(Actor* actor)
	{
	}
	void Region::RemoveActor(Actor* actor)
	{
	}
}