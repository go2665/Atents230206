#pragma once
#include "Monster.h"
class Monster_Orc : public Monster
{
public:
	virtual void Initialize() override;
	virtual void Attack() override;

protected:
	int Rage();
	int Smash();

	virtual void OnTurnAction() override;
	virtual void OnTurnEnd() override;

	virtual void SetRandomStatus() override;
	virtual void Die() override;
};

