#include <list>
#include "Test.h"
#include "Monster_Orc.h"

void Test::TestRun()
{
	Test_Buff();
	//Test_RandomNames();
	//Test_FileRead_fgets();
	//Test_FileRead_fgetc();
	//Test_MapRead();
	//Test_Position();
	//Test_Character();
	//Test_Ork();
	//Test_RandomRange();
	//Test_List();
}

void Test::Test_Buff()
{
	Monster_Orc* pOrc1 = new Monster_Orc();
	Monster_Orc* pOrc2 = new Monster_Orc();
	int counter = 50;

	pOrc1->PrintStatus();
	pOrc2->PrintStatus();
	while (pOrc1->GetHP() > 0 && pOrc2->GetHP() > 0 && counter > 0)
	{
		pOrc1->Attack(*pOrc2);
		pOrc2->Attack(*pOrc1);
		pOrc1->PrintStatus();
		pOrc2->PrintStatus();
		counter--;
	}
	

	delete pOrc1;
	pOrc1 = nullptr;
	delete pOrc2;
	pOrc2 = nullptr;
}

void Test::Test_RandomNames()
{
	for (int i = 0; i < 100; i++)
	{
		Monster_Orc* pOrc = new Monster_Orc();
		pOrc->PrintStatus();

		delete pOrc;
		pOrc = nullptr;
	}
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
	
	c.Loop();

	c.CleanUp();
}

void Test::Test_Ork()
{
	Monster_Orc* orc1 = new Monster_Orc();
	orc1->PrintStatus();
	/*Monster_Orc* orc2 = new Monster_Orc();
	orc2->PrintStatus();*/

	//for (int i = 0; i < 100; i++)
	//{
	//	orc1->Attack(*orc2);
	//	cout << endl;
	//}


	//delete orc2;
	//orc2 = nullptr;
	delete orc1;
	orc1 = nullptr;
}
void Test::Test_RandomRange()
{
	Utils::SetRandomSeedByTime();
	int counts[11];
	memset(counts, 0, sizeof(int) * 11);	// counts�� 0���� �ʱ�ȭ

	for (int i = 0; i < 2000000; i++)
	{
		int num = Utils::GetRandom(10, 19);		// �� 10�� ����
		//cout << "Random Number(10~19) : " << num << endl;
		if (num < 10 || 20 < num)
		{
			cout << "Random Number(10~20)(ERROR) : " << num << endl;
			counts[10]++;
		}
		else
		{
			counts[num - 10]++;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 10 << " : " << counts[i] << endl;
		sum += counts[i];
	}
	cout << "���� : " << counts[10] << endl;
	sum += counts[10];
	cout << "�հ� : " << sum << endl;


}

void Test::Test_List()
{
	list<int> testList;

	testList.push_back(10);
	testList.push_back(20);
	testList.push_back(30);
	testList.push_front(40);
	testList.push_front(50);
	testList.push_front(60);

	list<int>::iterator myIter = testList.begin();
	cout << *myIter << endl;
	myIter++;
	cout << *myIter << endl;
	myIter = testList.end();
	myIter--;
	cout << *myIter << endl;

	list<int>::reverse_iterator myRIter = testList.rbegin();
	cout << *myIter << endl;

	cout << "For ����ϱ�" << endl;
	for (list<int>::iterator iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "For ����ϱ�2" << endl;
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	testList.pop_back();
	testList.pop_front();
	cout << "For ����ϱ�3" << endl;	// 50 40 10 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	myIter = testList.begin();
	myIter++;
	myIter++;
	testList.erase(myIter);
	cout << "For ����ϱ�4" << endl;	// 50 40 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	myIter = testList.begin();
	myIter++;
	testList.insert(myIter, 100);

	cout << "For ����ϱ�5" << endl;	// 50 100 40 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	list<int>::iterator findIter = find(testList.begin(), testList.end(), 140);
	if (findIter != testList.end())
	{
		cout << *findIter << "�� ã�Ҵ�." << endl;
	}
	else
	{
		cout << "���ϴ� �����͸� ã�� �� ����." << endl;
	}
}
