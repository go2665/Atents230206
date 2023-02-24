#pragma once
#include <list>
#include "Enums.h"

using namespace std;

// ¸Ê ÇÑÄ­
class TerrainBase
{
public:
	virtual void Initialize() {};
	virtual void CleanUp();

	void TerrainEnter();
	void TerrainExit();
	void TerrainSearch();
	CreatureType GetAttackMonster();

	virtual void PrintLandscape() {};

protected:
	TerrainType type;

	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch() {};

};

