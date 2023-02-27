#pragma once
#include "TerrainBase.h"
class Desert : public TerrainBase
{
public:
	virtual void Initialize() override;
	virtual void CleanUp() override;

	virtual void OnEnter() override;
};

