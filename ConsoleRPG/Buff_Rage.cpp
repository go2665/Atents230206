#include "Buff_Rage.h"
#include "HumanoidBase.h"
#include <iostream>

using namespace std;

void Buff_Rage::InstanceEffect(HumanoidBase& target)
{
	BuffBase::InstanceEffect(target);

	target.AddStrength(buffStrength);
	cout << "[" << target.GetName() << "]�� ���� (" << buffStrength << ")��ŭ �����մϴ�." << endl;
}

void Buff_Rage::ContinuousEffect(HumanoidBase& target)
{
	BuffBase::ContinuousEffect(target);
	int max = target.GetMaxHP();	
	int damage = (int)(max * tickDamage);
	target.AddHP(-damage);

	cout << "[" << target.GetName() << "]�� HP�� (" << damage << ")��ŭ �����մϴ�." << endl;
}

void Buff_Rage::RemoveEffect(HumanoidBase& target)
{
	BuffBase::RemoveEffect(target);
	target.AddStrength(-buffStrength);
	cout << "[" << target.GetName() << "]�� ���� (" << buffStrength << ")��ŭ �����մϴ�." << endl;
}
