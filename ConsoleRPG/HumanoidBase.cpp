#include <iostream>
#include "HumanoidBase.h"
using namespace std;


void HumanoidBase::Attack(HumanoidBase& target)
{
	cout << this->name << "는 " << target.name << "을 공격한다." << endl;
}

void HumanoidBase::TakeDamage(int damage)
{
	cout << this->name << "은 " << damage << "의 피해를 받았다." << endl;
	
}

void HumanoidBase::SetRandomStatus()
{	
}
