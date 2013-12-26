#include "PathFinderObstacle.h"
#include <queue>
namespace PathEngine
{
	/* TODO:
	// 1. graham
	// 2. shortcut map
	// 3. intersect, return list edges
	// 4. find path combination
	// 5. dijkstra find shortest path
	*/
	Obstacle::Obstacle()
	{
	}
	Obstacle::Obstacle(Polygon* polygon)
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
		for (; it != polygon->end(); it++)
		{
			Node* node = *it;
			if (!polygon->IsConvexNode(it, true)) continue;
			m_Nodes.push_back(node);
			int index1 = index - 1;
			m_ShortcutMap[index1][index].length = GetLength(node, last);
			m_ShortcutMap[index1][index].next = index;
			last = node;
			index++;
		}
		index--;
		m_ShortcutMap[index_first][index].length = GetLength(first, last);
		m_ShortcutMap[index_first][index].next = index;
		BuildShortcutMap(index_first, index);
	}
	/*------------------------------------------------
	NAME: SetPolygon
	DATE: 27th DEC 2013
	TASK: Pre-compute some data
	-------------------------------------------------*/
	void Obstacle::SetPolygon(Polygon* polygon)
	{
		SimplePolygon* outer = polygon->GetOuter();
		SimplePolygons inners = polygon->GetInners();
		{
			m_MapLength = 0;
			m_MapLength += outer->size();
			SimplePolygons::iterator it = inners.begin();
			for (; it != inners.end(); it++)
			{
				SimplePolygon* inner = *it;
				m_MapLength += inner->size();
			}
			m_ShortcutMap = new Shortcut*[m_MapLength];
			for (int i = 0; i < m_MapLength; i++)
			{
				m_ShortcutMap[i] = new Shortcut[m_MapLength];
				for (int j = 0; j < m_MapLength; j++)
				{
					m_ShortcutMap[i][j].length = INF;
				}
			}
		}
		{
			Graham(outer);
			SimplePolygons::iterator it = inners.begin();
			for (; it != inners.end(); it++)
			{
				SimplePolygon* inner = *it;
				Graham(inner);
			}
		}
	}
	/*------------------------------------------------
	NAME: BuildShortcutMap
	DATE: 27th DEC 2013
	TASK: build shortcut map for nodes n to m, if nodes n to m are in the same polygon
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
				if(ccw) if (len_ccw > d[0] * 0.5)
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
	bool Obstacle::PathIntersect(Node* a, Node* b)
	{
		return false;
	}
	vector<Node*> Obstacle::FindPath(Node* a, Node* b)
	{
		vector<Node*> ret;
		return ret;
	}
}