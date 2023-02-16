#include "BuffBase.h"
#include "Creature_Base.h"
#include <iostream>
using namespace std;

void BuffBase::ContinuousEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ����ȿ���� ����˴ϴ�." << endl;
}		

void BuffBase::InstanceEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ȿ���� ����˴ϴ�." << endl;
}		

void BuffBase::RemoveEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ȿ���� ���ŵ˴ϴ�." << endl;
}

int BuffBase::OnTurnEnd(Creature_Base& target) 
{
	ContinuousEffect(target);
	duration--;
	return duration;
}
