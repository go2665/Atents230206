#include "Monster_Orc.h"
#include "Buff_Rage.h"

void Monster_Orc::Attack(HumanoidBase& target)
{
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
}

int Monster_Orc::Smash()
{
	cout << "스킬 발동 : [스메시]" << endl;
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
	cout << "스킬 발동 : [도끼 던지기]" << endl;
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
	cout << "스킬 발동 : [분노]" << endl;
	Buff_Rage* pBuff = new Buff_Rage();
	AddBuff(pBuff);
}

void Monster_Orc::Initialize()
{
	int index = Utils::GetRandom(0, NamePicker::orcNameCount);
	strcpy_s(name, NamePicker::GetOrcName(index));

	rewardExp = 30;
	rewardHP = 100;
	rewardMP = 50;

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

void Monster_Orc::Die()
{
	if (pBattleTarget != nullptr)
	{
		//Character* bad = (Character*)pBattleTarget;		// 되든 안되든 해본다. 무사히 되는 다행인데 안되면 망한다.		
		//Character* player = dynamic_cast<Character*>(pBattleTarget);	// 캐스팅을 시도해서 되면 null이 아닌 값이 리턴, 안되면 null을 리턴

		if (pBattleTarget->GetType() == Player)
		{
			Character* player = (Character*)pBattleTarget;
			cout << "경험치를 (" << rewardExp << ")만큼 획득합니다.";
			player->AddExp(rewardExp);
		}

		float rate = Utils::GetRandom();
		if (rate < 0.5f)
		{
			cout << "HP 오브를 얻었습니다. HP가 (" << rewardHP << ")만큼 회복됩니다.";
			pBattleTarget->AddHP(rewardHP);
		}
		rate = Utils::GetRandom();
		if (rate < 0.1f)
		{
			cout << "MP 오브를 얻었습니다. MP가 (" << rewardMP << ")만큼 회복됩니다.";
			pBattleTarget->AddMP(rewardMP);
		}		
	}
}


