#include "Buff_Bite.h"
#include "HumanoidBase.h"
#include <iostream>

using namespace std;

void Buff_Bite::InstanceEffect(HumanoidBase& target)
{
	BuffBase::InstanceEffect(target);

	target.AddDexterity(buffDex);
	cout << "[" << target.GetName() << "]의 민첩이 (" << -buffDex << ")만큼 감소합니다." << endl;
	target.TakeDamage(damage);
}

void Buff_Bite::ContinuousEffect(HumanoidBase& target)
{
	BuffBase::ContinuousEffect(target);
	int max = target.GetMaxHP();	
	int damage = (int)(max * tickDamage);
	target.AddHP(-damage);

	cout << "[" << target.GetName() << "]의 HP가 (" << damage << ")만큼 감소합니다." << endl;
}

void Buff_Bite::RemoveEffect(HumanoidBase& target)
{
	BuffBase::RemoveEffect(target);
	target.AddDexterity(-buffDex);
	cout << "[" << target.GetName() << "]의 민첩이 (" << -buffDex << ")만큼 회복합니다." << endl;
}
