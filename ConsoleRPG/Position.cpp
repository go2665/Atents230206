#include "Position.h"

Position& Position::operator=(const Position& ref)
{
	x = ref.x;
	y = ref.y;
	return *this;
}

const Position Position::operator+(const Position& ref)
{
	return Position(x + ref.x, y + ref.y);
}
