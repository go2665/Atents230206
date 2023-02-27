#pragma once
#include <stdlib.h>
// 싱글톤으로 만들기

class GameManager
{
private:
	// 생성자와 소멸자를 private으로 설정해서 마음대로 만들거나 지울 수 없게 만들기
	GameManager() {};
	GameManager(const GameManager& other) {};
	~GameManager() {};

	// 싱글톤 인스턴스를 저장할 static변수 만들기
	static GameManager* instance;

	// 인스턴스 삭제용 함수. 함수포인터에 넣기 위해 static으로 설정
	static void Destroy()
	{
		delete instance;		// 지우고
		instance = nullptr;		// null로 초기화
	}

public:
	// 인스턴스에 접근할 함수 만들기(읽기 전용)
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
			atexit(Destroy);	// 종료시에 Destroy 함수 실행하도록 설정
		}
		return instance;
	}

	// 테스트용 함수
	void Test();
};