#pragma once
#include <iostream>
#include "Map.h"
#include "Position.h"
#include "Physical.h"

using namespace std;

class Character : public Physical
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
		

	/// <summary>
	/// position�� Get �Լ�
	/// </summary>
	/// <returns>position�� ���� ��</returns>
	inline const Position& GetPosition() { return position; }

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
		
	int level = 1;
	int exp = 0;
	int maxExp = 100;		// �������� �ʿ��� ����ġ

	int mp = 1;
	int maxMP = 1;

	/// <summary>
	/// �÷��̾��� ��ġ
	/// </summary>
	Position position;

	/// <summary>
	/// position�� Set �Լ�
	/// </summary>
	/// <param name="newPos">position�� ������ �� ��</param>
	void SetPosition(const Position& newPos);


	/// <summary>
	/// ĳ������ �������ͽ��� �ٽ� �����ϴ� �Լ�
	/// </summary>
	void StatusReRoll();

	/// <summary>
	/// �ڽ��� ��ġ�� ����ϴ� �Լ�
	/// </summary>
	void PrintPosition();

	/// <summary>
	/// �÷��̾��� �̵� ó�� �Լ�
	/// </summary>
	int InputProcess_Move();
};

