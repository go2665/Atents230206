#include "Buff_Rage.h"
#include "Creature_Base.h"
#include <iostream>

using namespace std;

void Buff_Rage::InstanceEffect(Creature_Base& target)
{
	BuffBase::InstanceEffect(target);

	target.AddStrength(buffStrength);
	cout << "[" << target.GetName() << "]의 힘이 (" << buffStrength << ")만큼 증가합니다." << endl;
}

void Buff_Rage::ContinuousEffect(Creature_Base& target)
{
	BuffBase::ContinuousEffect(target);
	int max = target.GetMaxHP();	
	int damage = (int)(max * tickDamage);
	target.AddHP(-damage);

	cout << "[" << target.GetName() << "]의 HP가 (" << damage << ")만큼 감소합니다." << endl;
}

void Buff_Rage::RemoveEffect(Creature_Base& target)
{
	BuffBase::RemoveEffect(target);
	target.AddStrength(-buffStrength);
	cout << "[" << target.GetName() << "]의 힘이 (" << buffStrength << ")만큼 감소합니다." << endl;
}
