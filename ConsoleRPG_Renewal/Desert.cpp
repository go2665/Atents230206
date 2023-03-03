#include "Desert.h"
#include "Utils.h"
#include "Creature_Base.h"
#include "Factory.h"
#include "BattleManager.h"
#include "Map.h"
#include "GameManager.h"

void Desert::Initialize()
{
	type = DesertType;
	printChar = L'��';
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);

	encounterChange = 0.7f;

	strcpy_s(actionListText, "���ƽý��� ����(3)");
}

void Desert::CleanUp()
{
	TerrainBase::CleanUp();
}

void Desert::OnEnter()
{
	float change = Utils::GetRandom();
	if (encounterChange < change)
	{
		CreatureType type = GetAttackMonster();
		Creature_Base* enemy = Factory::MakeCreature(type);

		BattleManager* pBM = GameManager::GetInstance()->GetBattleManager();
		pBM->SetBattlers((GameManager::GetInstance()->GetPlayer()), enemy);
		pBM->BattleStart();
	}
}

void Desert::OnAction()
{
	cout << "���ƽý��� ���� �̵��մϴ�." << endl;
	float r = Utils::GetRandom();
	if (r < 0.3f)
	{
		cout << "�ű�翴��..." << endl;
		cout << "HP -100" << endl;
		cout << "MP -100" << endl;
		player->AddHP(-100);
		player->AddMP(-100);
	}
	else if (r < 0.9f)
	{
		cout << "���ƽý����� ������ �޽��� ���ߴ�." << endl;
		cout << "HP +200" << endl;
		cout << "MP +200" << endl;
		player->AddHP(200);
		player->AddMP(200);
	}
	else
	{
		cout << "���ƽý����� ����� �޽��� ���ߴ�." << endl;
		cout << "HP, MP ����ȸ��" << endl;
		player->RecoveryAll();
	}
}
