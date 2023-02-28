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
	cout << endl << "���� ������ ���Խ��ϴ�. " << endl;
	cout << "��� HP�� MP�� ȸ���˴ϴ�." << endl << endl;
	Character* player = GameManager::GetInstance()->GetPlayer();
	player->RecoveryAll();
}
