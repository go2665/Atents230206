#include "BuffBase.h"
#include "HumanoidBase.h"
#include <iostream>
using namespace std;

void BuffBase::ContinuousEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 지속효과가 적용됩니다." << endl;
}		

void BuffBase::InstanceEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 효과가 적용됩니다." << endl;
}		

void BuffBase::RemoveEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]에게 [" << name << "] 버프의 효과가 제거됩니다." << endl;
}

int BuffBase::OnTurnEnd(HumanoidBase& target) 
{
	ContinuousEffect(target);
	duration--;
	return duration;
}
