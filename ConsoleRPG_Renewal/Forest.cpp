#include "Forest.h"

void Forest::Initialize()
{
	type = ForestType;
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
}

void Forest::CleanUp()
{
	TerrainBase::CleanUp();
}
