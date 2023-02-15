#include <list>
#include "Test.h"
#include "Monster_Orc.h"
#include "Test_Orc.h"
#include "Monster_Wolf.h"

void Test::TestRun()
{
	Test_MonsterDie();
	//Test_MonsterBattle();
	//Test_Buff3();
	//Test_Buff2();
	//Test_Buff();
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

void Test::Test_MonsterDie()
{
	Monster_Orc* pOrc = new Monster_Orc();
	Monster_Wolf* pWolf = new Monster_Wolf();

	pOrc->OnTurnStart();
	pWolf->OnTurnStart();

	pOrc->AddHP(-(pOrc->GetHP() - 1));
	pWolf->Attack(*pOrc);

	pOrc->OnTurnEnd();
	pWolf->OnTurnEnd();

	delete pOrc;
	delete pWolf;
	pOrc = nullptr;
	pWolf = nullptr;
}

void Test::Test_MonsterBattle()
{
	Utils::SetRandomSeedByTime();

	Monster_Orc* pOrc = new Monster_Orc();
	pOrc->PrintStatus();
	Monster_Wolf* pWolf = new Monster_Wolf();
	pWolf->PrintStatus();

	pOrc->SetBattleTarget(pWolf);
	pWolf->SetBattleTarget(pOrc);

	int counter = 0;
	while (pOrc->GetHP() > 0 && pWolf->GetHP() > 0 && counter < 100)
	{
		counter++;

		cout << endl << "----------" << counter << "턴 시작----------" << endl;

		pOrc->OnTurnStart();
		pWolf->OnTurnStart();

		pOrc->Attack(*pWolf);
		pOrc->PrintStatus();
		pWolf->PrintStatus();

		if (pWolf->GetHP() <= 0)
		{
			break;
		}

		pWolf->Attack(*pOrc);
		pOrc->PrintStatus();
		pWolf->PrintStatus();

		pOrc->OnTurnEnd();
		pWolf->OnTurnEnd();
		
	}

	if (counter > 99)
	{
		cout << "무승부 " << endl;
	}
	else if (pOrc->GetHP() > 0)
	{
		cout << "오크의 승리!" << endl;
	}
	else if (pWolf->GetHP() > 0)
	{
		cout << "늑대의 승리!" << endl;
	}




	delete pOrc;
	delete pWolf;
	pOrc = nullptr;
	pWolf = nullptr;
}

void Test::Test_Buff3()
{
	Test_Orc* pOrc1 = new Test_Orc();
	Test_Orc* pOrc2 = new Test_Orc();
	
	pOrc2->PrintStatus();

	pOrc1->UseBuff(*pOrc2);

	pOrc2->PrintStatus();

	delete pOrc1;
	delete pOrc2;
	pOrc1 = nullptr;
	pOrc2 = nullptr;
}

void Test::Test_Buff2()
{
	Test_Orc* pOrc1 = new Test_Orc();
	Monster* pOrc2 = new Monster();

	pOrc1->PrintStatus();	// 힘 10

	pOrc1->OnTurnStart();
	pOrc1->Attack(*pOrc2);
	pOrc1->PrintStatus();	// 힘 15
	pOrc1->OnTurnEnd();		// 1 : 2턴 남음

	pOrc1->OnTurnStart();
	pOrc1->Attack(*pOrc2);	
	pOrc1->PrintStatus();	// 힘 20
	pOrc1->OnTurnEnd();		// 1 : 1턴 남음. 2 : 2턴 남음

	pOrc1->OnTurnStart();
	pOrc1->Attack(*pOrc2);
	pOrc1->PrintStatus();	// 힘 25
	pOrc1->OnTurnEnd();		// 1 : 종료. 2: 1턴 남음. 3 : 2턴 남음

	pOrc1->PrintStatus();	// 힘 20

	delete pOrc1;
	delete pOrc2;
	pOrc1 = nullptr;
	pOrc2 = nullptr;
}

void Test::Test_Buff()
{
	Monster_Orc* pOrc1 = new Monster_Orc();
	//Monster_Orc* pOrc2 = new Monster_Orc();
	Monster* pOrc2 = new Monster();
	int counter = 50;

	pOrc1->PrintStatus();
	pOrc2->PrintStatus();
	while (pOrc1->GetHP() > 0 && pOrc2->GetHP() > 0 && counter > 0)
	{
		pOrc1->OnTurnStart();
		pOrc2->OnTurnStart();

		pOrc1->Attack(*pOrc2);
		pOrc2->Attack(*pOrc1);

		pOrc1->PrintStatus();
		pOrc2->PrintStatus();

		pOrc1->OnTurnEnd();
		pOrc2->OnTurnEnd();
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
	memset(counts, 0, sizeof(int) * 11);	// counts를 0으로 초기화

	for (int i = 0; i < 2000000; i++)
	{
		int num = Utils::GetRandom(10, 19);		// 총 10개 범위
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
	cout << "에러 : " << counts[10] << endl;
	sum += counts[10];
	cout << "합계 : " << sum << endl;


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

	cout << "For 사용하기" << endl;
	for (list<int>::iterator iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	cout << "For 사용하기2" << endl;
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	testList.pop_back();
	testList.pop_front();
	cout << "For 사용하기3" << endl;	// 50 40 10 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	myIter = testList.begin();
	myIter++;
	myIter++;
	testList.erase(myIter);
	cout << "For 사용하기4" << endl;	// 50 40 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	myIter = testList.begin();
	myIter++;
	testList.insert(myIter, 100);

	cout << "For 사용하기5" << endl;	// 50 100 40 20
	for (auto iter = testList.begin(); iter != testList.end(); iter++)
	{
		cout << *iter << endl;
	}

	list<int>::iterator findIter = find(testList.begin(), testList.end(), 140);
	if (findIter != testList.end())
	{
		cout << *findIter << "를 찾았다." << endl;
	}
	else
	{
		cout << "원하는 데이터를 찾을 수 없다." << endl;
	}
}
