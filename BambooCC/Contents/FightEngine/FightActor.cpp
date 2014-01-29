#include "FightActor.h"
#include "../Geometry/GeometryConstant.h"
namespace FightEngine
{
	Actor::Actor()
		:PathEngine::Actor()
	{
		m_ObjectType = QOT_FIGHTACTOR;
		m_Character = new RigEngine::Character();
		m_Character->SetFullCloth("tianwang3");
		m_Character->SetHead("tianwang3");
		m_Character->SetDualWeapon("blade1");
		m_Character->ResetRender();

		m_Character->SetWeaponState(WS_DUAL_WEAPON);
		m_Character->SetHorseState(HS_NOHORSE);
		m_Character->SetActionState(AS_ATTACK);
		m_Character->SetDirection(D_DOWNRIGHT);
		m_Render = new ActorRender();
		m_ATKAnimationTime = 1000;
		m_ATKCRITAnimationTime = 1000;
		m_CASTAnimationTime = 1000;
		m_HURTAnimationTime = 1000;
		m_Character->SetAnimationTimeATK(m_ATKAnimationTime/1000);
		m_Character->SetAnimationTimeATKCRIT(m_ATKCRITAnimationTime/1000);
		m_Character->SetAnimationTimeCAST(m_CASTAnimationTime/1000);
		m_Character->SetAnimationTimeHURT(m_HURTAnimationTime/1000);
		m_LastATKTime = new cc_timeval();
		m_LastATKCRITTime = new cc_timeval();
		m_LastCASTTime = new cc_timeval();
		m_LastHURTTime = new cc_timeval();
		CCTime::gettimeofdayCocos2d(m_LastATKTime, NULL);
		CCTime::gettimeofdayCocos2d(m_LastATKCRITTime, NULL);
		CCTime::gettimeofdayCocos2d(m_LastCASTTime, NULL);
		CCTime::gettimeofdayCocos2d(m_LastHURTTime, NULL);
	}
	Actor::~Actor()
	{
		
	}
	void Actor::SetPosition(int x, int y)
	{
		PathEngine::Actor::SetPosition(x, y);
		m_FightPositionX = x;
		m_FightPositionY = y;
		m_Character->SetPosition(m_FightPositionX, m_FightPositionY);
	}
	void Actor::Step()
	{
		//if(m_Free)
		if(true)
		{
			//m_Character->SetActionState(AS_FIGHTIDLE);
			return;
		}
		/*PathEngine::Actor::Step();
		m_FightPositionX = m_PositionX;
		m_FightPositionY = m_PositionY;*/
		m_Character->SetPosition(m_FightPositionX, m_FightPositionY);
		m_Character->SetActionState(AS_MOVE);
	}
	void Actor::RefreshFaceDirection()
	{
		int last = m_FaceDirection;
		if(m_Angle >= - _PI_8 && m_Angle < _PI_8)
		{
			m_FaceDirection = 6;
		}
		else if(m_Angle >= _PI_8 && m_Angle < _3PI_8)
		{
			m_FaceDirection = 5;
		}
		else if(m_Angle >= _3PI_8 && m_Angle < _5PI_8)
		{
			m_FaceDirection = 4;
		}
		else if(m_Angle >= _5PI_8 && m_Angle < _7PI_8)
		{
			m_FaceDirection = 3;
		}
		else if((m_Angle >= _7PI_8 && m_Angle <= PI) || 
			(m_Angle < - _7PI_8 && m_Angle >= -PI))
		{
			m_FaceDirection = 2;
		}
		else if(m_Angle >= - _7PI_8 && m_Angle < - _5PI_8)
		{
			m_FaceDirection = 1;
		}
		else if(m_Angle >= - _5PI_8 && m_Angle < - _3PI_8)
		{
			m_FaceDirection = 0;
		}
		else if(m_Angle >= - _3PI_8 && m_Angle < _PI_8)
		{
			m_FaceDirection = 7;
		}
		if(m_FaceDirection == last) return;
		m_Character->SetDirection(m_FaceDirection);
	}
	void Actor::ResetRender()
	{
		m_Character->ResetRender();
		m_Render->SetCharacterRender(m_Character->GetRender());
	}
	void Actor::Update()
	{
		if(true)
		{
			Step();
			//SetPosition(m_PositionX,m_PositionY);
			//UpdateIdle();
			UpdateAnimation();
			RefreshFaceDirection();
		}
	}
	void Actor::LookAt(int x, int y)
	{
		//float dx = x - m_PositionX;
		//float dy = y - m_PositionY;
		//m_GoalAngle = atan2(dy, dx);
		//m_LookedToGoal = false;
	}
	Vector2* Actor::GetFrontPoint(float range_distance, float angle_distance)
	{
		//float x = m_PositionX;
		//float y = m_PositionY;
		//float ax = sin(m_Angle + angle_distance)*range_distance;
		//float ay = cos(m_Angle + angle_distance)*range_distance;
		//Vector2* ret = new Vector2(x+ax,y+ay);
		Vector2* ret = new Vector2(0,0);
		return ret;
	}
	void Actor::Stop()
	{
		RigEngine::ActionState state = m_Character->GetActionInfo().actionState;
		if(state == AS_ATTACK || state == AS_ATTACK_CRIT || 
			state == AS_CAST || state == AS_MOVE ||
			state == AS_THROW_DAGGER)
		{
			//m_Free = true;
			m_FinalSolution.clear();
			m_Character->SetActionState(AS_FIGHTIDLE);
		}
	}
	void Actor::UpdateAnimation()
	{
		cc_timeval* now = new cc_timeval();
		CCTime::gettimeofdayCocos2d(now, NULL);
		// TODO: this is draft, need to work on to have soft animation
		RigEngine::ActionState state = m_Character->GetActionInfo().actionState;
		if(state == AS_ATTACK)
		{
			double time_used = CCTime::timersubCocos2d(m_LastATKTime, now);
			cout<<"atk time "<<time_used<<endl;
			if(time_used >= m_ATKAnimationTime)
			{
				m_Character->SetActionState(AS_FIGHTIDLE);
			}
		}
		else if(state == AS_ATTACK_CRIT)
		{
			double time_used = CCTime::timersubCocos2d(m_LastATKCRITTime, now);
			if(time_used >= m_ATKCRITAnimationTime)
			{
				m_Character->SetActionState(AS_FIGHTIDLE);
			}
		}
		else if(state == AS_CAST)
		{
			double time_used = CCTime::timersubCocos2d(m_LastCASTTime, now);
			if(time_used >= m_CASTAnimationTime)
			{
				m_Character->SetActionState(AS_FIGHTIDLE);
			}
		}
		else if(state == AS_HURT)
		{
			double time_used = CCTime::timersubCocos2d(m_LastHURTTime, now);
			if(time_used >= m_HURTAnimationTime)
			{
				m_Character->SetActionState(AS_FIGHTIDLE);
			}
		}
		else if(state == AS_MOVE)
		{
			//if(m_Free)
			if(false)
			{
				m_Character->SetActionState(AS_FIGHTIDLE);
			}
		}
		else
		{
			m_Character->SetActionState(AS_FIGHTIDLE);
		}
	}
	// ========================================================================
	void Actor::PlayAttack()
	{
		m_Character->SetActionState(AS_ATTACK);
		CCTime::gettimeofdayCocos2d(m_LastATKTime, NULL); 
	}
	void Actor::PlayAttackCrit()
	{
		m_Character->SetActionState(AS_ATTACK_CRIT);
	}
	void Actor::PlayCast()
	{
		m_Character->SetActionState(AS_CAST);
	}
	void Actor::PlayHurt()
	{
		m_Character->SetActionState(AS_HURT);
	}
	void Actor::AddBuff(Buff* buff)
	{
		m_Buffs.push_back(buff);
	}
	int	Actor::GetBuffCount()
	{
		return m_Buffs.size();
	}
	Buff* Actor::GetBuff(int index)
	{
		return m_Buffs[index];
	}
	void Actor::CalculateBuffs()
	{
	}
	void Actor::AddFightSkill(FightSkill* skill)
	{
	}
	void Actor::AddPassiveSkill(PassiveSkill* skill)
	{
	}
	int	Actor::GetFightSkillCount()
	{
		return m_FightSkills.size();
	}
	FightSkill*	Actor::GetFightSkill(int index)
	{
		return m_FightSkills[index];
	}
	int	Actor::GetPassiveSkillCount()
	{
		return m_PassiveSkills.size();
	}
	PassiveSkill* Actor::GetPassiveSkill(int index)
	{
		return m_PassiveSkills[index];
	}
}