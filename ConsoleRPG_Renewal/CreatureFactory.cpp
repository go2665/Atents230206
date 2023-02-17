#include "CreatureFactory.h"
#include "Character.h"
#include "Monster_Orc.h"
#include "Monster_Wolf.h"

Creature_Base* CreatureFactory::MakeCreature(CreatureType type)
{
	Creature_Base* creature = nullptr;
	switch (type)
	{
	case Player:
		creature = new Character();
		break;
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

void CreatureFactory::DestroyCreature(Creature_Base* target)
{
	target->CleanUp();
	delete target;
}
