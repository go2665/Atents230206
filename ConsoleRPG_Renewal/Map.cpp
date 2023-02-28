#include "Map.h"
#include "Factory.h"
#include "Character.h"

Map::Map()	// 10 * 10 ������ �����
{
	width = 10;
	height = 10;
	int size = width * height;
	terrainMap = new TerrainBase*[size];
	for (int i = 0; i < size; i++)
	{
		terrainMap[i] = Factory::MakeTerrain(PlaneType);	// C++������ ���� �ڵ尡 �ƴ�		
		terrainMap[i]->SetMap(this);
	}
}

Map::Map(int xSize, int ySize)	// xSize * ySize ������ �����
{
	width = xSize;
	height = ySize;
	int size = width * height;
	terrainMap = new TerrainBase*[size];
	for (int i = 0; i < size; i++)
	{
		terrainMap[i] = Factory::MakeTerrain(PlaneType);	// C++������ ���� �ڵ尡 �ƴ�
		terrainMap[i]->SetMap(this);
	}
}

Map::Map(const char* filename)	// filename�� �ִ� ���� �о �� �����
{
	ReadMapData(filename);
}

Map::~Map()
{
	if (terrainMap != nullptr)		// ������ �ε��� ���� ������
	{
		int size = width * height;
		for (int i = 0; i < size; i++)
		{
			Factory::DestroyTerrain(terrainMap[i]);
			terrainMap[i] = nullptr;
		}

		delete[] terrainMap;		// ����
		terrainMap = nullptr;
	}
}

bool Map::IsValidPosition(const Position& pos) const
{
	return (pos.x >= 0) && (pos.x < width) && (pos.y >= 0) && (pos.y < height);
}

TerrainBase* Map::GetTerrain(const Position& pos) const
{
	if (IsValidPosition(pos))
	{
		int index = GridPositionToIndex(pos);
		return terrainMap[index];
	}

	return nullptr;
}

void Map::PrintLandscape(const Position& pos) const
{
	if (IsValidPosition(pos))
	{
		int index = GridPositionToIndex(pos);
		terrainMap[index]->PrintLandscape();
	}
	else
	{
		cout << "�̰��� �� �ٱ��Դϴ�." << endl;
	}
}

void Map::PrintMap() const
{
	for (int i = 0; i < height; i++)
	{		
		wchar_t temp[32];
		wcscpy_s(temp, L"");
		int j = 0;
		for (j = 0; j < width; j++)
		{
			TerrainBase* terrain = terrainMap[j + i * width];
			temp[j] = terrain->GetPrint();
		}
		temp[j] = L'\n';
		//cout << temp << endl;
		wprintf_s(temp);
	}
}

void Map::ReadMapData(const char* fileName)
{
	if (terrainMap != nullptr)		// ������ �ε��� ���� ������
	{
		delete terrainMap;			// ����
		terrainMap = nullptr;
	}

	FILE* fp = nullptr;
	fopen_s(&fp, ".//Data//SampleMap.txt", "r");		// SampleMap.txt ������ �б� �������� ����

	if (fp != nullptr)
	{
		int buffer[512];
		int index = 0;
		int lineCount = 0;
		int startIndex = -1;
		while (true)							// �ϴ� ���� ������ ������
		{
			char c = fgetc(fp);					// ���Ͽ��� ���� �ϳ��� ���� ������

			if (c == '\n')						// ���Ͱ� ������ ���� ���� �ٷ� �б�
			{
				lineCount++;
				continue;
			}
			if (c == EOF)						// ������ ������ ������ ĵ���ϱ�
				break;

			buffer[index] = c - '0';			// ���ڸ� ���ڷ� �ٲٱ�

			if (buffer[index] == StartPointType)	// �������� ���� ó��
			{
				startIndex = index;
			}

			index++;							// ���� ���� ����
		}
		lineCount++;	// ������ �������� �������� �� �߰�

		terrainMap = new TerrainBase*[index];
		for (int i = 0; i < index; i++)
		{
			terrainMap[i] = Factory::MakeTerrain((TerrainType)buffer[i]);	// �ʿ� ��ϵȴ�� ���� ����
			terrainMap[i]->SetMap(this);
		}

		height = lineCount;						// ���� ����
		width = index / height;					// index�� height�̿��ؼ� width ���

		if (startIndex != -1)
		{
			startPosition = IndexToGridPosition(startIndex);	// �������� ���� ������ ����
		}

		fclose(fp);								// ������� ������ �ݱ�
		fp = nullptr;
	}
	else
	{
		cout << "������ �дµ� �����߽��ϴ�." << endl;
		height = 0;	// ���� ǥ�ÿ�
		width = 0;
	}
}


Position Map::IndexToGridPosition(const int index) const
{
	return Position(index % width, index / width);
}

int Map::GridPositionToIndex(const Position& pos) const
{
	return pos.x + pos.y * width;
}