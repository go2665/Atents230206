#pragma once
#include "Monster.h"
class Monster_Wolf : public Monster
{
public:
	virtual void Initialize() override;
	virtual void Attack() override;

protected:
	int Bite();
	int Rush();

	virtual void OnTurnAction() override;

	virtual void SetRandomStatus() override;
	virtual void Die() override;
};

