#pragma once
#include "Creature_Base.h"

class BattleManager
{
private:	
	/// <summary>
	/// ���� ���� �÷��̾�� ���͸� ������ �迭
	/// �׼� 0�� ĳ���Ͱ� �� �ϸ��� ���� �����Ѵ�.(��ø�� ���� ĳ���Ͱ� 0��)
	/// </summary>
	Creature_Base* battlers[2] = { nullptr, nullptr };

	/// <summary>
	/// ����� �� ��
	/// </summary>
	int turn = 0;

public:
	
	/// <summary>
	/// �ο� ĳ���� ����
	/// </summary>
	/// <param name="battler1">�ο� ��� 1</param>
	/// <param name="battler2">�ο� ��� 2</param>
	void SetBattlers(Creature_Base* battler1, Creature_Base* battler2);

	/// <summary>
	/// ���� ������ Ȯ���ϴ� �Լ�
	/// battlers�� ������ ���۵Ǹ� null�� �ƴϰ� �ǰ� ������ ������ null�� �ǹǷ� �� �� null�̸� ������ ���� ���̴�.
	/// </summary>
	/// <returns>true�� ������ ���� ����. false�� ���� ���� ����.</returns>
	inline bool IsBattleEnd() 
	{ 
		return ((battlers[0] != nullptr && !battlers[0]->IsAlive()) || (battlers[1] != nullptr && !battlers[1]->IsAlive())); 
	};
	
	// !IsBattleEnd()
	// ((battlers[0] != nullptr) || (battlers[1] != nullptr))


	/// <summary>
	/// ���� ���ۿ� �Լ�. ����Ǹ� ���� ����.
	/// </summary>
	void BattleStart();

	/// <summary>
	/// �� �ϸ��� ����Ǵ� �Լ�
	/// </summary>
	void BattleTurnLoop();

	/// <summary>
	/// ������ ����Ǹ� ����Ǵ� �Լ�
	/// </summary>
	void BattleEnd();

};

