#include "Mesh.h"
#include <math.h>
#include <iostream>
namespace PathEngine
{
	bool Mesh::TestPointInside(Node* node)
	{
		return TestPointInside(node->X, node->Y);
	}
	bool Mesh::TestPointInside(int x, int y)
	{
		return m_Polygons->QueryPointOutside(x,y);
	}
	bool Mesh::TestEdgeInside(Edge* edge)
	{
		return !m_Polygons->QueryEdgeIntersect(edge);
	}
	int Mesh::GetLength(int i, int j)
	{
		int index = m_VisibilityGraph[i][j];
		if(index == INF) return INF;
		return m_VisibilityEdges[index]->GetLength();
	}
	int Mesh::GetFlyingLength(int i, int j)
	{
		int length = GetLength(i, j);
		if(length < INF) return length;
		Node* nodei = m_Nodes[i];
		Node* nodej = m_Nodes[j];
		int dx = nodei->X - nodej->X;
		int dy = nodei->Y - nodej->Y;
		return sqrt((double)(dx*dx+dy*dy));
	}
	void Mesh::AddNode(int x, int y, bool convex)
	{
		Node *node = new Node();
		node->X = x;
		node->Y = y;
		node->Convex = convex;
		AddNode(node);
	}
	void Mesh::AddNode(Node *node)
	{
		vector<int> len;
		for(unsigned int i = 0;i < m_Nodes.size();i++)
		{
			m_RawGraph[i].push_back(INF);
			len.push_back(INF);
		}
		len.push_back(INF);
		m_Nodes.push_back(node);
		m_RawGraph.push_back(len);
	}
	Edge* Mesh::Connect(int i, int j)
	{
		Edge* edge = new Edge(m_Nodes[i],m_Nodes[j]);
		int index = m_Edges.size();
		m_Edges.push_back(edge);
		m_RawGraph[i][j] = index;
		m_RawGraph[j][i] = index;
		return edge;
	}
	Mesh::Mesh(int width, int height)
	{
		m_Polygons = new PolygonContainer(width,height);
	}

	Mesh::~Mesh()
	{
	}
	void Mesh::AddPolygon(vector<Node*> vertexs)
	{
		if(vertexs.size() < 3) return;
		bool isHole = TestPointInside(vertexs[0]->X,vertexs[0]->Y);
		int index = m_Nodes.size();
		int min_x = INF;
		int min_y = INF;
		int max_x = 0;
		int max_y = 0;
		vector<Node*>::iterator it = vertexs.begin();
		vector<Node*>::iterator it_begin = vertexs.begin();
		vector<Node*>::iterator it_end = vertexs.end()-1;
		for(;it!= vertexs.end();it++)
		{
			Node* prev;
			Node* current;
			Node* next;
			current = *it;
			if(it == it_begin) prev = *(it_end); else prev = *(it-1);
			if(it == it_end) next = *(it_begin); else next = *(it+1);

			float cross = ((current->X - prev->X) * (next->Y - current->Y)) -
				((current->Y - prev->Y) * (next->X - current->X));
			current->Convex = cross < 0;
			if(isHole)
				current->Convex = !current->Convex;
			AddNode(current);
			int x = current->X;
			int y = current->Y;
			if(x < min_x) min_x = x;
			if(y < min_y) min_y = y;
			if(x > max_x) max_x = x;
			if(y > max_y) max_y = y;
		}
		Polygon* polygon = new Polygon();
		Edge* current = Connect(index+vertexs.size() - 1, index);
		polygon->SetIsHole(isHole);
		polygon->SetFirstEdge(current);
		polygon->SetBoundingBox(min_x, min_y, max_x, max_y);
		for(unsigned int i = 1;i < vertexs.size();i++)
		{
			Edge* next = Connect(index + i - 1,index + i);
			current->SetNextSibling(next);
			current = next;
		}
		m_Polygons->Insert(polygon);
	}
	void Mesh::BuildVisiGraph()
	{
		m_VisibilityGraph.clear();
		m_VisibilityEdges.clear();
		vector<Node*>::iterator it = m_Nodes.begin();
		for(unsigned int i = 0;i < m_Nodes.size();i++)
		{
			Node* nodei = *(it+i);
			vector<int> row;
			for(unsigned int j = 0;j < m_Nodes.size();j++)
			{
				if(i == j)
				{
					row.push_back(INF);
					continue;
				}
				if(i > j)
				{
					row.push_back(m_VisibilityGraph[j][i]);
					continue;
				}
				Node* nodej = *(it+j);
				if(!nodej->Convex || !nodei->Convex)
				{
					row.push_back(INF);
					continue;
				}
				if(m_RawGraph[i][j] != INF)
				{
					int index = m_VisibilityEdges.size();
					m_VisibilityEdges.push_back(m_Edges[m_RawGraph[i][j]]);
					row.push_back(index);
					continue;
				}
				Edge* test_edge = new Edge(nodei,nodej);
				if(!TestEdgeInside(test_edge))
				{
					row.push_back(INF);
					continue;
				}
				int index = m_VisibilityEdges.size();
				m_VisibilityEdges.push_back(test_edge);
				row.push_back(index);
			}
			m_VisibilityGraph.push_back(row);
		}
	}
	void Mesh::BuildShortcutGraph()
	{
		// TODO: build shortcut graph, this is draft, need to work on
		m_ShortcutGraph.clear();
		for(unsigned int i = 0;i < m_Nodes.size();i++)
		{
			vector<int> row;
			for(unsigned int j = 0;j < m_Nodes.size();j++)
			{
				row.push_back(m_VisibilityGraph[i][j]);
			}
			m_ShortcutGraph.push_back(row);
		}
	}
}