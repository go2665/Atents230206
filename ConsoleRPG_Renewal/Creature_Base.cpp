#include <iostream>
#include "Creature_Base.h"
using namespace std;


void Creature_Base::Initialize()
{
	SetRandomStatus();
}

void Creature_Base::CleanUp()
{
	for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
	{
		delete (*iter);
	}
	buffList.clear();
}

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
		cout << "[" << this->name << "]�� [" << pBattleTarget->name << "]�� �����Ѵ�." << endl;
	}
}

void Creature_Base::Defence(int damage)
{
	if (isBattle)
	{
		// ��� ���� �� �κ�----------------
		// �� ũ���� ���� ���� ����
		// ------------------------------------

		if (damage > 0)
		{
			cout << "[" << this->name << "]�� (" << damage << ")�� ���ظ� �޾Ҵ�." << endl;
			AddHP(-damage);
		}
	}
}

void Creature_Base::PrintStatus()
{
	cout << "\n ����������������������������������������������������������������������������������������������������������\n";
	printf(" �� �̸� : %-20s (Lv : %d)              ��\n", name, level);
	printf(" �� Health : ( %3d / %3d )     Mana : ( %3d / %3d )   ��\n", hp, maxHP, mp, maxMP);
	printf(" �� ��   : %5d  ��", status.strength);
	printf(" �� ��ø : %5d  ��", status.dexterity);
	printf(" �� ���� : %5d  ��\n", status.intelligence);
	printf(" �� ü�� : %5d  ��", status.stamina);
	printf(" �� ���� : %5d  ��                 ��\n", status.wisdom);
	cout << " ����������������������������������������������������������������������������������������������������������\n";
	if (buffList.size() > 0)
	{
		cout << "    ���� : ";
		for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
		{
			cout << "[" << (*iter)->GetName() << "] ";
		}
		cout << endl << endl;
	}
}

void Creature_Base::OnBattleStart(Creature_Base* pTarget)
{
	if (!isBattle)
	{
		isBattle = true;
		pBattleTarget = pTarget;
	}
}

void Creature_Base::OnBattleEnd()
{
	pBattleTarget = nullptr;
	isBattle = false;
}

void Creature_Base::AddBuff(Creature_Base& target, BuffBase* pBuff)
{
	cout << "[" << this->name << "]�� [" << target.GetName() << "]���� [" << pBuff->GetName() << "] ������ �̴ϴ�." << endl;
	pBuff->InstanceEffect(target);
	target.buffList.push_back(pBuff);
}

void Creature_Base::OnTurnEnd()
{
	list<BuffBase*> deleteList;
	for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
	{
		int dutation = (*iter)->OnTurnEnd(*this);
		if (dutation <= 0)
		{
			deleteList.push_back(*iter);
		}
	}

	for (auto iter = deleteList.begin(); iter != deleteList.end(); iter++)
	{
		(*iter)->RemoveEffect(*this);
		buffList.remove(*iter);

		delete (*iter);
	}
}

void Creature_Base::SetRandomStatus()
{	
	cout << "[" << this->name << "]�� �������ͽ��� �����մϴ�." << endl;
	
	status.strength = 5;
	status.dexterity = 5;
	status.intelligence = 5;
	status.stamina = 5;
	status.wisdom = 5;

	RefreshHPMP();
}

void Creature_Base::RefreshHPMP()
{
	maxHP = status.stamina * HP_Multiplier;
	hp = maxHP;
	maxMP = status.wisdom * MP_Multiplier;
	mp = maxMP;
}

void Creature_Base::Die()
{
	if (isAlive)
	{
		cout << "[" << this->name << "]�� �׾����ϴ�." << endl;
		isAlive = false;	// �׾��ٰ� ǥ��
	}
}

