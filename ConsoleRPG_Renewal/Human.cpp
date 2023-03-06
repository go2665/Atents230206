#include "Human.h"
#include "Utils.h"
#include <iostream>
using namespace std;

void Human::Initialize(SaveData* data)
{
	race = RaceType::HumanType;
	strcpy_s(skill1_Name, "단검 던지기");
	strcpy_s(skill2_Name, "매직 미사일");
	maxExp = (int)(ExpCap * 0.5f);

	Character::Initialize(data);
}

void Human::OnTurnAction()
{
	Attack();
}

void Human::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(10, 21);		// 10~20
	status.dexterity = Utils::GetRandom(10, 21);	// 10~20
	status.intelligence = Utils::GetRandom(10, 21);	// 10~20
	status.stamina = Utils::GetRandom(10, 21);		// 10~20
	status.wisdom = Utils::GetRandom(10, 21);		// 10~20	

	RefreshHPMP();
}

void Human::RefreshHPMP()
{
	maxHP = status.stamina * HP_Multiplier * 5;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier * 5;
	mp = maxMP;
}

void Human::NormalAttack()
{
	cout << "일반 공격" << endl;							// (힘 * 0.9 + 1) ~ (힘 * 1.1 + 1)
	int range = (int)(status.strength * 0.1f) + 1;
	int damage = Utils::GetRandom(status.strength - range, status.strength + range + 1);
	pBattleTarget->Defence(damage);
}

void Human::Skill01()
{
	cout << skill1_Name << endl;
	AddMP(-1);
	int range = (int)(status.dexterity * 0.5f) + 1;		// (힘 - 민첩 * 0.5 + 1) ~ (힘 + 민첩 * 0.5 + 1)
	int damage = Utils::GetRandom(status.strength - range, status.strength + range + 1);
	pBattleTarget->Defence(damage);
}

void Human::Skill02()
{
	cout << skill2_Name << endl;
	AddMP(-10);
	int count = Utils::GetRandom(3, 6);
	cout << count << "개 만큼의 매직 미사일 시전 성공." << endl;
	for (int i = 0; i < count; i++)
	{
		int damage = (int)(status.intelligence * 0.5f);
		pBattleTarget->Defence(damage * 5);
	}
}

void Human::LevelUp()
{
	Character::LevelUp();

	int random = Utils::GetRandom(0, 3);
	status.strength += random;
	cout << "힘이 (" << random << ")만큼 증가합니다." << endl;
	random = Utils::GetRandom(0, 3);
	status.dexterity += random;
	cout << "민첩이 (" << random << ")만큼 증가합니다." << endl;
	random = Utils::GetRandom(0, 3);
	status.intelligence += random;
	cout << "지능이 (" << random << ")만큼 증가합니다." << endl;
	random = Utils::GetRandom(0, 3);
	status.stamina += random;
	cout << "지능이 (" << random << ")만큼 증가합니다." << endl;
	random = Utils::GetRandom(0, 3);
	status.wisdom += random;
	cout << "지혜가 (" << random << ")만큼 증가합니다." << endl;

	RefreshHPMP();
}
