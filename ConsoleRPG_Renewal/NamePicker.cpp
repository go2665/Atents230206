#include "NamePicker.h"

const char* NamePicker::orcNames[orcNameCount] = { 
	"오크1", "오크2", "오크3", "오크4", "오크5", "오크6", "오크7", "오크8", "오크9", "오크10" };

const char* NamePicker::wolfNames[wolfNameCount] = {
	"늑대", "검은 늑대", "하얀 늑대", "갈색 늑대", "붉은 늑대" };

const char* NamePicker::GetName(CreatureType type)
{
	const char* result = nullptr;
	int index = 0;
	switch (type)
	{
	case Orc:
		index = Utils::GetRandom(0, orcNameCount);
		result = GetOrcName(index);
		break;
	case Wolf:
		index = Utils::GetRandom(0, wolfNameCount);
		result = GetWolfName(index);
		break;
	case Player:
	case None:
	default:
		break;
	}
	return result;
}
