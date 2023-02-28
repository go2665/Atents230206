#pragma once

enum TerrainType
{
	PlaneType = 0,	// 평지
	ForestType,		// 숲
	MountainType,	// 산(이동불가)
	DesertType,		// 사막
	StartPointType,	// 시작지점
	NumOfTypes
};

enum PlayerState
{
	Move = 0,	// 이동 상태
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