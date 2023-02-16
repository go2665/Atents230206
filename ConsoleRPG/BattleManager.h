#pragma once
#include "Character.h"
#include "Monster.h"

class BattleManager
{
private:
	/// <summary>
	/// �÷��̾� ĳ����
	/// </summary>
	Character* pPlayer = nullptr;

	/// <summary>
	/// ������ �� �� ����
	/// </summary>
	Monster* pEnemy = nullptr;		// ������ ���ٸ� ȿ���� ����. �̷��� ���� �ϴ� ����

	/// <summary>
	/// ���� ���� �÷��̾�� ���͸� ������ �迭
	/// �׼� 0�� ĳ���Ͱ� �� �ϸ��� ���� �����Ѵ�.(��ø�� ���� ĳ���Ͱ� 0��)
	/// </summary>
	Creature_Base* battlers[2] = { nullptr, nullptr };

	int turn = 0;

public:
	/// <summary>
	/// �÷��̾� ������ �Լ�(1ȸ��. ���Ӵ� �ѹ��� ���� ����)
	/// </summary>
	/// <param name="_player">�÷��̾�</param>
	/// <returns>true�� �÷��̾� ���� ����. false�� ����(����� �߻��ϸ� �ȵ�).</returns>
	inline bool SetPlayer(Character* _player) 
	{
		if (pPlayer == nullptr)	// �÷��̾ ������ �ȵǾ��� ���� 
		{
			pPlayer = _player;	// �÷��̾� ����
			return true;
		}
		return false;	// ����� ���� �ȵ�!!!
	};

	/// <summary>
	/// ���� ������ Ȯ���ϴ� �Լ�
	/// battlers�� ������ ���۵Ǹ� null�� �ƴϰ� �ǰ� ������ ������ null�� �ǹǷ� �� �� null�̸� ������ ���� ���̴�.
	/// </summary>
	/// <returns>true�� ������ ���� ����. false�� ���� ���� ����.</returns>
	inline bool IsBattleEnd() { return ((battlers[0] == nullptr) && (battlers[1] == nullptr));  };
	
	// !IsBattleEnd()
	// ((battlers[0] != nullptr) || (battlers[1] != nullptr))


	/// <summary>
	/// ���� ���ۿ� �Լ�. ����Ǹ� ���� ����.
	/// </summary>
	/// <param name="pOpponent">��</param>
	void Start(Monster* pOpponent);

	/// <summary>
	/// �� �ϸ��� ����Ǵ� �Լ�
	/// </summary>
	void TurnLoop();

	/// <summary>
	/// ������ ����Ǹ� ����Ǵ� �Լ�
	/// </summary>
	void End();

};

