#include <iostream>
#include "Creature_Base.h"
using namespace std;


void Creature_Base::Attack(Creature_Base& target)
{
	cout << "[" << this->name << "]는 [" << target.name << "]을 공격한다." << endl;
}

void Creature_Base::TakeDamage(int damage)
{
	cout << "[" << this->name << "]은 (" << damage << ")의 피해를 받았다." << endl;
	AddHP(-damage);
}

void Creature_Base::SetRandomStatus()
{	
	cout << "[" << this->name << "]의 스테이터스를 설정합니다." << endl;
}

void Creature_Base::Die()
{
	cout << "[" << this->name << "]가 죽었습니다." << endl;
	isAlive = false;	// 죽었다고 표시
}

void Creature_Base::PrintStatus()
{
	cout << "\n ┌───────────────────────────────────────────────────┐\n";
	printf(" │ 이름 : %-20s (Lv : %d)              │\n", name, level );
	printf(" │ Health : ( %3d / %3d )     Mana : ( %3d / %3d )   │\n", hp, maxHP, mp, maxMP);
	printf(" │ 힘   : %5d  │", status.strength);
	printf(" │ 민첩 : %5d  │", status.dexterity);
	printf(" │ 지능 : %5d  │\n", status.intelligence);
	printf(" │ 체력 : %5d  │", status.stamina);
	printf(" │ 지혜 : %5d  │                 │\n", status.wisdom);
	cout << " └───────────────────────────────────────────────────┘\n";
}
