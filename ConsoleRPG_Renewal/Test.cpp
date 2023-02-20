#include "Test.h"
#include "Enums.h"
#include "CreatureFactory.h"
#include "Creature_Base.h"
#include "Monster_Orc.h"
#include "BattleManager.h"
#include "Utils.h"

void Test::Run()
{
	cout << "Test 시작" << endl;
	Test_CreatureFactory();
}

void Test::Test_CreatureFactory()
{
	cout << "테스트 - CreatureFactory" << endl;
	Utils::SetRandomSeedByTime();

	Creature_Base* pOrc = CreatureFactory::MakeCreature(Orc);
	Creature_Base* pWolf = CreatureFactory::MakeCreature(Wolf);
	pOrc->PrintStatus();
	pWolf->PrintStatus();

	BattleManager bm;
	bm.SetBattlers(pOrc, pWolf);
	bm.BattleStart();

	CreatureFactory::DestroyCreature(pOrc);
	CreatureFactory::DestroyCreature(pWolf);
}
