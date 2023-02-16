#include "Buff_Bite.h"
#include "Creature_Base.h"
#include <iostream>

using namespace std;

void Buff_Bite::InstanceEffect(Creature_Base& target)
{
	BuffBase::InstanceEffect(target);

	target.AddDexterity(buffDex);
	cout << "[" << target.GetName() << "]�� ��ø�� (" << -buffDex << ")��ŭ �����մϴ�." << endl;
	target.TakeDamage(damage);
}

void Buff_Bite::ContinuousEffect(Creature_Base& target)
{
	BuffBase::ContinuousEffect(target);
	int max = target.GetMaxHP();	
	int damage = (int)(max * tickDamage);
	target.AddHP(-damage);

	cout << "[" << target.GetName() << "]�� HP�� (" << damage << ")��ŭ �����մϴ�." << endl;
}

void Buff_Bite::RemoveEffect(Creature_Base& target)
{
	BuffBase::RemoveEffect(target);
	target.AddDexterity(-buffDex);
	cout << "[" << target.GetName() << "]�� ��ø�� (" << -buffDex << ")��ŭ ȸ���մϴ�." << endl;
}
