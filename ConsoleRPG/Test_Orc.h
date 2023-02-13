#pragma once
#include "Monster_Orc.h"

class Test_Orc : public Monster_Orc
{
public:
	Test_Orc()
	{
		Initialize();
	}
	~Test_Orc()
	{
		CleanUp();
	}
	virtual void Attack(HumanoidBase& target) override;
protected:
	virtual void SetRandomStatus() override;
};

