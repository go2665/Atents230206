#pragma once

enum TerrainType
{
	Plane = 0,	// ����
	Forest,		// ��
	Mountain,	// ��(�̵��Ұ�)
	Desert,		// �縷
	StartPoint,	// ��������
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
	Player = 0,
	Enemy
};