#include "PathFinderObstacle.h"
#include <queue>
namespace PathEngine
{
	/* TODO:
	// 1. graham
	// 2. shortcut map
	// 3. intersect, return list edges
	// 4. find path combination, then return the shortest
	*/
	/*
	TODO:
	- Intersects result, bool -> enum
	TODO: World Theory:
	- we have a Quadtree to handle worlds
	- world has a Quadtree to handle object(obstacle & actor)
	- world has a convex hull as boundary
	- 1 object belong to 1 world 
	-> 2 object in 2 world can not collide
	- object can only travel through worlds by jumping, moving cant
	*/
	Obstacle::Obstacle()
	{
	}
	Obstacle::Obstacle(SimplePolygon* polygon)
	{
		Obstacle();
		SetPolygon(polygon);
	}
	/*------------------------------------------------
	NAME: Graham
	DATE: 27th DEC 2013
	TASK: find convex hull of a polygon
	-------------------------------------------------*/
	void Obstacle::Graham(SimplePolygon* polygon)
	{
		int index = m_Nodes.size();
		SimplePolygon::iterator it = polygon->begin();
		int index_first = index;
		Node* first = *it;
		Node* last = *it++;
		m_Nodes.push_back(last);
		index++;
		while (it != polygon->end())
		{
			Node* node = *it;
			Node* next = *(polygon->GetNext(it++));
			Node* prev = last;
			if (GetConvex(prev, node, next) == CR_CONVEX) continue;
			m_Nodes.push_back(node);
			int index1 = index - 1;
			m_ShortcutMap[index1][index].length = Distance(node, last);
			m_ShortcutMap[index1][index].next = index;
			last = node;
			index++;
		}
		index--;
		m_ShortcutMap[index_first][index].length = Distance(first, last);
		m_ShortcutMap[index_first][index].next = index;
		BuildShortcutMap(index_first, index);
	}
	/*------------------------------------------------
	NAME: SetPolygon
	DATE: 27th DEC 2013
	TASK: Pre-compute some data
	-------------------------------------------------*/
	void Obstacle::SetPolygon(SimplePolygon* polygon)
	{
		m_MapLength = polygon->size();
		m_ShortcutMap = new Shortcut*[m_MapLength];
		for (int i = 0; i < m_MapLength; i++)
		{
			m_ShortcutMap[i] = new Shortcut[m_MapLength];
			for (int j = 0; j < m_MapLength; j++)
			{
				m_ShortcutMap[i][j].length = INF;
			}
		}
		Graham(polygon);
	}
	/*------------------------------------------------
	NAME: BuildShortcutMap
	DATE: 27th DEC 2013
	TASK: if nodes n to m are in the same polygon, build shortcut map for nodes n to m
	-------------------------------------------------*/
	void Obstacle::BuildShortcutMap(int n, int m)
	{
		const int len = n - m + 1;
		if (len == 3) return;
		const int len1 = len - 1;
		int* d = new int[len];
		d[0] = 0;
		for (int i = 1; i < len; i++)
		{
			int ni = n + i;
			d[i] = d[i - 1] + m_ShortcutMap[ni - 1][ni].length;
		}
		d[0] = d[len1] + m_ShortcutMap[n][m].length;
		int p = d[0] / 2;
		for (int i = 0; i < len; i++)
		{
			int ni = n + i;
			int di;
			if (i) di = d[i];
			else di = 0;
			bool ccw = true;
			for (int j = i + 2; j < len; j++)
			{
				int nj = n + j;
				int dj = d[j];
				int len_ccw = dj - di;
				if(ccw) if (len_ccw > p)
				{
					ccw = false;
				}
				if (ccw)
				{
					int next;
					if (ni == len1) next = n;
					else next = ni + 1;
					m_ShortcutMap[ni][nj].next = next;
					m_ShortcutMap[ni][nj].length = len_ccw;
				}
				else
				{
					int len_cw = d[0] - len_ccw;
					int back;
					if (ni == n) back = len1;
					else back = ni - 1;
					m_ShortcutMap[ni][nj].next = back;
					m_ShortcutMap[ni][nj].length = len_cw;
				}
			}
		}
	}
	Nodes Obstacle::PathIntersect(Node* a, Node* b)
	{
		Nodes ret;
		Edge* edge_ab = new Edge(a, b);
		edge_ab->Calculate();
		//TODO: find a fast intersect algorithm
		/*
		{
			Rectangle* bb1 = polygon->GetBoundingBox();
			Rectangle* bb2 = edge->GetBoundingBox();
			if (!bb1->Collide(bb2, consider_touch))
				return false;
		}
		Rectangle* bb1 = edge->GetBoundingBox();
		Node* node_c = edge->GetNodeA();
		Node* node_d = edge->GetNodeB();
		Edge* edge_cd = new Edge(node_c, node_d);
		Nodes::iterator it1 = polygon->begin();
		Nodes::iterator it2 = it1 + 1;
		while (it2 != polygon->end())
		{
			Node* node_a = *it1;
			Node* node_b = *it2;
			it1 = it2;
			it2++;
			Edge* edge_ab = new Edge(node_a, node_b);
			edge_ab->Calculate();
			Rectangle* bb2 = edge_ab->GetBoundingBox();
			if (bb1->Collide(bb2, consider_touch))
			{
				bool result = SegmentSegmentIntersect(edge_ab, edge_cd, consider_touch);
				if (result) return true;
			}
		}
		*/
		return ret;
	}
	Nodes Obstacle::FindPath(Node* a, Node* b)
	{
		Nodes ret;
		return ret;
	}
}