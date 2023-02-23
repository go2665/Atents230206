#include "TerrainBase.h"
#include "Utils.h"

CreatureType TerrainBase::GetAttackMonster()
{
    int size = (int)monsters.size();            // ���� �� ���� ��������
    int random = Utils::GetRandom(0, size);     // 0 ~ (���ͼ�-1)��ŭ �������� ����

    auto iter = monsters.begin();               // monsters�� ���ۺ���
    for (int i = 0; i < random; i++)            // �������� �� ����ŭ ����
        iter++;    

    return *iter;       // ���� iter�� �������� ����
}
