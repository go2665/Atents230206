#include "Character.h"

void Character::Initialize()
{
	CleanUp();	// ������ �����ϰ� �� �����ϱ�

	srand((unsigned int)time(nullptr));

	pMap = new Map("./Data/SampleMap.txt");
	position = pMap->GetStartPosition();

	StatusReRoll();

	cout << "[" << name << "]�� " << "(" << position.x << "," << position.y << ")�� �ֽ��ϴ�." << endl;
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
	cout << "�Է�] ��(" << Move_East << "), ��(" << Move_West << "), ��(" 
		<< Move_South << "), ��(" << Move_North << ")" << endl;
	cout << "���� �̵��ұ��? : ";
	cin >> input;
	switch ((Input_Move)input)
	{
	case Move_East:
		cout << "�������� �̵��մϴ�." << endl;
		break;
	case Move_West:
		cout << "�������� �̵��մϴ�." << endl;
		break;
	case Move_South:
		cout << "�������� �̵��մϴ�." << endl;
		break;
	case Move_North:
		cout << "�������� �̵��մϴ�." << endl;
		break;
	default:
		cout << "�Է��� �߸��Ǿ����ϴ�." << endl;
		return INPUT_EXIT;		
	}
	return input;
}
