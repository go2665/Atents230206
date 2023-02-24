#pragma once
#include "Plane.h"
class StartPoint : public Plane
{
public:
	virtual void Initialize() override;
	virtual void CleanUp() override;

	virtual void OnEnter() override;
};

