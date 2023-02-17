#pragma once
#include "Creature_Base.h"
class Character :  public Creature_Base
{
protected:
	const int ExpCap = 100;
	int exp = 0;
	int maxExp = ExpCap;

public:
	inline void AddExp(int _exp) { exp += _exp; }
};

