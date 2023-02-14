#pragma once
#include "ConsoleRPG.h"

class Monster : public HumanoidBase
{
public :
/*	Monster()
	{
	}

	virtual ~Monster()
	{
	}*/	
	virtual void OnTurnStart();
	virtual void OnTurnEnd();


	void AddBuff(BuffBase* pBuff);

	virtual void PrintStatus() override;

protected:
	

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

	/// <summary>
	/// ���� ���
	/// </summary>
	list<BuffBase*> buffList;
};

//inline void Test123() { cout << "Hello" << endl; }