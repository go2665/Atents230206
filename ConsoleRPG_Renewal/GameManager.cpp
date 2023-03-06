#include "GameManager.h"
#include "Factory.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

GameManager* GameManager::instance = nullptr;

void GameManager::MakeCharacter()
{
	// � ���� ������ �Է¹ޱ�
	// �ش� ���� �����ϰ� player�� �ֱ�
	int select = 1;
	do
	{
		if (select != 1)
		{
			cout << "�߸��� �Է��Դϴ�. 1~3�� �Է��� �ּ���." << endl;
		}

		cout << "����� ������ �����Դϱ�?(1:�޸�, 2:����, 3:�����) : ";
		cin >> select;
		if (cin.fail())		// ���ڿ��� �Էµ� ���
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
	// ./Data/Save ������ SaveData.txt��� ���Ͽ� �����͸� �����Ѵ�.
	
	// ���� ���
	// �̸�,����,�������ͽ�,hp,maxHP,mp,maxMP,����,exp,�ִ�exp
	if (player != nullptr)
	{
		ofstream ofs;
		ofs.open("./Data/Save/SaveData.txt");
		ofs << player->GetName();					// �̸� ����
		ofs << "," << player->GetLevel();			// ����
		ofs << "," << player->GetStringth();		// ��
		ofs << "," << player->GetDexterity();		// ��ø
		ofs << "," << player->GetStatmina();		// ü��
		ofs << "," << player->GetIntelligence();	// ����
		ofs << "," << player->GetWisdom();			// ����
		ofs << "," << player->GetHP();				// HP
		ofs << "," << player->GetMaxHP();			// �ִ� HP
		ofs << "," << player->GetMP();				// MP
		ofs << "," << player->GetMaxMP();			// �ִ� MP
		ofs << "," << player->GetRace();			// ����
		ofs << "," << player->GetExp();				// ���� ����ġ
		ofs << "," << player->GetMaxExp();			// �ִ� ����ġ
		
		ofs.close();
	}
}

bool GameManager::LoadPlayerData()
{
	SaveData data;
	bool result = false;
	char temp[256];

	// �̸�,����,�������ͽ�,hp,maxHP,mp,maxMP,����,exp,�ִ�exp
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

		// ���� �÷��̾� �����ϰ� ���� ����� �۾�
		Factory::DestroyCreature(player);
		player = (Character*)Factory::MakeCreature((RaceType)data.race, &data);

		ifs.close();
	}

	return result;
}

void GameManager::Test()
{
	cout << "�̱��� �׽�Ʈ" << endl;	
}
