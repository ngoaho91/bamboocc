#include "PathRenderNew.h"
namespace PathEngine
{
	PathRenderNew::PathRenderNew()
	{
	}
	PathRenderNew::~PathRenderNew()
	{
	}
	void PathRenderNew::draw()
	{
		{
			ccPointSize(10);
			ccDrawColor4B(255, 255, 255, 255);
			points_iterator it = m_Vertexs.begin();
			for(;it != m_Vertexs.end();it++)
			{
				point_type v = *it;
				double vx = bg::get<0,point_type>(v);
				double vy = bg::get<1,point_type>(v);
				ccDrawColor4B(255, 255, 255, 255);
				ccDrawPoint(ccp(vx*50,vy*50));
			}
		}
		{
			ccDrawColor4B(255, 0, 0, 255);
			vector<vector<double> >::iterator it = m_Matrix.begin();
			points_iterator it_p1 = m_Vertexs.begin();
			for(;it != m_Matrix.end();it++,it_p1++)
			{
				vector<double> row = *it;
				vector<double>::iterator it2 = row.begin();
				points_iterator it_p2 = m_Vertexs.begin();
				for(;it2 != row.end();it2++,it_p2++)
				{
					double len = *it2;
					if(len == INF) continue;
					point_type p1 = *it_p1;
					point_type p2 = *it_p2;
					double p1x = bg::get<0,point_type>(p1);
					double p1y = bg::get<1,point_type>(p1);
					double p2x = bg::get<0,point_type>(p2);
					double p2y = bg::get<1,point_type>(p2);
					ccDrawLine(ccp(p1x*50,p1y*50), ccp(p2x*50,p2y*50));
				}
			}
		}
		if(m_Path.size() > 1){
			ccDrawColor4B(255, 255, 255, 255);
			vertex point_u;
			vertex point_v;
			for(int i=0;i<m_Path.size()-1;)
			{
				point_u = m_Path[i++];
				point_v = m_Path[i];
				double ux = point_u.first;
				double uy = point_u.second;
				double vx = point_v.first;
				double vy = point_v.second;
				ccDrawLine(ccp(ux*50,uy*50), ccp(vx*50,vy*50));
			}
		}
	}
	void PathRenderNew::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode == parent) return;
		if(m_ParentNode)
		{
			m_ParentNode->removeChild(this,false);
		}
		parent->addChild(this,9000000);
		m_ParentNode = parent;
	}
	void PathRenderNew::SetPath(vector<vertex> path)
	{
		m_Path = path;
	}
}