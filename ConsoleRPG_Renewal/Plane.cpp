#include "Plane.h"

void Plane::Initialize()
{
	type = PlaneType;
	monsters.push_back(OrcType);
	monsters.push_back(WolfType);
}

void Plane::CleanUp()
{
	TerrainBase::CleanUp();
}
