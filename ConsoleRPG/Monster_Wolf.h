#pragma once
#include "Monster.h"

class Monster_Wolf : public Monster
{
public:
	Monster_Wolf()
	{	
		Initialize();
	}
	virtual ~Monster_Wolf()
	{
		CleanUp();
	}
	virtual void Attack(HumanoidBase& target) override;

protected:

	int Rush();
	void Bite(HumanoidBase& target);

	virtual void Initialize() override;

	virtual void SetRandomStatus() override;

	virtual void Die() override;
};

