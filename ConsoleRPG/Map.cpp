#include "Map.h"

void Map::ReadMapData(const char* fileName)
{
	// �ǽ�
	// ������ ������ �ִ� SampleMap.txt �о
	// TerrainType* map; ������ ä���(���ʹ� �����ؾ� �Ѵ�.)
	// ���͸� ǥ���ϴ� ���� : '\n'

	if (map != nullptr)		// ������ �ε��� ���� ������
	{
		delete map;			// ����
		map = nullptr;
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
				
		map = new TerrainType[index];
		memcpy_s(map, sizeof(TerrainType) * index, buffer, sizeof(int) * index);	// map�� ������ ����

		height = lineCount;						// ���� ����
		width = index / height;					// index�� height�̿��ؼ� width ���

		if (startIndex != -1)
		{
			startPosition = Position(index % width, index / width);	// �������� ���� ������ ����
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
