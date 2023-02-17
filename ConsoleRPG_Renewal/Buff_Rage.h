#pragma once
#include <iostream>
#include "BuffBase.h"

class Buff_Rage : public BuffBase
{
public:
	Buff_Rage()
	{
		strcpy_s(name, "ºÐ³ë");
		duration = 3;
	}

	int buffStrength = 5;
	float tickDamage = 0.01f;

	virtual void InstanceEffect(Creature_Base& target) override;
	virtual void RemoveEffect(Creature_Base& target) override;

private:
	virtual void ContinuousEffect(Creature_Base& target) override;

};

