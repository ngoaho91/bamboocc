#ifndef PathFinderRectangle_h
#define PathFinderRectangle_h
namespace Geometry
{
	class Rectangle
	{
	private:
		double m_MinX;
		double m_MinY;
		double m_MaxX;
		double m_MaxY;
		double m_Width;
		double m_Height;
	public:
		Rectangle(double min_x, double min_y, double max_x, double max_y);
		~Rectangle();
		void SetMaxX(int value){ m_MaxX = value;}
		void SetMaxY(int value){ m_MaxY = value;}
		void SetMinX(int value){ m_MinX = value;}
		void SetMinY(int value){ m_MinY = value;}

		double GetMaxX(){ return m_MaxX; }
		double GetMaxY(){ return m_MaxY; }
		double GetMinX(){ return m_MinX; }
		double GetMinY(){ return m_MinY; }
		double GetWidth();
		double GetHeight();
		bool Collide(Rectangle* other, bool consider_touch=false);
		bool TestPointInside(double x, double y);
	};
}
#endif