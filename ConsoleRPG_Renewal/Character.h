#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"

class Character : public Creature_Base
{
private:
	void InputNameProcess();

protected:
	const int ExpCap = 100;
	int exp = 0;
	int maxExp = ExpCap;

	/// <summary>
	/// �� �÷��̾ �ִ� ��
	/// </summary>
	Map* pMap = nullptr;

	/// <summary>
	/// �� �÷��̾��� ���� ����(�̵���, ������ ���)
	/// </summary>
	PlayerState state = Move;

	/// <summary>
	/// �÷��̾��� ��ġ
	/// </summary>
	Position position;

public:
	inline void AddExp(int _exp) { exp += _exp; }

	/// <summary>
	/// �ʱ�ȭ�� �Լ�. ���丮���� ����.
	/// </summary>
	virtual void Initialize() override;

	/// <summary>
	/// ������ �Լ�. Die���� ����
	/// </summary>
	virtual void CleanUp() override;

	/// <summary>
	/// pBattleTarget�� �����ϴ� �Լ�. �� ���� Ŭ�������� override �� ��
	/// </summary>
	virtual void Attack() override;

	/// <summary>
	/// �������� �޾� ó���ϴ� �Լ�. �� ���� Ŭ�������� override �� ��
	/// </summary>
	virtual void Defence(int damage) override;

	/// <summary>
	/// �������ͽ� ����ϴ� �Լ�
	/// </summary>
	virtual void PrintStatus() override;

protected:
	/// <summary>
	/// Loop ���۵� �� ����� �Լ�.
	/// </summary>
	virtual void OnTurnStart() override;

	/// <summary>
	/// Loop �ȿ��� �ش� ũ��ó�� �� �ϸ��� �ϴ� �ൿ�� ��ϵ� �Լ�.
	/// </summary>
	virtual void OnTurnAction() override;

	/// <summary>
	/// Loop�� ���� �� ����� �Լ�
	/// </summary>
	virtual void OnTurnEnd() override;

	/// <summary>
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus() override;

	/// <summary>
	/// �׾��� �� ����� �Լ�
	/// </summary>
	virtual void Die() override;
};

