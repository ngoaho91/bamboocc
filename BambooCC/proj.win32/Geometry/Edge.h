#ifndef Edge_H
#define Edge_H
#include "Node.h"
#include "Rectangle.h"
namespace Geometry
{
	class Edge
		:public pair<Node*, Node*>
	{
	private:
		Rectangle* m_BoundingBox;
		int m_Length;
	public:
		Edge();
		~Edge();
		Edge(Node* nodeA, Node* nodeB);
		Rectangle* GetBoundingBox(){ return m_BoundingBox;}
		void Calculate();
		int GetLength();
		Node* GetNodeA(){ return first;}
		Node* GetNodeB(){ return second;}
	};
	bool SegmentSegmentIntersect(Edge* edge1, Edge* edge2, bool consider_touch = false);
	bool SegmentSegmentIntersect(int ax, int ay, int bx, int by,
		int cx, int cy, int dx, int dy, bool consider_touch = false);
}
#endif