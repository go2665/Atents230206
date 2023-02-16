#include "BuffBase.h"
#include "Creature_Base.h"
#include <iostream>
using namespace std;

void BuffBase::ContinuousEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 지속효과가 적용됩니다." << endl;
}		

void BuffBase::InstanceEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 효과가 적용됩니다." << endl;
}		

void BuffBase::RemoveEffect(Creature_Base& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 효과가 제거됩니다." << endl;
}

int BuffBase::OnTurnEnd(Creature_Base& target) 
{
	ContinuousEffect(target);
	duration--;
	return duration;
}
