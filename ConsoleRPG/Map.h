#pragma once
#include <iostream>
#include <memory.h>
#include "Enums.h"

using namespace std;

// 좌표계 (x+ : 오른쪽, y+ : 아래쪽) 

class Map
{
	// 변수
	//	전체 영역 크기	
	//	지형
		// 지형의 종류
		// 전체 영역에서 지형의 배치
	// PC나 NPC 배치 정보
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
		if (map != nullptr)		// 이전에 로딩된 맵이 있으면
		{
			delete map;			// 삭제
			map = nullptr;
		}
	}

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2차원 배열이지만 1차원으로 사용

	// 기능

	/// <summary>
	/// 맵파일을 읽는 함수
	/// </summary>
	/// <param name="fileName">맵파일의 전체 경로</param>
	void ReadMapData(const char* fileName);
};

