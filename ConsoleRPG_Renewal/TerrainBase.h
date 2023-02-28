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

	inline wchar_t GetPrint() { return printChar; }

protected:
	Map* map = nullptr;
	TerrainType type;
	wchar_t printChar;

	float encounterChange = 0.0f;
	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch() {};

};

