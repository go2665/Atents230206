#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"

class Character : public Creature_Base
{
private:
	const int MAX_NAME_SIZE = 10;
	void InputNameProcess();

protected:
	RaceType race = HumanType;
	char skill1_Name[16];
	char skill2_Name[16];

	const int ExpCap = 100;
	int exp = 0;
	int maxExp = ExpCap;

	/// <summary>
	/// 이 플레이어가 있는 맵
	/// </summary>
	Map* pMap = nullptr;

	/// <summary>
	/// 이 플레이어의 현재 상태(이동중, 전투중 등등)
	/// </summary>
	PlayerState state = Move;

	/// <summary>
	/// 플레이어의 위치
	/// </summary>
	Position position;

public:
	inline void AddExp(int _exp) 
	{ 
		exp += _exp; 
		if (exp > maxExp)
		{
			exp -= maxExp;
			LevelUp();
		}
	}

	/// <summary>
	/// 초기화용 함수. 팩토리에서 실행.
	/// </summary>
	virtual void Initialize() override;

	/// <summary>
	/// 정리용 함수. Die에서 실행
	/// </summary>
	virtual void CleanUp() override;

	/// <summary>
	/// pBattleTarget을 공격하는 함수. 각 개별 클래스마다 override 할 것
	/// </summary>
	virtual void Attack() override;

	/// <summary>
	/// 스테이터스 출력하는 함수
	/// </summary>
	virtual void PrintStatus() override;

protected:
	/// <summary>
	/// 죽었을 때 실행될 함수
	/// </summary>
	virtual void Die() override;

	virtual void NormalAttack();
	virtual void Skill01();
	virtual void Skill02();

	virtual void LevelUp();
	
};

