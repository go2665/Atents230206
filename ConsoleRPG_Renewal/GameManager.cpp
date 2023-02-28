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

	// 어떤 종족 만들지 입력받기
	// 해당 종족 생성하고 player에 넣기

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
	cout << "싱글톤 테스트" << endl;	
}
