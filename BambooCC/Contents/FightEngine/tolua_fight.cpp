/*
** Lua binding: fight
** Generated automatically by tolua++-1.0.92 on 07/11/13 09:53:03.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_fight_open (lua_State* tolua_S);

#include "FightEngine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_FightEngine__Vector2 (lua_State* tolua_S)
{
 FightEngine::Vector2* self = (FightEngine::Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__Actor (lua_State* tolua_S)
{
 FightEngine::Actor* self = (FightEngine::Actor*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__RaySkill (lua_State* tolua_S)
{
 FightEngine::RaySkill* self = (FightEngine::RaySkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__AuraSkill (lua_State* tolua_S)
{
 FightEngine::AuraSkill* self = (FightEngine::AuraSkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__Charge (lua_State* tolua_S)
{
 FightEngine::Charge* self = (FightEngine::Charge*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__MissileSkill (lua_State* tolua_S)
{
 FightEngine::MissileSkill* self = (FightEngine::MissileSkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__Missile (lua_State* tolua_S)
{
 FightEngine::Missile* self = (FightEngine::Missile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__DamageRay (lua_State* tolua_S)
{
 FightEngine::DamageRay* self = (FightEngine::DamageRay*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__DamageField (lua_State* tolua_S)
{
 FightEngine::DamageField* self = (FightEngine::DamageField*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__Trap (lua_State* tolua_S)
{
 FightEngine::Trap* self = (FightEngine::Trap*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__Damage (lua_State* tolua_S)
{
 FightEngine::Damage* self = (FightEngine::Damage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__PassiveSkill (lua_State* tolua_S)
{
 FightEngine::PassiveSkill* self = (FightEngine::PassiveSkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__TargetData (lua_State* tolua_S)
{
 FightEngine::TargetData* self = (FightEngine::TargetData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__FightSkill (lua_State* tolua_S)
{
 FightEngine::FightSkill* self = (FightEngine::FightSkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__AOESkill (lua_State* tolua_S)
{
 FightEngine::AOESkill* self = (FightEngine::AOESkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_FightEngine__TrapSkill (lua_State* tolua_S)
{
 FightEngine::TrapSkill* self = (FightEngine::TrapSkill*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"FightEngine::World");
 tolua_usertype(tolua_S,"FightEngine::DamageField");
 tolua_usertype(tolua_S,"FightEngine::AuraSkill");
 tolua_usertype(tolua_S,"FightEngine::MissileSkill");
 tolua_usertype(tolua_S,"FightEngine::Buff");
 tolua_usertype(tolua_S,"FightEngine::TargetData");
 tolua_usertype(tolua_S,"FightEngine::TrapSkill");
 tolua_usertype(tolua_S,"FightEngine::AOESkill");
 tolua_usertype(tolua_S,"FightEngine::PassiveSkill");
 tolua_usertype(tolua_S,"FightEngine::Trap");
 tolua_usertype(tolua_S,"FightEngine::Vector2");
 tolua_usertype(tolua_S,"FightEngine::Actor");
 tolua_usertype(tolua_S,"FightEngine::Charge");
 tolua_usertype(tolua_S,"FightEngine::BuffItem");
 tolua_usertype(tolua_S,"FightEngine::Damage");
 tolua_usertype(tolua_S,"FightEngine::RaySkill");
 tolua_usertype(tolua_S,"FightEngine::DamageRay");
 tolua_usertype(tolua_S,"FightEngine::FightSkill");
 tolua_usertype(tolua_S,"FightEngine::Missile");
 tolua_usertype(tolua_S,"FightEngine::DamageItem");
}

/* get function: Target of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__TargetData_Target_ptr
static int tolua_get_FightEngine__TargetData_Target_ptr(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Target'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Target,"FightEngine::Actor");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Target of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__TargetData_Target_ptr
static int tolua_set_FightEngine__TargetData_Target_ptr(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Target'",NULL);
  if (!tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Target = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X1 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__TargetData_X1
static int tolua_get_FightEngine__TargetData_X1(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X1 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__TargetData_X1
static int tolua_set_FightEngine__TargetData_X1(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X1 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y1 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__TargetData_Y1
static int tolua_get_FightEngine__TargetData_Y1(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y1'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y1);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y1 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__TargetData_Y1
static int tolua_set_FightEngine__TargetData_Y1(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y1'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y1 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: X2 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__TargetData_X2
static int tolua_get_FightEngine__TargetData_X2(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->X2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: X2 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__TargetData_X2
static int tolua_set_FightEngine__TargetData_X2(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'X2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->X2 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Y2 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__TargetData_Y2
static int tolua_get_FightEngine__TargetData_Y2(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y2'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Y2);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Y2 of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__TargetData_Y2
static int tolua_set_FightEngine__TargetData_Y2(lua_State* tolua_S)
{
  FightEngine::TargetData* self = (FightEngine::TargetData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Y2'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Y2 = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TargetData_new00
static int tolua_fight_FightEngine_TargetData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::TargetData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::TargetData* tolua_ret = (FightEngine::TargetData*)  Mtolua_new((FightEngine::TargetData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::TargetData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::TargetData */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TargetData_new00_local
static int tolua_fight_FightEngine_TargetData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::TargetData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::TargetData* tolua_ret = (FightEngine::TargetData*)  Mtolua_new((FightEngine::TargetData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::TargetData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_new00
static int tolua_fight_FightEngine_FightSkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::FightSkill* tolua_ret = (FightEngine::FightSkill*)  Mtolua_new((FightEngine::FightSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::FightSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_new00_local
static int tolua_fight_FightEngine_FightSkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::FightSkill* tolua_ret = (FightEngine::FightSkill*)  Mtolua_new((FightEngine::FightSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::FightSkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_delete00
static int tolua_fight_FightEngine_FightSkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTargetData of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_SetTargetData00
static int tolua_fight_FightEngine_FightSkill_SetTargetData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"FightEngine::TargetData",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::TargetData target = *((FightEngine::TargetData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTargetData'", NULL);
#endif
  {
   self->SetTargetData(target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTargetData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_Cast00
static int tolua_fight_FightEngine_FightSkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_LevelUp00
static int tolua_fight_FightEngine_FightSkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaster of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_SetCaster00
static int tolua_fight_FightEngine_FightSkill_SetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* caster = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaster'", NULL);
#endif
  {
   self->SetCaster(caster);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaster of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_GetCaster00
static int tolua_fight_FightEngine_FightSkill_GetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaster'", NULL);
#endif
  {
   FightEngine::Actor* tolua_ret = (FightEngine::Actor*)  self->GetCaster();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_GetName00
static int tolua_fight_FightEngine_FightSkill_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLevel of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_GetLevel00
static int tolua_fight_FightEngine_FightSkill_GetLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLevel'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetLevel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetManaCost of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_GetManaCost00
static int tolua_fight_FightEngine_FightSkill_GetManaCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetManaCost'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetManaCost();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetManaCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHealthCost of class  FightEngine::FightSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_FightSkill_GetHealthCost00
static int tolua_fight_FightEngine_FightSkill_GetHealthCost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::FightSkill* self = (FightEngine::FightSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHealthCost'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetHealthCost();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHealthCost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_new00
static int tolua_fight_FightEngine_RaySkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::RaySkill* tolua_ret = (FightEngine::RaySkill*)  Mtolua_new((FightEngine::RaySkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::RaySkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_new00_local
static int tolua_fight_FightEngine_RaySkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::RaySkill* tolua_ret = (FightEngine::RaySkill*)  Mtolua_new((FightEngine::RaySkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::RaySkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_delete00
static int tolua_fight_FightEngine_RaySkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::RaySkill* self = (FightEngine::RaySkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_LoadXml00
static int tolua_fight_FightEngine_RaySkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::RaySkill* self = (FightEngine::RaySkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_LevelUp00
static int tolua_fight_FightEngine_RaySkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::RaySkill* self = (FightEngine::RaySkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::RaySkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_RaySkill_Cast00
static int tolua_fight_FightEngine_RaySkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::RaySkill* self = (FightEngine::RaySkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_new00
static int tolua_fight_FightEngine_TrapSkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::TrapSkill* tolua_ret = (FightEngine::TrapSkill*)  Mtolua_new((FightEngine::TrapSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::TrapSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_new00_local
static int tolua_fight_FightEngine_TrapSkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::TrapSkill* tolua_ret = (FightEngine::TrapSkill*)  Mtolua_new((FightEngine::TrapSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::TrapSkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_delete00
static int tolua_fight_FightEngine_TrapSkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::TrapSkill* self = (FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_LoadXml00
static int tolua_fight_FightEngine_TrapSkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::TrapSkill* self = (FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_LevelUp00
static int tolua_fight_FightEngine_TrapSkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::TrapSkill* self = (FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::TrapSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_TrapSkill_Cast00
static int tolua_fight_FightEngine_TrapSkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::TrapSkill* self = (FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_new00
static int tolua_fight_FightEngine_AOESkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::AOESkill* tolua_ret = (FightEngine::AOESkill*)  Mtolua_new((FightEngine::AOESkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::AOESkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_new00_local
static int tolua_fight_FightEngine_AOESkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::AOESkill* tolua_ret = (FightEngine::AOESkill*)  Mtolua_new((FightEngine::AOESkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::AOESkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_delete00
static int tolua_fight_FightEngine_AOESkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AOESkill* self = (FightEngine::AOESkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_LoadXml00
static int tolua_fight_FightEngine_AOESkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AOESkill* self = (FightEngine::AOESkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_LevelUp00
static int tolua_fight_FightEngine_AOESkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AOESkill* self = (FightEngine::AOESkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::AOESkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AOESkill_Cast00
static int tolua_fight_FightEngine_AOESkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AOESkill* self = (FightEngine::AOESkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_new00
static int tolua_fight_FightEngine_MissileSkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::MissileSkill* tolua_ret = (FightEngine::MissileSkill*)  Mtolua_new((FightEngine::MissileSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::MissileSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_new00_local
static int tolua_fight_FightEngine_MissileSkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::MissileSkill* tolua_ret = (FightEngine::MissileSkill*)  Mtolua_new((FightEngine::MissileSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::MissileSkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_delete00
static int tolua_fight_FightEngine_MissileSkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::MissileSkill* self = (FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_LoadXml00
static int tolua_fight_FightEngine_MissileSkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::MissileSkill* self = (FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_LevelUp00
static int tolua_fight_FightEngine_MissileSkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::MissileSkill* self = (FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::MissileSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_MissileSkill_Cast00
static int tolua_fight_FightEngine_MissileSkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::MissileSkill* self = (FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_new00
static int tolua_fight_FightEngine_AuraSkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::AuraSkill* tolua_ret = (FightEngine::AuraSkill*)  Mtolua_new((FightEngine::AuraSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::AuraSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_new00_local
static int tolua_fight_FightEngine_AuraSkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::AuraSkill* tolua_ret = (FightEngine::AuraSkill*)  Mtolua_new((FightEngine::AuraSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::AuraSkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_delete00
static int tolua_fight_FightEngine_AuraSkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AuraSkill* self = (FightEngine::AuraSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Cast of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_Cast00
static int tolua_fight_FightEngine_AuraSkill_Cast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AuraSkill* self = (FightEngine::AuraSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Cast'", NULL);
#endif
  {
   self->Cast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Cast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_LoadXml00
static int tolua_fight_FightEngine_AuraSkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AuraSkill* self = (FightEngine::AuraSkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::AuraSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_AuraSkill_LevelUp00
static int tolua_fight_FightEngine_AuraSkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::AuraSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::AuraSkill* self = (FightEngine::AuraSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::PassiveSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_PassiveSkill_new00
static int tolua_fight_FightEngine_PassiveSkill_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::PassiveSkill* tolua_ret = (FightEngine::PassiveSkill*)  Mtolua_new((FightEngine::PassiveSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::PassiveSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::PassiveSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_PassiveSkill_new00_local
static int tolua_fight_FightEngine_PassiveSkill_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::PassiveSkill* tolua_ret = (FightEngine::PassiveSkill*)  Mtolua_new((FightEngine::PassiveSkill)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::PassiveSkill");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::PassiveSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_PassiveSkill_delete00
static int tolua_fight_FightEngine_PassiveSkill_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::PassiveSkill* self = (FightEngine::PassiveSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadXml of class  FightEngine::PassiveSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_PassiveSkill_LoadXml00
static int tolua_fight_FightEngine_PassiveSkill_LoadXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::PassiveSkill* self = (FightEngine::PassiveSkill*)  tolua_tousertype(tolua_S,1,0);
  const char* xmlFile = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadXml'", NULL);
#endif
  {
   self->LoadXml(xmlFile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LevelUp of class  FightEngine::PassiveSkill */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_PassiveSkill_LevelUp00
static int tolua_fight_FightEngine_PassiveSkill_LevelUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::PassiveSkill* self = (FightEngine::PassiveSkill*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LevelUp'", NULL);
#endif
  {
   self->LevelUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LevelUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: WIDTH of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__World_WIDTH
static int tolua_get_FightEngine__World_WIDTH(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)FightEngine::World::WIDTH);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: WIDTH of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__World_WIDTH
static int tolua_set_FightEngine__World_WIDTH(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  FightEngine::World::WIDTH = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: HEIGHT of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__World_HEIGHT
static int tolua_get_FightEngine__World_HEIGHT(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)FightEngine::World::HEIGHT);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: HEIGHT of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__World_HEIGHT
static int tolua_set_FightEngine__World_HEIGHT(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  FightEngine::World::HEIGHT = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: instance of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_instance00
static int tolua_fight_FightEngine_World_instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::World* tolua_ret = (FightEngine::World*)  FightEngine::World::instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::World");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMissile of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_AddMissile00
static int tolua_fight_FightEngine_World_AddMissile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::MissileSkill* skill = ((FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,2,0));
  int x1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,6,0));
  float speed = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMissile'", NULL);
#endif
  {
   self->AddMissile(skill,x1,y1,x2,y2,speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMissile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddTrap of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_AddTrap00
static int tolua_fight_FightEngine_World_AddTrap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::TrapSkill* skill = ((FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddTrap'", NULL);
#endif
  {
   self->AddTrap(skill,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddTrap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddDamageField of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_AddDamageField00
static int tolua_fight_FightEngine_World_AddDamageField00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::AOESkill* skill = ((FightEngine::AOESkill*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
  int range = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddDamageField'", NULL);
#endif
  {
   self->AddDamageField(skill,x,y,range);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDamageField'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddDamageRay of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_AddDamageRay00
static int tolua_fight_FightEngine_World_AddDamageRay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::RaySkill* skill = ((FightEngine::RaySkill*)  tolua_tousertype(tolua_S,2,0));
  int x1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,6,0));
  float length = ((float)  tolua_tonumber(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddDamageRay'", NULL);
#endif
  {
   self->AddDamageRay(skill,x1,y1,x2,y2,length);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDamageRay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChainMissileSkill of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_ChainMissileSkill00
static int tolua_fight_FightEngine_World_ChainMissileSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::FightSkill* parent = ((FightEngine::FightSkill*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChainMissileSkill'", NULL);
#endif
  {
   self->ChainMissileSkill(parent,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChainMissileSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChainTrapSkill of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_ChainTrapSkill00
static int tolua_fight_FightEngine_World_ChainTrapSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::FightSkill* parent = ((FightEngine::FightSkill*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChainTrapSkill'", NULL);
#endif
  {
   self->ChainTrapSkill(parent,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChainTrapSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChainAOESkill of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_ChainAOESkill00
static int tolua_fight_FightEngine_World_ChainAOESkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::FightSkill* parent = ((FightEngine::FightSkill*)  tolua_tousertype(tolua_S,2,0));
  int x = ((int)  tolua_tonumber(tolua_S,3,0));
  int y = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChainAOESkill'", NULL);
#endif
  {
   self->ChainAOESkill(parent,x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChainAOESkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ChainRaySkill of class  FightEngine::World */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_World_ChainRaySkill00
static int tolua_fight_FightEngine_World_ChainRaySkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::World",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::World* self = (FightEngine::World*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::FightSkill* parent = ((FightEngine::FightSkill*)  tolua_tousertype(tolua_S,2,0));
  int x1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ChainRaySkill'", NULL);
#endif
  {
   self->ChainRaySkill(parent,x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ChainRaySkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_new00
static int tolua_fight_FightEngine_Missile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Missile* tolua_ret = (FightEngine::Missile*)  Mtolua_new((FightEngine::Missile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Missile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_new00_local
static int tolua_fight_FightEngine_Missile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Missile* tolua_ret = (FightEngine::Missile*)  Mtolua_new((FightEngine::Missile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Missile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_delete00
static int tolua_fight_FightEngine_Missile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwner of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetOwner00
static int tolua_fight_FightEngine_Missile_SetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* actor = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwner'", NULL);
#endif
  {
   self->SetOwner(actor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSkill of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetSkill00
static int tolua_fight_FightEngine_Missile_SetSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::MissileSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::MissileSkill* skill = ((FightEngine::MissileSkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSkill'", NULL);
#endif
  {
   self->SetSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFollow of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetFollow00
static int tolua_fight_FightEngine_Missile_SetFollow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  bool value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFollow'", NULL);
#endif
  {
   self->SetFollow(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFollow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFollowObject of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetFollowObject00
static int tolua_fight_FightEngine_Missile_SetFollowObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* object = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFollowObject'", NULL);
#endif
  {
   self->SetFollowObject(object);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFollowObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetPosition00
static int tolua_fight_FightEngine_Missile_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngle of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetAngle00
static int tolua_fight_FightEngine_Missile_SetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngle'", NULL);
#endif
  {
   self->SetAngle(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngleFromVertex of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetAngleFromVertex00
static int tolua_fight_FightEngine_Missile_SetAngleFromVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngleFromVertex'", NULL);
#endif
  {
   self->SetAngleFromVertex(x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngleFromVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSpeed of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_SetSpeed00
static int tolua_fight_FightEngine_Missile_SetSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpeed'", NULL);
#endif
  {
   self->SetSpeed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_Destroy00
static int tolua_fight_FightEngine_Missile_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InstantDestroy of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_InstantDestroy00
static int tolua_fight_FightEngine_Missile_InstantDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InstantDestroy'", NULL);
#endif
  {
   self->InstantDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroying of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_Destroying00
static int tolua_fight_FightEngine_Missile_Destroying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroyed of class  FightEngine::Missile */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Missile_Destroyed00
static int tolua_fight_FightEngine_Missile_Destroyed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Missile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Missile* self = (FightEngine::Missile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroyed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroyed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroyed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_new00
static int tolua_fight_FightEngine_Trap_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Trap* tolua_ret = (FightEngine::Trap*)  Mtolua_new((FightEngine::Trap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Trap");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_new00_local
static int tolua_fight_FightEngine_Trap_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Trap* tolua_ret = (FightEngine::Trap*)  Mtolua_new((FightEngine::Trap)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Trap");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_delete00
static int tolua_fight_FightEngine_Trap_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwner of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_SetOwner00
static int tolua_fight_FightEngine_Trap_SetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* actor = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwner'", NULL);
#endif
  {
   self->SetOwner(actor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSkill of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_SetSkill00
static int tolua_fight_FightEngine_Trap_SetSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::TrapSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::TrapSkill* skill = ((FightEngine::TrapSkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSkill'", NULL);
#endif
  {
   self->SetSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_SetPosition00
static int tolua_fight_FightEngine_Trap_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_Destroy00
static int tolua_fight_FightEngine_Trap_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InstantDestroy of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_InstantDestroy00
static int tolua_fight_FightEngine_Trap_InstantDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InstantDestroy'", NULL);
#endif
  {
   self->InstantDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroying of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_Destroying00
static int tolua_fight_FightEngine_Trap_Destroying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroyed of class  FightEngine::Trap */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Trap_Destroyed00
static int tolua_fight_FightEngine_Trap_Destroyed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Trap",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Trap* self = (FightEngine::Trap*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroyed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroyed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroyed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_new00
static int tolua_fight_FightEngine_DamageField_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::DamageField* tolua_ret = (FightEngine::DamageField*)  Mtolua_new((FightEngine::DamageField)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::DamageField");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_new00_local
static int tolua_fight_FightEngine_DamageField_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::DamageField* tolua_ret = (FightEngine::DamageField*)  Mtolua_new((FightEngine::DamageField)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::DamageField");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_delete00
static int tolua_fight_FightEngine_DamageField_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwner of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_SetOwner00
static int tolua_fight_FightEngine_DamageField_SetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* actor = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwner'", NULL);
#endif
  {
   self->SetOwner(actor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSkill of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_SetSkill00
static int tolua_fight_FightEngine_DamageField_SetSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::AOESkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::AOESkill* skill = ((FightEngine::AOESkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSkill'", NULL);
#endif
  {
   self->SetSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_SetPosition00
static int tolua_fight_FightEngine_DamageField_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_Destroy00
static int tolua_fight_FightEngine_DamageField_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InstantDestroy of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_InstantDestroy00
static int tolua_fight_FightEngine_DamageField_InstantDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InstantDestroy'", NULL);
#endif
  {
   self->InstantDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroying of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_Destroying00
static int tolua_fight_FightEngine_DamageField_Destroying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroyed of class  FightEngine::DamageField */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageField_Destroyed00
static int tolua_fight_FightEngine_DamageField_Destroyed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageField",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageField* self = (FightEngine::DamageField*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroyed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroyed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroyed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_new00
static int tolua_fight_FightEngine_DamageRay_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::DamageRay* tolua_ret = (FightEngine::DamageRay*)  Mtolua_new((FightEngine::DamageRay)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::DamageRay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_new00_local
static int tolua_fight_FightEngine_DamageRay_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::DamageRay* tolua_ret = (FightEngine::DamageRay*)  Mtolua_new((FightEngine::DamageRay)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::DamageRay");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_delete00
static int tolua_fight_FightEngine_DamageRay_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetOwner of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetOwner00
static int tolua_fight_FightEngine_DamageRay_SetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* actor = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOwner'", NULL);
#endif
  {
   self->SetOwner(actor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSkill of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetSkill00
static int tolua_fight_FightEngine_DamageRay_SetSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::RaySkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::RaySkill* skill = ((FightEngine::RaySkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSkill'", NULL);
#endif
  {
   self->SetSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetPosition00
static int tolua_fight_FightEngine_DamageRay_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngle of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetAngle00
static int tolua_fight_FightEngine_DamageRay_SetAngle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngle'", NULL);
#endif
  {
   self->SetAngle(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAngleFromVertex of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetAngleFromVertex00
static int tolua_fight_FightEngine_DamageRay_SetAngleFromVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  int x1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,3,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,4,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAngleFromVertex'", NULL);
#endif
  {
   self->SetAngleFromVertex(x1,y1,x2,y2);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAngleFromVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLength of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_SetLength00
static int tolua_fight_FightEngine_DamageRay_SetLength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLength'", NULL);
#endif
  {
   self->SetLength(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_Destroy00
static int tolua_fight_FightEngine_DamageRay_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroy'", NULL);
#endif
  {
   self->Destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: InstantDestroy of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_InstantDestroy00
static int tolua_fight_FightEngine_DamageRay_InstantDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InstantDestroy'", NULL);
#endif
  {
   self->InstantDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InstantDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroying of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_Destroying00
static int tolua_fight_FightEngine_DamageRay_Destroying00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroying'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroying();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroying'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroyed of class  FightEngine::DamageRay */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_DamageRay_Destroyed00
static int tolua_fight_FightEngine_DamageRay_Destroyed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::DamageRay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::DamageRay* self = (FightEngine::DamageRay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Destroyed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Destroyed();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroyed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Style of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__DamageItem_Style
static int tolua_get_FightEngine__DamageItem_Style(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Style);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Style of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__DamageItem_Style
static int tolua_set_FightEngine__DamageItem_Style(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Style = ((FightEngine::DamageStyle) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Series of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__DamageItem_Series
static int tolua_get_FightEngine__DamageItem_Series(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Series'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Series);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Series of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__DamageItem_Series
static int tolua_set_FightEngine__DamageItem_Series(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Series'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Series = ((FightEngine::ElementSeries) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Value of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__DamageItem_Value
static int tolua_get_FightEngine__DamageItem_Value(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Value of class  FightEngine::DamageItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__DamageItem_Value
static int tolua_set_FightEngine__DamageItem_Value(lua_State* tolua_S)
{
  FightEngine::DamageItem* self = (FightEngine::DamageItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Value = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_new00
static int tolua_fight_FightEngine_Damage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Damage* tolua_ret = (FightEngine::Damage*)  Mtolua_new((FightEngine::Damage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Damage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_new00_local
static int tolua_fight_FightEngine_Damage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Damage* tolua_ret = (FightEngine::Damage*)  Mtolua_new((FightEngine::Damage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Damage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_delete00
static int tolua_fight_FightEngine_Damage_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Damage* self = (FightEngine::Damage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaster of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_SetCaster00
static int tolua_fight_FightEngine_Damage_SetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Damage* self = (FightEngine::Damage*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* caster = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaster'", NULL);
#endif
  {
   self->SetCaster(caster);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaster of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_GetCaster00
static int tolua_fight_FightEngine_Damage_GetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Damage* self = (FightEngine::Damage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaster'", NULL);
#endif
  {
   FightEngine::Actor* tolua_ret = (FightEngine::Actor*)  self->GetCaster();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_AddItem00
static int tolua_fight_FightEngine_Damage_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"FightEngine::DamageItem",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Damage* self = (FightEngine::Damage*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::DamageItem item = *((FightEngine::DamageItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
  {
   self->AddItem(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaster of class  FightEngine::Damage */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Damage_SetCaster01
static int tolua_fight_FightEngine_Damage_SetCaster01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Damage",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  FightEngine::Damage* self = (FightEngine::Damage*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* caster = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaster'", NULL);
#endif
  {
   self->SetCaster(caster);
  }
 }
 return 0;
tolua_lerror:
 return tolua_fight_FightEngine_Damage_SetCaster00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Detail of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_Detail
static int tolua_get_FightEngine__BuffItem_Detail(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Detail'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Detail);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Detail of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_Detail
static int tolua_set_FightEngine__BuffItem_Detail(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Detail'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Detail = ((FightEngine::BuffStyleDetail) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Style of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_Style
static int tolua_get_FightEngine__BuffItem_Style(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Style);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Style of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_Style
static int tolua_set_FightEngine__BuffItem_Style(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Style'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Style = ((FightEngine::BuffStyle) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Value of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_Value
static int tolua_get_FightEngine__BuffItem_Value(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Value of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_Value
static int tolua_set_FightEngine__BuffItem_Value(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Value = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Calculation of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_Calculation
static int tolua_get_FightEngine__BuffItem_Calculation(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Calculation'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Calculation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Calculation of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_Calculation
static int tolua_set_FightEngine__BuffItem_Calculation(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Calculation'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Calculation = ((FightEngine::BuffCalculation) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CalculationMethod of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_CalculationMethod
static int tolua_get_FightEngine__BuffItem_CalculationMethod(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationMethod'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CalculationMethod);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CalculationMethod of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_CalculationMethod
static int tolua_set_FightEngine__BuffItem_CalculationMethod(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationMethod'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CalculationMethod = ((FightEngine::BuffCalculationMethod) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CalculationDetail of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_CalculationDetail
static int tolua_get_FightEngine__BuffItem_CalculationDetail(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationDetail'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CalculationDetail);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CalculationDetail of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_CalculationDetail
static int tolua_set_FightEngine__BuffItem_CalculationDetail(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationDetail'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CalculationDetail = ((FightEngine::BuffCalculationDetail) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CalculationValue of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_CalculationValue
static int tolua_get_FightEngine__BuffItem_CalculationValue(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->CalculationValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CalculationValue of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_CalculationValue
static int tolua_set_FightEngine__BuffItem_CalculationValue(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CalculationValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CalculationValue = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Stackable of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_Stackable
static int tolua_get_FightEngine__BuffItem_Stackable(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Stackable'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->Stackable);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Stackable of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_Stackable
static int tolua_set_FightEngine__BuffItem_Stackable(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Stackable'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Stackable = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MaxStack of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_get_FightEngine__BuffItem_MaxStack
static int tolua_get_FightEngine__BuffItem_MaxStack(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxStack'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->MaxStack);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MaxStack of class  FightEngine::BuffItem */
#ifndef TOLUA_DISABLE_tolua_set_FightEngine__BuffItem_MaxStack
static int tolua_set_FightEngine__BuffItem_MaxStack(lua_State* tolua_S)
{
  FightEngine::BuffItem* self = (FightEngine::BuffItem*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MaxStack'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MaxStack = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaster of class  FightEngine::Buff */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Buff_GetCaster00
static int tolua_fight_FightEngine_Buff_GetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Buff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Buff* self = (FightEngine::Buff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaster'", NULL);
#endif
  {
   FightEngine::Actor* tolua_ret = (FightEngine::Actor*)  self->GetCaster();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaster of class  FightEngine::Buff */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Buff_SetCaster00
static int tolua_fight_FightEngine_Buff_SetCaster00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Buff",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Buff* self = (FightEngine::Buff*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Actor* caster = ((FightEngine::Actor*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaster'", NULL);
#endif
  {
   self->SetCaster(caster);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaster'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  FightEngine::Buff */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Buff_AddItem00
static int tolua_fight_FightEngine_Buff_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Buff",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"FightEngine::BuffItem",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Buff* self = (FightEngine::Buff*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::BuffItem item = *((FightEngine::BuffItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
  {
   self->AddItem(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_new00
static int tolua_fight_FightEngine_Charge_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Charge* tolua_ret = (FightEngine::Charge*)  Mtolua_new((FightEngine::Charge)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Charge");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_new00_local
static int tolua_fight_FightEngine_Charge_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Charge* tolua_ret = (FightEngine::Charge*)  Mtolua_new((FightEngine::Charge)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Charge");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_delete00
static int tolua_fight_FightEngine_Charge_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_GetName00
static int tolua_fight_FightEngine_Charge_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_SetName00
static int tolua_fight_FightEngine_Charge_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
  const char* value = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   self->SetName(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCount of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_GetCount00
static int tolua_fight_FightEngine_Charge_GetCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMax of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_GetMax00
static int tolua_fight_FightEngine_Charge_GetMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMax'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetMax();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMax of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_SetMax00
static int tolua_fight_FightEngine_Charge_SetMax00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
  int value = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMax'", NULL);
#endif
  {
   self->SetMax(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMax'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Increase of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_Increase00
static int tolua_fight_FightEngine_Charge_Increase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Increase'", NULL);
#endif
  {
   self->Increase();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Increase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Decrease of class  FightEngine::Charge */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Charge_Decrease00
static int tolua_fight_FightEngine_Charge_Decrease00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Charge",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Charge* self = (FightEngine::Charge*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Decrease'", NULL);
#endif
  {
   self->Decrease();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Decrease'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_new00
static int tolua_fight_FightEngine_Actor_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Actor* tolua_ret = (FightEngine::Actor*)  Mtolua_new((FightEngine::Actor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Actor");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_new00_local
static int tolua_fight_FightEngine_Actor_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FightEngine::Actor* tolua_ret = (FightEngine::Actor*)  Mtolua_new((FightEngine::Actor)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Actor");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_delete00
static int tolua_fight_FightEngine_Actor_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LookAt of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_LookAt00
static int tolua_fight_FightEngine_Actor_LookAt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LookAt'", NULL);
#endif
  {
   self->LookAt(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_Stop00
static int tolua_fight_FightEngine_Actor_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
  {
   self->Stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayAttack of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_PlayAttack00
static int tolua_fight_FightEngine_Actor_PlayAttack00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayAttack'", NULL);
#endif
  {
   self->PlayAttack();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayAttack'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayAttackCrit of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_PlayAttackCrit00
static int tolua_fight_FightEngine_Actor_PlayAttackCrit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayAttackCrit'", NULL);
#endif
  {
   self->PlayAttackCrit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayAttackCrit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayCast of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_PlayCast00
static int tolua_fight_FightEngine_Actor_PlayCast00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayCast'", NULL);
#endif
  {
   self->PlayCast();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayCast'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayHurt of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_PlayHurt00
static int tolua_fight_FightEngine_Actor_PlayHurt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayHurt'", NULL);
#endif
  {
   self->PlayHurt();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayHurt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBuff of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_AddBuff00
static int tolua_fight_FightEngine_Actor_AddBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::Buff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::Buff* buff = ((FightEngine::Buff*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBuff'", NULL);
#endif
  {
   self->AddBuff(buff);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBuffCount of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBuffCount00
static int tolua_fight_FightEngine_Actor_GetBuffCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBuffCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetBuffCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBuffCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBuff of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBuff00
static int tolua_fight_FightEngine_Actor_GetBuff00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBuff'", NULL);
#endif
  {
   FightEngine::Buff* tolua_ret = (FightEngine::Buff*)  self->GetBuff(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Buff");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBuff'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CalculateBuffs of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_CalculateBuffs00
static int tolua_fight_FightEngine_Actor_CalculateBuffs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CalculateBuffs'", NULL);
#endif
  {
   self->CalculateBuffs();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CalculateBuffs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddFightSkill of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_AddFightSkill00
static int tolua_fight_FightEngine_Actor_AddFightSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::FightSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::FightSkill* skill = ((FightEngine::FightSkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddFightSkill'", NULL);
#endif
  {
   self->AddFightSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddFightSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddPassiveSkill of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_AddPassiveSkill00
static int tolua_fight_FightEngine_Actor_AddPassiveSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"FightEngine::PassiveSkill",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  FightEngine::PassiveSkill* skill = ((FightEngine::PassiveSkill*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPassiveSkill'", NULL);
#endif
  {
   self->AddPassiveSkill(skill);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPassiveSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFightSkillCount of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetFightSkillCount00
static int tolua_fight_FightEngine_Actor_GetFightSkillCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFightSkillCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetFightSkillCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFightSkillCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFightSkill of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetFightSkill00
static int tolua_fight_FightEngine_Actor_GetFightSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFightSkill'", NULL);
#endif
  {
   FightEngine::FightSkill* tolua_ret = (FightEngine::FightSkill*)  self->GetFightSkill(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::FightSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFightSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPassiveSkillCount of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPassiveSkillCount00
static int tolua_fight_FightEngine_Actor_GetPassiveSkillCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPassiveSkillCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPassiveSkillCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPassiveSkillCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPassiveSkill of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPassiveSkill00
static int tolua_fight_FightEngine_Actor_GetPassiveSkill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPassiveSkill'", NULL);
#endif
  {
   FightEngine::PassiveSkill* tolua_ret = (FightEngine::PassiveSkill*)  self->GetPassiveSkill(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::PassiveSkill");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPassiveSkill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseHP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseHP00
static int tolua_fight_FightEngine_Actor_GetBaseHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseHP'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseHP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseHP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseHP00
static int tolua_fight_FightEngine_Actor_SetBaseHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseHP'", NULL);
#endif
  {
   self->SetBaseHP(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusHP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusHP00
static int tolua_fight_FightEngine_Actor_GetPlusHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusHP'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusHP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusHP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusHP00
static int tolua_fight_FightEngine_Actor_SetPlusHP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusHP'", NULL);
#endif
  {
   self->SetPlusHP(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusHP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseMP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseMP00
static int tolua_fight_FightEngine_Actor_GetBaseMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseMP'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseMP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseMP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseMP00
static int tolua_fight_FightEngine_Actor_SetBaseMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseMP'", NULL);
#endif
  {
   self->SetBaseMP(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusMP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusMP00
static int tolua_fight_FightEngine_Actor_GetPlusMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusMP'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusMP();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusMP of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusMP00
static int tolua_fight_FightEngine_Actor_SetPlusMP00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusMP'", NULL);
#endif
  {
   self->SetPlusMP(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusMP'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseHPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseHPRegen00
static int tolua_fight_FightEngine_Actor_GetBaseHPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseHPRegen'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseHPRegen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseHPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseHPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseHPRegen00
static int tolua_fight_FightEngine_Actor_SetBaseHPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseHPRegen'", NULL);
#endif
  {
   self->SetBaseHPRegen(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseHPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusHPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusHPRegen00
static int tolua_fight_FightEngine_Actor_GetPlusHPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusHPRegen'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusHPRegen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusHPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusHPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusHPRegen00
static int tolua_fight_FightEngine_Actor_SetPlusHPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusHPRegen'", NULL);
#endif
  {
   self->SetPlusHPRegen(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusHPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseMPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseMPRegen00
static int tolua_fight_FightEngine_Actor_GetBaseMPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseMPRegen'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseMPRegen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseMPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseMPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseMPRegen00
static int tolua_fight_FightEngine_Actor_SetBaseMPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseMPRegen'", NULL);
#endif
  {
   self->SetBaseMPRegen(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseMPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusMPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusMPRegen00
static int tolua_fight_FightEngine_Actor_GetPlusMPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusMPRegen'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusMPRegen();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusMPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusMPRegen of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusMPRegen00
static int tolua_fight_FightEngine_Actor_SetPlusMPRegen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusMPRegen'", NULL);
#endif
  {
   self->SetPlusMPRegen(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusMPRegen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseDamage of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseDamage00
static int tolua_fight_FightEngine_Actor_GetBaseDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseDamage'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseDamage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseDamage of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseDamage00
static int tolua_fight_FightEngine_Actor_SetBaseDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseDamage'", NULL);
#endif
  {
   self->SetBaseDamage(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusDamage of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusDamage00
static int tolua_fight_FightEngine_Actor_GetPlusDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusDamage'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusDamage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusDamage of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusDamage00
static int tolua_fight_FightEngine_Actor_SetPlusDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusDamage'", NULL);
#endif
  {
   self->SetPlusDamage(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseStrength of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseStrength00
static int tolua_fight_FightEngine_Actor_GetBaseStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseStrength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseStrength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseStrength of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseStrength00
static int tolua_fight_FightEngine_Actor_SetBaseStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseStrength'", NULL);
#endif
  {
   self->SetBaseStrength(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusStrength of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusStrength00
static int tolua_fight_FightEngine_Actor_GetPlusStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusStrength'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusStrength();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusStrength of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusStrength00
static int tolua_fight_FightEngine_Actor_SetPlusStrength00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusStrength'", NULL);
#endif
  {
   self->SetPlusStrength(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusStrength'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseDexterity of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseDexterity00
static int tolua_fight_FightEngine_Actor_GetBaseDexterity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseDexterity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseDexterity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseDexterity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseDexterity of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseDexterity00
static int tolua_fight_FightEngine_Actor_SetBaseDexterity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseDexterity'", NULL);
#endif
  {
   self->SetBaseDexterity(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseDexterity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusDexterity of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusDexterity00
static int tolua_fight_FightEngine_Actor_GetPlusDexterity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusDexterity'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusDexterity();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusDexterity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusDexterity of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusDexterity00
static int tolua_fight_FightEngine_Actor_SetPlusDexterity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusDexterity'", NULL);
#endif
  {
   self->SetPlusDexterity(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusDexterity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseAgility of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseAgility00
static int tolua_fight_FightEngine_Actor_GetBaseAgility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseAgility'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseAgility();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseAgility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseAgility of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseAgility00
static int tolua_fight_FightEngine_Actor_SetBaseAgility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseAgility'", NULL);
#endif
  {
   self->SetBaseAgility(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseAgility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusAgility of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusAgility00
static int tolua_fight_FightEngine_Actor_GetPlusAgility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusAgility'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusAgility();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusAgility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusAgility of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusAgility00
static int tolua_fight_FightEngine_Actor_SetPlusAgility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusAgility'", NULL);
#endif
  {
   self->SetPlusAgility(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusAgility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseInteligent of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseInteligent00
static int tolua_fight_FightEngine_Actor_GetBaseInteligent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseInteligent'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseInteligent();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseInteligent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseInteligent of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseInteligent00
static int tolua_fight_FightEngine_Actor_SetBaseInteligent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseInteligent'", NULL);
#endif
  {
   self->SetBaseInteligent(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseInteligent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusInteligent of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusInteligent00
static int tolua_fight_FightEngine_Actor_GetPlusInteligent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusInteligent'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusInteligent();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusInteligent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusInteligent of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusInteligent00
static int tolua_fight_FightEngine_Actor_SetPlusInteligent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusInteligent'", NULL);
#endif
  {
   self->SetPlusInteligent(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusInteligent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseLightningAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseLightningAbsor00
static int tolua_fight_FightEngine_Actor_GetBaseLightningAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseLightningAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseLightningAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseLightningAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseLightningAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseLightningAbsor00
static int tolua_fight_FightEngine_Actor_SetBaseLightningAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseLightningAbsor'", NULL);
#endif
  {
   self->SetBaseLightningAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseLightningAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusLightningAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusLightningAbsor00
static int tolua_fight_FightEngine_Actor_GetPlusLightningAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusLightningAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusLightningAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusLightningAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusLightningAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusLightningAbsor00
static int tolua_fight_FightEngine_Actor_SetPlusLightningAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusLightningAbsor'", NULL);
#endif
  {
   self->SetPlusLightningAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusLightningAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBasePoisonAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBasePoisonAbsor00
static int tolua_fight_FightEngine_Actor_GetBasePoisonAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBasePoisonAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBasePoisonAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBasePoisonAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBasePoisonAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBasePoisonAbsor00
static int tolua_fight_FightEngine_Actor_SetBasePoisonAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBasePoisonAbsor'", NULL);
#endif
  {
   self->SetBasePoisonAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBasePoisonAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusPoisonAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusPoisonAbsor00
static int tolua_fight_FightEngine_Actor_GetPlusPoisonAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusPoisonAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusPoisonAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusPoisonAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusPoisonAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusPoisonAbsor00
static int tolua_fight_FightEngine_Actor_SetPlusPoisonAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusPoisonAbsor'", NULL);
#endif
  {
   self->SetPlusPoisonAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusPoisonAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseIceAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseIceAbsor00
static int tolua_fight_FightEngine_Actor_GetBaseIceAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseIceAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseIceAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseIceAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseIceAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseIceAbsor00
static int tolua_fight_FightEngine_Actor_SetBaseIceAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseIceAbsor'", NULL);
#endif
  {
   self->SetBaseIceAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseIceAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusIceAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusIceAbsor00
static int tolua_fight_FightEngine_Actor_GetPlusIceAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusIceAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusIceAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusIceAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusIceAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusIceAbsor00
static int tolua_fight_FightEngine_Actor_SetPlusIceAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusIceAbsor'", NULL);
#endif
  {
   self->SetPlusIceAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusIceAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseFireAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseFireAbsor00
static int tolua_fight_FightEngine_Actor_GetBaseFireAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseFireAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseFireAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseFireAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseFireAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseFireAbsor00
static int tolua_fight_FightEngine_Actor_SetBaseFireAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseFireAbsor'", NULL);
#endif
  {
   self->SetBaseFireAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseFireAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusFireAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusFireAbsor00
static int tolua_fight_FightEngine_Actor_GetPlusFireAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusFireAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusFireAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusFireAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusFireAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusFireAbsor00
static int tolua_fight_FightEngine_Actor_SetPlusFireAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusFireAbsor'", NULL);
#endif
  {
   self->SetPlusFireAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusFireAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBasePhysicsAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBasePhysicsAbsor00
static int tolua_fight_FightEngine_Actor_GetBasePhysicsAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBasePhysicsAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBasePhysicsAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBasePhysicsAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBasePhysicsAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBasePhysicsAbsor00
static int tolua_fight_FightEngine_Actor_SetBasePhysicsAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBasePhysicsAbsor'", NULL);
#endif
  {
   self->SetBasePhysicsAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBasePhysicsAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusPhysicsAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusPhysicsAbsor00
static int tolua_fight_FightEngine_Actor_GetPlusPhysicsAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusPhysicsAbsor'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusPhysicsAbsor();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusPhysicsAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusPhysicsAbsor of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusPhysicsAbsor00
static int tolua_fight_FightEngine_Actor_SetPlusPhysicsAbsor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusPhysicsAbsor'", NULL);
#endif
  {
   self->SetPlusPhysicsAbsor(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusPhysicsAbsor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseMoveSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseMoveSpeed00
static int tolua_fight_FightEngine_Actor_GetBaseMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseMoveSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseMoveSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseMoveSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseMoveSpeed00
static int tolua_fight_FightEngine_Actor_SetBaseMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseMoveSpeed'", NULL);
#endif
  {
   self->SetBaseMoveSpeed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusMoveSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusMoveSpeed00
static int tolua_fight_FightEngine_Actor_GetPlusMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusMoveSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusMoveSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusMoveSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusMoveSpeed00
static int tolua_fight_FightEngine_Actor_SetPlusMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusMoveSpeed'", NULL);
#endif
  {
   self->SetPlusMoveSpeed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseAttackSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseAttackSpeed00
static int tolua_fight_FightEngine_Actor_GetBaseAttackSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseAttackSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseAttackSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseAttackSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseAttackSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseAttackSpeed00
static int tolua_fight_FightEngine_Actor_SetBaseAttackSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseAttackSpeed'", NULL);
#endif
  {
   self->SetBaseAttackSpeed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseAttackSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusAttackSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusAttackSpeed00
static int tolua_fight_FightEngine_Actor_GetPlusAttackSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusAttackSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusAttackSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusAttackSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusAttackSpeed of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusAttackSpeed00
static int tolua_fight_FightEngine_Actor_SetPlusAttackSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusAttackSpeed'", NULL);
#endif
  {
   self->SetPlusAttackSpeed(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusAttackSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseBaseAttackTime of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseBaseAttackTime00
static int tolua_fight_FightEngine_Actor_GetBaseBaseAttackTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseBaseAttackTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseBaseAttackTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseBaseAttackTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseBaseAttackTime of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseBaseAttackTime00
static int tolua_fight_FightEngine_Actor_SetBaseBaseAttackTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseBaseAttackTime'", NULL);
#endif
  {
   self->SetBaseBaseAttackTime(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseBaseAttackTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusBaseAttackTime of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusBaseAttackTime00
static int tolua_fight_FightEngine_Actor_GetPlusBaseAttackTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusBaseAttackTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusBaseAttackTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusBaseAttackTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusBaseAttackTime of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusBaseAttackTime00
static int tolua_fight_FightEngine_Actor_SetPlusBaseAttackTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusBaseAttackTime'", NULL);
#endif
  {
   self->SetPlusBaseAttackTime(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusBaseAttackTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseAccurate of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseAccurate00
static int tolua_fight_FightEngine_Actor_GetBaseAccurate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseAccurate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseAccurate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseAccurate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseAccurate of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseAccurate00
static int tolua_fight_FightEngine_Actor_SetBaseAccurate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseAccurate'", NULL);
#endif
  {
   self->SetBaseAccurate(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseAccurate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusAccurate of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusAccurate00
static int tolua_fight_FightEngine_Actor_GetPlusAccurate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusAccurate'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusAccurate();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusAccurate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusAccurate of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusAccurate00
static int tolua_fight_FightEngine_Actor_SetPlusAccurate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusAccurate'", NULL);
#endif
  {
   self->SetPlusAccurate(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusAccurate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseEvasion of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetBaseEvasion00
static int tolua_fight_FightEngine_Actor_GetBaseEvasion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseEvasion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetBaseEvasion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseEvasion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseEvasion of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetBaseEvasion00
static int tolua_fight_FightEngine_Actor_SetBaseEvasion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseEvasion'", NULL);
#endif
  {
   self->SetBaseEvasion(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseEvasion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlusEvasion of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_GetPlusEvasion00
static int tolua_fight_FightEngine_Actor_GetPlusEvasion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlusEvasion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetPlusEvasion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlusEvasion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlusEvasion of class  FightEngine::Actor */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Actor_SetPlusEvasion00
static int tolua_fight_FightEngine_Actor_SetPlusEvasion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Actor",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Actor* self = (FightEngine::Actor*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlusEvasion'", NULL);
#endif
  {
   self->SetPlusEvasion(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlusEvasion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_new00
static int tolua_fight_FightEngine_Vector2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   FightEngine::Vector2* tolua_ret = (FightEngine::Vector2*)  Mtolua_new((FightEngine::Vector2)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Vector2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_new00_local
static int tolua_fight_FightEngine_Vector2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   FightEngine::Vector2* tolua_ret = (FightEngine::Vector2*)  Mtolua_new((FightEngine::Vector2)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_new01
static int tolua_fight_FightEngine_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   FightEngine::Vector2* tolua_ret = (FightEngine::Vector2*)  Mtolua_new((FightEngine::Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_fight_FightEngine_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_new01_local
static int tolua_fight_FightEngine_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   FightEngine::Vector2* tolua_ret = (FightEngine::Vector2*)  Mtolua_new((FightEngine::Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FightEngine::Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_fight_FightEngine_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_delete00
static int tolua_fight_FightEngine_Vector2_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Vector2* self = (FightEngine::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetX of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_GetX00
static int tolua_fight_FightEngine_Vector2_GetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Vector2* self = (FightEngine::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetX'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetX();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetY of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_GetY00
static int tolua_fight_FightEngine_Vector2_GetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Vector2* self = (FightEngine::Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetY'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetY();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetX of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_SetX00
static int tolua_fight_FightEngine_Vector2_SetX00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Vector2* self = (FightEngine::Vector2*)  tolua_tousertype(tolua_S,1,0);
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetX'", NULL);
#endif
  {
   self->SetX(x);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetY of class  FightEngine::Vector2 */
#ifndef TOLUA_DISABLE_tolua_fight_FightEngine_Vector2_SetY00
static int tolua_fight_FightEngine_Vector2_SetY00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FightEngine::Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FightEngine::Vector2* self = (FightEngine::Vector2*)  tolua_tousertype(tolua_S,1,0);
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetY'", NULL);
#endif
  {
   self->SetY(y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_fight_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"FightEngine",0);
  tolua_beginmodule(tolua_S,"FightEngine");
   tolua_constant(tolua_S,"ST_FOE",FightEngine::ST_FOE);
   tolua_constant(tolua_S,"ST_FRIEND",FightEngine::ST_FRIEND);
   tolua_constant(tolua_S,"ST_NEUTRAL",FightEngine::ST_NEUTRAL);
   tolua_constant(tolua_S,"ST_NOT_FOE",FightEngine::ST_NOT_FOE);
   tolua_constant(tolua_S,"ST_NOT_FRIEND",FightEngine::ST_NOT_FRIEND);
   tolua_constant(tolua_S,"ST_NOT_NEUTRAL",FightEngine::ST_NOT_NEUTRAL);
   tolua_constant(tolua_S,"ST_POINT",FightEngine::ST_POINT);
   tolua_constant(tolua_S,"ST_AVAILABLE_POINT",FightEngine::ST_AVAILABLE_POINT);
   tolua_constant(tolua_S,"ST_2POINT",FightEngine::ST_2POINT);
   tolua_constant(tolua_S,"ST_2AVAILABLE_POINT",FightEngine::ST_2AVAILABLE_POINT);
   tolua_constant(tolua_S,"ST_INSTANT",FightEngine::ST_INSTANT);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"TargetData","FightEngine::TargetData","",tolua_collect_FightEngine__TargetData);
   #else
   tolua_cclass(tolua_S,"TargetData","FightEngine::TargetData","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"TargetData");
    tolua_variable(tolua_S,"Target",tolua_get_FightEngine__TargetData_Target_ptr,tolua_set_FightEngine__TargetData_Target_ptr);
    tolua_variable(tolua_S,"X1",tolua_get_FightEngine__TargetData_X1,tolua_set_FightEngine__TargetData_X1);
    tolua_variable(tolua_S,"Y1",tolua_get_FightEngine__TargetData_Y1,tolua_set_FightEngine__TargetData_Y1);
    tolua_variable(tolua_S,"X2",tolua_get_FightEngine__TargetData_X2,tolua_set_FightEngine__TargetData_X2);
    tolua_variable(tolua_S,"Y2",tolua_get_FightEngine__TargetData_Y2,tolua_set_FightEngine__TargetData_Y2);
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_TargetData_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_TargetData_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_TargetData_new00_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"FightSkill","FightEngine::FightSkill","",tolua_collect_FightEngine__FightSkill);
   #else
   tolua_cclass(tolua_S,"FightSkill","FightEngine::FightSkill","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"FightSkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_FightSkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_FightSkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_FightSkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_FightSkill_delete00);
    tolua_function(tolua_S,"SetTargetData",tolua_fight_FightEngine_FightSkill_SetTargetData00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_FightSkill_Cast00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_FightSkill_LevelUp00);
    tolua_function(tolua_S,"SetCaster",tolua_fight_FightEngine_FightSkill_SetCaster00);
    tolua_function(tolua_S,"GetCaster",tolua_fight_FightEngine_FightSkill_GetCaster00);
    tolua_function(tolua_S,"GetName",tolua_fight_FightEngine_FightSkill_GetName00);
    tolua_function(tolua_S,"GetLevel",tolua_fight_FightEngine_FightSkill_GetLevel00);
    tolua_function(tolua_S,"GetManaCost",tolua_fight_FightEngine_FightSkill_GetManaCost00);
    tolua_function(tolua_S,"GetHealthCost",tolua_fight_FightEngine_FightSkill_GetHealthCost00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"RaySkill","FightEngine::RaySkill","FightEngine::FightSkill",tolua_collect_FightEngine__RaySkill);
   #else
   tolua_cclass(tolua_S,"RaySkill","FightEngine::RaySkill","FightEngine::FightSkill",NULL);
   #endif
   tolua_beginmodule(tolua_S,"RaySkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_RaySkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_RaySkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_RaySkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_RaySkill_delete00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_RaySkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_RaySkill_LevelUp00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_RaySkill_Cast00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"TrapSkill","FightEngine::TrapSkill","FightEngine::FightSkill",tolua_collect_FightEngine__TrapSkill);
   #else
   tolua_cclass(tolua_S,"TrapSkill","FightEngine::TrapSkill","FightEngine::FightSkill",NULL);
   #endif
   tolua_beginmodule(tolua_S,"TrapSkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_TrapSkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_TrapSkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_TrapSkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_TrapSkill_delete00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_TrapSkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_TrapSkill_LevelUp00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_TrapSkill_Cast00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"AOESkill","FightEngine::AOESkill","FightEngine::FightSkill",tolua_collect_FightEngine__AOESkill);
   #else
   tolua_cclass(tolua_S,"AOESkill","FightEngine::AOESkill","FightEngine::FightSkill",NULL);
   #endif
   tolua_beginmodule(tolua_S,"AOESkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_AOESkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_AOESkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_AOESkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_AOESkill_delete00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_AOESkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_AOESkill_LevelUp00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_AOESkill_Cast00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"MissileSkill","FightEngine::MissileSkill","FightEngine::FightSkill",tolua_collect_FightEngine__MissileSkill);
   #else
   tolua_cclass(tolua_S,"MissileSkill","FightEngine::MissileSkill","FightEngine::FightSkill",NULL);
   #endif
   tolua_beginmodule(tolua_S,"MissileSkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_MissileSkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_MissileSkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_MissileSkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_MissileSkill_delete00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_MissileSkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_MissileSkill_LevelUp00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_MissileSkill_Cast00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"AuraSkill","FightEngine::AuraSkill","FightEngine::FightSkill",tolua_collect_FightEngine__AuraSkill);
   #else
   tolua_cclass(tolua_S,"AuraSkill","FightEngine::AuraSkill","FightEngine::FightSkill",NULL);
   #endif
   tolua_beginmodule(tolua_S,"AuraSkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_AuraSkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_AuraSkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_AuraSkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_AuraSkill_delete00);
    tolua_function(tolua_S,"Cast",tolua_fight_FightEngine_AuraSkill_Cast00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_AuraSkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_AuraSkill_LevelUp00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"PassiveSkill","FightEngine::PassiveSkill","",tolua_collect_FightEngine__PassiveSkill);
   #else
   tolua_cclass(tolua_S,"PassiveSkill","FightEngine::PassiveSkill","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"PassiveSkill");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_PassiveSkill_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_PassiveSkill_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_PassiveSkill_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_PassiveSkill_delete00);
    tolua_function(tolua_S,"LoadXml",tolua_fight_FightEngine_PassiveSkill_LoadXml00);
    tolua_function(tolua_S,"LevelUp",tolua_fight_FightEngine_PassiveSkill_LevelUp00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"World","FightEngine::World","",NULL);
   tolua_beginmodule(tolua_S,"World");
    tolua_variable(tolua_S,"WIDTH",tolua_get_FightEngine__World_WIDTH,tolua_set_FightEngine__World_WIDTH);
    tolua_variable(tolua_S,"HEIGHT",tolua_get_FightEngine__World_HEIGHT,tolua_set_FightEngine__World_HEIGHT);
    tolua_function(tolua_S,"instance",tolua_fight_FightEngine_World_instance00);
    tolua_function(tolua_S,"AddMissile",tolua_fight_FightEngine_World_AddMissile00);
    tolua_function(tolua_S,"AddTrap",tolua_fight_FightEngine_World_AddTrap00);
    tolua_function(tolua_S,"AddDamageField",tolua_fight_FightEngine_World_AddDamageField00);
    tolua_function(tolua_S,"AddDamageRay",tolua_fight_FightEngine_World_AddDamageRay00);
    tolua_function(tolua_S,"ChainMissileSkill",tolua_fight_FightEngine_World_ChainMissileSkill00);
    tolua_function(tolua_S,"ChainTrapSkill",tolua_fight_FightEngine_World_ChainTrapSkill00);
    tolua_function(tolua_S,"ChainAOESkill",tolua_fight_FightEngine_World_ChainAOESkill00);
    tolua_function(tolua_S,"ChainRaySkill",tolua_fight_FightEngine_World_ChainRaySkill00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"ES_METAL",FightEngine::ES_METAL);
   tolua_constant(tolua_S,"ES_PLANT",FightEngine::ES_PLANT);
   tolua_constant(tolua_S,"ES_ICE",FightEngine::ES_ICE);
   tolua_constant(tolua_S,"ES_FIRE",FightEngine::ES_FIRE);
   tolua_constant(tolua_S,"ES_EARTH",FightEngine::ES_EARTH);
   tolua_constant(tolua_S,"FS_FRIEND",FightEngine::FS_FRIEND);
   tolua_constant(tolua_S,"FS_FOE",FightEngine::FS_FOE);
   tolua_constant(tolua_S,"FS_NEUTRAL",FightEngine::FS_NEUTRAL);
   tolua_constant(tolua_S,"FS_ALL",FightEngine::FS_ALL);
   tolua_constant(tolua_S,"FS_NOT_NEUTRAL",FightEngine::FS_NOT_NEUTRAL);
   tolua_constant(tolua_S,"FS_NOT_FRIEND",FightEngine::FS_NOT_FRIEND);
   tolua_constant(tolua_S,"FS_NOT_FOE",FightEngine::FS_NOT_FOE);
   tolua_constant(tolua_S,"FW_FREE",FightEngine::FW_FREE);
   tolua_constant(tolua_S,"FW_BLOW",FightEngine::FW_BLOW);
   tolua_constant(tolua_S,"FW_CLAW",FightEngine::FW_CLAW);
   tolua_constant(tolua_S,"FW_PALM",FightEngine::FW_PALM);
   tolua_constant(tolua_S,"FW_FINGER",FightEngine::FW_FINGER);
   tolua_constant(tolua_S,"FW_SWORD",FightEngine::FW_SWORD);
   tolua_constant(tolua_S,"FW_DOUBLE_SWORD",FightEngine::FW_DOUBLE_SWORD);
   tolua_constant(tolua_S,"FW_BLADE",FightEngine::FW_BLADE);
   tolua_constant(tolua_S,"FW_DOUBLE_BLADE",FightEngine::FW_DOUBLE_BLADE);
   tolua_constant(tolua_S,"FW_CLUB",FightEngine::FW_CLUB);
   tolua_constant(tolua_S,"FW_DOUBLE_CLUB",FightEngine::FW_DOUBLE_CLUB);
   tolua_constant(tolua_S,"FW_AXE",FightEngine::FW_AXE);
   tolua_constant(tolua_S,"FW_DOUBLE_AXE",FightEngine::FW_DOUBLE_AXE);
   tolua_constant(tolua_S,"FW_STAFF",FightEngine::FW_STAFF);
   tolua_constant(tolua_S,"FW_LANCE",FightEngine::FW_LANCE);
   tolua_constant(tolua_S,"FW_DAGGER",FightEngine::FW_DAGGER);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Missile","FightEngine::Missile","",tolua_collect_FightEngine__Missile);
   #else
   tolua_cclass(tolua_S,"Missile","FightEngine::Missile","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Missile");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Missile_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Missile_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Missile_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Missile_delete00);
    tolua_function(tolua_S,"SetOwner",tolua_fight_FightEngine_Missile_SetOwner00);
    tolua_function(tolua_S,"SetSkill",tolua_fight_FightEngine_Missile_SetSkill00);
    tolua_function(tolua_S,"SetFollow",tolua_fight_FightEngine_Missile_SetFollow00);
    tolua_function(tolua_S,"SetFollowObject",tolua_fight_FightEngine_Missile_SetFollowObject00);
    tolua_function(tolua_S,"SetPosition",tolua_fight_FightEngine_Missile_SetPosition00);
    tolua_function(tolua_S,"SetAngle",tolua_fight_FightEngine_Missile_SetAngle00);
    tolua_function(tolua_S,"SetAngleFromVertex",tolua_fight_FightEngine_Missile_SetAngleFromVertex00);
    tolua_function(tolua_S,"SetSpeed",tolua_fight_FightEngine_Missile_SetSpeed00);
    tolua_function(tolua_S,"Destroy",tolua_fight_FightEngine_Missile_Destroy00);
    tolua_function(tolua_S,"InstantDestroy",tolua_fight_FightEngine_Missile_InstantDestroy00);
    tolua_function(tolua_S,"Destroying",tolua_fight_FightEngine_Missile_Destroying00);
    tolua_function(tolua_S,"Destroyed",tolua_fight_FightEngine_Missile_Destroyed00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Trap","FightEngine::Trap","",tolua_collect_FightEngine__Trap);
   #else
   tolua_cclass(tolua_S,"Trap","FightEngine::Trap","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Trap");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Trap_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Trap_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Trap_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Trap_delete00);
    tolua_function(tolua_S,"SetOwner",tolua_fight_FightEngine_Trap_SetOwner00);
    tolua_function(tolua_S,"SetSkill",tolua_fight_FightEngine_Trap_SetSkill00);
    tolua_function(tolua_S,"SetPosition",tolua_fight_FightEngine_Trap_SetPosition00);
    tolua_function(tolua_S,"Destroy",tolua_fight_FightEngine_Trap_Destroy00);
    tolua_function(tolua_S,"InstantDestroy",tolua_fight_FightEngine_Trap_InstantDestroy00);
    tolua_function(tolua_S,"Destroying",tolua_fight_FightEngine_Trap_Destroying00);
    tolua_function(tolua_S,"Destroyed",tolua_fight_FightEngine_Trap_Destroyed00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"DamageField","FightEngine::DamageField","",tolua_collect_FightEngine__DamageField);
   #else
   tolua_cclass(tolua_S,"DamageField","FightEngine::DamageField","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"DamageField");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_DamageField_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_DamageField_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_DamageField_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_DamageField_delete00);
    tolua_function(tolua_S,"SetOwner",tolua_fight_FightEngine_DamageField_SetOwner00);
    tolua_function(tolua_S,"SetSkill",tolua_fight_FightEngine_DamageField_SetSkill00);
    tolua_function(tolua_S,"SetPosition",tolua_fight_FightEngine_DamageField_SetPosition00);
    tolua_function(tolua_S,"Destroy",tolua_fight_FightEngine_DamageField_Destroy00);
    tolua_function(tolua_S,"InstantDestroy",tolua_fight_FightEngine_DamageField_InstantDestroy00);
    tolua_function(tolua_S,"Destroying",tolua_fight_FightEngine_DamageField_Destroying00);
    tolua_function(tolua_S,"Destroyed",tolua_fight_FightEngine_DamageField_Destroyed00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"DamageRay","FightEngine::DamageRay","",tolua_collect_FightEngine__DamageRay);
   #else
   tolua_cclass(tolua_S,"DamageRay","FightEngine::DamageRay","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"DamageRay");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_DamageRay_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_DamageRay_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_DamageRay_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_DamageRay_delete00);
    tolua_function(tolua_S,"SetOwner",tolua_fight_FightEngine_DamageRay_SetOwner00);
    tolua_function(tolua_S,"SetSkill",tolua_fight_FightEngine_DamageRay_SetSkill00);
    tolua_function(tolua_S,"SetPosition",tolua_fight_FightEngine_DamageRay_SetPosition00);
    tolua_function(tolua_S,"SetAngle",tolua_fight_FightEngine_DamageRay_SetAngle00);
    tolua_function(tolua_S,"SetAngleFromVertex",tolua_fight_FightEngine_DamageRay_SetAngleFromVertex00);
    tolua_function(tolua_S,"SetLength",tolua_fight_FightEngine_DamageRay_SetLength00);
    tolua_function(tolua_S,"Destroy",tolua_fight_FightEngine_DamageRay_Destroy00);
    tolua_function(tolua_S,"InstantDestroy",tolua_fight_FightEngine_DamageRay_InstantDestroy00);
    tolua_function(tolua_S,"Destroying",tolua_fight_FightEngine_DamageRay_Destroying00);
    tolua_function(tolua_S,"Destroyed",tolua_fight_FightEngine_DamageRay_Destroyed00);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"DS_INTERNAL",FightEngine::DS_INTERNAL);
   tolua_constant(tolua_S,"DS_EXTERNAL",FightEngine::DS_EXTERNAL);
   tolua_constant(tolua_S,"DS_PURE",FightEngine::DS_PURE);
   tolua_cclass(tolua_S,"DamageItem","FightEngine::DamageItem","",NULL);
   tolua_beginmodule(tolua_S,"DamageItem");
    tolua_variable(tolua_S,"Style",tolua_get_FightEngine__DamageItem_Style,tolua_set_FightEngine__DamageItem_Style);
    tolua_variable(tolua_S,"Series",tolua_get_FightEngine__DamageItem_Series,tolua_set_FightEngine__DamageItem_Series);
    tolua_variable(tolua_S,"Value",tolua_get_FightEngine__DamageItem_Value,tolua_set_FightEngine__DamageItem_Value);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Damage","FightEngine::Damage","",tolua_collect_FightEngine__Damage);
   #else
   tolua_cclass(tolua_S,"Damage","FightEngine::Damage","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Damage");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Damage_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Damage_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Damage_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Damage_delete00);
    tolua_function(tolua_S,"SetCaster",tolua_fight_FightEngine_Damage_SetCaster00);
    tolua_function(tolua_S,"GetCaster",tolua_fight_FightEngine_Damage_GetCaster00);
    tolua_function(tolua_S,"AddItem",tolua_fight_FightEngine_Damage_AddItem00);
    tolua_function(tolua_S,"SetCaster",tolua_fight_FightEngine_Damage_SetCaster01);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"BSD_MOVE_SPEED",FightEngine::BSD_MOVE_SPEED);
   tolua_constant(tolua_S,"BSD_ATTACK_SPEED",FightEngine::BSD_ATTACK_SPEED);
   tolua_constant(tolua_S,"BSD_ACCURATE",FightEngine::BSD_ACCURATE);
   tolua_constant(tolua_S,"BSD_EVASION",FightEngine::BSD_EVASION);
   tolua_constant(tolua_S,"BSD_HP_REGEN",FightEngine::BSD_HP_REGEN);
   tolua_constant(tolua_S,"BSD_MP_REGEN",FightEngine::BSD_MP_REGEN);
   tolua_constant(tolua_S,"BSD_STRENGTH",FightEngine::BSD_STRENGTH);
   tolua_constant(tolua_S,"BSD_AGILITY",FightEngine::BSD_AGILITY);
   tolua_constant(tolua_S,"BSD_DEXTERITY",FightEngine::BSD_DEXTERITY);
   tolua_constant(tolua_S,"BSD_INTELIGENT",FightEngine::BSD_INTELIGENT);
   tolua_constant(tolua_S,"BSD_LIGHTNING_ABSOR",FightEngine::BSD_LIGHTNING_ABSOR);
   tolua_constant(tolua_S,"BSD_POISON_ABSOR",FightEngine::BSD_POISON_ABSOR);
   tolua_constant(tolua_S,"BSD_ICE_ABSOR",FightEngine::BSD_ICE_ABSOR);
   tolua_constant(tolua_S,"BSD_FIRE_ABSOR",FightEngine::BSD_FIRE_ABSOR);
   tolua_constant(tolua_S,"BSD_PHYSICS_ABSOR",FightEngine::BSD_PHYSICS_ABSOR);
   tolua_constant(tolua_S,"BS_NEGATIVE",FightEngine::BS_NEGATIVE);
   tolua_constant(tolua_S,"BS_POSITIVE",FightEngine::BS_POSITIVE);
   tolua_constant(tolua_S,"BS_UNDEFINED",FightEngine::BS_UNDEFINED);
   tolua_constant(tolua_S,"BC_CASTER",FightEngine::BC_CASTER);
   tolua_constant(tolua_S,"BC_TARGET",FightEngine::BC_TARGET);
   tolua_constant(tolua_S,"BC_PERNALTY",FightEngine::BC_PERNALTY);
   tolua_constant(tolua_S,"BCM_PERCENT",FightEngine::BCM_PERCENT);
   tolua_constant(tolua_S,"BCM_VALUE",FightEngine::BCM_VALUE);
   tolua_constant(tolua_S,"BCD_HP_BASE",FightEngine::BCD_HP_BASE);
   tolua_constant(tolua_S,"BCD_MP_BASE",FightEngine::BCD_MP_BASE);
   tolua_constant(tolua_S,"BCD_MOVESPEED_BASE",FightEngine::BCD_MOVESPEED_BASE);
   tolua_constant(tolua_S,"BCD_ATTACKSPEED_BASE",FightEngine::BCD_ATTACKSPEED_BASE);
   tolua_constant(tolua_S,"BCD_STRENGTH_BASE",FightEngine::BCD_STRENGTH_BASE);
   tolua_constant(tolua_S,"BCD_AGILITY_BASE",FightEngine::BCD_AGILITY_BASE);
   tolua_constant(tolua_S,"BCD_DEXTERITY_BASE",FightEngine::BCD_DEXTERITY_BASE);
   tolua_constant(tolua_S,"BCD_INTELIGENT_BASE",FightEngine::BCD_INTELIGENT_BASE);
   tolua_cclass(tolua_S,"BuffItem","FightEngine::BuffItem","",NULL);
   tolua_beginmodule(tolua_S,"BuffItem");
    tolua_variable(tolua_S,"Detail",tolua_get_FightEngine__BuffItem_Detail,tolua_set_FightEngine__BuffItem_Detail);
    tolua_variable(tolua_S,"Style",tolua_get_FightEngine__BuffItem_Style,tolua_set_FightEngine__BuffItem_Style);
    tolua_variable(tolua_S,"Value",tolua_get_FightEngine__BuffItem_Value,tolua_set_FightEngine__BuffItem_Value);
    tolua_variable(tolua_S,"Calculation",tolua_get_FightEngine__BuffItem_Calculation,tolua_set_FightEngine__BuffItem_Calculation);
    tolua_variable(tolua_S,"CalculationMethod",tolua_get_FightEngine__BuffItem_CalculationMethod,tolua_set_FightEngine__BuffItem_CalculationMethod);
    tolua_variable(tolua_S,"CalculationDetail",tolua_get_FightEngine__BuffItem_CalculationDetail,tolua_set_FightEngine__BuffItem_CalculationDetail);
    tolua_variable(tolua_S,"CalculationValue",tolua_get_FightEngine__BuffItem_CalculationValue,tolua_set_FightEngine__BuffItem_CalculationValue);
    tolua_variable(tolua_S,"Stackable",tolua_get_FightEngine__BuffItem_Stackable,tolua_set_FightEngine__BuffItem_Stackable);
    tolua_variable(tolua_S,"MaxStack",tolua_get_FightEngine__BuffItem_MaxStack,tolua_set_FightEngine__BuffItem_MaxStack);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Buff","FightEngine::Buff","",NULL);
   tolua_beginmodule(tolua_S,"Buff");
    tolua_function(tolua_S,"GetCaster",tolua_fight_FightEngine_Buff_GetCaster00);
    tolua_function(tolua_S,"SetCaster",tolua_fight_FightEngine_Buff_SetCaster00);
    tolua_function(tolua_S,"AddItem",tolua_fight_FightEngine_Buff_AddItem00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Charge","FightEngine::Charge","",tolua_collect_FightEngine__Charge);
   #else
   tolua_cclass(tolua_S,"Charge","FightEngine::Charge","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Charge");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Charge_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Charge_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Charge_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Charge_delete00);
    tolua_function(tolua_S,"GetName",tolua_fight_FightEngine_Charge_GetName00);
    tolua_function(tolua_S,"SetName",tolua_fight_FightEngine_Charge_SetName00);
    tolua_function(tolua_S,"GetCount",tolua_fight_FightEngine_Charge_GetCount00);
    tolua_function(tolua_S,"GetMax",tolua_fight_FightEngine_Charge_GetMax00);
    tolua_function(tolua_S,"SetMax",tolua_fight_FightEngine_Charge_SetMax00);
    tolua_function(tolua_S,"Increase",tolua_fight_FightEngine_Charge_Increase00);
    tolua_function(tolua_S,"Decrease",tolua_fight_FightEngine_Charge_Decrease00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Actor","FightEngine::Actor","",tolua_collect_FightEngine__Actor);
   #else
   tolua_cclass(tolua_S,"Actor","FightEngine::Actor","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Actor");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Actor_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Actor_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Actor_new00_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Actor_delete00);
    tolua_function(tolua_S,"LookAt",tolua_fight_FightEngine_Actor_LookAt00);
    tolua_function(tolua_S,"Stop",tolua_fight_FightEngine_Actor_Stop00);
    tolua_function(tolua_S,"PlayAttack",tolua_fight_FightEngine_Actor_PlayAttack00);
    tolua_function(tolua_S,"PlayAttackCrit",tolua_fight_FightEngine_Actor_PlayAttackCrit00);
    tolua_function(tolua_S,"PlayCast",tolua_fight_FightEngine_Actor_PlayCast00);
    tolua_function(tolua_S,"PlayHurt",tolua_fight_FightEngine_Actor_PlayHurt00);
    tolua_function(tolua_S,"AddBuff",tolua_fight_FightEngine_Actor_AddBuff00);
    tolua_function(tolua_S,"GetBuffCount",tolua_fight_FightEngine_Actor_GetBuffCount00);
    tolua_function(tolua_S,"GetBuff",tolua_fight_FightEngine_Actor_GetBuff00);
    tolua_function(tolua_S,"CalculateBuffs",tolua_fight_FightEngine_Actor_CalculateBuffs00);
    tolua_function(tolua_S,"AddFightSkill",tolua_fight_FightEngine_Actor_AddFightSkill00);
    tolua_function(tolua_S,"AddPassiveSkill",tolua_fight_FightEngine_Actor_AddPassiveSkill00);
    tolua_function(tolua_S,"GetFightSkillCount",tolua_fight_FightEngine_Actor_GetFightSkillCount00);
    tolua_function(tolua_S,"GetFightSkill",tolua_fight_FightEngine_Actor_GetFightSkill00);
    tolua_function(tolua_S,"GetPassiveSkillCount",tolua_fight_FightEngine_Actor_GetPassiveSkillCount00);
    tolua_function(tolua_S,"GetPassiveSkill",tolua_fight_FightEngine_Actor_GetPassiveSkill00);
    tolua_function(tolua_S,"GetBaseHP",tolua_fight_FightEngine_Actor_GetBaseHP00);
    tolua_function(tolua_S,"SetBaseHP",tolua_fight_FightEngine_Actor_SetBaseHP00);
    tolua_function(tolua_S,"GetPlusHP",tolua_fight_FightEngine_Actor_GetPlusHP00);
    tolua_function(tolua_S,"SetPlusHP",tolua_fight_FightEngine_Actor_SetPlusHP00);
    tolua_function(tolua_S,"GetBaseMP",tolua_fight_FightEngine_Actor_GetBaseMP00);
    tolua_function(tolua_S,"SetBaseMP",tolua_fight_FightEngine_Actor_SetBaseMP00);
    tolua_function(tolua_S,"GetPlusMP",tolua_fight_FightEngine_Actor_GetPlusMP00);
    tolua_function(tolua_S,"SetPlusMP",tolua_fight_FightEngine_Actor_SetPlusMP00);
    tolua_function(tolua_S,"GetBaseHPRegen",tolua_fight_FightEngine_Actor_GetBaseHPRegen00);
    tolua_function(tolua_S,"SetBaseHPRegen",tolua_fight_FightEngine_Actor_SetBaseHPRegen00);
    tolua_function(tolua_S,"GetPlusHPRegen",tolua_fight_FightEngine_Actor_GetPlusHPRegen00);
    tolua_function(tolua_S,"SetPlusHPRegen",tolua_fight_FightEngine_Actor_SetPlusHPRegen00);
    tolua_function(tolua_S,"GetBaseMPRegen",tolua_fight_FightEngine_Actor_GetBaseMPRegen00);
    tolua_function(tolua_S,"SetBaseMPRegen",tolua_fight_FightEngine_Actor_SetBaseMPRegen00);
    tolua_function(tolua_S,"GetPlusMPRegen",tolua_fight_FightEngine_Actor_GetPlusMPRegen00);
    tolua_function(tolua_S,"SetPlusMPRegen",tolua_fight_FightEngine_Actor_SetPlusMPRegen00);
    tolua_function(tolua_S,"GetBaseDamage",tolua_fight_FightEngine_Actor_GetBaseDamage00);
    tolua_function(tolua_S,"SetBaseDamage",tolua_fight_FightEngine_Actor_SetBaseDamage00);
    tolua_function(tolua_S,"GetPlusDamage",tolua_fight_FightEngine_Actor_GetPlusDamage00);
    tolua_function(tolua_S,"SetPlusDamage",tolua_fight_FightEngine_Actor_SetPlusDamage00);
    tolua_function(tolua_S,"GetBaseStrength",tolua_fight_FightEngine_Actor_GetBaseStrength00);
    tolua_function(tolua_S,"SetBaseStrength",tolua_fight_FightEngine_Actor_SetBaseStrength00);
    tolua_function(tolua_S,"GetPlusStrength",tolua_fight_FightEngine_Actor_GetPlusStrength00);
    tolua_function(tolua_S,"SetPlusStrength",tolua_fight_FightEngine_Actor_SetPlusStrength00);
    tolua_function(tolua_S,"GetBaseDexterity",tolua_fight_FightEngine_Actor_GetBaseDexterity00);
    tolua_function(tolua_S,"SetBaseDexterity",tolua_fight_FightEngine_Actor_SetBaseDexterity00);
    tolua_function(tolua_S,"GetPlusDexterity",tolua_fight_FightEngine_Actor_GetPlusDexterity00);
    tolua_function(tolua_S,"SetPlusDexterity",tolua_fight_FightEngine_Actor_SetPlusDexterity00);
    tolua_function(tolua_S,"GetBaseAgility",tolua_fight_FightEngine_Actor_GetBaseAgility00);
    tolua_function(tolua_S,"SetBaseAgility",tolua_fight_FightEngine_Actor_SetBaseAgility00);
    tolua_function(tolua_S,"GetPlusAgility",tolua_fight_FightEngine_Actor_GetPlusAgility00);
    tolua_function(tolua_S,"SetPlusAgility",tolua_fight_FightEngine_Actor_SetPlusAgility00);
    tolua_function(tolua_S,"GetBaseInteligent",tolua_fight_FightEngine_Actor_GetBaseInteligent00);
    tolua_function(tolua_S,"SetBaseInteligent",tolua_fight_FightEngine_Actor_SetBaseInteligent00);
    tolua_function(tolua_S,"GetPlusInteligent",tolua_fight_FightEngine_Actor_GetPlusInteligent00);
    tolua_function(tolua_S,"SetPlusInteligent",tolua_fight_FightEngine_Actor_SetPlusInteligent00);
    tolua_function(tolua_S,"GetBaseLightningAbsor",tolua_fight_FightEngine_Actor_GetBaseLightningAbsor00);
    tolua_function(tolua_S,"SetBaseLightningAbsor",tolua_fight_FightEngine_Actor_SetBaseLightningAbsor00);
    tolua_function(tolua_S,"GetPlusLightningAbsor",tolua_fight_FightEngine_Actor_GetPlusLightningAbsor00);
    tolua_function(tolua_S,"SetPlusLightningAbsor",tolua_fight_FightEngine_Actor_SetPlusLightningAbsor00);
    tolua_function(tolua_S,"GetBasePoisonAbsor",tolua_fight_FightEngine_Actor_GetBasePoisonAbsor00);
    tolua_function(tolua_S,"SetBasePoisonAbsor",tolua_fight_FightEngine_Actor_SetBasePoisonAbsor00);
    tolua_function(tolua_S,"GetPlusPoisonAbsor",tolua_fight_FightEngine_Actor_GetPlusPoisonAbsor00);
    tolua_function(tolua_S,"SetPlusPoisonAbsor",tolua_fight_FightEngine_Actor_SetPlusPoisonAbsor00);
    tolua_function(tolua_S,"GetBaseIceAbsor",tolua_fight_FightEngine_Actor_GetBaseIceAbsor00);
    tolua_function(tolua_S,"SetBaseIceAbsor",tolua_fight_FightEngine_Actor_SetBaseIceAbsor00);
    tolua_function(tolua_S,"GetPlusIceAbsor",tolua_fight_FightEngine_Actor_GetPlusIceAbsor00);
    tolua_function(tolua_S,"SetPlusIceAbsor",tolua_fight_FightEngine_Actor_SetPlusIceAbsor00);
    tolua_function(tolua_S,"GetBaseFireAbsor",tolua_fight_FightEngine_Actor_GetBaseFireAbsor00);
    tolua_function(tolua_S,"SetBaseFireAbsor",tolua_fight_FightEngine_Actor_SetBaseFireAbsor00);
    tolua_function(tolua_S,"GetPlusFireAbsor",tolua_fight_FightEngine_Actor_GetPlusFireAbsor00);
    tolua_function(tolua_S,"SetPlusFireAbsor",tolua_fight_FightEngine_Actor_SetPlusFireAbsor00);
    tolua_function(tolua_S,"GetBasePhysicsAbsor",tolua_fight_FightEngine_Actor_GetBasePhysicsAbsor00);
    tolua_function(tolua_S,"SetBasePhysicsAbsor",tolua_fight_FightEngine_Actor_SetBasePhysicsAbsor00);
    tolua_function(tolua_S,"GetPlusPhysicsAbsor",tolua_fight_FightEngine_Actor_GetPlusPhysicsAbsor00);
    tolua_function(tolua_S,"SetPlusPhysicsAbsor",tolua_fight_FightEngine_Actor_SetPlusPhysicsAbsor00);
    tolua_function(tolua_S,"GetBaseMoveSpeed",tolua_fight_FightEngine_Actor_GetBaseMoveSpeed00);
    tolua_function(tolua_S,"SetBaseMoveSpeed",tolua_fight_FightEngine_Actor_SetBaseMoveSpeed00);
    tolua_function(tolua_S,"GetPlusMoveSpeed",tolua_fight_FightEngine_Actor_GetPlusMoveSpeed00);
    tolua_function(tolua_S,"SetPlusMoveSpeed",tolua_fight_FightEngine_Actor_SetPlusMoveSpeed00);
    tolua_function(tolua_S,"GetBaseAttackSpeed",tolua_fight_FightEngine_Actor_GetBaseAttackSpeed00);
    tolua_function(tolua_S,"SetBaseAttackSpeed",tolua_fight_FightEngine_Actor_SetBaseAttackSpeed00);
    tolua_function(tolua_S,"GetPlusAttackSpeed",tolua_fight_FightEngine_Actor_GetPlusAttackSpeed00);
    tolua_function(tolua_S,"SetPlusAttackSpeed",tolua_fight_FightEngine_Actor_SetPlusAttackSpeed00);
    tolua_function(tolua_S,"GetBaseBaseAttackTime",tolua_fight_FightEngine_Actor_GetBaseBaseAttackTime00);
    tolua_function(tolua_S,"SetBaseBaseAttackTime",tolua_fight_FightEngine_Actor_SetBaseBaseAttackTime00);
    tolua_function(tolua_S,"GetPlusBaseAttackTime",tolua_fight_FightEngine_Actor_GetPlusBaseAttackTime00);
    tolua_function(tolua_S,"SetPlusBaseAttackTime",tolua_fight_FightEngine_Actor_SetPlusBaseAttackTime00);
    tolua_function(tolua_S,"GetBaseAccurate",tolua_fight_FightEngine_Actor_GetBaseAccurate00);
    tolua_function(tolua_S,"SetBaseAccurate",tolua_fight_FightEngine_Actor_SetBaseAccurate00);
    tolua_function(tolua_S,"GetPlusAccurate",tolua_fight_FightEngine_Actor_GetPlusAccurate00);
    tolua_function(tolua_S,"SetPlusAccurate",tolua_fight_FightEngine_Actor_SetPlusAccurate00);
    tolua_function(tolua_S,"GetBaseEvasion",tolua_fight_FightEngine_Actor_GetBaseEvasion00);
    tolua_function(tolua_S,"SetBaseEvasion",tolua_fight_FightEngine_Actor_SetBaseEvasion00);
    tolua_function(tolua_S,"GetPlusEvasion",tolua_fight_FightEngine_Actor_GetPlusEvasion00);
    tolua_function(tolua_S,"SetPlusEvasion",tolua_fight_FightEngine_Actor_SetPlusEvasion00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Vector2","FightEngine::Vector2","",tolua_collect_FightEngine__Vector2);
   #else
   tolua_cclass(tolua_S,"Vector2","FightEngine::Vector2","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Vector2");
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Vector2_new00);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Vector2_new00_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Vector2_new00_local);
    tolua_function(tolua_S,"new",tolua_fight_FightEngine_Vector2_new01);
    tolua_function(tolua_S,"new_local",tolua_fight_FightEngine_Vector2_new01_local);
    tolua_function(tolua_S,".call",tolua_fight_FightEngine_Vector2_new01_local);
    tolua_function(tolua_S,"delete",tolua_fight_FightEngine_Vector2_delete00);
    tolua_function(tolua_S,"GetX",tolua_fight_FightEngine_Vector2_GetX00);
    tolua_function(tolua_S,"GetY",tolua_fight_FightEngine_Vector2_GetY00);
    tolua_function(tolua_S,"SetX",tolua_fight_FightEngine_Vector2_SetX00);
    tolua_function(tolua_S,"SetY",tolua_fight_FightEngine_Vector2_SetY00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_fight (lua_State* tolua_S) {
 return tolua_fight_open(tolua_S);
};
#endif

