#include "CreatureFactory.h"
#include "Character.h"
#include "Monster_Orc.h"
#include "Monster_Wolf.h"
#include "Human.h"

Creature_Base* CreatureFactory::MakeCreature(CreatureType type)
{
	Creature_Base* creature = nullptr;
	switch (type)
	{
	case Orc:
		creature = new Monster_Orc();
		break;
	case Wolf:
		creature = new Monster_Wolf();
		break;
	case None:
	default:
		// 들어오면 안되는 곳
		break;
	}

	if (creature != nullptr)
	{
		creature->Initialize();
	}
    return creature;
}

Creature_Base* CreatureFactory::MakeCreature(RaceType type)
{
	Creature_Base* player = nullptr;
	switch (type)
	{
	case HumanType :
		player = new Human();
		break;
	case ElfType :
		player = new Character();
		break;
	case DrawfType :
		player = new Character();
		break;
	default:
		// 들어오면 안되는 곳
		break;
	}

	if (player != nullptr)
	{
		player->Initialize();
	}
	return player;
}

void CreatureFactory::DestroyCreature(Creature_Base* target)
{
	target->CleanUp();
	delete target;
}
