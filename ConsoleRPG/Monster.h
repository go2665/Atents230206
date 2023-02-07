#pragma once
#include "ConsoleRPG.h"

class Monster
{
public :
	/// <summary>
	/// �ʱ�ȭ�� �Լ�. new ���Ŀ� ��� �ѹ� ����Ǿ�� �Ѵ�.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// ������ �Լ�. delete ���� �ݵ�� �ѹ� ����Ǿ�� �Ѵ�.
	/// </summary>
	virtual void CleanUp();

	virtual void Attack();
	virtual void TakeDamage();

private:
	char name[32];

	Status status;

	int level = 1;

	int hp = 1;
	int maxHP = 1;
	int mp = 1;
	int maxMP = 1;

	virtual void SetStatus();

	function<void()> fpSkill_1;
	function<void()> fpSkill_2;

	inline void Test() { cout << "�׽�Ʈ" << endl; }
};

