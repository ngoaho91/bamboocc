#ifndef PATHFINDERREGION_H
#define PATHFINDERREGION_H
#include "PathFinderObstacle.h"
#include "PathFinderActor.h"
#include "Geometry/PolygonContainer.h"
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
	class Region
		:public SimplePolygon
	{
	private:
		int						m_Height;
		Nodes*					m_GraphData;
		vector<vector<int> >	m_Graph;
		vector<Connection>		m_Connections;
		PolygonContainer*		m_Obstacles;
		//ActorContainer*		m_Actors;
	public:
		Region();
		Region(SimplePolygon* polygon);
		~Region();
		void SetBoundary(SimplePolygon* polygon);
		void AddObstacle(Region* obstacle);
		void RemoveObstacle(Region* obstacle);
		void RemoveObstacle(int index);
		void AddActor(Actor* actor);
		void RemoveActor(Actor* actor);
		void RemoveActor(int index);
	};
}
#endif