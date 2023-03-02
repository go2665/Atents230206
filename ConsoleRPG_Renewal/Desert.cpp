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
	printChar = L'¢Ì';
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);

	encounterChange = 0.7f;
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
