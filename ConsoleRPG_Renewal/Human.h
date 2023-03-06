#pragma once
#include "Character.h"
class Human : public Character
{
public:
	virtual void Initialize(SaveData* data = nullptr) override;

	

protected:
	
	/// <summary>
	/// Loop �ȿ��� �ش� ũ��ó�� �� �ϸ��� �ϴ� �ൿ�� ��ϵ� �Լ�.
	/// </summary>
	virtual void OnTurnAction() override;


	/// <summary>
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus() override;

	virtual void RefreshHPMP() override;
	

	virtual void NormalAttack() override;
	virtual void Skill01() override;
	virtual void Skill02() override;

	virtual void LevelUp() override;
	

};

