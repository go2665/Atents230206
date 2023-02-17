#pragma once
#include <list>
#include "Status.h"
#include "Enums.h"
#include "BuffBase.h"

class Creature_Base
{
public:

protected:
	const int HP_Multiplier = 10;
	const int MP_Multiplier = 10;

	/// <summary>
	/// ĳ������ Ÿ��(���� �÷��̾�, ���� ����)
	/// </summary>
	CreatureType type = None;

	/// <summary>
	/// �÷��̾��� �̸�(�ִ� 32��. �ѱ��� 16��)
	/// </summary>
	char name[32];

	/// <summary>
	/// ����
	/// </summary>
	int level = 1;

	/// <summary>
	/// �������ͽ�
	/// </summary>
	Status status;

	/// <summary>
	/// ���� HP
	/// </summary>
	int hp = 1;

	/// <summary>
	/// �ִ� HP
	/// </summary>
	int maxHP = 1;

	/// <summary>
	/// ���� MP
	/// </summary>
	int mp = 1;

	/// <summary>
	/// �ִ� MP
	/// </summary>
	int maxMP = 1;

	/// <summary>
	/// ���� ���
	/// </summary>
	Creature_Base* pBattleTarget = nullptr;

	/// <summary>
	/// ���� ����. true�� ����ְ� false�� �׾��ִ�.
	/// </summary>
	bool isAlive = true;

	/// <summary>
	/// ���� �� ���� ǥ���ϴ� ����
	/// </summary>
	bool isBattle = false;

	/// <summary>
	/// ���� ���
	/// </summary>
	std::list<BuffBase*> buffList;

public:
	/// <summary>
	/// �ʱ�ȭ�� �Լ�. ���丮���� ����.
	/// </summary>
	virtual void Initialize() {};

	/// <summary>
	/// ������ �Լ�. Die���� ����
	/// </summary>
	virtual void CleanUp();

	/// <summary>
	/// �������� ������ �Լ�. �� ����/�� �ൿ/�� ���� ó�� .
	/// </summary>
	void Loop();

	/// <summary>
	/// pBattleTarget�� �����ϴ� �Լ�. �� ���� Ŭ�������� override �� ��
	/// </summary>
	virtual void Attack();

	/// <summary>
	/// �������� �޾� ó���ϴ� �Լ�. �� ���� Ŭ�������� override �� ��
	/// </summary>
	virtual void Defence(int damage);

	/// <summary>
	/// �������ͽ� ����ϴ� �Լ�
	/// </summary>
	virtual void PrintStatus();

	/// <summary>
	/// ������ ���۵Ǹ� ����� �Լ�
	/// </summary>
	/// <param name="pTarget">���� ���</param>
	virtual void OnBattleStart(Creature_Base* pTarget);
	
	/// <summary>
	/// ������ ������ ����� �Լ�
	/// </summary>
	virtual void OnBattleEnd();

protected:
	/// <summary>
	/// ���� �߰��ϴ� �Լ�
	/// </summary>
	/// <param name="target">������ ���� ���</param>
	/// <param name="pBuff">������ �ּ�</param>
	void AddBuff(Creature_Base& target, BuffBase* pBuff);

	/// <summary>
	/// Loop ���۵� �� ����� �Լ�.
	/// </summary>
	virtual void OnTurnStart() {};

	/// <summary>
	/// Loop �ȿ��� �ش� ũ��ó�� �� �ϸ��� �ϴ� �ൿ�� ��ϵ� �Լ�.
	/// </summary>
	virtual void OnTurnAction() {};

	/// <summary>
	/// Loop�� ���� �� ����� �Լ�
	/// </summary>
	virtual void OnTurnEnd() {};

	/// <summary>
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus();

	/// <summary>
	/// �׾��� �� ����� �Լ�
	/// </summary>
	virtual void Die();

public :
	/// <summary>
	/// ���� ����ִ��� Ȯ���ϴ� ����
	/// </summary>
	/// <returns>��������� true. �׾����� false</returns>
	inline bool IsAlive() { return isAlive; }

	/// <summary>
	/// ���� ���� ������ Ȯ���ϴ� ����
	/// </summary>
	/// <returns>���� ���̸� true. �������� �ƴϸ� false</returns>
	inline bool IsBattle() { return isBattle; }

	// ���� Getter �Լ�
	inline CreatureType GetType() { return type; }
	inline const char* GetName() { return name; }
	inline const int GetStringth() { return status.strength; }
	inline const int GetDexterity() { return status.dexterity; }
	inline const int GetIntelligence() { return status.intelligence; }
	inline const int GetStatmina() { return status.stamina; }
	inline const int GetWisdom() { return status.wisdom; }
	inline const int GetMaxHP() { return maxHP; }
	inline const int GetHP() { return hp; }

	// ������ ��ȭ�� �Լ�
	inline void AddStrength(int str) { status.strength += str; }
	inline void AddDexterity(int dex) { status.dexterity += dex; }
	inline void AddIntelligence(int intel) { status.intelligence += intel; }
	inline void AddStamina(int stm) { status.stamina += stm; }
	inline void AddWisdom(int wis) { status.wisdom += wis; }
	inline void AddHP(int _hp)	// ��� HP������ �� �Լ��� ���ؼ� ó���� ��
	{ 
		hp += _hp; 
		if (hp > maxHP)
			hp = maxHP;
		if (hp < 0)
		{
			Die();
			hp = 0;
		}
	}
	inline void AddMP(int _mp)	// ��� HP������ �� �Լ��� ���ؼ� ó���� ��
	{ 
		mp += _mp; 
		if (mp > maxHP)
			mp = maxHP;
		if (mp < 0)
			mp = 0;
	}
};

