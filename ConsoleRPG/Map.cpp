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
			cout << "이 곳은 평지다." << endl;
			break;
		case Forest:
			cout << "이 곳은 숲이다." << endl;
			break;
		case Mountain:
			cout << "이 곳은 산이다." << endl;
			break;
		case Desert:
			cout << "이 곳은 사막이다." << endl;
			break;
		case StartPoint:
			cout << "이 곳은 시작지점이다." << endl;
			break;
		case NumOfTypes:
		default:
			cout << "ERROR - 맵에 설정되지 않은 지형이 있습니다.!!!!!!!!!!!!!!" << endl;
			break;
		}
	}
	else
	{
		cout << "이곳은 맵 바깥입니다." << endl;
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
	// 실습
	// 데이터 폴더에 있는 SampleMap.txt 읽어서
	// TerrainType* terrainMap; 변수를 채우기(엔터는 제외해야 한다.)
	// 엔터를 표현하는 글자 : '\n'

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

			if (buffer[index] == StartPoint)	// 시작지점 별도 처리
			{
				startIndex = index;				
			}

			index++;							// 읽은 글자 갯수
		}
		lineCount++;	// 파일이 끝났으니 마지막줄 수 추가
				
		terrainMap = new TerrainType[index];
		memcpy_s(terrainMap, sizeof(TerrainType) * index, buffer, sizeof(int) * index);	// map에 데이터 복사

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

void Map::OnEnterEvent_Plane(const void* p)
{
	cout << "평야의 효과가 발동됩니다." << endl;
}

void Map::OnEnterEvent_Forest(const void* p)
{
	cout << "숲의 효과가 발동됩니다." << endl;
}

void Map::OnEnterEvent_Mountain(const void* p)
{
	cout << "산의 효과가 발동됩니다." << endl;
}

void Map::OnEnterEvent_Desert(const void* p)
{
	cout << "사막의 효과가 발동됩니다." << endl;
}

void Map::OnEnterEvent_StartPoint(const void* p)
{
	cout << "시작지점의 효과가 발동됩니다." << endl;
}
