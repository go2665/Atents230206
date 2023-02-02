#pragma once
#include <iostream>
#include <memory.h>
#include "Enums.h"

using namespace std;

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
	Map(const char* filename)
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

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2���� �迭������ 1�������� ���

	// ���

	/// <summary>
	/// �������� �д� �Լ�
	/// </summary>
	/// <param name="fileName">�������� ��ü ���</param>
	void ReadMapData(const char* fileName);
};

