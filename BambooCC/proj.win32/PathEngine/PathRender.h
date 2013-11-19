#ifndef PATHRENDER_H
#define PATHRENDER_H
#include "cocos2d.h"
#include "Mesh.h"
using namespace cocos2d;
using namespace Geometry;
namespace PathEngine
{
	class PathRender : public CCLayer
	{
	private:
		CCNode*					m_ParentNode;
		Mesh*					m_Mesh;
		vector<Node*>			m_Path;
		bool					m_DrawVisibilityGraph;
		bool					m_DrawGraph;
		bool					m_DrawPath;
		bool					m_DrawComplete;
	public:
		PathRender();
		~PathRender();
		virtual void			draw();
		void					SetParentNode(CCNode* parent);
		void					SetDrawGraph(bool draw);
		void					ToggleDrawGraph();
		void					SetDrawPath(bool draw);
		void					SetDrawVisibility(bool draw);
		void					ToggleDrawVisibility();
		void					SetMesh(Mesh* mesh);
		void					SetPath(vector<Node*> path);
	};
}
#endif