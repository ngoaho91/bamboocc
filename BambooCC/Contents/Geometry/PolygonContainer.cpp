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
	IntersectResult PolygonContainer::QueryPointInPolygon(Node* node)
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
				SimplePolygon* poly = (SimplePolygon*)quad;
				IntersectResult ret = PointInPolygon(node, poly);
				if (ret != IR_SEPERATE) return ret;
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
		return IR_SEPERATE;
	}
	IntersectResult PolygonContainer::QueryPolygonSegmentIntersect(Segment* s)
	{
		queue<QuadTree*> trees;
		trees.push(this);
		int lx = s->GetBoundingBox()->GetMinX();
		int ly = s->GetBoundingBox()->GetMinY();
		int hx = s->GetBoundingBox()->GetMaxX();
		int hy = s->GetBoundingBox()->GetMaxY();
		IntersectResult ret = IR_SEPERATE;
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
				SimplePolygon* poly = (SimplePolygon*)quad;
				IntersectResult ret1 = PolygonSegmentIntersect(s, poly);
				if (ret1 == IR_WITHIN || ret1 == IR_INTERSECT) return ret1;
				ret = ret1;
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
		return ret;
	}
}