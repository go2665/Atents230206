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
			cout << "�Ϲ� ����" << endl;
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
	cout << "��ų �ߵ� : [����]" << endl;
	Buff_Bite* pBuff = new Buff_Bite();	
	AddBuff(*pBattleTarget, pBuff);
	return 0;
}

int Monster_Wolf::Rush()
{
	cout << "��ų �ߵ� : [����]" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.3f)
	{
		cout << "���� ����!" << endl;
		damage = status.strength * 5;
	}
	else
	{
		cout << "������" << endl;
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
	if (isAlive)	// ������� ���� �����ϱ�
	{
		Monster::Die();
		if (pBattleTarget != nullptr)	// �׾��� �� �ο�� ����� ������
		{
			if (pBattleTarget->GetType() == Player)
			{
				Character* player = (Character*)pBattleTarget;
				cout << "����ġ�� (" << rewardExp << ")��ŭ ȹ���մϴ�." << endl;
				player->AddExp(rewardExp);
			}

			float rate = Utils::GetRandom();
			if (rate < 0.75f)
			{
				cout << "HP ���긦 ������ϴ�. HP�� (" << rewardHP << ")��ŭ ȸ���˴ϴ�." << endl;
				pBattleTarget->AddHP(rewardHP);
			}
		}
	}
}
