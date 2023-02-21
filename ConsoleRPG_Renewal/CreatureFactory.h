#pragma once
#include "Enums.h"
#include "Creature_Base.h"

class CreatureFactory
{
public:
	static Creature_Base* MakeCreature(CreatureType type);
	static Creature_Base* MakeCreature(RaceType type);
	static void DestroyCreature(Creature_Base* target);
};

