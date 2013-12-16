#include "PolygonContainer.h"
#include <queue>
namespace Geometry
{
	PolygonContainer::PolygonContainer(int width, int height)
		:QuadTree(width,height)
	{
		//QuadTree::QuadTree(width,height);
	}
	PolygonContainer::~PolygonContainer()
	{
	}
	bool PolygonContainer::QueryPointInPolygon(Node* node, 
		bool consider_touch)
	{
		QuadTree* tree = this;
		while(tree)
		{
			if(tree == 0) continue;
			QuadObjects objects = tree->GetObjects();
			QuadObjectIterator it = objects.begin();
			for(;it != objects.end();it++)
			{
				QuadObject* quad = *it;
				Polygon* poly = (Polygon*)quad;
				bool inside = PointInPolygon(node, poly, consider_touch);
				if(inside) return true;
			}
			Geometry::TREE_LOCATION location = tree->GetLocation(node->X(), node->Y());
			if(location == Geometry::TL_CHILD0)
			{
				tree = tree->SubNode(0);
			}
			else if(location == Geometry::TL_CHILD1)
			{
				tree = tree->SubNode(1);
			}
			else if(location == Geometry::TL_CHILD2)
			{
				tree = tree->SubNode(2);
			}
			else if(location == Geometry::TL_CHILD3)
			{
				tree = tree->SubNode(3);
			}
			else
			{
				break;
			}
		}
		return false;
	}
	bool PolygonContainer::QueryPolygonSegmentIntersect(Edge* edge, 
		bool consider_touch)
	{
		queue<QuadTree*> trees;
		trees.push(this);
		int lx = edge->GetBoundingBox()->GetMinX();
		int ly = edge->GetBoundingBox()->GetMinY();
		int hx = edge->GetBoundingBox()->GetMaxX();
		int hy = edge->GetBoundingBox()->GetMaxY();
		while(!trees.empty())
		{
			QuadTree* tree = trees.front();
			trees.pop();
			if(tree == 0) continue;
			QuadObjects objects = tree->GetObjects();
			QuadObjectIterator it = objects.begin();
			for(;it != objects.end();it++)
			{
				QuadObject* quad = *it;
				Polygon* poly = (Polygon*)quad;
				bool intersect = PolygonSegmentIntersect(edge, poly, consider_touch);
				if(intersect) return true;
			}
			
			Geometry::TREE_LOCATION location = tree->GetLocation(lx, ly, hx, hy);
			if(location == Geometry::TL_CHILD0)
			{
				trees.push(tree->SubNode(0));
			}
			else if(location == Geometry::TL_CHILD1)
			{
				trees.push(tree->SubNode(1));
			}
			else if(location == Geometry::TL_CHILD2)
			{
				trees.push(tree->SubNode(2));
			}
			else if(location == Geometry::TL_CHILD3)
			{
				trees.push(tree->SubNode(3));
			}
			else
			{
				trees.push(tree->SubNode(0));
				trees.push(tree->SubNode(1));
				trees.push(tree->SubNode(2));
				trees.push(tree->SubNode(3));
			}
		}
		return false;
	}
}