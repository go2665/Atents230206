#include "Position.h"

Position& Position::operator=(const Position& ref)
{
	x = ref.x;
	y = ref.y;
	return *this;
}

Position& Position::operator+=(const Position& ref)
{
	x += ref.x;
	y += ref.y;
	return *this;

	// this : Ŭ������ü �ڱ� �ڽ��� �ּ�
	// �ּ� �տ� *�� ���̸� �� �ּҿ� ����ִ� ���� ��
}

const Position Position::operator+(const Position& ref)
{
	return Position(x + ref.x, y + ref.y);
}

const Position Position::operator-(const Position& ref)
{
	return Position(x - ref.x, y - ref.y);
}

const Position Position::operator*(const int& ref)
{
	return Position(x * ref, y * ref);
}

const Position Position::operator/(const int& ref)
{
	return Position(x / ref, y / ref);
}