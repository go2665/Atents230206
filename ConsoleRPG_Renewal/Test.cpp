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
	cout << "Test ����" << endl;
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
			cout << endl << "[" << pMonster->GetName() << "]�� ���Ӱ� �����մϴ�." << endl;
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
	cout << "�׽�Ʈ - CreatureFactory" << endl;
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
