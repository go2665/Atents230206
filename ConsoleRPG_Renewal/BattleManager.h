#pragma once
#include "Creature_Base.h"

class BattleManager
{
private:	
	/// <summary>
	/// 전투 중인 플레이어와 몬스터를 저장할 배열
	/// 항성 0번 캐릭터가 매 턴마다 먼저 공격한다.(민첩이 높은 캐릭터가 0번)
	/// </summary>
	Creature_Base* battlers[2] = { nullptr, nullptr };

	/// <summary>
	/// 진행된 턴 수
	/// </summary>
	int turn = 0;

public:
	
	/// <summary>
	/// 싸울 캐릭터 설정
	/// </summary>
	/// <param name="battler1">싸울 대상 1</param>
	/// <param name="battler2">싸울 대상 2</param>
	void SetBattlers(Creature_Base* battler1, Creature_Base* battler2);

	/// <summary>
	/// 전투 중인지 확인하는 함수
	/// battlers는 전투가 시작되면 null이 아니게 되고 전투가 끝나면 null이 되므로 둘 다 null이면 전투가 끝난 것이다.
	/// </summary>
	/// <returns>true면 전투가 끝난 상태. false면 전투 중인 상태.</returns>
	inline bool IsBattleEnd() 
	{ 
		return ((battlers[0] != nullptr && !battlers[0]->IsAlive()) || (battlers[1] != nullptr && !battlers[1]->IsAlive())); 
	};
	
	// !IsBattleEnd()
	// ((battlers[0] != nullptr) || (battlers[1] != nullptr))


	/// <summary>
	/// 전투 시작용 함수. 실행되면 전투 시작.
	/// </summary>
	void BattleStart();

	/// <summary>
	/// 매 턴마다 실행되는 함수
	/// </summary>
	void BattleTurnLoop();

	/// <summary>
	/// 전투가 종료되면 실행되는 함수
	/// </summary>
	void BattleEnd();

};

