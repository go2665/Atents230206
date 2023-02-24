#pragma once
#include "Enums.h"
#include "Position.h"
#include "Utils.h"
#include "TerrainBase.h"

using namespace std;
class Character;

// ��ǥ�� (x+ : ������, y+ : �Ʒ���) 

class Map
{
	// ����
	// PC�� NPC ��ġ ����
public:
	/// <summary>
	/// 10 * 10 �������� ����� ������
	/// </summary>
	Map();

	/// <summary>
	/// xSize * ySize ������ ����� ������
	/// </summary>
	/// <param name="xSize">����ũ��</param>
	/// <param name="ySize">����ũ��</param>
	Map(int xSize, int ySize);

	/// <summary>
	/// filename�� �ִ� ���� �о �� ����� ������
	/// </summary>
	/// <param name="filename">�����̸�</param>
	Map(const char* filename);

	/// <summary>
	/// �⺻�Ҹ���
	/// </summary>
	~Map();

	const Position GetStartPosition() { return startPosition; }	// �б� �������� startPosition �� �����ϱ�

	/// <summary>
	/// �Ķ���ͷ� ���� ��ġ�� �� ������ �ƴ��� üũ�ϴ� �Լ�
	/// </summary>
	/// <param name="pos">Ȯ���� ��ġ</param>
	/// <returns>true�� �� ��, false�� �� ��</returns>
	bool IsValidPosition(const Position& pos) const;	// �Լ� �ڿ� const�� �ٿ��� �ɹ� ������ ������� �ʰ� �Ѵ�.

	/// <summary>
	/// �׸��� ��ǥ�� �ִ� �ͷ��� ����
	/// </summary>
	/// <param name="pos">�ͷ����� ������ ��ġ</param>
	/// <returns>�ͷ����� �ּ�</returns>
	TerrainBase* GetTerrain(const Position& pos) const;

	/// <summary>
	/// �Ķ���ͷ� ���� ��ġ�� ǳ���� ����ϴ� �Լ�
	/// </summary>
	/// <param name="pos">ǳ���� ����� �Լ�</param>
	void PrintLandscape(const Position& pos) const;

	inline void SetPlayer(Character* target)
	{
		if (player == nullptr)
		{
			player = target;
		}
	}
	inline Character* GetPlayer() { return player; }

	
private:
	Character* player = nullptr;

	int width = 10;
	int height = 10;

	TerrainBase** terrainMap;	// 2���� �迭������ 1�������� ���. TerrainBase*�� �迭�� ���� ����

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
