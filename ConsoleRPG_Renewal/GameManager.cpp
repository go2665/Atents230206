#include "GameManager.h"
#include "Factory.h"

#include <iostream>
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

void GameManager::Test()
{
	cout << "�̱��� �׽�Ʈ" << endl;	
}
