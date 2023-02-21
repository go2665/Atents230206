#include "Human.h"
#include "Utils.h"
#include <iostream>
using namespace std;

void Human::Initialize()
{
	Character::Initialize();
	race = RaceType::HumanType;
}

void Human::OnTurnStart()
{
}

void Human::OnTurnAction()
{
}

void Human::OnTurnEnd()
{
}

void Human::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(10, 21);		// 10~20
	status.dexterity = Utils::GetRandom(10, 21);	// 10~20
	status.intelligence = Utils::GetRandom(10, 21);	// 10~20
	status.stamina = Utils::GetRandom(10, 21);		// 10~20
	status.wisdom = Utils::GetRandom(10, 21);		// 10~20

	maxHP = status.stamina * HP_Multiplier;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier;
	mp = maxMP;
}

void Human::NormalAttack()
{
}

void Human::Skill01()
{
}

void Human::Skill02()
{
}
