#include "Character.h"
#include <iostream>
using namespace std;

void Character::InputNameProcess()
{
	// "�̸��� �Է��ϼ��� : "��� ����� �� �Է� ���� ������ �̸����� �����ϱ�
	// �̸��� �ִ� 10�ڸ� �Ѿ�� �ʾƾ� �Ѵ�.
	// 10�ڰ� �Ѿ�� �ٽ� �Է��� �޴´�.
}

void Character::Initialize()
{
	type = Player;
	InputNameProcess();

	// �� ���� �ʱ�ȭ
}

void Character::CleanUp() 
{
	// �� ���� Ŭ����
}

void Character::Attack() 
{
}

void Character::Defence(int damage) 
{
}

void Character::PrintStatus() 
{
}

void Character::OnTurnStart() 
{
}

void Character::OnTurnAction() 
{
}

void Character::OnTurnEnd() 
{
}

void Character::SetRandomStatus() 
{
}

void Character::Die() 
{
}