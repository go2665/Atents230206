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
	Position(Position& pos)	// 복사생성자
	{
		x = pos.x;
		y = pos.y;
	}

	int x;
	int y;

	// 명령어 오버로딩
	Position& operator= (const Position& ref)
	{

	}
};

