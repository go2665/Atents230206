#pragma once
#include "ConsoleRPG.h"
#include "HumanoidBase.h"

class Monster : public HumanoidBase
{
public :
	Monster()
	{
		Initialize();
	}

	virtual ~Monster()
	{
		CleanUp();
	}	

	/// <summary>
	/// target�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">���� ���</param>
	virtual void Attack(HumanoidBase& target);	

protected:
	/// <summary>
	/// �̸�
	/// </summary>
	char name[32];	

	/// <summary>
	/// ����
	/// </summary>
	int level = 1;

	/// <summary>
	/// ���� MP
	/// </summary>
	int mp = 1;

	/// <summary>
	/// �ִ� MP
	/// </summary>
	int maxMP = 1;

	/// <summary>
	/// �ʱ�ȭ�� �Լ�. �����ڿ��� ����ȴ�.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// ������ �Լ�. �Ҹ��ڿ��� ����ȴ�.
	/// </summary>
	virtual void CleanUp();	

	/// <summary>
	/// 1�� ��ų�� �Լ��� ������ �Լ� ������
	/// </summary>
	function<void(Monster&)> fpSkill_1;

	/// <summary>
	/// 2�� ��ų�� �Լ��� ������ �Լ� ������
	/// </summary>
	function<void(Monster&)> fpSkill_2;

	//inline void Test() { cout << "�׽�Ʈ" << level << endl; }
};

//inline void Test123() { cout << "Hello" << endl; }