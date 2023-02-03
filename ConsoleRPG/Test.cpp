#include "Test.h"

void Test::TestRun()
{
	//Test_FileRead_fgets();
	//Test_FileRead_fgetc();
	//Test_MapRead();
	//Test_Position();
	Test_Character();
}

void Test::Test_FileRead_fgets()
{
	FILE* fp = nullptr;
	fopen_s(&fp, ".//Data//test.txt", "r");		// test.txt 파일을 읽기 전용으로 열기

	char buffer[256];
	if (fp != nullptr)
	{
		while (fgets(buffer, 256, fp) != nullptr)
		{
			cout << buffer;
		}

		fclose(fp);								// 열어놓은 파일을 닫기
		fp = nullptr;
	}
}

void Test::Test_FileRead_fgetc()
{
	FILE* fp = nullptr;
	fopen_s(&fp, ".//Data//test.txt", "r");		// test.txt 파일을 읽기 전용으로 열기

	if (fp != nullptr)
	{
		while (true)							// 일단 무한 루프를 돌리고
		{
			char c = fgetc(fp);					// 파일에서 글자 하나를 읽은 다음에
			if (c == EOF)						// 파일이 끝나면 루프를 캔슬하기
				break;
			cout << c;							// 끝이 안났으면 글자 출력하기
		} 

		fclose(fp);								// 열어놓은 파일을 닫기
		fp = nullptr;
	}
}

void Test::Test_MapRead()
{
	Map* pMap = new Map(".//Data//SampleMap.txt");

	delete pMap;
	pMap = nullptr;
}

void Test::Test_Position()
{
	Position a = Position();	// a(0,0)
	Position b = Position(1,2);	// b(1,2)
	Position c = Position(b);	// c(1,2)
	Position d = a;
	a = b + c;
	a = a * 3;
	a = a - b;
	a = a / 2;
	a += Position(3, 5);

	
	
	int i = 0;
}

void Test::Test_Character()
{
	Character c = Character("임시");
	c.Initialize();
	
	int i = 0;

	c.CleanUp();
}
