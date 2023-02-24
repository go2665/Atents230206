#include "Mountain.h"

void Mountain::Initialize()
{
	type = MountainType;
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
	monsters.push_back(WolfType);
}

void Mountain::CleanUp()
{
	TerrainBase::CleanUp();
}
