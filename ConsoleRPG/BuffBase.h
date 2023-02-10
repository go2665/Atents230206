#pragma once
//#include "HumanoidBase.h"

class HumanoidBase;

class BuffBase
{
protected:
	/// <summary>
	/// 버프 지속 시간
	/// </summary>
	int duration = 1;

public:
	// 버프 효과
	virtual void Effect(HumanoidBase& target) {};

	/// <summary>
	/// 턴이 종료될 때 이팩트를 제거하는 함수
	/// </summary>
	/// <param name="target">제거될 대상(캐릭터)</param>
	/// <returns>버프 남은 시간</returns>
	virtual int RemoveEffect(HumanoidBase& target) { return duration; };
};

