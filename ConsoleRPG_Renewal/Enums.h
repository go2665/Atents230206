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
	Move = 0,	// �̵� ����
};

enum Input_Move
{
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