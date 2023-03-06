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
	cout << "Test 시작" << endl;
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
			cout << "읽은 것 " << line++ << " : " << temp << endl;
		}
		ifs.close();
	}
}

void Test::Test_FileWrite()
{
	ofstream ofs;
	ofs.open("./data/_Hello.txt");
	ofs << "Hello Hello Hello Hello Hello, World! 안녕!";
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
	printf("성공률 : %.5f %%\n", (float)count / (float)testNum);
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

	//cout << "100만번 시도" << endl;
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
		cout << "종족을 선택해 주세요(1:인간, 2:엘프, 3:드워프) : ";
		cin >> select;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT32_MAX, '\n');
			select = -1;
			cout << "잘못된 입력입니다." << endl;
		}
		else
		{
			if (select < 1 || select > 3)
			{
				select = -1;
				cout << "잘못된 입력입니다." << endl;
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
			cout << endl << "[" << pMonster->GetName() << "]가 새롭게 등장합니다." << endl;
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
	// "이름을 입력하세요 : "라고 출력한 후 입력 받은 내용을 이름으로 설정하기
	// 이름이 최대 10자를 넘어가지 않아야 한다.
	// 10자가 넘어가면 다시 입력을 받는다.
	// 이름이 입력되면 y/n로 확인받기

	char name[16];
	const int MAX_NAME_SIZE = 10;
	bool pass = false;
	int size = 0;
	do
	{
		cout << "이름을 입력하세요 : ";
		cin >> setw(16) >> name;
		size = (int)strlen(name);

		if (size > MAX_NAME_SIZE)
		{
			cout << "이름의 길이가 너무 깁니다. 다시 입력해주세요. 최대 " << MAX_NAME_SIZE << "자 입니다." << endl;
			//char temp[1024];
			//cin >> temp;	// 버퍼에 있는 남은 글자 처리하기
			cin.clear();	// cin 내부 플래그 초기화
			cin.ignore(256, '\n');
			continue;		// 반복문의 처음으로 돌아가기
		}
		else
		{
			cout << "입력한 이름은 " << name << "입니다." << endl;
			cout << "이대로 결정할까요? (yes/no): ";
			char yesNo[16];
			cin >> yesNo;
			bool isYes = false;

			// yes로 확정 되는 종류(yes, YES, Yes, y, Y)
			if (yesNo[0] == 'y' || yesNo[0] == 'Y')	// yes가 아닌 글자들을 한번 거르기
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

	cout << "확정 이름 : " << name << endl;
}

void Test::Test_CreatureFactory()
{
	cout << "테스트 - Factory" << endl;
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
