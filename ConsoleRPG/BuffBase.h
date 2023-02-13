#pragma once
//#include "HumanoidBase.h"
class HumanoidBase;

class BuffBase
{
protected:
	/// <summary>
	/// 버프 이름
	/// </summary>
	char name[64];

	/// <summary>
	/// 버프 지속 시간
	/// </summary>
	int duration = 1;

	/// <summary>
	/// 버프를 받을 때 매 턴마다 받는 효과를 적용하는 함수
	/// </summary>
	/// <param name="target">효과를 받을 대상</param>
	virtual void ContinuousEffect(HumanoidBase& target);		// 도트 계열(힐, 데미지)

public:
	/// <summary>
	/// 버프를 받을 때 처음 한번만 받는 효과 적용하는 함수
	/// </summary>
	/// <param name="target">효과를 받을 대상</param>
	virtual void InstanceEffect(HumanoidBase& target);		// 증가 계열

	/// <summary>
	/// 버프의 모든 효과를 제거하는 함수
	/// </summary>
	/// <param name="target">버프가 제거될 대상(캐릭터)</param>
	virtual void RemoveEffect(HumanoidBase& target);

	/// <summary>
	/// 턴이 종료될 때 실행될 함수
	/// </summary>
	/// <returns>버프 남은 턴 수</returns>
	virtual int OnTurnEnd(HumanoidBase& target);
};

