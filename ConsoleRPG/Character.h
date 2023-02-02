#pragma once
#include <iostream>
#include "Map.h"
#include "Status.h"

using namespace std;

class Character
{
protected:
	/// <summary>
	/// 이 플레이어가 있는 맵
	/// </summary>
	Map* pMap = nullptr;	

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
	/// 캐릭터의 스테이터스를 다시 설정하는 함수
	/// </summary>
	void StatusReRoll();


};

