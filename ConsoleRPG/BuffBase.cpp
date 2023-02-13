#include "BuffBase.h"
#include "HumanoidBase.h"
#include <iostream>
using namespace std;

void BuffBase::ContinuousEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ����ȿ���� ����˴ϴ�." << endl;
}		

void BuffBase::InstanceEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ȿ���� ����˴ϴ�." << endl;
}		

void BuffBase::RemoveEffect(HumanoidBase& target)
{
	cout << "[" << target.GetName() << "]���� [" << name << "] ������ ȿ���� ���ŵ˴ϴ�." << endl;
}

int BuffBase::OnTurnEnd(HumanoidBase& target) 
{
	ContinuousEffect(target);
	duration--;
	return duration;
}
