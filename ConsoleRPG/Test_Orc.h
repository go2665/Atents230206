#pragma once
#include "Monster_Orc.h"

class Test_Orc : public Monster_Orc
{
public:
	Test_Orc()
	{
		Initialize();
	}
	virtual ~Test_Orc()
	{
		CleanUp();
	}
	virtual void Attack(Creature_Base& target) override;
	void UseBuff(Creature_Base& target);

protected:
	virtual void SetRandomStatus() override;
};

