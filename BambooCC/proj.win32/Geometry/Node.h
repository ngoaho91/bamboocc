#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
using namespace std;
namespace Geometry
{
	class Edge;
	class Node
		:public pair<int, int>
	{
	public:
		Node(int x, int y)
			:pair<int,int>(x,y)
		{
		}
		int X(){ return first;}
		int Y(){ return second;}
	};
	typedef vector<Node*> Nodes;
}
#endif