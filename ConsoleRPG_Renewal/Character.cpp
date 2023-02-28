#include "Character.h"
#include "NamePicker.h"
#include "GameManager.h"

#include <iostream>
#include <iomanip>
using namespace std;

void Character::InputNameProcess()
{
	// "이름을 입력하세요 : "라고 출력한 후 입력 받은 내용을 이름으로 설정하기
	// 이름이 최대 10자를 넘어가지 않아야 한다.
	// 10자가 넘어가면 다시 입력을 받는다.
	// 이름이 입력되면 y/n로 확인받기

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
			cin.clear();			// cin 내부 플래그 초기화
			cin.ignore(256, '\n');	// cin 버퍼 비우기
			continue;				// 반복문의 처음으로 돌아가기
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

	cout << "당신의 이름은 " << name << "입니다." << endl;
}

void Character::Initialize()
{
	type = PlayerType;
	InputNameProcess();

	strcpy_s(skill1_Name, "스킬1");
	strcpy_s(skill2_Name, "스킬2");


	StatusReroll();		// 스테이터스 설정
}

void Character::Loop()
{
	int input = INPUT_EXIT;

	do
	{
		switch (state)
		{
		case Move:
			input = InputProcess_Move();
			break;
		default:
			break;
		}

	} while (input != INPUT_EXIT);

}

void Character::CleanUp() 
{
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
				cout << "1~3 중 하나를 입력해 주세요" << endl;
			}

			cout << "어떤 공격을 할까요? (1:[일반공격], 2:[" << skill1_Name << "], 3:[" << skill2_Name << "])" << endl;
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
	cout << "\n ┌───────────────────────────────────────────────────┐\n";
	printf(" │ 이름 : %-20s (종족 : %s, Lv : %d)   │\n", name, raceName, level);
	printf(" │ Health : ( %3d / %3d )     Mana : ( %3d / %3d )   │\n", hp, maxHP, mp, maxMP);
	printf(" │ Experience : ( %3d / %3d )                        │\n", exp, maxExp);
	printf(" │ 힘   : %5d  │", status.strength);
	printf(" │ 민첩 : %5d  │", status.dexterity);
	printf(" │ 지능 : %5d  │\n", status.intelligence);
	printf(" │ 체력 : %5d  │", status.stamina);
	printf(" │ 지혜 : %5d  │                 │\n", status.wisdom);
	cout << " └───────────────────────────────────────────────────┘\n";
	if (buffList.size() > 0)
	{
		cout << "    버프 : ";
		for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
		{
			cout << "[" << (*iter)->GetName() << "] ";
		}
		cout << endl << endl;
	}
}

void Character::StartMap()
{	
	pMap = GameManager::GetInstance()->GetMap();
	Position pos = pMap->GetStartPosition();
	SetPosition(pos);
}

void Character::Die()
{
	if (isAlive)
	{
		Creature_Base::Die();

		// 게임 종료를 위한 처리 추가 필요

		cout << endl << endl << endl << endl << endl << "Game Over" << endl << endl << endl << endl << endl;
	}
}

void Character::NormalAttack()
{
	cout << "일반 공격" << endl;
	int damage = status.strength;
	pBattleTarget->Defence(damage);
}

void Character::Skill01()
{
	cout << "스킬 1번" << endl;
}

void Character::Skill02()
{
	cout << "스킬 2번" << endl;
}

void Character::LevelUp()
{
	level++;
	RecoveryAll();

	cout << endl << endl << "LEVEL UP!" << endl << "당신은 이제 " << level << "레벨 입니다." << endl;
	cout << "HP와 MP가 완전 회복 됩니다." << endl;
}

void Character::PrintPosition()
{
	cout << "[" << name << "]이(가) " << "(" << position.x << "," << position.y << ")에 있습니다." << endl << endl;
}

void Character::SetPosition(const Position& newPos)
{
	TerrainBase* terrainOld = pMap->GetTerrain(position);
	if(terrainOld != nullptr)
		terrainOld->TerrainExit();

	position = newPos;
	PrintPosition();

	TerrainBase* terrainNew = pMap->GetTerrain(position);
	if(terrainNew != nullptr)
		terrainNew->TerrainEnter();
}

int Character::InputProcess_Move()
{
	int input = INPUT_EXIT;
	cout << "입력] 동(" << Move_East << "), 서(" << Move_West << "), 남("
		<< Move_South << "), 북(" << Move_North << ")" << endl;
	cout << "어디로 이동할까요? : ";
	cin >> input;

	Position tempPos = position;
	switch ((Input_Move)input)
	{
	case Move_East:
		cout << "동쪽으로 이동합니다." << endl;
		tempPos += Position(1, 0);
		break;
	case Move_West:
		cout << "서쪽으로 이동합니다." << endl;
		tempPos += Position(-1, 0);
		break;
	case Move_South:
		cout << "남쪽으로 이동합니다." << endl;
		tempPos += Position(0, 1);
		break;
	case Move_North:
		cout << "북쪽으로 이동합니다." << endl;
		tempPos += Position(0, -1);
		break;
	default:
		cout << "입력이 잘못되었습니다." << endl;
		return INPUT_EXIT;
	}

	if (pMap->IsValidPosition(tempPos))
	{
		SetPosition(tempPos);
	}
	else
	{
		cout << "맵 밖입니다. 이동하지 않습니다." << endl;
	}

	return input;
}

void Character::StatusReroll()
{
	bool retry = true;
	
	SetRandomStatus();
	PrintStatus();

	while(retry)
	{
		// 확정할지 물어보기(y면 다음, n면 다시 SetRandomStatus)
		cout << "이 스테이터스로 결정하시겠습니까?(yes/no) : ";
		char temp[32];
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT32_MAX, '\n');
			cout << "입력이 잘못되었습니다. 다시 입력해 주세요." << endl;
			retry = true;
			continue;
		}

		if (temp[0] == 'y' || temp[0] == 'Y')	// yes가 아닌 글자들을 한번 거르기
		{
			if (strcmp(temp, "yes") == 0
				|| strcmp(temp, "y") == 0
				|| strcmp(temp, "YES") == 0
				|| strcmp(temp, "Yes") == 0
				|| strcmp(temp, "Y") == 0)
			{
				retry = false;
				continue;
			}
		}

		SetRandomStatus();
		PrintStatus();
	} 	
}

