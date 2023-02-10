#include "Monster.h"

void Monster::Initialize()
{
	// 함수 포인터 사용 예시
	// fpSkill_1 = &Monster::Test;	// 함수 포인터에 맴버함수 저장하기
	// fpSkill_1(*this);			// 함수 포인터에 저장된 함수 실행하기
	
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

		// erase  : iterator가 가르키는 위치에 있는 항목을 삭제
		// remove : 리스트에서 같은 값을 가지는 항목을 삭제
		delete (*iter);
	}

	// * : 포인터의 실제값
	// & : 변수의 주소값
}

