#include "Forest.h"
#include "Utils.h"
#include "Creature_Base.h"
#include "Factory.h"
#include "BattleManager.h"
#include "Map.h"
#include "GameManager.h"

void Forest::Initialize()
{
	type = ForestType;
	printChar = L'��';
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);

	encounterChange = 0.5f;

	strcpy_s(actionListText, "ä���ϱ�(3)");
}

void Forest::CleanUp()
{
	TerrainBase::CleanUp();
}

void Forest::OnEnter()
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

void Forest::OnAction()
{
	cout << "ä���� �����մϴ�." << endl;
	float r = Utils::GetRandom();
	if (r < 0.5f)
	{
		cout << "�������� �Ծ���ȴ�." << endl;
		cout << "HP -100" << endl;
		player->AddHP(-100);
	}
	else if (r < 0.9f)
	{
		cout << "���ִ� ������ �߰��ߴ�." << endl;
		cout << "HP +50" << endl;
		player->AddHP(50);
	}
	else
	{
		cout << "�ɺô�!" << endl;
		cout << "�ִ� HP +500" << endl;
		player->AddMaxHP(500);
	}
}
