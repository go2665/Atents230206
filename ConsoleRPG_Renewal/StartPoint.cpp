#include "StartPoint.h"
#include "Plane.h"
#include "Map.h"
#include "Character.h"
#include "GameManager.h"

void StartPoint::Initialize()
{
	type = StartPointType;
}

void StartPoint::CleanUp()
{
	Plane::CleanUp();
}

void StartPoint::OnEnter()
{
	cout << endl << "시작 지점에 들어왔습니다. " << endl;
	cout << "모든 HP와 MP가 회복됩니다." << endl << endl;
	Character* player = GameManager::GetInstance()->GetPlayer();
	player->RecoveryAll();
}
