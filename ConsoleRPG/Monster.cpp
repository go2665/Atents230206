#include "Monster.h"

void Monster::Initialize()
{
	// �Լ� ������ ��� ����
	// fpSkill_1 = &Monster::Test;	// �Լ� �����Ϳ� �ɹ��Լ� �����ϱ�
	// fpSkill_1(*this);			// �Լ� �����Ϳ� ����� �Լ� �����ϱ�
	int i = 0;

}

void Monster::CleanUp()
{
	fpSkill_1 = nullptr;
	fpSkill_2 = nullptr;
}

