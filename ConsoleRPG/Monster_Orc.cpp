#include "Monster_Orc.h"

void Monster_Orc::Attack(Physical& target)
{
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)	// 50%
	{
		cout << "일반 공격" << endl;
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
	cout << "스킬 발동 : 스메시" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.8f)
	{
		cout << "스메시 명중!" << endl;
		damage = status.strength * 2;
	}
	else
	{
		cout << "빗나감" << endl;
	}

	return damage;
}

int Monster_Orc::AxeThrowing()
{
	cout << "스킬 발동 : 도끼 던지기" << endl;
	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)
	{
		cout << "도끼 던지기 명중!" << endl;
		damage = status.strength * 3;
	}
	else
	{
		cout << "빗나감" << endl;
	}

	return damage;
}


