#include "Monster.h"

void Monster::Initialize()
{
	// �Լ� ������ ��� ����
	// fpSkill_1 = &Monster::Test;	// �Լ� �����Ϳ� �ɹ��Լ� �����ϱ�
	// fpSkill_1(*this);			// �Լ� �����Ϳ� ����� �Լ� �����ϱ�

}

void Monster::CleanUp()
{
	fpSkill_1 = nullptr;
	fpSkill_2 = nullptr;
}

void Monster::Attack(HumanoidBase& target)
{
	int damage = 1;
	target.TakeDamage(damage);
}

