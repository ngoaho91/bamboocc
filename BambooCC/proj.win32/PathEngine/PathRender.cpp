#include "PathRender.h"
namespace PathEngine
{
	PathRender::PathRender()
		:CCLayer()
	{
		m_Mesh = 0;
		m_DrawGraph = true;
		m_DrawPath = true;
		m_DrawVisibilityGraph = true;
		m_DrawComplete = true;// default false
		m_ParentNode = 0;
	}
	PathRender::~PathRender()
	{
	}
	void PathRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode == parent) return;
		if(m_ParentNode)
		{
			m_ParentNode->removeChild(this,false);
		}
		parent->addChild(this,9000000);
		m_ParentNode = parent;
	}
	void PathRender::draw()
	{
		int size;
		ccPointSize(10);
		if(m_Mesh)
		{
			if(m_DrawVisibilityGraph)
			{
				CHECK_GL_ERROR_DEBUG();
				ccDrawColor4B(255, 255, 255, 255);
				size = m_Mesh->m_VisibilityEdges.size();
				for(int i=0;i<size;i++)
				{
					Edge* edge = m_Mesh->m_VisibilityEdges[i];
					Node* a = edge->GetNodeA();
					Node* b = edge->GetNodeB();
					ccDrawLine(ccp(a->X,a->Y), ccp(b->X,b->Y));
				}
				

			}
			if(m_DrawGraph)
			{
				CHECK_GL_ERROR_DEBUG();
				ccDrawColor4B(255, 0, 0, 255);
				size = m_Mesh->m_Edges.size();
				for(int i=0;i<size;i++)
				{
					Node* a = m_Mesh->m_Edges[i]->GetNodeA();
					Node* b = m_Mesh->m_Edges[i]->GetNodeB();
					ccDrawLine(ccp(a->X,a->Y), ccp(b->X,b->Y));
				}
			}
			CHECK_GL_ERROR_DEBUG();
			ccDrawColor4B(255, 0, 0, 255);
			size = m_Mesh->m_Nodes.size();
			for(int i=0;i<size;i++)
			{
				Node* a = m_Mesh->m_Nodes[i];
				ccDrawPoint(ccp(a->X,a->Y));
				if(!m_DrawComplete)
				{
					ostringstream soutA;
					soutA<<"N"<<i<<"("<<a->X<<","<<a->Y<<")";
					CCLabelTTF* labelA = CCLabelTTF::create(soutA.str().c_str(), "Code Bold", 15);
					addChild(labelA, 1);
					labelA->setPosition( ccp(a->X,a->Y-10) );
				}
			}
			m_DrawComplete = true;
		}
		if(m_DrawPath)
		{
			if(m_Path.size()>=2)
			{
				CHECK_GL_ERROR_DEBUG();
				size = m_Path.size();
				
				ccDrawColor4B(0, 128, 255, 255);
				ccDrawPoint(ccp(m_Path[0]->X,m_Path[0]->Y));
				ccDrawPoint(ccp(m_Path[size-1]->X,m_Path[size-1]->Y));
				ccDrawColor4B(0, 128, 255, 255);
				for(int i=0;i<size-1;i++)
				{
					Node* a = m_Path[i];
					Node* b = m_Path[i+1];
					ccDrawLine(ccp(a->X,a->Y), ccp(b->X,b->Y));
				}
			}
		}
	}
	void PathRender::SetDrawGraph(bool draw)
	{
		m_DrawGraph = draw;
	}
	void PathRender::ToggleDrawGraph()
	{
		m_DrawGraph = !m_DrawGraph;
	}
	void PathRender::SetDrawPath(bool draw)
	{
		m_DrawPath = draw;
	}
	void PathRender::SetDrawVisibility(bool draw)
	{
		m_DrawVisibilityGraph = draw;
	}
	void PathRender::ToggleDrawVisibility()
	{
		m_DrawVisibilityGraph = !m_DrawVisibilityGraph;
	}
	void PathRender::SetMesh(Mesh* mesh)
	{
		m_Mesh = mesh;
	}
	void PathRender::SetPath(vector<Node*> path)
	{
		m_Path = path;
	}
}