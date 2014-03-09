#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
namespace Geometry
{
	enum ConvexResult
	{
		CR_STRAIGHT = 0,
		CR_CONVEX = 1,
		CR_CONCAVE = 2
	};
	class Vector;
	class Node;
	class Node
		:public pair<double, double>
	{
	public:
		Node(double x, double y);
		double X(){ return first; }
		double Y(){ return second; }
		void Apply(Vector* v);
		bool Equal(Node* other);
	};
	class Vector
		:public pair<double, double>
	{
	public:
		Vector(double x, double y);
		Vector(Node* a, Node* b);
		void Inverse();
		void Multiply(double m);
		double X(){ return first; }
		double Y(){ return second; }
	};
	typedef vector<Node*> Nodes;
	ConvexResult GetConvex(Node* prev, Node* current, Node* next);
	double Distance(Node* u, Node* v);
	double Normal(Vector* v);
	double DotProduct(Vector* u, Vector* v);
}
#endif