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
	cout << this->name << "의 스테이터스를 설정합니다." << endl;
}

void HumanoidBase::PrintStatus()
{
	cout << "\n ┌───────────────────────────────────────────────────┐\n";
	printf(" │ 이름 : %-20s (Lv : %d)              │\n", name, level );
	printf(" │ Health : ( %3d / %3d )     Mana : ( %3d / %3d )   │\n", hp, maxHP, mp, maxMP);
	printf(" │ 힘   : %5d  │", status.strength);
	printf(" │ 민첩 : %5d  │", status.dexterity);
	printf(" │ 지능 : %5d  │\n", status.intelligence);
	printf(" │ 체력 : %5d  │", status.stamina);
	printf(" │ 지혜 : %5d  │                 │\n", status.wisdom);
	cout << " └───────────────────────────────────────────────────┘\n\n";
}
