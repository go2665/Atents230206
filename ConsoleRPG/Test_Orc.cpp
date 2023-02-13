#include "Test_Orc.h"
#include "Buff_Rage.h"

void Test_Orc::Attack(HumanoidBase& target)
{
	HumanoidBase::Attack(target);

	Rage();	
}

void Test_Orc::UseBuff(HumanoidBase& target)
{
	Monster& targetMonster = (Monster&)target;
	Buff_Rage* pBuff = new Buff_Rage();
	targetMonster.AddBuff(pBuff);
}

void Test_Orc::SetRandomStatus()
{
	status.strength = 10;
	status.dexterity = 10;
	status.intelligence = 10;
	status.stamina = 10;
	status.wisdom = 10;
	maxHP = status.stamina * 10;
	hp = maxHP;
	maxMP = status.wisdom * 10;
	mp = maxMP;
}
