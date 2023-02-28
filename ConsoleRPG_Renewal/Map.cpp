#include "Map.h"
#include "Factory.h"
#include "Character.h"

Map::Map()	// 10 * 10 평지맵 만들기
{
	width = 10;
	height = 10;
	int size = width * height;
	terrainMap = new TerrainBase*[size];
	for (int i = 0; i < size; i++)
	{
		terrainMap[i] = Factory::MakeTerrain(PlaneType);	// C++에서는 좋은 코드가 아님		
		terrainMap[i]->SetMap(this);
	}
}

Map::Map(int xSize, int ySize)	// xSize * ySize 평지맵 만들기
{
	width = xSize;
	height = ySize;
	int size = width * height;
	terrainMap = new TerrainBase*[size];
	for (int i = 0; i < size; i++)
	{
		terrainMap[i] = Factory::MakeTerrain(PlaneType);	// C++에서는 좋은 코드가 아님
		terrainMap[i]->SetMap(this);
	}
}

Map::Map(const char* filename)	// filename에 있는 파일 읽어서 맵 만들기
{
	ReadMapData(filename);
}

Map::~Map()
{
	if (terrainMap != nullptr)		// 이전에 로딩된 맵이 있으면
	{
		int size = width * height;
		for (int i = 0; i < size; i++)
		{
			Factory::DestroyTerrain(terrainMap[i]);
			terrainMap[i] = nullptr;
		}

		delete[] terrainMap;		// 삭제
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
		cout << "이곳은 맵 바깥입니다." << endl;
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
	if (terrainMap != nullptr)		// 이전에 로딩된 맵이 있으면
	{
		delete terrainMap;			// 삭제
		terrainMap = nullptr;
	}

	FILE* fp = nullptr;
	fopen_s(&fp, ".//Data//SampleMap.txt", "r");		// SampleMap.txt 파일을 읽기 전용으로 열기

	if (fp != nullptr)
	{
		int buffer[512];
		int index = 0;
		int lineCount = 0;
		int startIndex = -1;
		while (true)							// 일단 무한 루프를 돌리고
		{
			char c = fgetc(fp);					// 파일에서 글자 하나를 읽은 다음에

			if (c == '\n')						// 엔터가 들어오면 다음 글자 바로 읽기
			{
				lineCount++;
				continue;
			}
			if (c == EOF)						// 파일이 끝나면 루프를 캔슬하기
				break;

			buffer[index] = c - '0';			// 글자를 숫자로 바꾸기

			if (buffer[index] == StartPointType)	// 시작지점 별도 처리
			{
				startIndex = index;
			}

			index++;							// 읽은 글자 갯수
		}
		lineCount++;	// 파일이 끝났으니 마지막줄 수 추가

		terrainMap = new TerrainBase*[index];
		for (int i = 0; i < index; i++)
		{
			terrainMap[i] = Factory::MakeTerrain((TerrainType)buffer[i]);	// 맵에 기록된대로 지형 생성
			terrainMap[i]->SetMap(this);
		}

		height = lineCount;						// 높이 저장
		width = index / height;					// index와 height이용해서 width 계산

		if (startIndex != -1)
		{
			startPosition = IndexToGridPosition(startIndex);	// 시작지점 따로 저장해 놓기
		}

		fclose(fp);								// 열어놓은 파일을 닫기
		fp = nullptr;
	}
	else
	{
		cout << "파일을 읽는데 실패했습니다." << endl;
		height = 0;	// 실패 표시용
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