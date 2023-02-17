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

	virtual void InstanceEffect(Creature_Base& target) override;
	virtual void RemoveEffect(Creature_Base& target) override;

private:
	virtual void ContinuousEffect(Creature_Base& target) override;

};

