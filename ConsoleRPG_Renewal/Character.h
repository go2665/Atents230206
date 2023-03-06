#pragma once
#include "Creature_Base.h"
#include "Position.h"
#include "Map.h"
#include "SaveData.h"

class Character : public Creature_Base
{
private:
	/// <summary>
	/// �̸� �ִ� ����
	/// </summary>
	const int MAX_NAME_SIZE = 10;

	/// <summary>
	/// ���� �Է� ó����
	/// </summary>
	const int INPUT_EXIT = -1;

	/// <summary>
	/// �Է� ���� ǥ�ÿ�
	/// </summary>
	const int INPUT_FAIL = -999;
	
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
	/// �� �÷��̾��� ���� ����(�̵���, �ൿ�� ���)
	/// </summary>
	PlayerState state = Action;

	/// <summary>
	/// �÷��̾��� ��ġ. �⺻������ (-1,-1)
	/// </summary>
	Position position = Position::MinusOne;

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
	virtual void Initialize(SaveData* data = nullptr) override;

	/// <summary>
	/// �÷��̾��� �ൿ�� ó���� ��
	/// </summary>
	void Loop();

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

	/// <summary>
	/// ĳ������ ��ġ�� �����ִ� �Լ�
	/// </summary>
	/// <returns>ĳ������ ��ġ�� ���� ����</returns>
	const Position& GetPosition() { return position; }

	/// <summary>
	/// ���� �޴����� ������ �� �����ϱ�
	/// </summary>
	void StartMap();

	inline const RaceType GetRace() { return race; }
	inline const int GetExp() { return exp; }
	inline const int GetMaxExp() { return maxExp; }

	void LoadData(SaveData& data);

protected:
	/// <summary>
	/// �׾��� �� ����� �Լ�
	/// </summary>
	virtual void Die() override;

	virtual void NormalAttack();
	virtual void Skill01();
	virtual void Skill02();

	virtual void LevelUp();

	/// <summary>
	/// position�� Set �Լ�
	/// </summary>
	/// <param name="newPos">position�� ������ �� ��</param>
	void SetPosition(const Position& newPos);

	/// <summary>
	/// �ڽ��� ��ġ�� ����ϴ� �Լ�
	/// </summary>
	void PrintPosition();

	/// <summary>
	/// �÷��̾��� �׼� ó�� �Լ�
	/// </summary>
	int InputProcess_Action();

	/// <summary>
	/// �÷��̾��� �̵� ó�� �Լ�
	/// </summary>
	int InputProcess_Move();	

	/// <summary>
	/// �������ͽ��� ������ ������ �ٽ� ������ �Լ�
	/// </summary>
	void StatusReroll();
};

