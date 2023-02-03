#pragma once
#include <iostream>
#include <memory.h>
#include "Enums.h"
#include "Position.h"

using namespace std;

// ��ǥ�� (x+ : ������, y+ : �Ʒ���) 

class Map
{
	// ����
	// PC�� NPC ��ġ ����
public:
	Map()	// 10 * 10 ������ �����
	{
		width = 10;
		height = 10;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);		
	}
	Map(int xSize, int ySize)	// xSize * ySize ������ �����
	{
		width = xSize;
		height = ySize;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);
	}
	Map(const char* filename)	// filename�� �ִ� ���� �о �� �����
	{
		ReadMapData(filename);
	}

	~Map()
	{
		if (map != nullptr)		// ������ �ε��� ���� ������
		{
			delete map;			// ����
			map = nullptr;
		}
	}

	const Position GetStartPosition() { return startPosition; }	// �б� �������� startPosition �� �����ϱ�

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2���� �迭������ 1�������� ���

	Position startPosition;


	/// <summary>
	/// �������� �д� �Լ�
	/// </summary>
	/// <param name="fileName">�������� ��ü ���</param>
	void ReadMapData(const char* fileName);
};

