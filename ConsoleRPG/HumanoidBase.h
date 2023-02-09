#pragma once
#include "Status.h"

class HumanoidBase
{
public :
//	HumanoidBase() {};
//	~HumanoidBase() {};

	/// <summary>
	/// target�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">���� ���</param>
	virtual void Attack(HumanoidBase& target);

	/// <summary>
	/// �������� �޴� �Լ�
	/// </summary>
	/// <param name="damage">���� ������ �� ������(������)</param>
	virtual void TakeDamage(int damage);
	
	/// <summary>
	/// �������ͽ� ����ϴ� �Լ�
	/// </summary>
	virtual void PrintStatus();

protected:
	/// <summary>
	/// �÷��̾��� �̸�(�ִ� 32��. �ѱ��� 16��)
	/// </summary>
	char name[32];

	/// <summary>
	/// ����
	/// </summary>
	int level = 1;	
	
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
	/// ���� MP
	/// </summary>
	int mp = 1;

	/// <summary>
	/// �ִ� MP
	/// </summary>
	int maxMP = 1;

	/// <summary>
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus();

};

