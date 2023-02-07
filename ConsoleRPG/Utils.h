#pragma once
#include <iostream>
#include <time.h>

class Utils
{
public:
	static inline void SetRandomSeedByTime() { srand((unsigned int)time(nullptr)); }
	static inline float GetRandom() { return (float)rand() / (float)RAND_MAX;}
};

