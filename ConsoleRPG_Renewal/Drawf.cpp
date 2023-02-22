#include "Drawf.h"
#include "Utils.h"
#include <iostream>
using namespace std;

void Drawf::Initialize()
{
	Character::Initialize();
	race = RaceType::DrawfType;
	strcpy_s(skill1_Name, "발구르기");
	strcpy_s(skill2_Name, "도끼 던지기");
	maxExp = ExpCap;
}

void Drawf::OnTurnAction()
{
	Attack();
}

void Drawf::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(15, 31);		// 15~30
	status.dexterity = Utils::GetRandom(10, 16);	// 10~15
	status.intelligence = Utils::GetRandom(10, 16);	// 10~15
	status.stamina = Utils::GetRandom(15, 31);		// 15~30
	status.wisdom = Utils::GetRandom(10, 21);		// 10~20	

	RefreshHPMP();
}

void Drawf::RefreshHPMP()
{
	maxHP = status.stamina * HP_Multiplier * 7;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier;
	mp = maxMP;
}

void Drawf::NormalAttack()
{
	cout << "일반 공격" << endl;							// (힘 * 0.9 + 1) ~ (힘 * 1.1 + 1)
	int range = (int)(status.strength * 0.1f) + 1;
	int damage = Utils::GetRandom(status.strength - range, status.strength + range + 1);
	pBattleTarget->Defence(damage);
}

void Drawf::Skill01()
{
	cout << skill1_Name << endl;
	AddMP(-10);
	int range = (int)(status.strength * 0.5f) + 1;		// (힘 + 1) ~ (힘 * 1.5 + 1)
	int damage = Utils::GetRandom(status.strength, status.strength + range + 1);
	pBattleTarget->Defence(damage);
}

void Drawf::Skill02()
{
	cout << skill2_Name << endl;
	AddMP(-10);
	if (Utils::GetRandom() < 0.5f)
	{
		int range1 = (int)(status.strength * 2.0f);		// (힘 * 2) ~ (힘 * 5)
		int range2 = (int)(status.strength * 5.0f);
		int damage = Utils::GetRandom(status.strength + range1, status.strength + range2 + 1);
		pBattleTarget->Defence(damage);
	}
	else
	{
		cout << "빗나감!" << endl;
	}
}

void Drawf::LevelUp()
{
	Character::LevelUp();

	int random = Utils::GetRandom(0, 3);
	status.strength += random;
	cout << "힘이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 3);
	status.dexterity += random;
	cout << "민첩이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 3);
	status.intelligence += random;
	cout << "지능이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 3);
	status.stamina += random;
	cout << "지능이 (" << random << ")만큼 증가합니다.";
	random = Utils::GetRandom(0, 3);
	status.wisdom += random;
	cout << "지혜가 (" << random << ")만큼 증가합니다.";

	RefreshHPMP();
}
