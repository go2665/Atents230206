#pragma once
#include <iostream>
#include "Map.h"
#include "Position.h"
#include "HumanoidBase.h"

using namespace std;

class Character : public HumanoidBase
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

	inline void AddExp(int _exp) { exp += _exp; }

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

	int exp = 0;
	int maxExp = 100;		// �������� �ʿ��� ����ġ

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

