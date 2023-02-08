#pragma once
#include "Status.h"

class Physical
{
public :
//	Physical() {};
//	~Physical() {};

	/// <summary>
	/// �������� �޴� �Լ�
	/// </summary>
	/// <param name="damage">���� ������ �� ������(������)</param>
	virtual void TakeDamage(int damage);

protected:
	/// <summary>
	/// �������ͽ�
	/// </summary>
	Status status;

	/// <summary>
	/// ���� HP
	/// </summary>
	int hp = 1;

	/// <summary>
	/// �ִ� HP
	/// </summary>
	int maxHP = 1;

	/// <summary>
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus();


};

