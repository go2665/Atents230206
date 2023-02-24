#include "Desert.h"

void Desert::Initialize()
{
	type = DesertType;
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
}

void Desert::CleanUp()
{
	TerrainBase::CleanUp();
}
