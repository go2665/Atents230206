#include "BattleManager.h"
#include <iostream>
using namespace std;

void BattleManager::SetBattlers(Creature_Base* battler1, Creature_Base* battler2)
{
	battler1->SetBattleTarget(battler2);	// 전투 상대 설정
	battler2->SetBattleTarget(battler1);
	
	if (battler1->GetDexterity() < battler2->GetDexterity())	// 민첩성에 따라 먼저 공격할 캐릭터 결정
	{
		battlers[0] = battler2;
		battlers[1] = battler1;
	}
	else
	{
		battlers[0] = battler1;
		battlers[1] = battler2;
	}
}

void BattleManager::BattleStart()
{
	battlers[0]->OnBattleStart(battlers[1]);
	battlers[1]->OnBattleStart(battlers[0]);

	turn = 1;

	while (!IsBattleEnd())
	{
		BattleTurnLoop();
	}

	BattleEnd();
}

void BattleManager::BattleTurnLoop()
{
	cout << "-------------------- " << turn << "턴 시작 -------------------------------" << endl;
	battlers[0]->Loop();
	if (IsBattleEnd())
	{
		return;
	}
	battlers[1]->Loop();
	if (IsBattleEnd())
	{
		return;
	}

	battlers[0]->PrintStatus();
	battlers[1]->PrintStatus();
	
	turn++;
	cout << "--------------------------------------------------------------" << endl << endl;
}

void BattleManager::BattleEnd()
{
	battlers[1]->OnBattleEnd();
	battlers[0]->OnBattleEnd();

	Creature_Base* winner;
	Creature_Base* loser;
	if (battlers[0]->IsAlive())
	{
		winner = battlers[0];
		loser = battlers[1];
	}
	else
	{
		winner = battlers[1];
		loser = battlers[0];
	}
	cout << endl << endl << "전투 종료." << endl;
	cout << "[" << winner->GetName() << "]가 [" << loser->GetName() << "]를 이겼습니다." << endl << endl;
	winner->PrintStatus();

	battlers[0] = nullptr;
	battlers[1] = nullptr;
}
