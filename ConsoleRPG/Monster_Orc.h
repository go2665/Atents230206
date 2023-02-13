#pragma once
#include "Monster.h"

class Monster_Orc : public Monster
{
public:
	Monster_Orc()
	{	
		Initialize();
	}
	virtual ~Monster_Orc()
	{
		CleanUp();
	}
	virtual void Attack(HumanoidBase& target) override;

protected:

	int Smash();
	int AxeThrowing();
	void Rage();

	virtual void Initialize() override;

	virtual void SetRandomStatus() override;
};

