#include "Elf.h"
#include "Utils.h"
#include <iostream>
using namespace std;

void Elf::Initialize()
{
	Character::Initialize();
	race = RaceType::ElfType;
	strcpy_s(skill1_Name, "저격");
	strcpy_s(skill2_Name, "정령소환");
	maxExp = (int)(ExpCap * 1.1f);
}

void Elf::OnTurnAction()
{
	Attack();
}

void Elf::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(10, 16);		// 10~15
	status.dexterity = Utils::GetRandom(15, 26);	// 15~25
	status.intelligence = Utils::GetRandom(10, 21);	// 10~20
	status.stamina = Utils::GetRandom(10, 19);		// 10~18
	status.wisdom = Utils::GetRandom(10, 23);		// 10~22	

	RefreshHPMP();
}

void Elf::RefreshHPMP()
{
	maxHP = status.stamina * HP_Multiplier * 3;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier * 3;
	mp = maxMP;
}

void Elf::NormalAttack()
{
	cout << "일반 공격" << endl;							// (힘 + 1) ~ (힘 + 민첩 *0.1 + 1)
	int range = (int)(status.dexterity * 0.1f) + 1;
	int damage = Utils::GetRandom(status.strength, status.strength + range + 1);
	pBattleTarget->Defence(damage);
}

void Elf::Skill01()
{
	cout << skill1_Name << endl;
	AddMP(-10);
	int range = (int)(status.dexterity * 0.5f) + 1;		// (민첩) ~ (민첩 * 1.5 + 1)
	int damage = Utils::GetRandom(status.dexterity, status.dexterity + range + 1);
	pBattleTarget->Defence(damage);
}

void Elf::Skill02()
{
	cout << skill2_Name << endl;
	AddMP(-30);
	int range = (int)(status.intelligence * 2.0f) + 1;		// 지능 ~ (지능 * 3 + 1)
	int damage = Utils::GetRandom(status.intelligence, status.intelligence + range + 1);
	pBattleTarget->Defence(damage);
}

void Elf::LevelUp()
{
	Character::LevelUp();

	int random = 0;
	random = Utils::GetRandom(1, 6);
	status.dexterity += random;
	cout << "민첩이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(1, 3);
	status.intelligence += random;
	cout << "지능이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 2);
	status.stamina += random;
	cout << "체력이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 4);
	status.wisdom += random;
	cout << "지혜가 (" << random << ")만큼 증가합니다.";

	RefreshHPMP();
}
