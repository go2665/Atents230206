#include "Monster_Orc.h"

#include <iostream>
#include "Utils.h"
#include "NamePicker.h"
#include "Buff_Rage.h"
#include "Character.h"

using namespace std;

void Monster_Orc::Initialize()
{
	type = Orc;
	strcpy_s(name, NamePicker::GetName(Orc));

	rewardExp = 30;
	rewardHP = 100;
	rewardMP = 50;

	Monster::Initialize();
}

void Monster_Orc::Attack()
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
		else if (f < 0.8f)	// 30%
		{
			damage = Rage();
		}
		else // 20%
		{
			damage = Smash();
		}
		pBattleTarget->Defence(damage);
	}
}

int Monster_Orc::Rage()
{
	cout << "��ų �ߵ� : [�г�]" << endl;
	Buff_Rage* pBuff = new Buff_Rage();
	AddBuff(*this, pBuff);

	return 0;
}

int Monster_Orc::Smash()
{
	cout << "��ų �ߵ� : [���޽�]" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.8f)
	{
		cout << "���޽� ����!" << endl;
		damage = status.strength * 2;
	}
	else
	{
		cout << "������" << endl;
	}

	return damage;
}

void Monster_Orc::OnTurnAction()
{
	Attack();
}

void Monster_Orc::SetRandomStatus()
{
	Creature_Base::SetRandomStatus();
	status.strength = Utils::GetRandom(15, 26);		// 15 ~ 25
	status.dexterity = Utils::GetRandom(10, 16);	// 10 ~ 15
	status.intelligence = Utils::GetRandom(1, 6);	// 1  ~  5
	status.stamina = Utils::GetRandom(15, 21);		// 15 ~ 20
	status.wisdom = Utils::GetRandom(1, 6);			// 1  ~  5

	maxHP = (int)(status.stamina * HP_Multiplier * 1.2f);
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier;
	mp = maxMP;
}

void Monster_Orc::Die()
{
	if (isAlive)	// ������� ���� �����ϱ�
	{
		Monster::Die();
		if (pBattleTarget != nullptr)	// �׾��� �� �ο�� ����� ������
		{
			cout << endl << "�¸� ���� ------------------------------------------------------" << endl;
			float rate = Utils::GetRandom();
			if (rate < 0.5f)
			{
				cout << "HP ���긦 ������ϴ�. HP�� (" << rewardHP << ")��ŭ ȸ���˴ϴ�." << endl;
				pBattleTarget->AddHP(rewardHP);
			}
			rate = Utils::GetRandom();
			if (rate < 0.1f)
			{
				cout << "MP ���긦 ������ϴ�. MP�� (" << rewardMP << ")��ŭ ȸ���˴ϴ�." << endl;
				pBattleTarget->AddMP(rewardMP);
			}
			if (pBattleTarget->GetType() == Player)
			{
				Character* player = (Character*)pBattleTarget;
				cout << "����ġ�� (" << rewardExp << ")��ŭ ȹ���մϴ�." << endl;
				player->AddExp(rewardExp);
			}

			cout << "----------------------------------------------------------------" << endl << endl;
		}
	}
}