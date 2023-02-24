#include "Mountain.h"

void Mountain::Initialize()
{
	type = MountainType;
	monsters.push_back(Orc);
	monsters.push_back(Wolf);
	monsters.push_back(Wolf);
	monsters.push_back(Wolf);
	monsters.push_back(Wolf);
}

void Mountain::CleanUp()
{
	TerrainBase::CleanUp();
}
