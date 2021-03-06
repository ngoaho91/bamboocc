#ifndef FightMaterial_h
#define FightMaterial_h
namespace FightEngine
{
	enum ElementSeries
	{
		ES_METAL,
		ES_PLANT,
		ES_ICE,
		ES_FIRE,
		ES_EARTH
	};
	enum FightScope
	{
		FS_FRIEND,
		FS_FOE,
		FS_NEUTRAL,
		FS_ALL,
		FS_NOT_NEUTRAL,
		FS_NOT_FRIEND,
		FS_NOT_FOE
	};
	enum FightWeapon
	{
		FW_FREE,
		FW_BLOW,// quyền pháp
		FW_CLAW, // trảo pháp
		FW_PALM,// chưởng pháp
		FW_FINGER,// chỉ pháp
		FW_SWORD,// kiếm pháp
		FW_DOUBLE_SWORD,// song kiếm
		FW_BLADE,// đao pháp
		FW_DOUBLE_BLADE,// song đao
		FW_CLUB,// chùy pháp
		FW_DOUBLE_CLUB,// song chùy
		FW_AXE,// phủ pháp
		FW_DOUBLE_AXE,// song phủ
		FW_STAFF,// bổng pháp/côn pháp
		FW_LANCE,// mâu pháp
		FW_DAGGER// phi đao
	};
}
#endif