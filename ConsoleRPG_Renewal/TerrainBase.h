#pragma once
#include <list>
#include "Enums.h"

using namespace std;

class Character;
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
		
	inline const char* GetActionListText() { return actionListText; }
	
	void RunAction();

protected:
	Character* player = nullptr;
	Map* map = nullptr;
	TerrainType type;
	wchar_t printChar;
	char actionListText[64];

	int actionCost = 20;

	float encounterChange = 0.0f;
	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch();

	virtual void OnAction() {};

	void Event_Nothing();
	void Event_Insomnia();
	void Event_AmbushOfTiger();
};

