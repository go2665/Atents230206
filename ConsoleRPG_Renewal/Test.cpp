#include "Test.h"
#include "Enums.h"
#include "CreatureFactory.h"
#include "Creature_Base.h"
#include "Monster_Orc.h"
#include "BattleManager.h"

void Test::Run()
{
	cout << "Test 시작" << endl;
	Test_CreatureFactory();
}

void Test::Test_CreatureFactory()
{
	cout << "테스트 - CreatureFactory" << endl;
	Creature_Base* pOrc = CreatureFactory::MakeCreature(Orc);
	Creature_Base* pWolf = CreatureFactory::MakeCreature(Wolf);

	BattleManager bm;
	bm.SetBattlers(pOrc, pWolf);
	bm.BattleStart();

	CreatureFactory::DestroyCreature(pOrc);
	CreatureFactory::DestroyCreature(pWolf);
}
