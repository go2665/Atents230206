#pragma once
class Position
{	
public:
	// ������ : Ŭ������ ������ �� ����Ǵ� �ڵ�
	// const : ���. ������ �ʴ´�.
	// ���� ����(������ �纻 ����)�� ���� ����(�������� �ּҸ� ����)

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
	Position(const Position& pos)	// ���������. �� ���� ������ �Ķ���͸� �����ϱ� ������ ���� ���簡 �Ͼ�� �ʴ´�.
	{
		x = pos.x;
		y = pos.y;
	}

	int x;
	int y;

	// ��ɾ� �����ε�(������ �����ε�)
	Position& operator= (const Position& ref);	// ���� ������
	const Position operator+(const Position& ref);

	// �ǽ� : ��ɾ� �����ε� ������
	//	1. - �����ε��ϱ�.	(1,2) - (0,1) = (1,1)
	//  2. * �����ε��ϱ�.	(1,2) * 3 = (3,6)
	//  3. / �����ε��ϱ�.	(2,4) / 2 = (1,2)
	//  4. += �����ε��ϱ�.  a(1,2).		a += (2,2).		a(3,4)
};

