#pragma once
#include <iostream>
#include "BuffBase.h"

class Buff_Rage : public BuffBase
{
public:
	Buff_Rage()
	{		
		strcpy_s(name, "�г�");
		duration = 3;
	}

	int buffStrength = 5;
	float tickDamage = 0.01f;

	virtual void InstanceEffect(HumanoidBase& target) override;
	virtual void RemoveEffect(HumanoidBase& target) override;

private:
	virtual void ContinuousEffect(HumanoidBase& target) override;

};

