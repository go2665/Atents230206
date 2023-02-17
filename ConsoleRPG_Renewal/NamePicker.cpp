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
