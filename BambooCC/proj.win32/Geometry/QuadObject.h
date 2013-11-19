#ifndef QuadObject_h
#define QuadObject_h
#include <vector>
#include "Rectangle.h"
namespace Geometry
{
	class QuadTree;
	class QuadObject
	{
		friend class QuadTree;
	protected:
		Rectangle*		m_BoundingBox;
		QuadTree*		m_ParentNode;
		int				m_ObjectType;
	public:
		QuadObject(int min_x, int min_y, int max_x, int max_y);
		~QuadObject();
	public:
		Rectangle*		GetBoundingBox(){ return m_BoundingBox;}
		void			SetBoundingBox(Rectangle* rect);
		void			SetBoundingBox(int min_x, int min_y, int max_x, int max_y);
		void			SetPosition(int x, int y);
		void			SetParentNode(QuadTree* parent);
	public:
		int				GetObjectType(){ return m_ObjectType;}
	};
	typedef std::vector<QuadObject*> QuadObjects;
	typedef std::vector<QuadObject*>::iterator QuadObjectIterator;
}

#endif