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
		m_MapLength = this->size();
		m_ShortcutMap = new Shortcut*[m_MapLength];
		for (int i = 0; i < m_MapLength; i++)
		{
			m_ShortcutMap[i] = new Shortcut[m_MapLength];
			for (int j = 0; j < m_MapLength; j++)
			{
				m_ShortcutMap[i][j].length = INF;
			}
		}
		m_Nodes.clear();
		int index = 0;
		SimplePolygon::iterator it = this->begin();
		Node* first = *it;
		Node* last = *it++;
		m_Nodes.push_back(last);
		index++;
		while (it != this->end())
		{
			Node* node = *it;
			Node* next = *(this->GetNext(it++));
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
		int* d = new int[len];
		d[0] = 0;
		for (int i = 1; i < len; i++)
		{
			d[i] = d[i - 1] + m_ShortcutMap[i-1][i].length;
		}
		d[0] = d[len1] + m_ShortcutMap[0][len1].length;
		int p = d[0] / 2;
		for (int i = 0; i < len; i++)
		{
			int di = i == 0 ? 0 : d[i];
			bool ccw = true;
			for (int j = i + 2; j < len; j++)
			{
				int dj = d[j];
				int len_ccw = dj - di;
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
					int len_cw = d[0] - len_ccw;
					int back;
					if (i == 0) back = len1;
					else back = i - 1;
					m_ShortcutMap[i][j].next = back;
					m_ShortcutMap[i][j].length = len_cw;
				}
			}
		}
	}
	Nodes Obstacle::PathIntersect(Node* from, Node* to)
	{
		Nodes ret;
		Edge* edge_ab = new Edge(from, to);
		edge_ab->Calculate();
		return ret;
	}
	Nodes Obstacle::FindPath(Node* from, Node* to)
	{
		Nodes ret;
		return ret;
	}
}