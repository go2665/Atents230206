#include "Character.h"

void Character::Initialize()
{
	CleanUp();	// ������ �����ϰ� �� �����ϱ�

	srand(time(nullptr));

	pMap = new Map("./Data/SampleMap.txt");
	position = pMap->GetStartPosition();
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
