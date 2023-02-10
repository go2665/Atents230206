#pragma once
//#include "HumanoidBase.h"

class HumanoidBase;

class BuffBase
{
protected:
	/// <summary>
	/// ���� ���� �ð�
	/// </summary>
	int duration = 1;

public:
	// ���� ȿ��
	virtual void Effect(HumanoidBase& target) {};

	/// <summary>
	/// ���� ����� �� ����Ʈ�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">���ŵ� ���(ĳ����)</param>
	/// <returns>���� ���� �ð�</returns>
	virtual int RemoveEffect(HumanoidBase& target) { return duration; };
};

