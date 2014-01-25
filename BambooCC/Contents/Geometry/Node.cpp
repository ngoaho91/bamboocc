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
	bool Node::Equal(Node* other)
	{
		if (this->X() != other->X()) return false;
		if (this->Y() != other->Y()) return false;
		return true;
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
	ConvexResult GetConvex(Node* prev, Node* current, Node* next)
	{
		double cross = ((current->X() - prev->X()) * (next->Y() - current->Y())) -
			((current->Y() - prev->Y()) * (next->X() - current->X()));
		if (cross == 0) return CR_STRAIGHT;
		if (cross < 0) return CR_CONVEX;
		return CR_CONCAVE;
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