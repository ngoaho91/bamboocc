#include "TilemapRender.h"
namespace TileEngine
{
	TilemapRender::TilemapRender(int width, int height)
	{
		m_MapWidth = width;
		m_MapHeight = height;
		m_MatrixAB = new CCSprite**[width];
		m_MatrixID = new short*[width];
		for(int i=0;i<width;i++)
		{
			m_MatrixAB[i] = new CCSprite*[height];
			m_MatrixID[i] = new short[height];
			for(int j = 0;j<height;j++)
			{
				m_MatrixAB[i][j] = 0;
				m_MatrixID[i][j] = 14;
			}
		}
		m_SpriteAB = CCSprite::create();
		m_SpriteAB->setPosition(ccp(0,0));
		m_SpriteAB->setAnchorPoint(ccp(0,0));
		m_SpriteB = CCSprite::create();
		m_SpriteB->setPosition(ccp(0,0));
		m_SpriteB->setAnchorPoint(ccp(0,0));
		m_SetID = "";
		m_ParentNode = 0;
	}
	TilemapRender::~TilemapRender()
	{
	}
	void TilemapRender::SetParentNode(CCNode* parent)
	{
		if(m_ParentNode != parent)
		{
			if(m_ParentNode)
			{
				m_ParentNode->removeChild(m_SpriteAB,false);
				m_ParentNode->removeChild(m_SpriteB,false);
				parent->addChild(m_SpriteAB,2);
				parent->addChild(m_SpriteB,1);
			}
			else
			{
				parent->addChild(m_SpriteAB,2);
				parent->addChild(m_SpriteB,1);
			}
			m_SpriteB->setPosition(ccp(0,0));
			m_SpriteAB->setPosition(ccp(0,0));
			m_ParentNode = parent;
		}
	}
	void TilemapRender::Resize(int width, int height)
	{
		short** pMatrixID;
		CCSprite*** pMatrixAB;
		pMatrixID = new short*[width];
		pMatrixAB = new CCSprite**[width];
		for(int i=0;i<width;i++)
		{
			pMatrixID[i] = new short[height];
			pMatrixAB[i] = new CCSprite*[height];
			for(int j=0;j<height;j++)
			{
				if(i<m_MapWidth && j< m_MapHeight)
				{
					pMatrixID[i][j] = m_MatrixID[i][j];
					pMatrixAB[i][j] = m_MatrixAB[i][j];
				}
				else
				{
					pMatrixID[i][j] = 14;
					pMatrixAB[i][j] = 0;
				}
			}
		}
		for(int i=0;i<m_MapWidth;i++)
		{
			delete m_MatrixID[i];
			delete m_MatrixAB[i];
		}
		m_MatrixID = pMatrixID;
		m_MatrixAB = pMatrixAB;
		m_MapWidth = width;
		m_MapHeight = height;
	}
	void TilemapRender::setTile(int x, int y, int id)
	{
		y = m_MapHeight-1-y;
		if(id == m_MatrixID[x][y]) return;
		m_MatrixID[x][y] = id;
		if(id == 14 && m_MatrixAB[x][y])
		{
			m_SpriteAB->removeChild(m_MatrixAB[x][y],true);
			//m_MatrixAB[x][y]->release();
		}
		else
		{
			ostringstream texturePath;
			texturePath<<"resources.pak/terrain/";
			texturePath<<m_SetID<<"-"<<id<<".png";
			if(m_MatrixAB[x][y])
			{
				if(m_SetID != "")
				{
					m_MatrixAB[x][y]->setTexture(
						CCTextureCache::sharedTextureCache()->addImage(texturePath.str().c_str())
						);
				}
			}
			else
			{
				if(m_SetID != "")
				{
					m_MatrixAB[x][y] = CCSprite::create(texturePath.str().c_str());
				}
				else
				{
					m_MatrixAB[x][y] = CCSprite::create();
				}
				m_MatrixAB[x][y]->setPosition(ccp(x*64,y*64));
				m_MatrixAB[x][y]->setAnchorPoint(ccp(0,0));
				m_SpriteAB->addChild(m_MatrixAB[x][y],1);
			}
		}
	}
	void TilemapRender::SetTileset(const char* setName)
	{
		if(m_SetID == setName) return;
		m_SetID = setName;
		for(int i=0;i<m_MapWidth;i++)
		{
			for(int j=0;j<m_MapHeight;j++)
			{
				if(!m_MatrixAB[i][j]) continue;
				ostringstream texturePath;
				texturePath<<"resources.pak/terrain/";
				texturePath<<m_SetID<<"-"<<m_MatrixID[i][j]<<".png";
				m_MatrixAB[i][j]->setTexture(
						CCTextureCache::sharedTextureCache()->addImage(texturePath.str().c_str())
						);
			}
		}
		generateBackground();
	}
	void TilemapRender::generateBackground()
	{
		ostringstream texturePath;
		texturePath<<"resources.pak/terrain/";
		texturePath<<m_SetID<<"-14.png";
		
		CCRenderTexture* rt = CCRenderTexture::create(64,64);
		rt->begin();
		CCSprite* tile1 = CCSprite::create(texturePath.str().c_str());
		tile1->setAnchorPoint(ccp(0,0));
		tile1->setPosition(ccp(0,0));
		tile1->visit();
		rt->end();

		CCTexture2D* texture = rt->getSprite()->getTexture();
		ccTexParams tp = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
		texture->setTexParameters(&tp);
		m_SpriteB->setTexture(texture);
		m_SpriteB->setTextureRect(CCRectMake(0, 0, m_MapWidth*64, m_MapHeight*64));
	}

}