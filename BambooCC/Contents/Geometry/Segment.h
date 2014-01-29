#ifndef Edge_H
#define Edge_H
#include "Node.h"
#include "Rectangle.h"

namespace Geometry
{
	class Segment
		:public pair<Node*, Node*>
	{
	private:
		Rectangle* m_BoundingBox;
		double m_Length;
	public:
		Segment();
		~Segment();
		Segment(Node* nodeA, Node* nodeB);
		Rectangle* GetBoundingBox(){ return m_BoundingBox;}
		void Calculate();
		double GetLength();
		Node* GetNodeA(){ return first;}
		Node* GetNodeB(){ return second;}
	};
	double PointSegmentDistance(Segment* edge, Node* p);
	
}
#endif