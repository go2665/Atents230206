#include "Monster.h"

void Monster::Initialize()
{
	// �Լ� ������ ��� ����
	// fpSkill_1 = &Monster::Test;	// �Լ� �����Ϳ� �ɹ��Լ� �����ϱ�
	// fpSkill_1(*this);			// �Լ� �����Ϳ� ����� �Լ� �����ϱ�
	
	SetRandomStatus();

}

void Monster::CleanUp()
{
	for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
	{
		delete (*iter);
	}
	fpSkill_1 = nullptr;
	fpSkill_2 = nullptr;
}

void Monster::OnTurnStart()
{
	for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
	{
		(*iter)->Effect(*this);
	}
}

void Monster::OnTurnEnd()
{
	list<BuffBase*> deleteList;
	for (auto iter = buffList.begin(); iter != buffList.end(); iter++)
	{
		int dutation = (*iter)->RemoveEffect(*this);
		if (dutation <= 0)
		{
			deleteList.push_back(*iter);
		}
	}

	for (auto iter = deleteList.begin(); iter != deleteList.end(); iter++)
	{
		buffList.remove(*iter);

		// erase  : iterator�� ����Ű�� ��ġ�� �ִ� �׸��� ����
		// remove : ����Ʈ���� ���� ���� ������ �׸��� ����
		delete (*iter);
	}

	// * : �������� ������
	// & : ������ �ּҰ�
}

