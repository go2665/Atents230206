#pragma once
#include "TerrainBase.h"
class Forest : public TerrainBase
{
public:
	virtual void Initialize() override;
	virtual void CleanUp() override;

	virtual void OnEnter() override;

	virtual void OnAction() override;
};

