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
	printChar = L'△';
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);

	encounterChange = 0.5f;

	strcpy_s(actionListText, "명상하기(3)");
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
	cout << "명상을 시작합니다." << endl;
	float r = Utils::GetRandom();
	if (r < 0.5f)
	{
		cout << "심신이 안정되었다." << endl;
		cout << "MP +100" << endl;
		player->AddMP(100);
	}
	else if (r < 0.9f)
	{
		cout << "잠념이 들었다." << endl;
		cout << "시간만 날렸다..." << endl;
	}
	else
	{
		cout << "거대한 깨닳음을 얻었다!" << endl;
		cout << "최대 MP +100" << endl;
		cout << "MP 완전 회복!" << endl;
		player->AddMaxMP(100);
		player->AddMP(player->GetMaxMP());
	}
}
