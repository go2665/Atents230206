#include "Test.h"
#include "Enums.h"
#include "CreatureFactory.h"
#include "Creature_Base.h"
#include "Monster_Orc.h"
#include "BattleManager.h"
#include "Utils.h"
#include <iomanip>

void Test::Run()
{
	cout << "Test 시작" << endl;
	//Test_CreatureFactory();
	//Test_CharacterNameInput();
	//Test_CharacterAttackSelect();
	Test_HumanBattle();
}

void Test::Test_HumanBattle()
{
	Creature_Base* pPlayer = CreatureFactory::MakeCreature(HumanType);
	Creature_Base* pMonster = CreatureFactory::MakeCreature(Orc);	

	BattleManager bm;
	while ( pPlayer->IsAlive() )
	{
		bm.SetBattlers(pPlayer, pMonster);
		
		pPlayer->PrintStatus();
		pMonster->PrintStatus();

		bm.BattleStart();

		if (!pMonster->IsAlive())
		{
			CreatureFactory::DestroyCreature(pMonster);
			pMonster = CreatureFactory::MakeCreature(Orc);		
			cout << endl << "[" << pMonster->GetName() << "]가 새롭게 등장합니다." << endl;
		}
	}

	CreatureFactory::DestroyCreature(pMonster);
	CreatureFactory::DestroyCreature(pPlayer);
}

void Test::Test_CharacterPrintStatus()
{
	Creature_Base* pPlayer = CreatureFactory::MakeCreature(HumanType);
	pPlayer->PrintStatus();
	CreatureFactory::DestroyCreature(pPlayer);

}

void Test::Test_CharacterAttackSelect()
{
	Creature_Base* pPlayer = CreatureFactory::MakeCreature(Player);
	Creature_Base* pMonster = CreatureFactory::MakeCreature(Orc);
	pPlayer->PrintStatus();
	pMonster->PrintStatus();

	BattleManager bm;
	bm.SetBattlers(pPlayer, pMonster);

	while (pMonster->IsAlive())
	{
		pPlayer->Attack();
	}

	//bm.BattleStart();



	CreatureFactory::DestroyCreature(pMonster);
	CreatureFactory::DestroyCreature(pPlayer);
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
	cout << "테스트 - CreatureFactory" << endl;
	Utils::SetRandomSeedByTime();

	Creature_Base* pOrc = CreatureFactory::MakeCreature(Orc);
	Creature_Base* pWolf = CreatureFactory::MakeCreature(Wolf);
	pOrc->PrintStatus();
	pWolf->PrintStatus();

	BattleManager bm;
	bm.SetBattlers(pOrc, pWolf);
	bm.BattleStart();

	CreatureFactory::DestroyCreature(pOrc);
	CreatureFactory::DestroyCreature(pWolf);
}
