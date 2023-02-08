#pragma once
#include "Status.h"

class HumanoidBase
{
public :
//	HumanoidBase() {};
//	~HumanoidBase() {};

	/// <summary>
	/// 데미지를 받는 함수
	/// </summary>
	/// <param name="damage">적이 나에게 준 데미지(감소전)</param>
	virtual void TakeDamage(int damage);

protected:
	/// <summary>
	/// 스테이터스
	/// </summary>
	Status status;

	/// <summary>
	/// 현재 HP
	/// </summary>
	int hp = 1;

	/// <summary>
	/// 최대 HP
	/// </summary>
	int maxHP = 1;

	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus();


};

