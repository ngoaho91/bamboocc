#include "QuadTree.h"
namespace Geometry
{
	const int QuadTree::MAX_OBJECTS = 10;
	const int QuadTree::MAX_LEVEL = 4;
	QuadTree::QuadTree()
	{
		m_BoundingBox = 0;
		m_Level = 0;
		m_MidX = 0;
		m_MidY = 0;
		m_ParentNode = 0;
		m_SubNodes[0] = 0;
		m_SubNodes[1] = 0;
		m_SubNodes[2] = 0;
		m_SubNodes[3] = 0;
	}
	QuadTree::QuadTree(int width, int height, 
		int x, int y, int level, QuadTree* parent)
	{
		m_BoundingBox = new Rectangle(x, y, x + width, y + height);
		m_Level = level;
		m_MidX = (width + x)/2;
		m_MidY = (height + y)/2;
		m_ParentNode = parent;
		m_SubNodes[0] = 0;
		m_SubNodes[1] = 0;
		m_SubNodes[2] = 0;
		m_SubNodes[3] = 0;
	}
	QuadTree::~QuadTree()
	{
	}
	void QuadTree::SetBoundingBox(Rectangle* rect)
	{
		m_BoundingBox = rect;
	}
	void QuadTree::SetBoundingBox(int min_x, int min_y, int max_x, int max_y)
	{
		m_BoundingBox = new Rectangle(min_x,min_y,max_x,max_y);
	}
	void QuadTree::Clear()
	{
		m_Objects.clear();
		if(!m_SubNodes[0]) return;
		m_SubNodes[0]->Clear();
		delete m_SubNodes[0];
		m_SubNodes[0] = 0;
		m_SubNodes[1]->Clear();
		delete m_SubNodes[1];
		m_SubNodes[1] = 0;
		m_SubNodes[2]->Clear();
		delete m_SubNodes[2];
		m_SubNodes[2] = 0;
		m_SubNodes[3]->Clear();
		delete m_SubNodes[3];
		m_SubNodes[3] = 0;
	}
	TREE_LOCATION QuadTree::GetLocation(int x, int y)
	{
		if(m_SubNodes[0] == 0) return TL_CURRENT;
		if(y > m_MidY)
		{
			if(x > m_MidX)
			{
				return TL_CHILD0;
			}
			else
			{
				return TL_CHILD1;
			}
		}
		else
		{
			if(x < m_MidX)
			{
				return TL_CHILD2;
			}
			else
			{
				return TL_CHILD3;
			}
		}
	}
	TREE_LOCATION QuadTree::GetLocation(int lx, int ly, int hx, int hy)
	{
		if(m_SubNodes[0] == 0) return TL_CURRENT;
		if(ly > m_MidY)
		{
			if(lx > m_MidX)
			{
				return TL_CHILD0;
			}
			else if(hx < m_MidX)
			{
				return TL_CHILD1;
			}
			else
			{
				return TL_CURRENT;
			}
		}
		else if(hy < m_MidY)
		{
			if(hx < m_MidX)
			{
				return TL_CHILD2;
			}
			else if(lx > m_MidX)
			{
				return TL_CHILD3;
			}
			else
			{
				return TL_CURRENT;
			}
		}
		else
		{
			return TL_CURRENT;
		}
	}
	void QuadTree::Insert(QuadObject* object)
	{
		if(!m_SubNodes[0])
		{
			object->m_ParentNode = this;
			m_Objects.push_back(object);
			if(m_Objects.size() >= MAX_OBJECTS)
			{
				split();
			}
		}
		else
		{
			Rectangle* object_aabb = object->GetBoundingBox();
			TREE_LOCATION location = GetLocation(
				object_aabb->GetMinX(),
				object_aabb->GetMinY(),
				object_aabb->GetMaxX(),
				object_aabb->GetMaxY());
			if(location == TL_CHILD0)
			{
				m_SubNodes[0]->Insert(object);
			}
			else if(location == TL_CHILD1)
			{
				m_SubNodes[1]->Insert(object);
			}
			else if(location == TL_CHILD2)
			{
				m_SubNodes[2]->Insert(object);
			}
			else if(location == TL_CHILD3)
			{
				m_SubNodes[3]->Insert(object);
			}
			else
			{
				m_Objects.push_back(object);
			}
		}
	}
	void QuadTree::UpdateObject(QuadObject* object)
	{
		QuadTree* current = this;
		Rectangle* object_aabb = object->GetBoundingBox();
		Rectangle* current_aabb = object->GetBoundingBox();
		bool out = object_aabb->GetMinX() < current_aabb->GetMinX() ||
			object_aabb->GetMinY() < current_aabb->GetMinY() ||
			object_aabb->GetMaxX() > current_aabb->GetMaxX() ||
			object_aabb->GetMaxY() > current_aabb->GetMaxY();
		if(!out) return;
		QuadObjectIterator it;
		for(it = m_Objects.begin();it<m_Objects.end();it++)
		{
			QuadObject* item = (*it);
			if(item == object)
			{
				m_Objects.erase(it);
				break;
			}
		}
		while(current)
		{
			if(out)
			{
				current = current->m_ParentNode;
				out = object_aabb->GetMinX() < current_aabb->GetMinX() ||
					object_aabb->GetMinY() < current_aabb->GetMinY() ||
					object_aabb->GetMaxX() > current_aabb->GetMaxX() ||
					object_aabb->GetMaxY() > current_aabb->GetMaxY();
			}
			else 
			{
				current->Insert(object);
				break;
			}
		}
	}
	void QuadTree::split()
	{
		if(m_Level == MAX_LEVEL) return;
		int width = m_BoundingBox->GetWidth()/2;
		int height = m_BoundingBox->GetHeight()/2;
		int level = m_Level+1;
		m_SubNodes[0] = new QuadTree(width,height,m_MidX,m_MidY,level, this);
		m_SubNodes[1] = new QuadTree(width,height,0,m_MidY,level, this);
		m_SubNodes[2] = new QuadTree(width,height,0,0,level, this);
		m_SubNodes[3] = new QuadTree(width,height,m_MidX,0,level, this);
		QuadObjectIterator it = m_Objects.begin();
		while(it!=m_Objects.end())
		{
			QuadObjectIterator next = it+1;
			QuadObject* object = (*it);
			Rectangle* object_aabb = object->GetBoundingBox();
			TREE_LOCATION location = GetLocation(
				object_aabb->GetMinX(),
				object_aabb->GetMinY(),
				object_aabb->GetMaxX(),
				object_aabb->GetMaxY());
			if(location == TL_CHILD0)
			{
				m_SubNodes[0]->Insert(object);
				next = m_Objects.erase(it);
			}
			else if(location == TL_CHILD1)
			{
				m_SubNodes[1]->Insert(object);
				next = m_Objects.erase(it);
			}
			else if(location == TL_CHILD2)
			{
				m_SubNodes[2]->Insert(object);
				next = m_Objects.erase(it);
			}
			else if(location == TL_CHILD3)
			{
				m_SubNodes[3]->Insert(object);
				next = m_Objects.erase(it);
			}
			it = next;
		}
	}
}