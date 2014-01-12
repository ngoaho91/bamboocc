#ifndef QuadTree_h
#define QuadTree_h
#include <vector>
#include "Rectangle.h"
#include "QuadObject.h"
#define QOT_DEFAULT 0
using namespace std;
namespace Geometry
{
	enum TREE_LOCATION
	{
		TL_CHILD0,
		TL_CHILD1,
		TL_CHILD2,
		TL_CHILD3,
		TL_CURRENT
	};
	class QuadTree
	{
		friend class		QuadObject;
	protected:
		static const int	MAX_OBJECTS;
		static const int	MAX_LEVEL;
		int					m_Level;
		Rectangle*			m_BoundingBox;
		int					m_MidX, m_MidY;
		QuadObjects			m_Objects;
		QuadTree*			m_SubNodes[4];
		QuadTree*			m_ParentNode;
	public:
		QuadTree();
		QuadTree(int width, int height, 
			int x = 0, int y = 0, int level = 0, QuadTree* parent = 0);
		~QuadTree();
	public:
		QuadObjects			GetObjects(){ return m_Objects; }
		QuadObjects*		GetObjectsPointer(){ return &m_Objects; }
		QuadTree*			GetParent(){ return m_ParentNode; }
		void				Clear();
		void				Insert(QuadObject* object);
		void				UpdateObject(QuadObject* object);
		TREE_LOCATION		GetLocation(int x, int y);
		TREE_LOCATION		GetLocation(int lx, int ly, int hx, int hy);
	public:
		QuadTree*			SubNode(int i){ return m_SubNodes[i];}
		int					GetMidX(){ return m_MidX;}
		int					GetMidY(){ return m_MidY;}
		Rectangle*			GetBoundingBox(){ return m_BoundingBox;}
		void				SetBoundingBox(Rectangle* rect);
		void				SetBoundingBox(int min_x, int min_y, int max_x, int max_y);
	private:
		void				split();
	};
}
#endif