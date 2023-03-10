#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"
#include "SaveData.h"

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

	/// <summary>
	/// 입력 실패 표시용
	/// </summary>
	const int INPUT_FAIL = -999;
	
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
	/// 이 플레이어의 현재 상태(이동중, 행동중 등등)
	/// </summary>
	PlayerState state = Action;

	/// <summary>
	/// 플레이어의 위치. 기본값으로 (-1,-1)
	/// </summary>
	Position position = Position::MinusOne;

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
	virtual void Initialize(SaveData* data = nullptr) override;

	/// <summary>
	/// 플레이어의 행동을 처리할 곳
	/// </summary>
	void Loop();

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
	/// 게임 메니저에 설정딘 맵 시작하기
	/// </summary>
	void StartMap();

	inline const RaceType GetRace() { return race; }
	inline const int GetExp() { return exp; }
	inline const int GetMaxExp() { return maxExp; }

	void LoadData(SaveData& data);

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
	/// 플레이어의 액션 처리 함수
	/// </summary>
	int InputProcess_Action();

	/// <summary>
	/// 플레이어의 이동 처리 함수
	/// </summary>
	int InputProcess_Move();	

	/// <summary>
	/// 스테이터스를 만족할 때까지 다시 돌리는 함수
	/// </summary>
	void StatusReroll();
};

