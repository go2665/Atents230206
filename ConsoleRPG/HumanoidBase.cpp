#include <iostream>
#include "HumanoidBase.h"
using namespace std;


void HumanoidBase::Attack(HumanoidBase& target)
{
	cout << this->name << "�� " << target.name << "�� �����Ѵ�." << endl;
}

void HumanoidBase::TakeDamage(int damage)
{
	cout << this->name << "�� " << damage << "�� ���ظ� �޾Ҵ�." << endl;
	
}

void HumanoidBase::SetRandomStatus()
{	
}
