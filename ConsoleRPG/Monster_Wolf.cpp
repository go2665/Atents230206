#include "Monster_Wolf.h"
#include "Buff_Bite.h"

void Monster_Wolf::Attack(HumanoidBase& target)
{
	HumanoidBase::Attack(target);

	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.7f)	// 50%
	{
		cout << "일반 공격" << endl;
		damage = (int)(status.strength * 1.2f);
	}
	else if (f < 0.8f)	// 30%
	{
		damage = Rush();
	}
	else // 20%
	{
		Bite(target);
	}

	if (damage > 0)
	{
		target.TakeDamage(damage);
	}
}

int Monster_Wolf::Rush()
{
	cout << "스킬 발동 : [돌진]" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.9f)
	{
		cout << "돌진 명중!" << endl;
		damage = status.strength * 10;
	}
	else
	{
		cout << "빗나감" << endl;
	}

	return damage;
}

void Monster_Wolf::Bite(HumanoidBase& target)
{
	cout << "스킬 발동 : [물기]" << endl;
	Buff_Bite* pBuff = new Buff_Bite();
	Monster& monster = (Monster&)target;
	monster.AddBuff(pBuff);
}

void Monster_Wolf::Initialize()
{
	int index = Utils::GetRandom(0, NamePicker::wolfNameCount);
	strcpy_s(name, NamePicker::GetWolfName(index));
	Monster::Initialize();
}

void Monster_Wolf::SetRandomStatus()
{
	HumanoidBase::SetRandomStatus();
	status.strength = Utils::GetRandom(10,12);		// 10 ~ 11
	status.dexterity = Utils::GetRandom(12,20);		// 12 ~ 19
	status.intelligence = Utils::GetRandom(1,6);	// 1  ~  5
	status.stamina = Utils::GetRandom(15,21);		// 15 ~ 20
	status.wisdom = Utils::GetRandom(1,6);			// 1  ~  5

	maxHP = status.stamina * 10;
	hp = maxHP;
	maxMP = status.wisdom * 10;
	mp = maxMP;
}


