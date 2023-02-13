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
	cout << this->name << "�� �������ͽ��� �����մϴ�." << endl;
}

void HumanoidBase::PrintStatus()
{
	cout << "\n ����������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (Lv : %d)              ��\n", name, level );
	printf(" �� Health : ( %3d / %3d )     Mana : ( %3d / %3d )   ��\n", hp, maxHP, mp, maxMP);
	printf(" �� ��   : %5d  ��", status.strength);
	printf(" �� ��ø : %5d  ��", status.dexterity);
	printf(" �� ���� : %5d  ��\n", status.intelligence);
	printf(" �� ü�� : %5d  ��", status.stamina);
	printf(" �� ���� : %5d  ��                 ��\n", status.wisdom);
	cout << " ����������������������������������������������������������������������������������������������������������\n\n";
}
