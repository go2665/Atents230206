#pragma once
class Creature_Base;

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
	virtual void ContinuousEffect(Creature_Base& target);		// ��Ʈ �迭(��, ������)

public:
	/// <summary>
	/// ������ ���� �� ó�� �ѹ��� �޴� ȿ�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">ȿ���� ���� ���</param>
	virtual void InstanceEffect(Creature_Base& target);		// ���� �迭

	/// <summary>
	/// ������ ��� ȿ���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">������ ���ŵ� ���(ĳ����)</param>
	virtual void RemoveEffect(Creature_Base& target);

	/// <summary>
	/// ���� ����� �� ����� �Լ�
	/// </summary>
	/// <returns>���� ���� �� ��</returns>
	virtual int OnTurnEnd(Creature_Base& target);

	/// <summary>
	/// �̸� Ȯ�ο� �Լ�
	/// </summary>
	/// <returns></returns>
	inline const char* GetName() { return name; }
};

