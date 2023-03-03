#pragma once

enum TerrainType
{
	PlaneType = 0,	// ����
	ForestType,		// ��
	MountainType,	// ��(�̵��Ұ�)
	DesertType,		// �縷
	StartPointType,	// ��������
	NumOfTypes
};

enum PlayerState
{
	Action = 0,		// �ൿ ����
	Move,			// �̵� ����
};

enum Input_Move
{
	To_Action = 0,
	Move_East = 1,
	Move_West,
	Move_South,
	Move_North
};

enum CreatureType
{
	None = -1,
	PlayerType = 0,	
	OrcType,
	WolfType
};

enum RaceType
{
	HumanType = 0,
	ElfType,
	DrawfType,
	NumOfRaceType
};