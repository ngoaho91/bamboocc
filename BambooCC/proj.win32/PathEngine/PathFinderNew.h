#pragma once
#include <stack>
#include "../Geometry/QuadTree.h"
#include "PathRenderNew.h"
#include "bg_typedef.h"
namespace PathEngine
{
	class PolygonQuadObject
		: public Geometry::QuadObject
	{
	private:
		polygon_type m_Polygon;
	public:
		PolygonQuadObject(int min_x, int min_y, int max_x, int max_y);
		~PolygonQuadObject();
		void SetPolygon(polygon_type value);
		polygon_type GetPolygon();
	};
	class PathFinderNew
	{
	private:
		vector< vector<double> > m_Matrix;
		points_type m_Vertexs;
		vector<int> m_VertexPrev;
		Geometry::QuadTree* m_QuadTree;
		PathRenderNew* m_Render;
	private:
		bool IsConvex(point_type prev, point_type current, point_type next, bool outer);
		double GetLength(point_type u, point_type v);
		double GetLength(int u, int v);
		bool TestIntersect(polygon_type_open poly1, polygon_type poly2, bool consider_touch = false);
		void AddSinglePolygon(polygon_type poly);
		void SinglePolygonToMatrix(ring_type ring, bool outer);
	public:
		PathFinderNew();
		~PathFinderNew();
		void AddSinglePolygon(vertexs points);
		void UnionPolygon();
		void PolygonToMatrix();
		void FindPath(double x, double y, double gx, double gy, vector<vertex>* result);
		bool TestIntersect(double x1, double y1, double x2, double y2, bool consider_touch = false);
		bool TestPointInPolygon(double x, double y, bool consider_touch = false);
		bool FixPoint(double* x, double* y, bool consider_touch = false, double jump_length = 5.0, int max_try = 10);
	public:
		void SelfTest();
		PathRenderNew* GetRender(){ return m_Render;}
	};
}