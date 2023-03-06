#pragma once

struct SaveData
{
	// 이름,레벨,스테이터스,hp,maxHP,mp,maxMP,종족,exp,최대exp
	char name[256];
	int level;
	int strength;
	int dexterity;
	int stamina;
	int intelligence;
	int wisdom;
	int hp;
	int maxHP;
	int mp;
	int maxMP;
	int race;
	int exp;
	int maxExp;
};