#include "Monster_Orc.h"

void Monster_Orc::Attack(Physical& target)
{
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)	// 50%
	{
		cout << "�Ϲ� ����" << endl;
		damage = status.strength * 1.2f;
	}
	else if (f < 0.8f)	// 30%
	{
		damage = Smash();
	}
	else // 20%
	{
		damage = AxeThrowing();
	}

	target.TakeDamage(damage);
}

int Monster_Orc::Smash()
{
	cout << "��ų �ߵ� : ���޽�" << endl;
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

int Monster_Orc::AxeThrowing()
{
	cout << "��ų �ߵ� : ���� ������" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)
	{
		cout << "���� ������ ����!" << endl;
		damage = status.strength * 3;
	}
	else
	{
		cout << "������" << endl;
	}

	return damage;
}


