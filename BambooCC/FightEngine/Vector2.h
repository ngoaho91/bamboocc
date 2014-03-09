#ifndef FightEngineVector2_h
#define FightEngineVector2_h
namespace FightEngine
{
	class Vector2
	{
	private:
		int m_X;
		int m_Y;
	public:
		Vector2(int x, int y)
		{
			m_X = x;
			m_Y = y;
		}
		Vector2()
		{
			m_X = 0;
			m_Y = 0;
		}
		int GetX(){ return m_X;}
		int GetY(){ return m_Y;}
		void SetX(int x){ m_X = x;}
		void SetY(int y){ m_Y = y;}
	};
}
#endif