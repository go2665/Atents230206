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
    cout << endl << endl << endl << NamePicker::GetTerrainName(type) << " ������ ���ϴ� ------------------------" << endl;
    player = GameManager::GetInstance()->GetPlayer();
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
    cout << "Ư�� �ൿ�� �����ϴµ� (" << actionCost << ")��ŭ�� MP�� ���˴ϴ�." << endl;
    if (player->GetMP() > actionCost)
    {
        cout << "�׼��� �����մϴ�. " << endl;
        OnAction();
    }
    else
    {
        cout << "MP�� �����մϴ�." << endl;
    }
}

void TerrainBase::Event_Nothing()
{
    cout << "�ƹ��ϵ� �Ͼ�� �ʾҴ�." << endl;
}

void TerrainBase::Event_Insomnia()
{
    cout << "�Ҹ������� ���� ���ƴ�." << endl;
    player->AddMP(-(player->GetMaxHP() >> 2));  // MP 25% ����
}

void TerrainBase::Event_AmbushOfTiger()
{
    cout << "ȣ���̰� �����ߴ�!" << endl;
    int dex = player->GetDexterity();
    // 15���� 100% ���ݴ���
    // 25���� 0% ���ݴ���

    bool result = Utils::CheckSavingThrow(15, 25, dex);
    if (!result)
    {
        cout << "ȣ������ ������ �����̾���." << endl << "���� ��û�� ���ظ� �Ծ���." << endl;
        player->AddHP(-(player->GetMaxHP() >> 1));  // HP �ִ�ġ�� ���ݸ�ŭ ����
    }
    else
    {
        cout << "���� ȣ������ ������ �����ƴ�." << endl;
        cout << "35�� ����ġ�� �����." << endl;
        player->AddExp(35);
    }
}
