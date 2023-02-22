#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"

class Character : public Creature_Base
{
private:
	const int MAX_NAME_SIZE = 10;
	void InputNameProcess();

protected:
	RaceType race = HumanType;
	char skill1_Name[16];
	char skill2_Name[16];

	const int ExpCap = 100;
	int exp = 0;
	int maxExp = ExpCap;

	/// <summary>
	/// �� �÷��̾ �ִ� ��
	/// </summary>
	Map* pMap = nullptr;

	/// <summary>
	/// �� �÷��̾��� ���� ����(�̵���, ������ ���)
	/// </summary>
	PlayerState state = Move;

	/// <summary>
	/// �÷��̾��� ��ġ
	/// </summary>
	Position position;

public:
	inline void AddExp(int _exp) 
	{ 
		exp += _exp; 
		if (exp > maxExp)
		{
			exp -= maxExp;
			LevelUp();
		}
	}

	/// <summary>
	/// �ʱ�ȭ�� �Լ�. ���丮���� ����.
	/// </summary>
	virtual void Initialize() override;

	/// <summary>
	/// ������ �Լ�. Die���� ����
	/// </summary>
	virtual void CleanUp() override;

	/// <summary>
	/// pBattleTarget�� �����ϴ� �Լ�. �� ���� Ŭ�������� override �� ��
	/// </summary>
	virtual void Attack() override;

	/// <summary>
	/// �������ͽ� ����ϴ� �Լ�
	/// </summary>
	virtual void PrintStatus() override;

protected:
	/// <summary>
	/// �׾��� �� ����� �Լ�
	/// </summary>
	virtual void Die() override;

	virtual void NormalAttack();
	virtual void Skill01();
	virtual void Skill02();

	virtual void LevelUp();
	
};

