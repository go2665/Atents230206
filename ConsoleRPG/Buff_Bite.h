#pragma once
#include <iostream>
#include "BuffBase.h"

class Buff_Bite : public BuffBase
{
public:
	Buff_Bite()
	{		
		strcpy_s(name, "¹°±â");
		duration = 5;
	}

	int buffDex = -5;
	int damage = 10;
	float tickDamage = 0.2f;

	virtual void InstanceEffect(HumanoidBase& target) override;
	virtual void RemoveEffect(HumanoidBase& target) override;

private:
	virtual void ContinuousEffect(HumanoidBase& target) override;

};

