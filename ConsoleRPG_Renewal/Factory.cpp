#include "Factory.h"
#include "Character.h"
#include "Monster_Orc.h"
#include "Monster_Wolf.h"
#include "Human.h"
#include "Elf.h"
#include "Drawf.h"
#include "Plane.h"
#include "Forest.h"
#include "Mountain.h"
#include "Desert.h"
#include "StartPoint.h"
#include "GameManager.h"

Creature_Base* Factory::MakeCreature(CreatureType type)
{
	Creature_Base* creature = nullptr;
	switch (type)
	{
	case OrcType:
		creature = new Monster_Orc();
		break;
	case WolfType:
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

Creature_Base* Factory::MakeCreature(RaceType type, SaveData* data)
{
	Creature_Base* player = nullptr;
	switch (type)
	{
	case HumanType :
		player = new Human();
		break;
	case ElfType :
		player = new Elf();
		break;
	case DrawfType :
		player = new Drawf();
		break;
	default:
		// 들어오면 안되는 곳
		cout << "ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!!";
		break;
	}

	if (player != nullptr)
	{
		player->Initialize(data);
	}
	return player;
}

void Factory::DestroyCreature(Creature_Base* target)
{
	if (target != nullptr)
	{
		target->CleanUp();
		delete target;
	}
}

TerrainBase* Factory::MakeTerrain(TerrainType type)
{
	TerrainBase* terrain = nullptr;
	switch (type)
	{
	case PlaneType:
		terrain = new Plane();
		break;
	case ForestType:
		terrain = new Forest();
		break;
	case MountainType:
		terrain = new Mountain();
		break;
	case DesertType:
		terrain = new Desert();
		break;
	case StartPointType:
		terrain = new StartPoint();
		break;
	case NumOfTypes:
	default:
		break;
	}
	if (terrain != nullptr)
	{
		terrain->Initialize();
	}

	return terrain;
}

void Factory::DestroyTerrain(TerrainBase* target)
{
	if (target != nullptr)
	{
		target->CleanUp();
		delete target;
	}
}
