#pragma once
#include "ConsoleRPG.h"

class Monster : public Creature_Base
{
public :
/*	Monster()
	{
	}

	virtual ~Monster()
	{
	}*/	
	virtual void OnTurnStart() override;
	virtual void OnTurnEnd() override;


	void AddBuff(BuffBase* pBuff);

	virtual void PrintStatus() override;

protected:
	int rewardHP = 0;
	int rewardMP = 0;
	int rewardExp = 0;

	/// <summary>
	/// 초기화용 함수. 생성자에서 실행된다.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 삭제용 함수. 소멸자에서 실행된다.
	/// </summary>
	virtual void CleanUp();	

	virtual void Die() override;

	/// <summary>
	/// 1번 스킬용 함수를 저장할 함수 포인터
	/// </summary>
	function<void(Monster&)> fpSkill_1;

	/// <summary>
	/// 2번 스킬용 함수를 저장할 함수 포인터
	/// </summary>
	function<void(Monster&)> fpSkill_2;

	//inline void Test() { cout << "테스트" << level << endl; }

	/// <summary>
	/// 버프 목록
	/// </summary>
	list<BuffBase*> buffList;

};

//inline void Test123() { cout << "Hello" << endl; }