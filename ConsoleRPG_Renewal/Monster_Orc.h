#pragma once
#include "Monster.h"
class Monster_Orc : public Monster
{
public:
	virtual void Initialize(SaveData* data = nullptr) override;
	virtual void Attack() override;

protected:
	int Rage();
	int Smash();

	virtual void OnTurnAction() override;

	virtual void SetRandomStatus() override;
	virtual void Die() override;
};

