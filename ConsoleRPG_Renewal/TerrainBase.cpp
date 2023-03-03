#include "TerrainBase.h"
#include "Map.h"
#include "Utils.h"
#include "NamePicker.h"
#include "GameManager.h"

void TerrainBase::CleanUp()
{
    monsters.clear();
}

void TerrainBase::TerrainEnter()
{
    cout << endl << endl << endl << NamePicker::GetTerrainName(type) << " 지역에 들어갑니다 ------------------------" << endl;
    player = GameManager::GetInstance()->GetPlayer();
    PrintLandscape();
    OnEnter();
}

void TerrainBase::TerrainExit()
{
    OnExit();
    cout << NamePicker::GetTerrainName(type) << " 지역에서 나갑니다 ------------------------" << endl << endl << endl << endl;
}

void TerrainBase::TerrainSearch()
{
    cout << "탐색을 시작합니다. " << endl;
    OnSearch();
}

CreatureType TerrainBase::GetAttackMonster()
{
    int size = (int)monsters.size();            // 몬스터 총 갯수 가져오기
    int random = Utils::GetRandom(0, size);     // 0 ~ (몬스터수-1)만큼 랜덤으로 고르기

    auto iter = monsters.begin();               // monsters의 시작부터
    for (int i = 0; i < random; i++)            // 랜덤으로 고른 수만큼 증가
        iter++;    

    return *iter;       // 최종 iter의 실제값을 리턴
}

void TerrainBase::OnSearch()
{
    float eventRatio = Utils::GetRandom();
    if (eventRatio < 0.5f)
    {
        Event_Nothing();            // 50%
    }
    else if (eventRatio < 0.8f)
    {
        Event_Insomnia();           // 30%
    }
    else
    {
        Event_AmbushOfTiger();      // 20%
    }
}

void TerrainBase::RunAction()
{
    cout << "특수 행동을 실행하는데 (" << actionCost << ")만큼의 MP가 사용됩니다." << endl;
    if (player->GetMP() > actionCost)
    {
        cout << "액션을 수행합니다. " << endl;
        OnAction();
    }
    else
    {
        cout << "MP가 부족합니다." << endl;
    }
}

void TerrainBase::Event_Nothing()
{
    cout << "아무일도 일어나지 않았다." << endl;
}

void TerrainBase::Event_Insomnia()
{
    cout << "불면증으로 잠을 설쳤다." << endl;
    player->AddMP(-(player->GetMaxHP() >> 2));  // MP 25% 감소
}

void TerrainBase::Event_AmbushOfTiger()
{
    cout << "호랑이가 습격했다!" << endl;
    int dex = player->GetDexterity();
    // 15에서 100% 습격당함
    // 25에서 0% 습격당함

    bool result = Utils::CheckSavingThrow(15, 25, dex);
    if (!result)
    {
        cout << "호랑이의 습격은 성공이었다." << endl << "나는 엄청난 피해를 입었다." << endl;
        player->AddHP(-(player->GetMaxHP() >> 1));  // HP 최대치의 절반만큼 감소
    }
    else
    {
        cout << "나는 호랑이의 습격을 물리쳤다." << endl;
        cout << "35의 경험치를 얻었다." << endl;
        player->AddExp(35);
    }
}
