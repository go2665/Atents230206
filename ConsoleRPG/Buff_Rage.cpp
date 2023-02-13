#include "Buff_Rage.h"
#include "HumanoidBase.h"

void Buff_Rage::InstanceEffect(HumanoidBase& target)
{
	target.AddStrength(buffStrength);
}

void Buff_Rage::ContinuousEffect(HumanoidBase& target)
{
	int max = target.GetMaxHP();	
	target.AddHP((int)(-max * tickDamage));
}

void Buff_Rage::RemoveEffect(HumanoidBase& target)
{
	target.AddStrength(-buffStrength);
}
