#pragma once
#include "cocos2d.h"
#include "bg_typedef.h"
#include <stack>
using namespace cocos2d;
namespace PathEngine
{
	class PathRenderNew : public CCLayer
	{
	private:
		CCNode*					m_ParentNode;
		vector<vector<double> > m_Matrix;
		points_type				m_Vertexs;
		vector<vertex>			m_Path;
	public:
		PathRenderNew();
		~PathRenderNew();
		virtual void			draw();
		void					SetParentNode(CCNode* parent);
		void					SetVertexs(points_type vertexs){ m_Vertexs = vertexs;}
		void					SetMatrix(vector<vector<double> > matrix){ m_Matrix = matrix;}
		void					SetPath(vector<vertex> path);
	};
}