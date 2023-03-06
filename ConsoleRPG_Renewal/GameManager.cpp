#include "GameManager.h"
#include "Factory.h"

#include <iostream>
#include <fstream>
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
	return false;
}

void GameManager::Test()
{
	cout << "�̱��� �׽�Ʈ" << endl;	
}
