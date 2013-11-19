#ifndef PassiveSkill_h
#define PassiveSkill_h
namespace FightEngine
{
	class PassiveSkill
	{
	private:
	public:
		PassiveSkill();
		~PassiveSkill();
		void LoadXml(const char* xmlFile);
		void LevelUp();
	};
}
#endif