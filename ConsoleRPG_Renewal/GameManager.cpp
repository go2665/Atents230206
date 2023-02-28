#include "GameManager.h"
#include "Factory.h"

#include <iostream>
using namespace std;

GameManager* GameManager::instance = nullptr;

void GameManager::Initialize()
{
	CleanUp();

	map = new Map("./Data/SampleMap.txt");
	battleManager = new BattleManager();

	// � ���� ������ �Է¹ޱ�
	// �ش� ���� �����ϰ� player�� �ֱ�

}

void GameManager::CleanUp()
{
	Factory::DestroyCreature(player);
	player = nullptr;	

	delete battleManager;
	battleManager = nullptr;

	delete map;
	map = nullptr;
}

void GameManager::Test()
{
	cout << "�̱��� �׽�Ʈ" << endl;	
}
