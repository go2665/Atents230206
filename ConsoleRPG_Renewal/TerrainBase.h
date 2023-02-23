#pragma once
#include <list>
#include "Enums.h"

using namespace std;

// �� ��ĭ
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

public:	// �ӽ÷� �׽�Ʈ�뵵�� public
	TerrainType type;

	list<CreatureType> monsters;

	virtual void OnEnter() {};
	virtual void OnExit() {};
	virtual void OnSearch() {};

};

