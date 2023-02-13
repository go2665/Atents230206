#pragma once
//#include "HumanoidBase.h"
class HumanoidBase;

class BuffBase
{
protected:
	/// <summary>
	/// ���� �̸�
	/// </summary>
	char name[64];

	/// <summary>
	/// ���� ���� �ð�
	/// </summary>
	int duration = 1;

	/// <summary>
	/// ������ ���� �� �� �ϸ��� �޴� ȿ���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">ȿ���� ���� ���</param>
	virtual void ContinuousEffect(HumanoidBase& target);		// ��Ʈ �迭(��, ������)

public:
	/// <summary>
	/// ������ ���� �� ó�� �ѹ��� �޴� ȿ�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">ȿ���� ���� ���</param>
	virtual void InstanceEffect(HumanoidBase& target);		// ���� �迭

	/// <summary>
	/// ������ ��� ȿ���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">������ ���ŵ� ���(ĳ����)</param>
	virtual void RemoveEffect(HumanoidBase& target);

	/// <summary>
	/// ���� ����� �� ����� �Լ�
	/// </summary>
	/// <returns>���� ���� �� ��</returns>
	virtual int OnTurnEnd(HumanoidBase& target);
};

