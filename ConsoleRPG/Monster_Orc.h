#pragma once
#include "Monster.h"

class Monster_Orc : public Monster
{
public:
	Monster_Orc() : Monster()
	{		
	}
	virtual void Attack(Physical& target) override;

protected:

	int Smash();
	int AxeThrowing();
};

