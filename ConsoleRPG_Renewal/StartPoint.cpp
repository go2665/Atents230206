#include "StartPoint.h"
#include "Plane.h"

void StartPoint::Initialize()
{
	type = StartPointType;
}

void StartPoint::CleanUp()
{
	Plane::CleanUp();
}
