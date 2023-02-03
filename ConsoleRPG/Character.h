#pragma once
#include <iostream>
#include "Map.h"
#include "Status.h"
#include "Position.h"

using namespace std;

class Character
{
public:
	Character()
	{
		strcpy_s(name, "이름");
	}

	Character(const char* name)
	{
		strcpy_s(this->name, name);
	}

	/// <summary>
	/// 초기화용 함수. new 이후에 즉시 한번 실행되어야 한다.
	/// </summary>
	void Initialize();	

	/// <summary>
	/// 삭제용 함수. delete 전에 반드시 한번 실행되어야 한다.
	/// </summary>
	void CleanUp();

protected:
	/// <summary>
	/// 이 플레이어가 있는 맵
	/// </summary>
	Map* pMap = nullptr;	

	/// <summary>
	/// 플레이어의 이름(최대 32자. 한글은 16자)
	/// </summary>
	char name[32];

	/// <summary>
	/// 플레이어의 스테이터스
	/// </summary>
	Status status;

	int level = 1;
	int exp = 0;
	int maxExp = 100;		// 레벨업에 필요한 경험치

	int hp = 1;
	int maxHP = 1;
	int mp = 1;
	int maxMP = 1;

	/// <summary>
	/// 플레이어의 위치
	/// </summary>
	Position position;

	/// <summary>
	/// 캐릭터의 스테이터스를 다시 설정하는 함수
	/// </summary>
	void StatusReRoll();


};

