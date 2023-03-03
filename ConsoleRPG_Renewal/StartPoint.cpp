#include "StartPoint.h"
#include "Plane.h"
#include "Map.h"
#include "Character.h"
#include "GameManager.h"

void StartPoint::Initialize()
{
	type = StartPointType;
	printChar = L'◎';

	strcpy_s(actionListText, "저장하기(3)");
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

void StartPoint::OnAction()
{
	// 파일에 저장하기
	cout << "저장을 시작합니다." << endl;
}
