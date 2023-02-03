#pragma once
#include <iostream>
#include <memory.h>
#include "Enums.h"
#include "Position.h"

using namespace std;

// 좌표계 (x+ : 오른쪽, y+ : 아래쪽) 

class Map
{
	// 변수
	// PC나 NPC 배치 정보
public:
	Map()	// 10 * 10 평지맵 만들기
	{
		width = 10;
		height = 10;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);		
	}
	Map(int xSize, int ySize)	// xSize * ySize 평지맵 만들기
	{
		width = xSize;
		height = ySize;
		map = new TerrainType[width * height];
		memset(map, 0, sizeof(TerrainType) * width * height);
	}
	Map(const char* filename)	// filename에 있는 파일 읽어서 맵 만들기
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

	const Position GetStartPosition() { return startPosition; }	// 읽기 전용으로 startPosition 값 전달하기

private:
	int width = 10;
	int height = 10;

	TerrainType* map;	// 2차원 배열이지만 1차원으로 사용

	Position startPosition;


	/// <summary>
	/// 맵파일을 읽는 함수
	/// </summary>
	/// <param name="fileName">맵파일의 전체 경로</param>
	void ReadMapData(const char* fileName);
};

