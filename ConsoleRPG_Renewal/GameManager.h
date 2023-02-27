#pragma once
#include <stdlib.h>
// �̱������� �����

class GameManager
{
private:
	// �����ڿ� �Ҹ��ڸ� private���� �����ؼ� ������� ����ų� ���� �� ���� �����
	GameManager() {};
	GameManager(const GameManager& other) {};
	~GameManager() {};

	// �̱��� �ν��Ͻ��� ������ static���� �����
	static GameManager* instance;

	// �ν��Ͻ� ������ �Լ�. �Լ������Ϳ� �ֱ� ���� static���� ����
	static void Destroy()
	{
		delete instance;		// �����
		instance = nullptr;		// null�� �ʱ�ȭ
	}

public:
	// �ν��Ͻ��� ������ �Լ� �����(�б� ����)
	static GameManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
			atexit(Destroy);	// ����ÿ� Destroy �Լ� �����ϵ��� ����
		}
		return instance;
	}

	// �׽�Ʈ�� �Լ�
	void Test();
};