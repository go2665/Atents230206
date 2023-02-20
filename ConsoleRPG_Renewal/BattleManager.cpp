#include "BattleManager.h"
#include <iostream>
using namespace std;

//void BattleManager::TurnLoop()
//{
//	//if (battlers[0] != nullptr && battlers[1] != nullptr)
//	if( !IsBattleEnd() )	// ���� ���� ���� �Ʒ� �ڵ� ����
//	{
//		battlers[0]->OnTurnStart();
//		battlers[1]->OnTurnStart();
//
//		battlers[0]->Attack(*battlers[1]);		// �����ϰ�
//		if (!battlers[1]->IsAlive())
//		{
//			End();								// ��밡 �׾����� ���� ���� ó��			
//		}
//
//		if (battlers[1] != nullptr)
//		{
//			battlers[1]->Attack(*battlers[0]);	// ��밡 ��������� ���� ����
//			if (!battlers[0]->IsAlive())
//			{
//				End();
//			}
//		}
//
//		battlers[0]->OnTurnEnd();
//		battlers[1]->OnTurnEnd();
//	}
//}
//


void BattleManager::SetBattlers(Creature_Base* battler1, Creature_Base* battler2)
{
	battler1->SetBattleTarget(battler2);	// ���� ��� ����
	battler2->SetBattleTarget(battler1);
	
	if (battler1->GetDexterity() < battler2->GetDexterity())	// ��ø���� ���� ���� ������ ĳ���� ����
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
	battlers[0]->Loop();
	if (IsBattleEnd())
	{
		return;
	}
	battlers[1]->Loop();

	battlers[0]->PrintStatus();
	battlers[1]->PrintStatus();
}

void BattleManager::BattleEnd()
{
	battlers[1]->OnBattleEnd();
	battlers[0]->OnBattleEnd();

	battlers[0] = nullptr;
	battlers[1] = nullptr;

	cout << "���� ����." << endl;
}
