#pragma once
#include "Character.h"
#include "Monster.h"

class BattleManager
{
private:
	/// <summary>
	/// 플레이어 캐릭터
	/// </summary>
	Character* pPlayer = nullptr;

	/// <summary>
	/// 전투를 할 적 몬스터
	/// </summary>
	Monster* pEnemy = nullptr;		// 지금은 별다른 효용이 없음. 미래를 위해 일단 유지

	/// <summary>
	/// 전투 중인 플레이어와 몬스터를 저장할 배열
	/// 항성 0번 캐릭터가 매 턴마다 먼저 공격한다.(민첩이 높은 캐릭터가 0번)
	/// </summary>
	Creature_Base* battlers[2] = { nullptr, nullptr };

	int turn = 0;

public:
	/// <summary>
	/// 플레이어 설정용 함수(1회용. 게임당 한번만 설정 가능)
	/// </summary>
	/// <param name="_player">플레이어</param>
	/// <returns>true면 플레이어 설정 성공. false면 실패(절대로 발생하면 안됨).</returns>
	inline bool SetPlayer(Character* _player) 
	{
		if (pPlayer == nullptr)	// 플레이어가 설정이 안되었을 때만 
		{
			pPlayer = _player;	// 플레이어 설정
			return true;
		}
		return false;	// 여기로 오면 안됨!!!
	};

	/// <summary>
	/// 전투 중인지 확인하는 함수
	/// battlers는 전투가 시작되면 null이 아니게 되고 전투가 끝나면 null이 되므로 둘 다 null이면 전투가 끝난 것이다.
	/// </summary>
	/// <returns>true면 전투가 끝난 상태. false면 전투 중인 상태.</returns>
	inline bool IsBattleEnd() { return ((battlers[0] == nullptr) && (battlers[1] == nullptr));  };
	
	// !IsBattleEnd()
	// ((battlers[0] != nullptr) || (battlers[1] != nullptr))


	/// <summary>
	/// 전투 시작용 함수. 실행되면 전투 시작.
	/// </summary>
	/// <param name="pOpponent">적</param>
	void Start(Monster* pOpponent);

	/// <summary>
	/// 매 턴마다 실행되는 함수
	/// </summary>
	void TurnLoop();

	/// <summary>
	/// 전투가 종료되면 실행되는 함수
	/// </summary>
	void End();

};

