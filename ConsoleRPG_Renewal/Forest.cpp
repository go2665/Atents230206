#include "Forest.h"

void Forest::Initialize()
{
	type = ForestType;
	monsters.push_back(Orc);
	monsters.push_back(Orc);
	monsters.push_back(Wolf);
	monsters.push_back(Wolf);
	monsters.push_back(Wolf);
}

void Forest::CleanUp()
{
	TerrainBase::CleanUp();
}
