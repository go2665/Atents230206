#pragma once

// 모든 스텟은 1~20 사이의 범위를 가진다.

struct Status
{
public:
	int strength = 1;		// 전사 주 스텟
	int dexterity = 1;		// 도적 주 스텟
	int intelligence = 1;	// 마법사 주 스텟
	int stamina = 1;		// HP 보너스
	int wisdom = 1;			// MP 보너스
};