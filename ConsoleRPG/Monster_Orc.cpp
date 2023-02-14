#include "Monster_Orc.h"
#include "Buff_Rage.h"

void Monster_Orc::Attack(HumanoidBase& target)
{
	HumanoidBase::Attack(target);

	float f = Utils::GetRandom();
	int damage = 0;
	if (f < 0.5f)	// 50%
	{
		cout << "�Ϲ� ����" << endl;
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

int Monster_Orc::AxeThrowing()
{
	cout << "��ų �ߵ� : [���� ������]" << endl;
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

void Monster_Orc::Rage()
{
	cout << "��ų �ߵ� : [�г�]" << endl;
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
		//Character* bad = (Character*)pBattleTarget;		// �ǵ� �ȵǵ� �غ���. ������ �Ǵ� �����ε� �ȵǸ� ���Ѵ�.		
		//Character* player = dynamic_cast<Character*>(pBattleTarget);	// ĳ������ �õ��ؼ� �Ǹ� null�� �ƴ� ���� ����, �ȵǸ� null�� ����

		if (pBattleTarget->GetType() == Player)
		{
			Character* player = (Character*)pBattleTarget;
			cout << "����ġ�� (" << rewardExp << ")��ŭ ȹ���մϴ�.";
			player->AddExp(rewardExp);
		}

		float rate = Utils::GetRandom();
		if (rate < 0.5f)
		{
			cout << "HP ���긦 ������ϴ�. HP�� (" << rewardHP << ")��ŭ ȸ���˴ϴ�.";
			pBattleTarget->AddHP(rewardHP);
		}
		rate = Utils::GetRandom();
		if (rate < 0.1f)
		{
			cout << "MP ���긦 ������ϴ�. MP�� (" << rewardMP << ")��ŭ ȸ���˴ϴ�.";
			pBattleTarget->AddMP(rewardMP);
		}		
	}
}


