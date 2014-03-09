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
		Rectangle*	m_BoundingBox;
		double		m_Length;
	public:
		Segment();
		Segment(Node* nodeA, Node* nodeB);
		~Segment();
		Rectangle*	GetBoundingBox(){ return m_BoundingBox;}
		void		Calculate();
		double		GetLength();
		Node*		A(){ return first;}
		Node*		B(){ return second;}
	};
	double NodeSegmentDistance(Segment* edge, Node* p);
	
}
#endif