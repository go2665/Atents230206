#pragma once
#include <stdlib.h>
#include "Character.h"
#include "Map.h"
#include "BattleManager.h"

class GameManager
{
private:
	Character* player = nullptr;
	BattleManager* battleManager = nullptr;
	Map* map = nullptr;

public:
	void Initialize();
	void CleanUp();

	inline Character* GetPlayer() { return player; }
	inline BattleManager* GetBattleManager() { return battleManager; }
	inline Map* GetMap() { return map; }


private:
	// �̱��� �ν��Ͻ��� ������ static���� �����
	static GameManager* instance;

	// �����ڿ� �Ҹ��ڸ� private���� �����ؼ� ������� ����ų� ���� �� ���� �����
	GameManager() {};
	GameManager(const GameManager& other) {};
	~GameManager() {};

	// �ν��Ͻ� ������ �Լ�. �Լ������Ϳ� �ֱ� ���� static���� ����
	static void Destroy()
	{
		delete instance;		// �����
		instance = nullptr;		// null�� �ʱ�ȭ
	}

public:
	// �ν��Ͻ��� ������ �Լ� �����(�б� ����)
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
			atexit(Destroy);	// ����ÿ� Destroy �Լ� �����ϵ��� ����			
		}
		return instance;
	}

	// �׽�Ʈ�� �Լ�
	void Test();
};