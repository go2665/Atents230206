#pragma once
#include <iostream>
#include "Map.h"
#include "Position.h"
#include "Character.h"

using namespace std;

class Test
{
public :
	void TestRun();

private :
	void Test_FileRead_fgets();
	void Test_FileRead_fgetc();

	void Test_MapRead();

	// 2/3
	void Test_Position();
	void Test_Character();

};

