#include "NamePicker.h"

const char* NamePicker::orcNames[orcNameCount] = { 
	"��ũ1", "��ũ2", "��ũ3", "��ũ4", "��ũ5", "��ũ6", "��ũ7", "��ũ8", "��ũ9", "��ũ10" };

const char* NamePicker::wolfNames[wolfNameCount] = {
	"����", "���� ����", "�Ͼ� ����", "���� ����", "���� ����" };

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

const char* NamePicker::GetRaceName(RaceType race)
{
	switch (race)
	{
	case HumanType:
		return "�ΰ�";
	case ElfType:
		return "����";
	case DrawfType:
		return "�����";
	}
	return nullptr;
}

const char* NamePicker::GetTerrainName(TerrainType type)
{
	switch (type)
	{
	case StartPointType:
	case PlaneType:
		return "���";
	case ForestType:
		return "��";
	case MountainType:
		return "��";
	case DesertType:
		return "�縷";
	case NumOfTypes:
	default:
		break;
	}
	return nullptr;
}
