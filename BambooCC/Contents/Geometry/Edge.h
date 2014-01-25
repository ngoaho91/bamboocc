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
		double m_Length;
	public:
		Edge();
		~Edge();
		Edge(Node* nodeA, Node* nodeB);
		Rectangle* GetBoundingBox(){ return m_BoundingBox;}
		void Calculate();
		double GetLength();
		Node* GetNodeA(){ return first;}
		Node* GetNodeB(){ return second;}
	};
	double PointSegmentDistance(Edge* edge, Node* p);
	
}
#endif