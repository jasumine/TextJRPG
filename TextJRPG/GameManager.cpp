#include "GameManager.h"

GameManager::GameManager(Player _player, Player _monster)
{
	player = _player;
	monster = _monster;

}

GameManager::~GameManager()
{
}

void GameManager::CoutHP()
{
	cout<< "�÷��̾��� HP : " << player.GetHp() << endl
		<< "������ HP : " << monster.GetHp() << endl;
}

void GameManager::Battle()
{
	if (playerTurn)
	{
		PlayerTurn();
	}
	else
	{
		MonsterTurn();
	}
}

void GameManager::PlayerTurn()
{
	cout << "�÷��̾��� �����Դϴ�." << endl;
	CoutHP();

	input.clear();
	cout<< "1. ����  2. ��� 3. ������ 4. ��������" << endl;
	cin >> input;

	if (input[0] == '1')
	{
		cout << "���Ϳ��� " << player.GetAtk() << "��ŭ ������ �մϴ�." << endl << endl;
		monster.SetHp(-player.GetAtk());
	}
	else if (input[0] == '2')
	{
		cout << "�� �մϴ�." << endl << endl;
		isDef = true;
	}
	else if (input[0] == '3')
	{
		cout << " �������� �����ϴ�... " << endl << endl;
	}
	else if (input[0] == '4')
	{
		PlayerRunAway();
	}
	
	playerTurn = false;
}

void GameManager::MonsterTurn()
{
	cout << "������ �����Դϴ�." << endl;
	CoutHP();
	cout << "�÷��̾�� " << monster.GetAtk() << "��ŭ ������ �մϴ�." << endl << endl;

	if (isDef)
	{
		cout << "�÷��̾ ����� ��ŭ �����Ǿ� �������� ���ϴ�.";
		int atk = CompareAtknDef(monster.GetAtk(), player.GetDef());
		player.SetHp(-atk);
		isDef = false;
	}
	else
	{
		player.SetHp(-monster.GetAtk());
	}
	playerTurn = true;
}

void GameManager::PlayerRunAway()
{
	if (player.GetLevel() >= monster.GetLevel())
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(1, 2);

		if (dist(gen) == 2)
		{
			cout << "����ġ�⿡ �����߽��ϴ�!" << endl;
			isRunAway = true;
		}
		else
		{
			cout << "����ġ�⿡ �����߽��ϴ�..." << endl;
			isRunAway = false;
		}
	}
	else
	{
		cout << "������ ������ ���� ����ĥ �� �����ϴ�..." << endl;
		isRunAway = false;
	}
}

int GameManager::CompareAtknDef(int atk, int def)
{
	int total;
	if (atk > def)
	{
		total = atk - def;
	}
	else if (atk <= def)
	{
		total = 0;
	}
	return total;
}




bool GameManager::CheckHp()
{
	if (player.Death())
	{
		cout << "�÷��̾��� Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "GAME OVER" << endl;
		return false;
	}
	else if (monster.Death())
	{
		cout << "������ Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "GAME WIN" << endl;
		return false;
	}
	else if (isRunAway)
	{
		cout << "Player RunAway" << endl;
		return false;
	}
	else
		return true;

}