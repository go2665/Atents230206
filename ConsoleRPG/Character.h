#pragma once
#include <iostream>
#include "Map.h"
#include "Status.h"
#include "Position.h"

using namespace std;

class Character
{
public:
	Character()
	{
		strcpy_s(name, "�̸�");
	}

	Character(const char* name)
	{
		strcpy_s(this->name, name);
	}

	/// <summary>
	/// �ʱ�ȭ�� �Լ�. new ���Ŀ� ��� �ѹ� ����Ǿ�� �Ѵ�.
	/// </summary>
	void Initialize();	

	/// <summary>
	/// ĳ���Ϳ� ����
	/// </summary>
	void Loop();

	/// <summary>
	/// ������ �Լ�. delete ���� �ݵ�� �ѹ� ����Ǿ�� �Ѵ�.
	/// </summary>
	void CleanUp();

protected:

	/// <summary>
	/// ���� �Է� ó����
	/// </summary>
	const int INPUT_EXIT = -1;

	/// <summary>
	/// �� �÷��̾ �ִ� ��
	/// </summary>
	Map* pMap = nullptr;	

	/// <summary>
	/// �� �÷��̾��� ���� ����(�̵���, ������ ���)
	/// </summary>
	PlayerState state = Move;

	/// <summary>
	/// �÷��̾��� �̸�(�ִ� 32��. �ѱ��� 16��)
	/// </summary>
	char name[32];

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
	/// �÷��̾��� ��ġ
	/// </summary>
	Position position;

	/// <summary>
	/// ĳ������ �������ͽ��� �ٽ� �����ϴ� �Լ�
	/// </summary>
	void StatusReRoll();

	/// <summary>
	/// �÷��̾��� �̵� ó�� �Լ�
	/// </summary>
	int InputProcess_Move();

};

