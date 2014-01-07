#include "Node.h"
namespace Geometry
{
	Node::Node(double x, double y)
		:pair<double, double>(x, y){}
	
	void Node::Apply(Vector* v)
	{
		first += v->first;
		second += v->second;
	}
	Vector::Vector(double x, double y)
		:pair<double, double>(x, y){}
	Vector::Vector(Node* a, Node* b)
	{
		first = a->X() - b->X();
		second = a->Y() - b->Y();
	}
	void Vector::Inverse()
	{
		first = -first;
		second = -second;
	}
	void Vector::Multiply(double m)
	{
		first *= m;
		second *= m;
	}
	bool IsConvex(Node* prev, Node* current, Node* next, bool outer)
	{
		float cross = ((current->X() - prev->X()) * (next->Y() - current->Y())) -
			((current->Y() - prev->Y()) * (next->X() - current->X()));
		bool convex = outer ? cross < 0 : cross > 0;
		return convex;
	}
	double Normal(Vector* v)
	{
		return sqrt(DotProduct(v, v));
	}
	double DotProduct(Vector* u, Vector* v)
	{
		return u->X()*v->X() + u->Y()*v->Y();
	}
	double Distance(Node* u, Node* v)
	{
		return Normal(new Vector(u,v));
	}
}