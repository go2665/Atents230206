#pragma once
#include <iostream>
#include <time.h>

class Utils
{
public:
	static inline void SetRandomSeedByTime() { srand((unsigned int)time(nullptr)); }
	static inline float GetRandom() { return (float)rand() / (float)RAND_MAX;}
	
	/// <summary>
	/// ���� int ���ϴ� �Լ�(�ּ�~�ִ�)
	/// </summary>
	/// <param name="min">�ּ� ����(����)</param>
	/// <param name="max">�ִ� ����(������)</param>
	/// <returns>min~max�� ��</returns>
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
	//	// ��: min = 5, max = 10
	//	float f = GetRandom();		// f = 0.0 ~ 1.0
	//	int gap = max - min;		// gap = 10 - 5 = 5
	//	int range = (int)(gap * f);	// gap * f = 0.0 ~ 5.0
	//	return min + range;			// ��� = 5 + (0 ~ 5)
	//}

	//static inline float GetRandom(float min, float max)
	//{
	//	// ��: min = 5.5, max = 10.0
	//	float f = GetRandom();			// f = 0.0 ~ 1.0
	//	float gap = max - min;			// gap = 10.0 - 5.5 = 4.5
	//	float range = (float)(gap * f);	// gap * f = 0.0 ~ 4.5
	//	return min + range;				// ��� = 5.5 + (0.0 ~ 4.5)
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

