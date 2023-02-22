#include "Character.h"
#include "NamePicker.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Character::InputNameProcess()
{
	// "�̸��� �Է��ϼ��� : "��� ����� �� �Է� ���� ������ �̸����� �����ϱ�
	// �̸��� �ִ� 10�ڸ� �Ѿ�� �ʾƾ� �Ѵ�.
	// 10�ڰ� �Ѿ�� �ٽ� �Է��� �޴´�.
	// �̸��� �ԷµǸ� y/n�� Ȯ�ιޱ�

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
			cin.clear();			// cin ���� �÷��� �ʱ�ȭ
			cin.ignore(256, '\n');	// cin ���� ����
			continue;				// �ݺ����� ó������ ���ư���
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

	cout << "����� �̸��� " << name << "�Դϴ�." << endl;
}

void Character::Initialize()
{
	type = Player;
	InputNameProcess();

	strcpy_s(skill1_Name, "��ų1");
	strcpy_s(skill2_Name, "��ų2");

	SetRandomStatus();

	// �� ���� �ʱ�ȭ
}

void Character::CleanUp() 
{
	// �� ���� Ŭ����
	Creature_Base::CleanUp();
}

void Character::Attack() 
{
	if (isBattle)
	{
		int select = INT32_MIN;
		while (select < 1 || select > 3)
		{
			if (select != INT32_MIN)
			{
				cout << "1~3 �� �ϳ��� �Է��� �ּ���" << endl;
			}

			cout << "� ������ �ұ��? (1:[�Ϲݰ���], 2:[" << skill1_Name << "], 3:[" << skill2_Name << "])" << endl;
			cin >> select;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				select = -1;
			}
		} 

		Creature_Base::Attack();

		switch (select)
		{
		case 1:
			NormalAttack();
			break;
		case 2:
			Skill01();
			break;
		case 3:
			Skill02();
			break;
		default:
			break;
		}
	}
}

void Character::PrintStatus()
{
	const char* raceName = NamePicker::GetRaceName(race);
	cout << "\n ����������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (���� : %s, Lv : %d)   ��\n", name, raceName, level);
	printf(" �� Health : ( %3d / %3d )     Mana : ( %3d / %3d )   ��\n", hp, maxHP, mp, maxMP);
	printf(" �� Experience : ( %3d / %3d )                        ��\n", exp, maxExp);
	printf(" �� ��   : %5d  ��", status.strength);
	printf(" �� ��ø : %5d  ��", status.dexterity);
	printf(" �� ���� : %5d  ��\n", status.intelligence);
	printf(" �� ü�� : %5d  ��", status.stamina);
	printf(" �� ���� : %5d  ��                 ��\n", status.wisdom);
	cout << " ����������������������������������������������������������������������������������������������������������\n";
	if (buffList.size() > 0)
	{
		cout << "    ���� : ";
		for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
		{
			cout << "[" << (*iter)->GetName() << "] ";
		}
		cout << endl << endl;
	}
}

void Character::Die()
{
	if (isAlive)
	{
		Creature_Base::Die();

		// ���� ���Ḧ ���� ó�� �߰� �ʿ�

		cout << endl << endl << endl << endl << endl << "Game Over" << endl << endl << endl << endl << endl;
	}
}

void Character::NormalAttack()
{
	cout << "�Ϲ� ����" << endl;
	int damage = status.strength;
	pBattleTarget->Defence(damage);
}

void Character::Skill01()
{
	cout << "��ų 1��" << endl;
}

void Character::Skill02()
{
	cout << "��ų 2��" << endl;
}

void Character::LevelUp()
{
	level++;
	hp = maxHP;
	mp = maxMP;

	cout << endl << endl << "LEVEL UP!" << endl << "����� ���� " << level << "���� �Դϴ�." << endl;
	cout << "HP�� MP�� ���� ȸ�� �˴ϴ�." << endl;
}
