#pragma once
#include "Monster.h"

class Monster_Orc : public Monster
{
public:
	Monster_Orc()
	{	
		Initialize();
	}
	virtual void Attack(HumanoidBase& target) override;

protected:

	int Smash();
	int AxeThrowing();

	virtual void Initialize() override;

	virtual void SetRandomStatus() override;
};

