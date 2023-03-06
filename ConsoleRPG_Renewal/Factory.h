#pragma once
#include "Enums.h"
#include "Creature_Base.h"
#include "TerrainBase.h"

class Factory
{
public:
	static Creature_Base* MakeCreature(CreatureType type);
	static Creature_Base* MakeCreature(RaceType type, SaveData* data = nullptr);
	static void DestroyCreature(Creature_Base* target);

	static TerrainBase* MakeTerrain(TerrainType type);
	static void DestroyTerrain(TerrainBase* target);
};

