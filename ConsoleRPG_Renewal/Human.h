#pragma once
#include "Character.h"
class Human : public Character
{
public:
	virtual void Initialize() override;

	

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

	

	virtual void NormalAttack() override;
	virtual void Skill01() override;
	virtual void Skill02() override;

};

