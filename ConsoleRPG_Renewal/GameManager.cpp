#include "GameManager.h"
#include "Factory.h"

#include <iostream>
using namespace std;

GameManager* GameManager::instance = nullptr;

void GameManager::MakeCharacter()
{
	// 어떤 종족 만들지 입력받기
	// 해당 종족 생성하고 player에 넣기
	int select = 1;
	do
	{
		if (select != 1)
		{
			cout << "잘못된 입력입니다. 1~3을 입력해 주세요." << endl;
		}

		cout << "당신의 종족은 무엇입니까?(1:휴먼, 2:엘프, 3:드워프) : ";
		cin >> select;
		if (cin.fail())		// 문자열이 입력된 경우
		{
			cin.clear();
			cin.ignore(INT32_MAX, '\n');
			select = INT32_MAX;
		}
	} while (!(select > 0 && select < (NumOfRaceType + 1)));

	RaceType type = (RaceType)(select - 1);
	player = (Character*)Factory::MakeCreature(type);
	if (player == nullptr)
	{
		cout << "ERROR!!! ERROR!!! ERROR!!! ERROR!!! ERROR!!!" << endl;
	}
}

void GameManager::Initialize()
{
	setlocale(LC_ALL, "");

	CleanUp();

	map = new Map("./Data/SampleMap.txt");
	battleManager = new BattleManager();
	
	MakeCharacter();
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
