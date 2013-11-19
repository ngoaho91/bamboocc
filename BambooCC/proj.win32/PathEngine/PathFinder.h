#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <vector>
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	enum PathFinderGoal
	{
		SHORTEST = 0,
		POSSIBLE = 1
	};
	class PathFinder
	{
	private:
		vector< vector<int> > m_Matrix;
		vector<int> m_VertexPrev;
		Geometry::QuadTree* m_QuadTree;
		PathRender* m_Render;
	private:
		bool IsConvex(Node* prev, Node* current, Node* next, bool outer);
		int GetLength(Node* u, Node* v);
		int GetLength(int u, int v);
		void AddSinglePolygon(Polygon* poly);
		void SinglePolygonToMatrix(SimplePolygon* poly, bool outer);
	public:
		PathFinder();
		~PathFinder();
		PathRender* GetRender(){ return m_Render;}
		void AddSinglePolygon(Polygon* poly);
		void UnionPolygon();
		void PolygonToMatrix();
		vector<Node*> FindPath
			(Node* start, Node* end, PathFinderGoal goal=SHORTEST);
		vector<Node*> FindPathNear
			(Node* start, Node* end, int range, PathFinderGoal goal=SHORTEST);
		bool FixPoint(int* x, int* y, bool consider_touch = false, double jump_length = 5.0, int max_try = 10);
		bool QueryPointAvailable(int x, int y);
	};
}
#endif