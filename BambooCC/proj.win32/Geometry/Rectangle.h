#ifndef PathFinderRectangle_h
#define PathFinderRectangle_h
namespace Geometry
{
	class Rectangle
	{
	private:
		int m_MinX;
		int m_MinY;
		int m_MaxX;
		int m_MaxY;
		int m_Width;
		int m_Height;
	public:
		Rectangle(int min_x, int min_y, int max_x, int max_y);
		~Rectangle();
		void SetMaxX(int value){ m_MaxX = value;}
		void SetMaxY(int value){ m_MaxY = value;}
		void SetMinX(int value){ m_MinX = value;}
		void SetMinY(int value){ m_MinY = value;}

		int GetMaxX(){ return m_MaxX;}
		int GetMaxY(){ return m_MaxY;}
		int GetMinX(){ return m_MinX;}
		int GetMinY(){ return m_MinY;}
		int GetWidth();
		int GetHeight();
		bool Collide(Rectangle* other, bool consider_touch=false);
		bool TestPointInside(int x, int y);
	};
}
#endif