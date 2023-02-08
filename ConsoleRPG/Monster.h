#pragma once
#include "ConsoleRPG.h"
#include "Physical.h"

class Monster : public Physical
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
	/// target을 공격하는 함수
	/// </summary>
	/// <param name="target">공격 대상</param>
	virtual void Attack(Physical& target);	

private:
	/// <summary>
	/// 이름
	/// </summary>
	char name[32];	

	/// <summary>
	/// 레벨
	/// </summary>
	int level = 1;

	/// <summary>
	/// 현재 MP
	/// </summary>
	int mp = 1;

	/// <summary>
	/// 최대 MP
	/// </summary>
	int maxMP = 1;

	/// <summary>
	/// 초기화용 함수. 생성자에서 실행된다.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 삭제용 함수. 소멸자에서 실행된다.
	/// </summary>
	virtual void CleanUp();	

	/// <summary>
	/// 1번 스킬용 함수를 저장할 함수 포인터
	/// </summary>
	function<void(Monster&)> fpSkill_1;

	/// <summary>
	/// 2번 스킬용 함수를 저장할 함수 포인터
	/// </summary>
	function<void(Monster&)> fpSkill_2;

	//inline void Test() { cout << "테스트" << level << endl; }
};

//inline void Test123() { cout << "Hello" << endl; }