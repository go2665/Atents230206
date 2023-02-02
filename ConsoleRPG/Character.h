#pragma once
#include <iostream>
#include "Map.h"
#include "Status.h"

using namespace std;

class Character
{
protected:
	/// <summary>
	/// �� �÷��̾ �ִ� ��
	/// </summary>
	Map* pMap = nullptr;	

	/// <summary>
	/// �÷��̾��� �������ͽ�
	/// </summary>
	Status status;

	int level = 1;
	int exp = 0;
	int maxExp = 100;		// �������� �ʿ��� ����ġ

	int hp = 1;
	int maxHP = 1;
	int mp = 1;
	int maxMP = 1;

	/// <summary>
	/// ĳ������ �������ͽ��� �ٽ� �����ϴ� �Լ�
	/// </summary>
	void StatusReRoll();


};

