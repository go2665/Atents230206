#include "BattleManager.h"

void BattleManager::Start(Monster* pOpponent)
{
	pEnemy = pOpponent;					// 적 설정
	pEnemy->SetBattleTarget(pPlayer);	// 전투 상대 설정
	pPlayer->SetBattleTarget(pEnemy);

	if (pPlayer->GetDexterity() >= pEnemy->GetDexterity())	// 민첩성에 따라 먼저 공격할 캐릭터 결정
	{
		battlers[0] = pPlayer;
		battlers[1] = pEnemy;
	}
	else
	{
		battlers[0] = pEnemy;
		battlers[1] = pPlayer;
	}
}

void BattleManager::TurnLoop()
{
	//if (battlers[0] != nullptr && battlers[1] != nullptr)
	if( !IsBattleEnd() )	// 전투 중일 때만 아래 코드 실행
	{
		battlers[0]->OnTurnStart();
		battlers[1]->OnTurnStart();

		battlers[0]->Attack(*battlers[1]);		// 공격하고
		if (!battlers[1]->IsAlive())
		{
			End();								// 상대가 죽었으면 전투 종료 처리			
		}

		if (battlers[1] != nullptr)
		{
			battlers[1]->Attack(*battlers[0]);	// 상대가 살아있으면 상대방 공격
			if (!battlers[0]->IsAlive())
			{
				End();
			}
		}

		battlers[0]->OnTurnEnd();
		battlers[1]->OnTurnEnd();
	}
}

void BattleManager::End()
{
	battlers[0] = nullptr;
	battlers[1] = nullptr;
	pEnemy = nullptr;
}
