#include "Plane.h"
#include "Utils.h"
#include "Factory.h"
#include "Creature_Base.h"
#include "Map.h"
#include "BattleManager.h"

void Plane::Initialize()
{
	type = PlaneType;
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);

	encounterChange = 0.2f;
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

		BattleManager* pBM = map->GetBattleManager();
		pBM->SetBattlers((Creature_Base*)(map->GetPlayer()), enemy);
		pBM->BattleStart();
	}
}
