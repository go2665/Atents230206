#pragma once
#include <list>
#include "Status.h"
#include "Enums.h"
#include "BuffBase.h"

class Creature_Base
{
public:

protected:
	const int HP_Multiplier = 10;
	const int MP_Multiplier = 10;

	/// <summary>
	/// 캐릭터의 타입(현재 플레이어, 적만 있음)
	/// </summary>
	CreatureType type = None;

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
	/// 공격 대상
	/// </summary>
	Creature_Base* pBattleTarget = nullptr;

	/// <summary>
	/// 생존 여부. true면 살아있고 false면 죽어있다.
	/// </summary>
	bool isAlive = true;

	/// <summary>
	/// 전투 중 인지 표시하는 변수
	/// </summary>
	bool isBattle = false;

	/// <summary>
	/// 버프 목록
	/// </summary>
	std::list<BuffBase*> buffList;

public:
	/// <summary>
	/// 초기화용 함수. 팩토리에서 실행.
	/// </summary>
	virtual void Initialize() {};

	/// <summary>
	/// 정리용 함수. Die에서 실행
	/// </summary>
	virtual void CleanUp();

	/// <summary>
	/// 루프에서 실행할 함수. 턴 시작/턴 행동/턴 종료 처리 .
	/// </summary>
	void Loop();

	/// <summary>
	/// pBattleTarget을 공격하는 함수. 각 개별 클래스마다 override 할 것
	/// </summary>
	virtual void Attack();

	/// <summary>
	/// 데미지를 받아 처리하는 함수. 각 개별 클래스마다 override 할 것
	/// </summary>
	virtual void Defence(int damage);

	/// <summary>
	/// 스테이터스 출력하는 함수
	/// </summary>
	virtual void PrintStatus();

	/// <summary>
	/// 전투가 시작되면 실행될 함수
	/// </summary>
	/// <param name="pTarget">전투 대상</param>
	virtual void OnBattleStart(Creature_Base* pTarget);
	
	/// <summary>
	/// 전투가 끝나면 실행될 함수
	/// </summary>
	virtual void OnBattleEnd();

protected:
	/// <summary>
	/// 버프 추가하는 함수
	/// </summary>
	/// <param name="target">버프를 받을 대상</param>
	/// <param name="pBuff">버프의 주소</param>
	void AddBuff(Creature_Base& target, BuffBase* pBuff);

	/// <summary>
	/// Loop 시작될 때 실행될 함수.
	/// </summary>
	virtual void OnTurnStart() {};

	/// <summary>
	/// Loop 안에서 해당 크리처가 매 턴마다 하는 행동이 기록된 함수.
	/// </summary>
	virtual void OnTurnAction() {};

	/// <summary>
	/// Loop가 끝날 때 실행될 함수
	/// </summary>
	virtual void OnTurnEnd() {};

	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus();

	/// <summary>
	/// 죽었을 때 실행될 함수
	/// </summary>
	virtual void Die();

public :
	/// <summary>
	/// 지금 살아있는지 확인하는 변수
	/// </summary>
	/// <returns>살아있으면 true. 죽었으면 false</returns>
	inline bool IsAlive() { return isAlive; }

	/// <summary>
	/// 지금 전투 중인지 확인하는 변수
	/// </summary>
	/// <returns>전투 중이면 true. 전투중이 아니면 false</returns>
	inline bool IsBattle() { return isBattle; }

	// 각종 Getter 함수
	inline CreatureType GetType() { return type; }
	inline const char* GetName() { return name; }
	inline const int GetStringth() { return status.strength; }
	inline const int GetDexterity() { return status.dexterity; }
	inline const int GetIntelligence() { return status.intelligence; }
	inline const int GetStatmina() { return status.stamina; }
	inline const int GetWisdom() { return status.wisdom; }
	inline const int GetMaxHP() { return maxHP; }
	inline const int GetHP() { return hp; }

	// 데이터 변화용 함수
	inline void AddStrength(int str) { status.strength += str; }
	inline void AddDexterity(int dex) { status.dexterity += dex; }
	inline void AddIntelligence(int intel) { status.intelligence += intel; }
	inline void AddStamina(int stm) { status.stamina += stm; }
	inline void AddWisdom(int wis) { status.wisdom += wis; }
	inline void AddHP(int _hp)	// 모든 HP변동은 이 함수를 통해서 처리할 것
	{ 
		hp += _hp; 
		if (hp > maxHP)
			hp = maxHP;
		if (hp < 0)
		{
			Die();
			hp = 0;
		}
	}
	inline void AddMP(int _mp)	// 모든 HP변동은 이 함수를 통해서 처리할 것
	{ 
		mp += _mp; 
		if (mp > maxHP)
			mp = maxHP;
		if (mp < 0)
			mp = 0;
	}
};

