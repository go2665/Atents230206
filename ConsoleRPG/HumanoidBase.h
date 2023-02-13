#pragma once
#include "Status.h"

class HumanoidBase
{
public :
//	HumanoidBase() {};
//	~HumanoidBase() {};

	/// <summary>
	/// target�� �����ϴ� �Լ�
	/// </summary>
	/// <param name="target">���� ���</param>
	virtual void Attack(HumanoidBase& target);

	/// <summary>
	/// �������� �޴� �Լ�
	/// </summary>
	/// <param name="damage">���� ������ �� ������(������)</param>
	virtual void TakeDamage(int damage);
	
	/// <summary>
	/// �������ͽ� ����ϴ� �Լ�
	/// </summary>
	virtual void PrintStatus();

	inline const char* GetName() { return name; }
	//inline const int GetStringth() { return status.strength; }
	//inline const int GetDexterity() { return status.dexterity; }
	//inline const int GetIntelligence() { return status.intelligence; }
	//inline const int GetStatmina() { return status.stamina; }
	//inline const int GetWisdom() { return status.wisdom; }
	inline const int GetMaxHP() { return maxHP; }
	inline const int GetHP() { return hp; }

	//inline void SetStrength(int str) { status.strength = str; }
	//inline void SetDexterity(int dex) { status.dexterity= dex; }
	//inline void SetIntelligence(int intel) { status.intelligence = intel; }
	//inline void SetStamina(int stm) { status.stamina = stm; }
	//inline void SetWisdom(int wis) { status.wisdom = wis; }
	//inline void SetHP(int _hp) { hp = _hp; }
	//inline void SetMP(int _mp) { mp = _mp; }

	inline void AddStrength(int str) { 
		status.strength += str; 
		int i = 0;
	}
	inline void AddDexterity(int dex) { status.dexterity += dex; }
	inline void AddIntelligence(int intel) { status.intelligence += intel; }
	inline void AddStamina(int stm) { status.stamina += stm; }
	inline void AddWisdom(int wis) { status.wisdom += wis; }
	inline void AddHP(int _hp) { hp += _hp; }
	inline void AddMP(int _mp) { mp += _mp; }


protected:
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
	/// �������ͽ��� �������� �����ϴ� �Լ�
	/// </summary>
	virtual void SetRandomStatus();

};

