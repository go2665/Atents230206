#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"

class Character : public Creature_Base
{
private:
	void InputNameProcess();

protected:
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
	inline void AddExp(int _exp) { exp += _exp; }

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
	/// 데미지를 받아 처리하는 함수. 각 개별 클래스마다 override 할 것
	/// </summary>
	virtual void Defence(int damage) override;

	/// <summary>
	/// 스테이터스 출력하는 함수
	/// </summary>
	virtual void PrintStatus() override;

protected:
	/// <summary>
	/// Loop 시작될 때 실행될 함수.
	/// </summary>
	virtual void OnTurnStart() override;

	/// <summary>
	/// Loop 안에서 해당 크리처가 매 턴마다 하는 행동이 기록된 함수.
	/// </summary>
	virtual void OnTurnAction() override;

	/// <summary>
	/// Loop가 끝날 때 실행될 함수
	/// </summary>
	virtual void OnTurnEnd() override;

	/// <summary>
	/// 스테이터스를 랜덤으로 설정하는 함수
	/// </summary>
	virtual void SetRandomStatus() override;

	/// <summary>
	/// 죽었을 때 실행될 함수
	/// </summary>
	virtual void Die() override;
};

