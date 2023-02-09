#pragma once
#include "Status.h"

class HumanoidBase
{
public :
//	HumanoidBase() {};
//	~HumanoidBase() {};

	/// <summary>
	/// target을 공격하는 함수
	/// </summary>
	/// <param name="target">공격 대상</param>
	virtual void Attack(HumanoidBase& target);

	/// <summary>
	/// 데미지를 받는 함수
	/// </summary>
	/// <param name="damage">적이 나에게 준 데미지(감소전)</param>
	virtual void TakeDamage(int damage);
	
	/// <summary>
	/// 스테이터스 출력하는 함수
	/// </summary>
	virtual void PrintStatus();

protected:
	/// <summary>
	/// 플레이어의 이름(최대 32자. 한글은 16자)
	/// </summary>
	char name[32];

	/// <summary>
	/// 레벨
	/// </summary>
	int level = 1;	
	
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
	/// 현재 MP
	/// </summary>
	int mp = 1;

	/// <summary>
	/// 최대 MP
	/// </summary>
	int maxMP = 1;

	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus();

};

