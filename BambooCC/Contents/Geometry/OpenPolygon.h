#ifndef OPENPOLYGON_H
#define OPENPOLYGON_H
#include "Polygon.h"
namespace Geometry
{
	class OpenPolygon
		:public Polygon
	{
	private:
		bool* m_Portal;
	public:
		OpenPolygon();
		OpenPolygon(Polygon* polygon);
		~OpenPolygon();
		void ResetPortal();
		void SetPortal(int index, bool value){ m_Portal[index] = value;}
		bool IsPortal(int index){return m_Portal[index];}
	};
}
#endif