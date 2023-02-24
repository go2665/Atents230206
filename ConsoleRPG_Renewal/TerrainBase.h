#pragma once
#include <list>
#include "Enums.h"

using namespace std;

class Map;

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

	inline void SetMap(Map* pNewMap)
	{
		if (map == nullptr)
		{
			map = pNewMap;
		}
	}

protected:
	Map* map = nullptr;
	TerrainType type;

	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch() {};

};

