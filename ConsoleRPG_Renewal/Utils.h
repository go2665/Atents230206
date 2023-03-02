#pragma once
#include <iostream>
#include <time.h>

class Utils
{
public:
	static inline void SetRandomSeedByTime() { srand((unsigned int)time(nullptr)); }
	static inline float GetRandom() { return (float)rand() / (float)RAND_MAX;}
	
	/// <summary>
	/// 랜덤 int 구하는 함수(최소~최대)
	/// </summary>
	/// <param name="min">최소 범위(포함)</param>
	/// <param name="max">최대 범위(미포함)</param>
	/// <returns>min~max의 값</returns>
	template<typename T>
	static inline T GetRandom(T min, T max)
	{
		float f = GetRandom() - 0.0001f;
		T gap = max - min;
		T range = (T)(gap * f);
		return min + range;
	}

	//static inline int GetRandom(int min, int max)
	//{
	//	// 예: min = 5, max = 10
	//	float f = GetRandom();		// f = 0.0 ~ 1.0
	//	int gap = max - min;		// gap = 10 - 5 = 5
	//	int range = (int)(gap * f);	// gap * f = 0.0 ~ 5.0
	//	return min + range;			// 결과 = 5 + (0 ~ 5)
	//}

	//static inline float GetRandom(float min, float max)
	//{
	//	// 예: min = 5.5, max = 10.0
	//	float f = GetRandom();			// f = 0.0 ~ 1.0
	//	float gap = max - min;			// gap = 10.0 - 5.5 = 4.5
	//	float range = (float)(gap * f);	// gap * f = 0.0 ~ 4.5
	//	return min + range;				// 결과 = 5.5 + (0.0 ~ 4.5)
	//}

	template<typename T>
	static inline bool CheckSavingThrow(T min, T max, T check)
	{
		float ratio = (float)(check - min) / (float)(max - min);
		float rand = GetRandom();
		bool result = false;

		if (rand < ratio)
			result = true;

		return result;
	}
};

