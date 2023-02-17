#pragma once

enum TerrainType
{
	Plane = 0,	// 평지
	Forest,		// 숲
	Mountain,	// 산(이동불가)
	Desert,		// 사막
	StartPoint,	// 시작지점
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
	Player = 0,	
	Orc,
	Wolf
};