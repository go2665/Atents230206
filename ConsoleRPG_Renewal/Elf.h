#pragma once
#include "Character.h"
class Elf : public Character
{
public:
	virtual void Initialize() override;

	

protected:
	
	/// <summary>
	/// Loop 안에서 해당 크리처가 매 턴마다 하는 행동이 기록된 함수.
	/// </summary>
	virtual void OnTurnAction() override;


	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus() override;

	virtual void RefreshHPMP() override;
	

	virtual void NormalAttack() override;
	virtual void Skill01() override;
	virtual void Skill02() override;

	virtual void LevelUp() override;
	

};

