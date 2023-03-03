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
	printChar = L'□';
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);

	encounterChange = 0.2f;

	strcpy_s(actionListText, "둘러보기(3)");
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
	cout << "새가 날아가는 것이 보인다." << endl;
	float r = Utils::GetRandom();
	if (r < 0.7f)
	{
		cout << "돌을 던져 새를 잡았다." << endl;
		cout << "안정적인 맛이었다." << endl;
		cout << "최대 HP +10" << endl;
		player->AddMaxHP(10);
	}
	else
	{
		cout << "새똥을 맞았다." << endl;
		player->AddMP(-100);
	}
}
