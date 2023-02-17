#include "Monster_Wolf.h"

#include <iostream>
#include "Utils.h"
#include "NamePicker.h"
#include "Buff_Bite.h"
#include "Character.h"

using namespace std;

void Monster_Wolf::Initialize()
{
	Monster::Initialize();

	strcpy_s(name, NamePicker::GetName(Wolf));

	rewardExp = 30;
	rewardHP = 100;
	rewardMP = 50;
}

void Monster_Wolf::Attack()
{
	if (isBattle)
	{
		Creature_Base::Attack();

		float f = Utils::GetRandom();
		int damage = 0;
		if (f < 0.5f)	// 50%
		{
			cout << "일반 공격" << endl;
			damage = (int)(status.strength * 1.2f);
		}
		else if (f < 0.9f)	// 40%
		{
			damage = Rush();
		}
		else // 10%
		{
			damage = Bite();
		}
		pBattleTarget->Defence(damage);
	}
}

int Monster_Wolf::Bite()
{
	cout << "스킬 발동 : [물기]" << endl;
	Buff_Bite* pBuff = new Buff_Bite();	
	AddBuff(*pBattleTarget, pBuff);
	return 0;
}

int Monster_Wolf::Rush()
{
	cout << "스킬 발동 : [돌진]" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.3f)
	{
		cout << "돌진 명중!" << endl;
		damage = status.strength * 5;
	}
	else
	{
		cout << "빗나감" << endl;
	}

	return damage;
}

void Monster_Wolf::OnTurnAction()
{
	Attack();
}

void Monster_Wolf::OnTurnEnd()
{
	PrintStatus();
}

void Monster_Wolf::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(10, 12);		// 10 ~ 11
	status.dexterity = Utils::GetRandom(12, 20);	// 12 ~ 19
	status.intelligence = Utils::GetRandom(1, 6);	// 1  ~  5
	status.stamina = Utils::GetRandom(5, 11);		// 5 ~ 10
	status.wisdom = Utils::GetRandom(1, 6);			// 1  ~  5

	maxHP = status.stamina * HP_Multiplier;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier;
	mp = maxMP;
}

void Monster_Wolf::Die()
{
	if (isAlive)	// 살아있을 때만 실행하기
	{
		Monster::Die();
		if (pBattleTarget != nullptr)	// 죽었을 때 싸우던 대상이 있으면
		{
			if (pBattleTarget->GetType() == Player)
			{
				Character* player = (Character*)pBattleTarget;
				cout << "경험치를 (" << rewardExp << ")만큼 획득합니다." << endl;
				player->AddExp(rewardExp);
			}

			float rate = Utils::GetRandom();
			if (rate < 0.75f)
			{
				cout << "HP 오브를 얻었습니다. HP가 (" << rewardHP << ")만큼 회복됩니다." << endl;
				pBattleTarget->AddHP(rewardHP);
			}
		}
	}
}
