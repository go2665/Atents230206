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

	inline const char* GetName() { return name; }
	//inline const int GetStringth() { return status.strength; }
	//inline const int GetDexterity() { return status.dexterity; }
	//inline const int GetIntelligence() { return status.intelligence; }
	//inline const int GetStatmina() { return status.stamina; }
	//inline const int GetWisdom() { return status.wisdom; }
	inline const int GetMaxHP() { return maxHP; }
	inline const int GetHP() { return hp; }

	//inline void SetStrength(int str) { status.strength = str; }
	//inline void SetDexterity(int dex) { status.dexterity= dex; }
	//inline void SetIntelligence(int intel) { status.intelligence = intel; }
	//inline void SetStamina(int stm) { status.stamina = stm; }
	//inline void SetWisdom(int wis) { status.wisdom = wis; }
	//inline void SetHP(int _hp) { hp = _hp; }
	//inline void SetMP(int _mp) { mp = _mp; }

	inline void AddStrength(int str) { 
		status.strength += str; 
		int i = 0;
	}
	inline void AddDexterity(int dex) { status.dexterity += dex; }
	inline void AddIntelligence(int intel) { status.intelligence += intel; }
	inline void AddStamina(int stm) { status.stamina += stm; }
	inline void AddWisdom(int wis) { status.wisdom += wis; }
	inline void AddHP(int _hp) { hp += _hp; }
	inline void AddMP(int _mp) { mp += _mp; }


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

