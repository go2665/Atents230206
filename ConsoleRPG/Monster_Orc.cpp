#include "Monster_Orc.h"
#include "Buff_Rage.h"

void Monster_Orc::Attack(HumanoidBase& target)
{
	// 턴 시작
	OnTurnStart();

	HumanoidBase::Attack(target);

	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)	// 50%
	{
		cout << "일반 공격" << endl;
		damage = (int)(status.strength * 1.2f);
	}
	else if (f < 0.8f)	// 30%
	{
		Rage();
	}
	else // 20%
	{
		damage = Smash();
		//damage = AxeThrowing();
	}
	target.TakeDamage(damage);	

	// 턴 종료
	OnTurnEnd();
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

void Monster_Orc::Rage()
{
	cout << "스킬 발동 : 분노!" << endl;
	Buff_Rage* pBuff = new Buff_Rage();
	buffList.push_back(pBuff);
}

void Monster_Orc::Initialize()
{
	int index = Utils::GetRandom(0, NamePicker::orcNameCount);
	strcpy_s(name, NamePicker::GetOrcName(index));
	Monster::Initialize();
}

void Monster_Orc::SetRandomStatus()
{
	HumanoidBase::SetRandomStatus();
	status.strength = Utils::GetRandom(15,26);		// 15 ~ 25
	status.dexterity = Utils::GetRandom(10,16);		// 10 ~ 15
	status.intelligence = Utils::GetRandom(1,6);	// 1  ~  5
	status.stamina = Utils::GetRandom(15,21);		// 15 ~ 20
	status.wisdom = Utils::GetRandom(1,6);			// 1  ~  5

	maxHP = status.stamina * 10;
	hp = maxHP;
	maxMP = status.wisdom * 10;
	mp = maxMP;
}


