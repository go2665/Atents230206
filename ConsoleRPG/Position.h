#pragma once
class Position
{
public:
	Position()
	{
		x = 0;
		y = 0;
	}
	Position(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	Position(Position& pos)	// ���������
	{
		x = pos.x;
		y = pos.y;
	}

	int x;
	int y;

	// ��ɾ� �����ε�
	Position& operator= (const Position& ref)
	{

	}
};

