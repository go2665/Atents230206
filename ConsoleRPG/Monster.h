#pragma once
#include "ConsoleRPG.h"

class Monster
{
public :
	/// <summary>
	/// 초기화용 함수. new 이후에 즉시 한번 실행되어야 한다.
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 삭제용 함수. delete 전에 반드시 한번 실행되어야 한다.
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

	inline void Test() { cout << "테스트" << endl; }
};

