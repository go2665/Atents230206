#pragma once
#include <memory.h>
#include "Enums.h"

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

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2차원 배열이지만 1차원으로 사용


	// 기능
};

