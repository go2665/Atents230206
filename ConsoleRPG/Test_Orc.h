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
	virtual void Attack(HumanoidBase& target) override;
	void UseBuff(HumanoidBase& target);

protected:
	virtual void SetRandomStatus() override;
};

