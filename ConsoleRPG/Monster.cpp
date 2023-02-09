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
	fpSkill_1 = nullptr;
	fpSkill_2 = nullptr;
}

