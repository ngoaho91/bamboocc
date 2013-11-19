#ifndef MESH_H
#define MESH_H
#include <vector>
#include "../Geometry/Edge.h"
#include "../Geometry/Node.h"
#include "../Geometry/PolygonContainer.h"
#define INF 2000000000
using namespace std;
using namespace Geometry;
namespace PathEngine
{
	class PathFinder;
	class PathRender;
	class Mesh
	{
		friend class PathFinder;
		friend class PathRender;
	private:
		vector<Node*>				m_Nodes;
		vector<Edge*>				m_Edges;
		PolygonContainer*			m_Polygons;
		vector< vector<int> >		m_RawGraph;// raw graph
		vector<Edge*>				m_VisibilityEdges;
		vector< vector<int> >		m_VisibilityGraph;// dijkstra graph
		vector< vector<int> >		m_ShortcutGraph;// hu's graph :)), didn't implement yet

		void	AddNode				(int x, int y, bool convex = false);
		void	AddNode				(Node* node);
		Edge*	Connect				(int i, int j);
	public:
		Mesh						(int width, int height);
		~Mesh						();
		bool	TestPointInside_OLD	(int x, int y);
		bool	TestPointInside	(int x, int y);
		bool	TestPointInside		(Node* node);
		bool	TestEdgeInside		(Edge* edge);
		int		GetLength			(int i, int j);
		int		GetFlyingLength		(int i, int j);
		void	AddPolygon			(vector<Node*> vertexs);
		void	BuildVisiGraph		();
		void	BuildShortcutGraph	();
		
	};
}
#endif