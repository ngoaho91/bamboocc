#include "PathFinderObstacle.h"
#include <queue>
namespace PathEngine
{
	/*
	TODO: World Theory:
	- we have a Quadtree to handle worlds
	- world has a Quadtree to handle object(obstacle & actor)
	- world has a convex hull as boundary
	- 1 object belong to 1 world 
	-> 2 object in 2 world can not collide
	- object can only travel through worlds by jumping, moving cant
	*/
	Obstacle::Obstacle()
		:SimplePolygon()
	{
	}
	Obstacle::Obstacle(SimplePolygon* polygon)
	{
		Obstacle();
		SimplePolygon::iterator it = polygon->begin();
		while (it != polygon->end())
		{
			Node* node = *it;
			this->push_back(node);
		}
		Graham();
		BuildShortcutMap();
	}
	/*------------------------------------------------
	NAME: Graham
	DATE: 27th DEC 2013
	TASK: find convex hull of a polygon
	-------------------------------------------------*/
	void Obstacle::Graham()
	{
		const int len = this->size();
		m_ShortcutMap = new Shortcut*[len];
		for (int i = 0; i < len; i++)
		{
			m_ShortcutMap[i] = new Shortcut[len];
			for (int j = 0; j < len; j++)
			{
				m_ShortcutMap[i][j].length = INF;
			}
		}
		m_ConvexHull = new ConvexHull(this);
		int index = 0;
		SimplePolygon::iterator it = m_ConvexHull->begin();
		Node* first = *it;
		Node* last = *it++;
		index++;
		for (; it != m_ConvexHull->end(); it++)
		{
			Node* node = *it;
			Node* prev = last;
			int index1 = index - 1;
			m_ShortcutMap[index1][index].length = Distance(node, last);
			m_ShortcutMap[index1][index].next = index;
			last = node;
			index++;
		}
		index--;
		m_ShortcutMap[0][index].length = Distance(first, last);
		m_ShortcutMap[0][index].next = index;
	}
	/*------------------------------------------------
	NAME: BuildShortcutMap
	DATE: 27th DEC 2013
	TASK: if nodes n to m are in the same polygon, build shortcut map for nodes n to m
	-------------------------------------------------*/
	void Obstacle::BuildShortcutMap()
	{
		const int len = this->size();
		if (len == 3) return;
		const int len1 = len - 1;
		double* d = new double[len];
		d[0] = 0;
		for (int i = 1; i < len; i++)
		{
			d[i] = d[i - 1] + m_ShortcutMap[i-1][i].length;
		}
		d[0] = d[len1] + m_ShortcutMap[0][len1].length;
		double p = d[0] / 2;
		for (int i = 0; i < len; i++)
		{
			double di = i == 0 ? 0 : d[i];
			bool ccw = true;
			for (int j = i + 2; j < len; j++)
			{
				double dj = d[j];
				double len_ccw = dj - di;
				if(ccw) if (len_ccw > p)
				{
					ccw = false;
				}
				if (ccw)
				{
					int next;
					if (i == len1) next = 0;
					else next = i + 1;
					m_ShortcutMap[i][j].next = next;
					m_ShortcutMap[i][j].length = len_ccw;
				}
				else
				{
					double len_cw = d[0] - len_ccw;
					int back;
					if (i == 0) back = len1;
					else back = i - 1;
					m_ShortcutMap[i][j].next = back;
					m_ShortcutMap[i][j].length = len_cw;
				}
			}
		}
	}
	Nodes Obstacle::FindPath(Node* from, Node* to)
	{
		Nodes ret;
		// intersect
		ConvexHull::iterator it = m_ConvexHull->begin();
		Node *a, *b, *c, *d;
		int ia, ib, ic, id;
		a = b = c = d = *it;
		ia, ib, ic, id = 0;
		it++;
		int i = 1;
		for (; it != m_ConvexHull->end(); it++)
		{
			ConvexResult cr;
			cr = GetConvex(from, *it, a);
			if (cr == CR_CONCAVE)
			{
				a = *it;
				ia = i;
			}
			cr = GetConvex(from, *it, b);
			if (cr == CR_CONVEX)
			{
				b = *it;
				ib = i;
			}
			cr = GetConvex(to, *it, c);
			if (cr == CR_CONVEX)
			{
				c = *it;
				ic = i;
			}
			cr = GetConvex(to, *it, d);
			if (cr == CR_CONCAVE)
			{
				d = *it;
				id = i;
			}
			i++;
		}
		// trace
		double len_ad = GetLength(ia, id);
		double len_bc = GetLength(ib, ic);
		int i, j;
		if (len_ad < len_bc)
		{
			i = ia;
			j = id;
		}
		else
		{
			i = ib;
			j = ic;
		}
		int i = ia;
		while (true)
		{
			ret.push_back(m_ConvexHull->at(i));
			if (i == j) break;
			i = m_ShortcutMap[i][j].next;
		}
		ret.push_back(to);
		return ret;
	}
	double Obstacle::GetLength(int from, int to)
	{
		if (from >= m_ConvexHull->size()) return;
		if (to >= m_ConvexHull->size()) return;
		if (from == to) return 0;
		if (from < to)
		{
			return m_ShortcutMap[from][to].length;
		}
		else
		{
			return m_ShortcutMap[to][from].length;
		}
	}
}