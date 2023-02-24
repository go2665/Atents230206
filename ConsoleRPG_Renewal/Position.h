#pragma once
class Position
{	
public:
	// 생성자 : 클래스가 생성될 때 실행되는 코드
	// const : 상수. 변하지 않는다.
	// 깊은 복사(완전한 사본 생성)와 얕은 복사(데이터의 주소만 전달)

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
	Position(const Position& pos)	// 복사생성자. 이 경우는 참조로 파라메터를 전달하기 때문에 깊은 복사가 일어나지 않는다.
	{
		x = pos.x;
		y = pos.y;
	}

	int x;
	int y;

	static const Position Zero;
	static const Position One;
	static const Position MinusOne;

	//const Position& Left = Position(-1, 0);
	//const Position& Right = Position(1, 0);
	//const Position& Up = Position(0, 1);
	//const Position& Down = Position(0, -1);

	// 명령어 오버로딩(연산자 오버로딩)
	Position& operator= (const Position& ref);	// 대입 연산자
	Position& operator+= (const Position& ref);

	const Position operator+(const Position& ref);
	const Position operator-(const Position& ref);
	const Position operator*(const int& ref);
	const Position operator/(const int& ref);


	// 실습 : 명령어 오버로딩 만들어보기
	//	1. - 오버로딩하기.	(1,2) - (0,1) = (1,1)
	//  2. * 오버로딩하기.	(1,2) * 3 = (3,6)
	//  3. / 오버로딩하기.	(2,4) / 2 = (1,2)
	//  4. += 오버로딩하기.  a(1,2).		a += (2,2).		a(3,4)
};

