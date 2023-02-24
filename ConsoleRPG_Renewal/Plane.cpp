#include "Plane.h"

void Plane::Initialize()
{
	type = PlaneType;
	monsters.push_back(Orc);
	monsters.push_back(Wolf);
}

void Plane::CleanUp()
{
	TerrainBase::CleanUp();
}
