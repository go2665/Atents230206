#include "Character.h"

void Character::Initialize()
{
	CleanUp();	// 완전히 정리하고 새 시작하기

	srand((unsigned int)time(nullptr));

	pMap = new Map("./Data/SampleMap.txt");
	position = pMap->GetStartPosition();

	StatusReRoll();

	cout << "[" << name << "]이 " << "(" << position.x << "," << position.y << ")에 있습니다." << endl;
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
	if (pMap != nullptr)
		delete pMap;
	pMap = nullptr;
}

void Character::StatusReRoll()
{
	status.strength = rand() % 20 + 1;	//1~20
	status.dexterity = rand() % 20 + 1;
	status.intelligence = rand() % 20 + 1;
	status.stamina = rand() % 20 + 1;
	status.wisdom = rand() % 20 + 1;
}

int Character::InputProcess_Move()
{
	int input = INPUT_EXIT;
	cout << "입력] 동(" << Move_East << "), 서(" << Move_West << "), 남(" 
		<< Move_South << "), 북(" << Move_North << ")" << endl;
	cout << "어디로 이동할까요? : ";
	cin >> input;
	switch ((Input_Move)input)
	{
	case Move_East:
		cout << "동쪽으로 이동합니다." << endl;
		break;
	case Move_West:
		cout << "서쪽으로 이동합니다." << endl;
		break;
	case Move_South:
		cout << "남쪽으로 이동합니다." << endl;
		break;
	case Move_North:
		cout << "북쪽으로 이동합니다." << endl;
		break;
	default:
		cout << "입력이 잘못되었습니다." << endl;
		return INPUT_EXIT;		
	}
	return input;
}
