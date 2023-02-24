#pragma once
#include "TerrainBase.h"
class Mountain : public TerrainBase
{
public:
	virtual void Initialize() override;
	virtual void CleanUp() override;
};

