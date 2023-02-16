#include <iostream>
#include "Creature_Base.h"
using namespace std;


void Creature_Base::Attack(Creature_Base& target)
{
	cout << "[" << this->name << "]�� [" << target.name << "]�� �����Ѵ�." << endl;
}

void Creature_Base::TakeDamage(int damage)
{
	cout << "[" << this->name << "]�� (" << damage << ")�� ���ظ� �޾Ҵ�." << endl;
	AddHP(-damage);
}

void Creature_Base::SetRandomStatus()
{	
	cout << "[" << this->name << "]�� �������ͽ��� �����մϴ�." << endl;
}

void Creature_Base::Die()
{
	cout << "[" << this->name << "]�� �׾����ϴ�." << endl;
	isAlive = false;	// �׾��ٰ� ǥ��
}

void Creature_Base::PrintStatus()
{
	cout << "\n ����������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (Lv : %d)              ��\n", name, level );
	printf(" �� Health : ( %3d / %3d )     Mana : ( %3d / %3d )   ��\n", hp, maxHP, mp, maxMP);
	printf(" �� ��   : %5d  ��", status.strength);
	printf(" �� ��ø : %5d  ��", status.dexterity);
	printf(" �� ���� : %5d  ��\n", status.intelligence);
	printf(" �� ü�� : %5d  ��", status.stamina);
	printf(" �� ���� : %5d  ��                 ��\n", status.wisdom);
	cout << " ����������������������������������������������������������������������������������������������������������\n";
}
