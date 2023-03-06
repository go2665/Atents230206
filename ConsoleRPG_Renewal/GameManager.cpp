#include "GameManager.h"
#include "Factory.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
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

void GameManager::SavePlayerData()
{
	// ./Data/Save 폴더에 SaveData.txt라는 파일에 데이터를 저장한다.
	
	// 저장 양식
	// 이름,레벨,스테이터스,hp,maxHP,mp,maxMP,종족,exp,최대exp
	if (player != nullptr)
	{
		ofstream ofs;
		ofs.open("./Data/Save/SaveData.txt");
		ofs << player->GetName();					// 이름 저장
		ofs << "," << player->GetLevel();			// 레벨
		ofs << "," << player->GetStringth();		// 힘
		ofs << "," << player->GetDexterity();		// 민첩
		ofs << "," << player->GetStatmina();		// 체력
		ofs << "," << player->GetIntelligence();	// 지능
		ofs << "," << player->GetWisdom();			// 지혜
		ofs << "," << player->GetHP();				// HP
		ofs << "," << player->GetMaxHP();			// 최대 HP
		ofs << "," << player->GetMP();				// MP
		ofs << "," << player->GetMaxMP();			// 최대 MP
		ofs << "," << player->GetRace();			// 종족
		ofs << "," << player->GetExp();				// 현재 경험치
		ofs << "," << player->GetMaxExp();			// 최대 경험치
		
		ofs.close();
	}
}

bool GameManager::LoadPlayerData()
{
	SaveData data;
	bool result = false;
	char temp[256];

	// 이름,레벨,스테이터스,hp,maxHP,mp,maxMP,종족,exp,최대exp
	ifstream ifs;
	ifs.open("./Data/Save/SaveData.txt");
	if (ifs.is_open())
	{
		ifs.getline(temp, 256, ',');
		strcpy_s(data.name, temp);

		ifs.getline(temp, 256, ',');
		data.level = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.strength = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.dexterity = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.stamina = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.intelligence = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.wisdom = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.hp = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.maxHP = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.mp = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.maxMP = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.race = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.exp = atoi(temp);

		ifs.getline(temp, 256, ',');
		data.maxExp = atoi(temp);

		result = true;

		// 기존 플레이어 삭제하고 새로 만드는 작업
		Factory::DestroyCreature(player);
		player = (Character*)Factory::MakeCreature((RaceType)data.race, &data);

		ifs.close();
	}

	return result;
}

void GameManager::Test()
{
	cout << "싱글톤 테스트" << endl;	
}
