#include "Mountain.h"
#include "Utils.h"
#include "Creature_Base.h"
#include "Factory.h"
#include "BattleManager.h"
#include "Map.h"
#include "GameManager.h"

void Mountain::Initialize()
{
	type = MountainType;
	printChar = L'��';
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);

	encounterChange = 0.5f;

	strcpy_s(actionListText, "����ϱ�(3)");
}

void Mountain::CleanUp()
{
	TerrainBase::CleanUp();
}

void Mountain::OnEnter()
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

void Mountain::OnAction()
{
	cout << "����� �����մϴ�." << endl;
	float r = Utils::GetRandom();
	if (r < 0.5f)
	{
		cout << "�ɽ��� �����Ǿ���." << endl;
		cout << "MP +100" << endl;
		player->AddMP(100);
	}
	else if (r < 0.9f)
	{
		cout << "����� �����." << endl;
		cout << "�ð��� ���ȴ�..." << endl;
	}
	else
	{
		cout << "�Ŵ��� �������� �����!" << endl;
		cout << "�ִ� MP +100" << endl;
		cout << "MP ���� ȸ��!" << endl;
		player->AddMaxMP(100);
		player->AddMP(player->GetMaxMP());
	}
}
