#include "Map.h"

void Map::ReadMapData(const char* fileName)
{
	// 실습
	// 데이터 폴더에 있는 SampleMap.txt 읽어서
	// TerrainType* map; 변수를 채우기(엔터는 제외해야 한다.)
	// 엔터를 표현하는 글자 : '\n'

	if (map != nullptr)		// 이전에 로딩된 맵이 있으면
	{
		delete map;			// 삭제
		map = nullptr;
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
				
		map = new TerrainType[index];
		memcpy_s(map, sizeof(TerrainType) * index, buffer, sizeof(int) * index);	// map에 데이터 복사

		height = lineCount;						// 높이 저장
		width = index / height;					// index와 height이용해서 width 계산

		if (startIndex != -1)
		{
			startPosition = Position(index % width, index / width);	// 시작지점 따로 저장해 놓기
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
