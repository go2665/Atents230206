#include <iostream>
#include "GameManager.h"
#include "Test.h"

int main()
{
	GameManager* pManager = GameManager::GetInstance();
	pManager->Initialize();

	Test test;
	test.Run();

	pManager->CleanUp();

	return 0;
}