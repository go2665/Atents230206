#pragma once
#include "BuffBase.h"

class Buff_Rage : public BuffBase
{
public:
	Buff_Rage()
	{		
		duration = 2;
	}

	int strength = 5;
	float damage = 0.01f;

	virtual void Effect(HumanoidBase& target) override;
	virtual int RemoveEffect(HumanoidBase& target) override;
};

