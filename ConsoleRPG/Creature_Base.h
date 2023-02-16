#pragma once
#include "Status.h"
#include "Enums.h"

class Creature_Base
{
public :
//	Creature_Base() {};
//	~Creature_Base() {};
	

	/// <summary>
	/// target을 공격하는 함수
	/// </summary>
	/// <param name="target">공격 대상</param>
	virtual void Attack(Creature_Base& target);

	/// <summary>
	/// 데미지를 받는 함수(방어력 계산할 때)
	/// </summary>
	/// <param name="damage">적이 나에게 준 데미지(감소전)</param>
	virtual void TakeDamage(int damage);

	virtual void OnTurnStart() {};
	virtual void OnTurnEnd() {};
	
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
	inline const int GetDexterity() { return status.dexterity; }

	//inline void SetStrength(int str) { status.strength = str; }
	//inline void SetDexterity(int dex) { status.dexterity= dex; }
	//inline void SetIntelligence(int intel) { status.intelligence = intel; }
	//inline void SetStamina(int stm) { status.stamina = stm; }
	//inline void SetWisdom(int wis) { status.wisdom = wis; }
	//inline void SetHP(int _hp) { hp = _hp; }
	//inline void SetMP(int _mp) { mp = _mp; }

	inline void AddStrength(int str) { status.strength += str; }
	inline void AddDexterity(int dex) { status.dexterity += dex; }
	inline void AddIntelligence(int intel) { status.intelligence += intel; }
	inline void AddStamina(int stm) { status.stamina += stm; }
	inline void AddWisdom(int wis) { status.wisdom += wis; }
	inline void AddHP(int _hp) 
	{ 
		hp += _hp; 
		if (hp > maxHP)
			hp = maxHP;
		if (hp < 0)
		{
			Die();
			hp = 0;
		}
	}	// 방어력 무시
	inline void AddMP(int _mp) 
	{ 
		mp += _mp; 
		if (mp > maxHP)
			mp = maxHP;
		if (mp < 0)
			mp = 0;
	}

	inline CharacterType GetType() { return type; }

	inline void SetBattleTarget(Creature_Base* pTarget) { pBattleTarget = pTarget; }

	inline bool IsAlive() { return isAlive; }

protected:
	CharacterType type = Enemy;

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

	Creature_Base* pBattleTarget = nullptr;

	bool isAlive = true;	// 이 변수를 이용해서 한번만 죽게 만들기(4시 30분까지)


	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus();


	virtual void Die();
};

