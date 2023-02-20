#include "Character.h"
#include <iostream>
using namespace std;

void Character::InputNameProcess()
{
	// "이름을 입력하세요 : "라고 출력한 후 입력 받은 내용을 이름으로 설정하기
	// 이름이 최대 10자를 넘어가지 않아야 한다.
	// 10자가 넘어가면 다시 입력을 받는다.
}

void Character::Initialize()
{
	type = Player;
	InputNameProcess();

	// 맵 관련 초기화
}

void Character::CleanUp() 
{
	// 맵 관련 클리어
}

void Character::Attack() 
{
}

void Character::Defence(int damage) 
{
}

void Character::PrintStatus() 
{
}

void Character::OnTurnStart() 
{
}

void Character::OnTurnAction() 
{
}

void Character::OnTurnEnd() 
{
}

void Character::SetRandomStatus() 
{
}

void Character::Die() 
{
}