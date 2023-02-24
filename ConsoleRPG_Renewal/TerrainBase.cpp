#include "TerrainBase.h"
#include "Utils.h"
#include "NamePicker.h"

void TerrainBase::CleanUp()
{
    monsters.clear();
}

void TerrainBase::TerrainEnter()
{
    cout << endl << endl << endl << NamePicker::GetTerrainName(type) << " ������ ���ϴ� ------------------------" << endl;
    PrintLandscape();
    OnEnter();
}

void TerrainBase::TerrainExit()
{
    OnExit();
    cout << NamePicker::GetTerrainName(type) << " �������� �����ϴ� ------------------------" << endl << endl << endl << endl;
}

void TerrainBase::TerrainSearch()
{
    cout << "Ž���� �����մϴ�. " << endl;
    OnSearch();
}

CreatureType TerrainBase::GetAttackMonster()
{
    int size = (int)monsters.size();            // ���� �� ���� ��������
    int random = Utils::GetRandom(0, size);     // 0 ~ (���ͼ�-1)��ŭ �������� ����

    auto iter = monsters.begin();               // monsters�� ���ۺ���
    for (int i = 0; i < random; i++)            // �������� �� ����ŭ ����
        iter++;    

    return *iter;       // ���� iter�� �������� ����
}
