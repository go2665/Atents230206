#include "Map.h"
#include "Character.h"

bool Map::IsValidPosition(const Position& pos) const
{	
	return (pos.x >= 0) && (pos.x < width) && (pos.y >= 0) && (pos.y < height);
}

void Map::PrintLandscape(const Position& pos) const
{
	if (IsValidPosition(pos))
	{
		int index = GridPositionToIndex(pos);
		TerrainType type = terrainMap[index];
		switch (type)
		{
		case Plane:
			cout << "�� ���� ������." << endl;
			break;
		case Forest:
			cout << "�� ���� ���̴�." << endl;
			break;
		case Mountain:
			cout << "�� ���� ���̴�." << endl;
			break;
		case Desert:
			cout << "�� ���� �縷�̴�." << endl;
			break;
		case StartPoint:
			cout << "�� ���� ���������̴�." << endl;
			break;
		case NumOfTypes:
		default:
			cout << "ERROR - �ʿ� �������� ���� ������ �ֽ��ϴ�.!!!!!!!!!!!!!!" << endl;
			break;
		}
	}
	else
	{
		cout << "�̰��� �� �ٱ��Դϴ�." << endl;
	}
}

void Map::OnMapMove(const void* pPlayer)
{
	Character* p = (Character*)pPlayer;
	const Position& pos = p->GetPosition();
	PrintLandscape(pos);
	
	TerrainType terrain = terrainMap[GridPositionToIndex(pos)];

	switch (terrain)
	{
	case Plane:
		OnEnterEvent_Plane(pPlayer);
		break;
	case Forest:
		OnEnterEvent_Forest(pPlayer);
		break;
	case Mountain:
		OnEnterEvent_Mountain(pPlayer);
		break;
	case Desert:
		OnEnterEvent_Desert(pPlayer);
		break;
	case StartPoint:
		OnEnterEvent_StartPoint(pPlayer);
		break;
	case NumOfTypes:
	default:

		break;
	}
}

void Map::ReadMapData(const char* fileName)
{
	// �ǽ�
	// ������ ������ �ִ� SampleMap.txt �о
	// TerrainType* terrainMap; ������ ä���(���ʹ� �����ؾ� �Ѵ�.)
	// ���͸� ǥ���ϴ� ���� : '\n'

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

			if (buffer[index] == StartPoint)	// �������� ���� ó��
			{
				startIndex = index;				
			}

			index++;							// ���� ���� ����
		}
		lineCount++;	// ������ �������� �������� �� �߰�
				
		terrainMap = new TerrainType[index];
		memcpy_s(terrainMap, sizeof(TerrainType) * index, buffer, sizeof(int) * index);	// map�� ������ ����

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

void Map::OnEnterEvent_Plane(const void* p)
{
	cout << "����� ȿ���� �ߵ��˴ϴ�." << endl;
}

void Map::OnEnterEvent_Forest(const void* p)
{
	cout << "���� ȿ���� �ߵ��˴ϴ�." << endl;
}

void Map::OnEnterEvent_Mountain(const void* p)
{
	cout << "���� ȿ���� �ߵ��˴ϴ�." << endl;
}

void Map::OnEnterEvent_Desert(const void* p)
{
	cout << "�縷�� ȿ���� �ߵ��˴ϴ�." << endl;
}

void Map::OnEnterEvent_StartPoint(const void* p)
{
	cout << "���������� ȿ���� �ߵ��˴ϴ�." << endl;
}
