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
	fopen_s(&fp, ".//Data//test.txt", "r");		// test.txt ������ �б� �������� ����

	char buffer[256];
	if (fp != nullptr)
	{
		while (fgets(buffer, 256, fp) != nullptr)
		{
			cout << buffer;
		}

		fclose(fp);								// ������� ������ �ݱ�
		fp = nullptr;
	}
}

void Test::Test_FileRead_fgetc()
{
	FILE* fp = nullptr;
	fopen_s(&fp, ".//Data//test.txt", "r");		// test.txt ������ �б� �������� ����

	if (fp != nullptr)
	{
		while (true)							// �ϴ� ���� ������ ������
		{
			char c = fgetc(fp);					// ���Ͽ��� ���� �ϳ��� ���� ������
			if (c == EOF)						// ������ ������ ������ ĵ���ϱ�
				break;
			cout << c;							// ���� �ȳ����� ���� ����ϱ�
		} 

		fclose(fp);								// ������� ������ �ݱ�
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
	Character c = Character("�ӽ�");
	c.Initialize();
	
	int i = 0;

	c.CleanUp();
}
