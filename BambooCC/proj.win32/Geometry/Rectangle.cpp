#include "Rectangle.h"
namespace Geometry
{
	Rectangle::Rectangle(int min_x, int min_y, int max_x, int max_y)
	{
		m_MinX = min_x;
		m_MinY = min_y;
		m_MaxX = max_x;
		m_MaxY = max_y;
		m_Width = m_Height = -1;
	}
	Rectangle::~Rectangle()
	{
	}
	int Rectangle::GetWidth()
	{
		if(m_Width == -1) m_Width = m_MaxX - m_MinX;
		return m_Width;
	}
	int Rectangle::GetHeight()
	{
		if(m_Height == -1) m_Height = m_MaxY - m_MinY;
		return m_Height;
	}
	bool Rectangle::TestPointInside(int x, int y)
	{
		if(x < m_MinX) return false;
		if(x > m_MaxX) return false;
		if(y < m_MinY) return false;
		if(y > m_MaxY) return false;
		return true;
	}
	bool Rectangle::Collide(Rectangle* other, bool consider_touch)
	{
		if(consider_touch)
		{
			if(other->m_MinX > this->m_MaxX) return false;
			if(other->m_MaxX < this->m_MinX) return false;
			if(other->m_MinY > this->m_MaxY) return false;
			if(other->m_MaxY < this->m_MinY) return false;
		}
		else
		{
			if(other->m_MinX >= this->m_MaxX) return false;
			if(other->m_MaxX <= this->m_MinX) return false;
			if(other->m_MinY >= this->m_MaxY) return false;
			if(other->m_MaxY <= this->m_MinY) return false;
		}
		return true;
	}
}