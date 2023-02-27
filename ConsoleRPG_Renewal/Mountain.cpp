#include "Mountain.h"
#include "Utils.h"
#include "Creature_Base.h"
#include "Factory.h"
#include "BattleManager.h"
#include "Map.h"

void Mountain::Initialize()
{
	type = MountainType;
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);

	encounterChange = 0.5f;
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

		BattleManager* pBM = map->GetBattleManager();
		pBM->SetBattlers((Creature_Base*)(map->GetPlayer()), enemy);
		pBM->BattleStart();
	}
}
