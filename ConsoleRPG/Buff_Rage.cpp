#include "Buff_Rage.h"
#include "HumanoidBase.h"

void Buff_Rage::Effect(HumanoidBase& target)
{
	target.AddStrength(strength);
}

int Buff_Rage::RemoveEffect(HumanoidBase& target)
{
	target.AddStrength(-strength);
	int max = target.GetMaxHP();	
	target.AddHP((int)(-max * damage));

	duration--;

	return duration;
}
