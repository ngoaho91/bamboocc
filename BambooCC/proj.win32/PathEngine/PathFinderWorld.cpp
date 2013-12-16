#include "PathFinderWorld.h"
namespace PathEngine
{
	World* World::m_Instance = 0;
	int World::WIDTH = 3000;
	int	World::HEIGHT = 3000;
	World* World::instance()
	{
		if(!m_Instance) m_Instance = new World();
		return m_Instance;
	}
	World::World()
		:QuadTree(WIDTH,HEIGHT)
	{
		//m_Mesh = new Mesh(WIDTH,HEIGHT);
		//m_PathFinder = new PathFinder(m_Mesh);
	}
	World::~World()
	{
	}
	Nodes World::FindPath(int bx, int by, int gx, int gy)
	{
		return m_PathFinder->FindPath(new Node(bx, by), new Node(gx, gy));
	}
	Nodes World::FindPathNear(int bx, int by, int gx, int gy, int range)
	{
		return m_PathFinder->FindPathNear(new Node(bx, by), new Node(gx, gy), range);
	}
	void World::AddActor(Actor* actor)
	{
		QuadTree::Insert(actor);
	}
	bool World::AvailableXY(int x, int y)
	{
		return m_PathFinder->QueryPointAvailable(x,y);
	}
}