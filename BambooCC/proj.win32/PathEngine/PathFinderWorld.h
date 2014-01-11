#ifndef PathFinderWorld_h
#define PathFinderWorld_h
#include <vector>
#include "PathFinder.h"
#include "Mesh.h"
#include "PathFinderActor.h"
#include "../Geometry/QuadTree.h"
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	
	class World
		:public QuadTree
	{
		friend class		Actor;
	private:
		static World*		m_Instance;
	public:
		static World*		instance();
		static int			WIDTH;
		static int			HEIGHT;
	private:
		PathFinder*			m_PathFinder;
	public:
		World();
		~World();
		void				AddActor(Actor* actor);
		Nodes				FindPath(int bx, int by, int gx, int gy);
		Nodes				FindPathNear(int bx, int by, int gx, int gy, int range);
		bool				AvailableXY(int x, int y);
	};
	class WorldManager
	{

	};
}
#endif