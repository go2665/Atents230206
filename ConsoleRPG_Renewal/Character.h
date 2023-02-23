#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"

class Character : public Creature_Base
{
private:
	/// <summary>
	/// 이름 최대 길이
	/// </summary>
	const int MAX_NAME_SIZE = 10;

	/// <summary>
	/// 종료 입력 처리용
	/// </summary>
	const int INPUT_EXIT = -1;
	
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

	/// <summary>
	/// 캐릭터의 위치를 돌려주는 함수
	/// </summary>
	/// <returns>캐릭터의 위치에 대한 참조</returns>
	const Position& GetPosition() { return position; }

	/// <summary>
	/// 맵을 할당하기
	/// </summary>
	/// <param name="newMap">새로운 맵</param>
	void SetMap(Map* newMap);

protected:
	/// <summary>
	/// 죽었을 때 실행될 함수
	/// </summary>
	virtual void Die() override;

	virtual void NormalAttack();
	virtual void Skill01();
	virtual void Skill02();

	virtual void LevelUp();

	/// <summary>
	/// position용 Set 함수
	/// </summary>
	/// <param name="newPos">position에 설정될 새 값</param>
	void SetPosition(const Position& newPos);

	/// <summary>
	/// 자신의 위치를 출력하는 함수
	/// </summary>
	void PrintPosition();

	/// <summary>
	/// 플레이어의 이동 처리 함수
	/// </summary>
	int InputProcess_Move();	
};

