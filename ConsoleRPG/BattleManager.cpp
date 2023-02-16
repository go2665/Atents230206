#include "BattleManager.h"

void BattleManager::Start(Monster* pOpponent)
{
	pEnemy = pOpponent;					// �� ����
	pEnemy->SetBattleTarget(pPlayer);	// ���� ��� ����
	pPlayer->SetBattleTarget(pEnemy);

	if (pPlayer->GetDexterity() >= pEnemy->GetDexterity())	// ��ø���� ���� ���� ������ ĳ���� ����
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
	if( !IsBattleEnd() )	// ���� ���� ���� �Ʒ� �ڵ� ����
	{
		battlers[0]->OnTurnStart();
		battlers[1]->OnTurnStart();

		battlers[0]->Attack(*battlers[1]);		// �����ϰ�
		if (!battlers[1]->IsAlive())
		{
			End();								// ��밡 �׾����� ���� ���� ó��			
		}

		if (battlers[1] != nullptr)
		{
			battlers[1]->Attack(*battlers[0]);	// ��밡 ��������� ���� ����
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
