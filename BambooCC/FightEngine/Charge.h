#ifndef Charge_h
#define Charge_h
namespace FightEngine
{
	class Charge
	{
	private:
		const char* m_Name;
		int m_Count;
		int m_Max;
	public:
		Charge();
		~Charge();
		const char* GetName(){ return m_Name;}
		void SetName(const char* value){ m_Name = value;}
		int GetCount(){ return m_Count;}
		int GetMax(){ return m_Max;}
		void SetMax(int value){ m_Max = value;}
		void Increase();
		void Decrease();
	};
}
#endif