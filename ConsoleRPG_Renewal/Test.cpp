#include "Test.h"
#include "Enums.h"
#include "Factory.h"
#include "Creature_Base.h"
#include "Monster_Orc.h"
#include "BattleManager.h"
#include "Utils.h"
#include <iomanip>
#include "TerrainBase.h"
#include "Map.h"
#include "Character.h"
#include "GameManager.h"

void Test::Run()
{
	cout << "Test ����" << endl;
	Utils::SetRandomSeedByTime();

	bool makeGameManager = true;
	if (makeGameManager)
	{
		GameManager* pManager = GameManager::GetInstance();
		pManager->Initialize();

		//Test_CreatureFactory();
		//Test_CharacterNameInput();
		//Test_CharacterAttackSelect();
		//Test_HumanBattle();
		//Test_SelectRace();
		//Test_Terrain();
		//Test_StatusReroll();
		//Test_Renewal();
		//Test_Singleton();
		//Test_MakeCharacter();
		//Test_MapPrint();
		//Test_MapMove();
		Test_SaveGameData();

		pManager->CleanUp();
	}
	else
	{
		//Test_SavingThrow();
		//Test_FileWrite();
		Test_FileRead();
	}
}

void Test::Test_SaveGameData()
{
	GameManager::GetInstance()->SavePlayerData();

}

void Test::Test_FileRead()
{
	char temp[256];
	int line = 0;

	ifstream ifs;
	ifs.open("./data/_Hello.txt");
	if (ifs.is_open())
	{
		while (ifs.getline(temp, 256, ' '))
		{
			cout << "���� �� " << line++ << " : " << temp << endl;
		}
		ifs.close();
	}
}

void Test::Test_FileWrite()
{
	ofstream ofs;
	ofs.open("./data/_Hello.txt");
	ofs << "Hello Hello Hello Hello Hello, World! �ȳ�!";
	ofs.close();
}

void Test::Test_SavingThrow()
{
	int testNum = 1000000;
	int count = 0;
	for (int i = 0; i < testNum; i++)
	{
		bool result = Utils::CheckSavingThrow(15, 25, 20);
		if (result)
			count++;
	}
	printf("������ : %.5f %%\n", (float)count / (float)testNum);
}

void Test::Test_MapMove()
{
	Character* player = GameManager::GetInstance()->GetPlayer();
	player->StartMap();
	player->Loop();
}

void Test::Test_MapPrint()
{
	Map* map = GameManager::GetInstance()->GetMap();
	map->PrintMap();
}

void Test::Test_MakeCharacter()
{
}

void Test::Test_Singleton()
{
	/*GameManager a;
	GameManager* b = new GameManager();
	GameManager* c = new GameManager(a);*/
	GameManager* pManager = GameManager::GetInstance();
}

void Test::Test_StatusReroll()
{
	Character* pPlayer = (Character*)Factory::MakeCreature(HumanType);
	Factory::DestroyCreature(pPlayer);
	
}

void Test::Test_Renewal()
{	
	Character* pPlayer = (Character*)Factory::MakeCreature(HumanType);
	pPlayer->StartMap();
	pPlayer->Loop();

	Factory::DestroyCreature(pPlayer);	
}

void Test::Test_Terrain()
{
	//TerrainBase* pTerrain = new TerrainBase();

	//pTerrain->monsters.push_back(OrcType);
	//pTerrain->monsters.push_back(OrcType);
	//pTerrain->monsters.push_back(WolfType);
	//pTerrain->monsters.push_back(WolfType);
	//pTerrain->monsters.push_back(WolfType);

	//int counter[2] = { 0, 0 };

	//for (int i = 0; i < 1000000; i++)
	//{
	//	CreatureType type = pTerrain->GetAttackMonster();
	//	if (type == OrcType)
	//		counter[0]++;
	//	else
	//		counter[1]++;
	//}

	//cout << "100���� �õ�" << endl;
	//cout << "Orc : " << counter[0] << endl;
	//cout << "Wolf : " << counter[1] << endl;

	//delete pTerrain;
	//pTerrain = nullptr;
}

void Test::Test_SelectRace()
{
	int select = -1;
	while (select == -1)
	{
		cout << "������ ������ �ּ���(1:�ΰ�, 2:����, 3:�����) : ";
		cin >> select;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT32_MAX, '\n');
			select = -1;
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		else
		{
			if (select < 1 || select > 3)
			{
				select = -1;
				cout << "�߸��� �Է��Դϴ�." << endl;
			}
		}
	}

	RaceType type = (RaceType)(select - 1);

	Creature_Base* pPlayer = Factory::MakeCreature(type);
	Creature_Base* pMonster = Factory::MakeCreature(OrcType);

	BattleManager bm;
	
	bm.SetBattlers(pPlayer, pMonster);

	pPlayer->PrintStatus();
	pMonster->PrintStatus();

	bm.BattleStart();

	Factory::DestroyCreature(pMonster);
	Factory::DestroyCreature(pPlayer);
	
}

void Test::Test_HumanBattle()
{
	Creature_Base* pPlayer = Factory::MakeCreature(HumanType);
	Creature_Base* pMonster = Factory::MakeCreature(OrcType);	

	BattleManager bm;
	while ( pPlayer->IsAlive() )
	{
		bm.SetBattlers(pPlayer, pMonster);
		
		pPlayer->PrintStatus();
		pMonster->PrintStatus();

		bm.BattleStart();

		if (!pMonster->IsAlive())
		{
			Factory::DestroyCreature(pMonster);
			pMonster = Factory::MakeCreature(OrcType);		
			cout << endl << "[" << pMonster->GetName() << "]�� ���Ӱ� �����մϴ�." << endl;
		}
	}

	Factory::DestroyCreature(pMonster);
	Factory::DestroyCreature(pPlayer);
}

void Test::Test_CharacterPrintStatus()
{
	Creature_Base* pPlayer = Factory::MakeCreature(HumanType);
	pPlayer->PrintStatus();
	Factory::DestroyCreature(pPlayer);

}

void Test::Test_CharacterAttackSelect()
{
	Creature_Base* pPlayer = Factory::MakeCreature(PlayerType);
	Creature_Base* pMonster = Factory::MakeCreature(OrcType);
	pPlayer->PrintStatus();
	pMonster->PrintStatus();

	BattleManager bm;
	bm.SetBattlers(pPlayer, pMonster);

	while (pMonster->IsAlive())
	{
		pPlayer->Attack();
	}

	//bm.BattleStart();



	Factory::DestroyCreature(pMonster);
	Factory::DestroyCreature(pPlayer);
}

void Test::Test_CharacterNameInput()
{
	// "�̸��� �Է��ϼ��� : "��� ����� �� �Է� ���� ������ �̸����� �����ϱ�
	// �̸��� �ִ� 10�ڸ� �Ѿ�� �ʾƾ� �Ѵ�.
	// 10�ڰ� �Ѿ�� �ٽ� �Է��� �޴´�.
	// �̸��� �ԷµǸ� y/n�� Ȯ�ιޱ�

	char name[16];
	const int MAX_NAME_SIZE = 10;
	bool pass = false;
	int size = 0;
	do
	{
		cout << "�̸��� �Է��ϼ��� : ";
		cin >> setw(16) >> name;
		size = (int)strlen(name);

		if (size > MAX_NAME_SIZE)
		{
			cout << "�̸��� ���̰� �ʹ� ��ϴ�. �ٽ� �Է����ּ���. �ִ� " << MAX_NAME_SIZE << "�� �Դϴ�." << endl;
			//char temp[1024];
			//cin >> temp;	// ���ۿ� �ִ� ���� ���� ó���ϱ�
			cin.clear();	// cin ���� �÷��� �ʱ�ȭ
			cin.ignore(256, '\n');
			continue;		// �ݺ����� ó������ ���ư���
		}
		else
		{
			cout << "�Է��� �̸��� " << name << "�Դϴ�." << endl;
			cout << "�̴�� �����ұ��? (yes/no): ";
			char yesNo[16];
			cin >> yesNo;
			bool isYes = false;

			// yes�� Ȯ�� �Ǵ� ����(yes, YES, Yes, y, Y)
			if (yesNo[0] == 'y' || yesNo[0] == 'Y')	// yes�� �ƴ� ���ڵ��� �ѹ� �Ÿ���
			{
				if (strcmp(yesNo, "yes") == 0
					|| strcmp(yesNo, "y") == 0
					|| strcmp(yesNo, "YES") == 0
					|| strcmp(yesNo, "Yes") == 0
					|| strcmp(yesNo, "Y") == 0)
				{
					pass = true;
				}
			}
		}
	} while (!pass);

	cout << "Ȯ�� �̸� : " << name << endl;
}

void Test::Test_CreatureFactory()
{
	cout << "�׽�Ʈ - Factory" << endl;
	Utils::SetRandomSeedByTime();

	Creature_Base* pOrc = Factory::MakeCreature(OrcType);
	Creature_Base* pWolf = Factory::MakeCreature(WolfType);
	pOrc->PrintStatus();
	pWolf->PrintStatus();

	BattleManager bm;
	bm.SetBattlers(pOrc, pWolf);
	bm.BattleStart();

	Factory::DestroyCreature(pOrc);
	Factory::DestroyCreature(pWolf);
}
