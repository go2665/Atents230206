#include "TerrainBase.h"
#include "Utils.h"

CreatureType TerrainBase::GetAttackMonster()
{
    int size = (int)monsters.size();            // 몬스터 총 갯수 가져오기
    int random = Utils::GetRandom(0, size);     // 0 ~ (몬스터수-1)만큼 랜덤으로 고르기

    auto iter = monsters.begin();               // monsters의 시작부터
    for (int i = 0; i < random; i++)            // 랜덤으로 고른 수만큼 증가
        iter++;    

    return *iter;       // 최종 iter의 실제값을 리턴
}
