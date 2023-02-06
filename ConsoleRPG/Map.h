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
		terrainMap = new TerrainType[width * height];
		memset(terrainMap, 0, sizeof(TerrainType) * width * height);		
	}
	Map(int xSize, int ySize)	// xSize * ySize 평지맵 만들기
	{
		width = xSize;
		height = ySize;
		terrainMap = new TerrainType[width * height];
		memset(terrainMap, 0, sizeof(TerrainType) * width * height);
	}
	Map(const char* filename)	// filename에 있는 파일 읽어서 맵 만들기
	{
		ReadMapData(filename);
	}

	~Map()
	{
		if (terrainMap != nullptr)		// 이전에 로딩된 맵이 있으면
		{
			delete terrainMap;			// 삭제
			terrainMap = nullptr;
		}
	}

	const Position GetStartPosition() { return startPosition; }	// 읽기 전용으로 startPosition 값 전달하기

	/// <summary>
	/// 파라메터로 받은 위치가 맵 안인지 아닌지 체크하는 함수
	/// </summary>
	/// <param name="pos">확인할 위치</param>
	/// <returns>true면 맵 안, false면 맵 밖</returns>
	bool IsValidPosition(const Position& pos) const;	// 함수 뒤에 const를 붙여서 맴버 변수가 변경되지 않게 한다.

	/// <summary>
	/// 파라메터로 받은 위치의 풍경을 출력하는 함수
	/// </summary>
	/// <param name="pos">풍경을 출력할 함수</param>
	void PrintLandscape(const Position& pos) const;

private:
	int width = 10;
	int height = 10;

	TerrainType* terrainMap;	// 2차원 배열이지만 1차원으로 사용

	Position startPosition;


	/// <summary>
	/// 맵파일을 읽는 함수
	/// </summary>
	/// <param name="fileName">맵파일의 전체 경로</param>
	void ReadMapData(const char* fileName);

	/// <summary>
	/// 지형 배열 인덱스 값을 그리드 좌표로 변경해주는 함수
	/// </summary>
	/// <param name="index">TerrainType 배열의 인덱스</param>
	/// <returns>그리드 좌표로 변경된 위치</returns>
	Position IndexToGridPosition(const int index) const;

	/// <summary>
	/// 그리드 좌표를 지형 배열 인덱스 값으로 변경해주는 함수
	/// </summary>
	/// <param name="pos">변경할 그리드 위치</param>
	/// <returns>변경된 인덱스값</returns>
	int GridPositionToIndex(const Position& pos) const;
};

