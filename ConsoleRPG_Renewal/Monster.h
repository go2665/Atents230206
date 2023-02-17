#pragma once
#include "Creature_Base.h"
class Monster : public Creature_Base
{
protected:
	int rewardHP = 1;
	int rewardMP = 1;
	int rewardExp = 1;
};

