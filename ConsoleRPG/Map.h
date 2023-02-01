#pragma once
#include <memory.h>
#include "Enums.h"

// ��ǥ�� (x+ : ������, y+ : �Ʒ���) 

class Map
{
	// ����
	//	��ü ���� ũ��	
	//	����
		// ������ ����
		// ��ü �������� ������ ��ġ
	// PC�� NPC ��ġ ����
public:
	Map()
	{
		width = 10;
		height = 10;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);		
	}
	Map(int xSize, int ySize)
	{
		width = xSize;
		height = ySize;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);
	}

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2���� �迭������ 1�������� ���


	// ���
};

