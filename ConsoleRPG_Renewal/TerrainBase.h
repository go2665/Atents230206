#pragma once
#include <list>
#include "Enums.h"

using namespace std;

// 맵 한칸
class TerrainBase
{
public:
	virtual void Initialize() {};
	virtual void CleanUp() {};

	void TerrainEnter();
	void TerrainExit();
	void TerrainSearch();
	CreatureType GetAttackMonster();

	virtual void PrintLandscape() {};

public:	// 임시로 테스트용도로 public
	TerrainType type;

	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch() {};

};

