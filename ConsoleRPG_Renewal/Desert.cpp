#include "Desert.h"

void Desert::Initialize()
{
	type = DesertType;
	monsters.push_back(Orc);
	monsters.push_back(Orc);
	monsters.push_back(Orc);
	monsters.push_back(Orc);
	monsters.push_back(Wolf);
}

void Desert::CleanUp()
{
	TerrainBase::CleanUp();
}
