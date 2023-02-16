#include <iostream>
#include "Creature_Base.h"
using namespace std;


void Creature_Base::Loop()
{
	OnTurnStart();
	OnTurnAction();
	OnTurnEnd();
}

void Creature_Base::Attack()
{
	if (isBattle)
	{
		cout << "[" << this->name << "]는 [" << pBattleTarget->name << "]을 공격한다." << endl;
	}
}

void Creature_Base::Defence(int damage)
{
	if (isBattle)
	{
		cout << "[" << this->name << "]은 (" << damage << ")의 피해를 받았다." << endl;
		AddHP(-damage);
	}
}

void Creature_Base::PrintStatus()
{
	cout << "\n ┌───────────────────────────────────────────────────┐\n";
	printf(" │ 이름 : %-20s (Lv : %d)              │\n", name, level);
	printf(" │ Health : ( %3d / %3d )     Mana : ( %3d / %3d )   │\n", hp, maxHP, mp, maxMP);
	printf(" │ 힘   : %5d  │", status.strength);
	printf(" │ 민첩 : %5d  │", status.dexterity);
	printf(" │ 지능 : %5d  │\n", status.intelligence);
	printf(" │ 체력 : %5d  │", status.stamina);
	printf(" │ 지혜 : %5d  │                 │\n", status.wisdom);
	cout << " └───────────────────────────────────────────────────┘\n";
}

void Creature_Base::OnBattleStart(Creature_Base* pTarget)
{
	if (!isBattle)
	{
		isBattle = true;
	}
}

void Creature_Base::OnBattleEnd()
{
	isBattle = false;
}

void Creature_Base::AddBuff(Creature_Base& target, BuffBase* pBuff)
{
	// 누가 누구에게 버프를 걸었음.
	buffList.push_back(pBuff);
}


void Creature_Base::SetRandomStatus()
{	
	cout << "[" << this->name << "]의 스테이터스를 설정합니다." << endl;
	// 기본 스텟 주기
}

void Creature_Base::Die()
{
	if (isAlive)
	{
		cout << "[" << this->name << "]가 죽었습니다." << endl;
		isAlive = false;	// 죽었다고 표시
	}
}

