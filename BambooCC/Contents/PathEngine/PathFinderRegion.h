#ifndef PATHFINDERREGION_H
#define PATHFINDERREGION_H
#include "PathFinderObstacle.h"
#include "PathFinderActor.h"
#include "Geometry/PolygonContainer.h"
#include "Path.h"
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	class Region;
	struct Connection
	{
		int			segment_index;
		Region*		destination; 
	};
	enum SegmentRegionCrossResult
	{
		SR_INTERSECT=0,
		SR_WITHIN=1,
		SR_CROSSPORTAL=2,
		SR_SEPERATE=3
	};
	class Region
		:public OpenPolygon
	{
	private:
		int									m_Height;
		PolygonContainer<OpenPolygon>*		m_ChildRegions;
		PolygonContainer<Polygon>*			m_Obstacles;
		Nodes								m_GraphData;
		vector< vector< pair<int,int> > >	m_Graph;
		//ActorContainer*					m_Actors;
	public:
		Region();
		Region(OpenPolygon* polygon);
		~Region();
		void BuildNavigationGraph();
		void SetBoundary(OpenPolygon* polygon);
		void AddObstacle(Region* obstacle);
		void RemoveObstacle(Region* obstacle);
		void RemoveObstacle(int index);
		void AddActor(Actor* actor);
		void RemoveActor(Actor* actor);
		void RemoveActor(int index);
		Path FindPath(Node* from, Node* to);
	private:
		bool SegmentValid(Segment* s);
	};
}
#endif