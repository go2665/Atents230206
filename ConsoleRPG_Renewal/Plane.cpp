#include "Plane.h"
#include "Utils.h"
#include "Factory.h"
#include "Creature_Base.h"
#include "Map.h"
#include "BattleManager.h"
#include "GameManager.h"

void Plane::Initialize()
{
	type = PlaneType;
	printChar = L'��';
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);

	encounterChange = 0.2f;

	strcpy_s(actionListText, "�ѷ�����(3)");
}

void Plane::CleanUp()
{
	TerrainBase::CleanUp();
}

void Plane::OnEnter()
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

void Plane::OnAction()
{	
	cout << "���� ���ư��� ���� ���δ�." << endl;
	float r = Utils::GetRandom();
	if (r < 0.7f)
	{
		cout << "���� ���� ���� ��Ҵ�." << endl;
		cout << "�������� ���̾���." << endl;
		cout << "�ִ� HP +10" << endl;
		player->AddMaxHP(10);
	}
	else
	{
		cout << "������ �¾Ҵ�." << endl;
		player->AddMP(-100);
	}
}
