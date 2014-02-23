#include "PathFinderRegion.h"
namespace PathEngine
{
	Region::Region()
		:OpenPolygon()
	{
	}
	Region::Region(OpenPolygon* polygon)
	{
		Region();
		SetBoundary(polygon);
	}
	Region::~Region()
	{
	}
	void Region::BuildNavigationGraph()
	{
		m_GraphData.clear();
		m_Graph.clear();// TODO: need more code to actually clear

		//...
	}
	void Region::SetBoundary(OpenPolygon* polygon)
	{
		SetBoundingBox(polygon->GetBoundingBox());
		OpenPolygon::iterator it = polygon->begin();
		for(;it!=polygon->end();it++)
		{
			this->push_back(*it);
		}
		for(int i=0;i<this->size();i++)
		{
			SetPortal(i,polygon->IsPortal(i));
		}
	}
	void Region::AddObstacle(Region* obstacle)
	{
		m_Obstacles->Insert(obstacle);
		//....
	}
	void Region::RemoveObstacle(Region* obstacle)
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
	bool Region::SegmentValid(Segment* s)
	{

	}
}