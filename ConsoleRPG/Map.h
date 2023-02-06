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
		terrainMap = new TerrainType[width * height];
		memset(terrainMap, 0, sizeof(TerrainType) * width * height);		
	}
	Map(int xSize, int ySize)	// xSize * ySize ������ �����
	{
		width = xSize;
		height = ySize;
		terrainMap = new TerrainType[width * height];
		memset(terrainMap, 0, sizeof(TerrainType) * width * height);
	}
	Map(const char* filename)	// filename�� �ִ� ���� �о �� �����
	{
		ReadMapData(filename);
	}

	~Map()
	{
		if (terrainMap != nullptr)		// ������ �ε��� ���� ������
		{
			delete terrainMap;			// ����
			terrainMap = nullptr;
		}
	}

	const Position GetStartPosition() { return startPosition; }	// �б� �������� startPosition �� �����ϱ�

	/// <summary>
	/// �Ķ���ͷ� ���� ��ġ�� �� ������ �ƴ��� üũ�ϴ� �Լ�
	/// </summary>
	/// <param name="pos">Ȯ���� ��ġ</param>
	/// <returns>true�� �� ��, false�� �� ��</returns>
	bool IsValidPosition(const Position& pos) const;	// �Լ� �ڿ� const�� �ٿ��� �ɹ� ������ ������� �ʰ� �Ѵ�.

	/// <summary>
	/// �Ķ���ͷ� ���� ��ġ�� ǳ���� ����ϴ� �Լ�
	/// </summary>
	/// <param name="pos">ǳ���� ����� �Լ�</param>
	void PrintLandscape(const Position& pos) const;

private:
	int width = 10;
	int height = 10;

	TerrainType* terrainMap;	// 2���� �迭������ 1�������� ���

	Position startPosition;


	/// <summary>
	/// �������� �д� �Լ�
	/// </summary>
	/// <param name="fileName">�������� ��ü ���</param>
	void ReadMapData(const char* fileName);

	/// <summary>
	/// ���� �迭 �ε��� ���� �׸��� ��ǥ�� �������ִ� �Լ�
	/// </summary>
	/// <param name="index">TerrainType �迭�� �ε���</param>
	/// <returns>�׸��� ��ǥ�� ����� ��ġ</returns>
	Position IndexToGridPosition(const int index) const;

	/// <summary>
	/// �׸��� ��ǥ�� ���� �迭 �ε��� ������ �������ִ� �Լ�
	/// </summary>
	/// <param name="pos">������ �׸��� ��ġ</param>
	/// <returns>����� �ε�����</returns>
	int GridPositionToIndex(const Position& pos) const;
};

