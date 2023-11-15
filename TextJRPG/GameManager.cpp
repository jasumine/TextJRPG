#include "GameManager.h"

GameManager::GameManager()
{
	shopInventory = Inventory("shop");
}

GameManager::GameManager(Player _player)
{
	player = _player;
}

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

void GameManager::GameStart()
{
	cout << "1. ���� 2. ���� 3. �ʵ� 4. ����" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "������ ���� �̱����Դϴ�..." << endl;
	}
	else if (input[0] == '2')
	{
		cout << "������ ���ϴ�." << endl;
		Shop();
	}
	else if (input[0] == '3')
	{
		cout << "�ʵ忡 ���ϴ�." << endl;
		isBattle = true;
		Battle();
	}
	else if (input[0] == '4')
	{
		cout << "������ �����մϴ�." << endl;
		isEnd = true;
		End();
	}
}

void GameManager::Shop()
{
	shopInventory.LoadInventory();
	cout << "�����ϰ���� �������� ��ȣ�� �Է��ϼ���." << endl;
	string num;
	cin >> num;
	player.SetItem(shopInventory.BuyItem(stoi(num)));
	cout << player.GetItem().GetName() << "�� �����߽��ϴ�." << endl;
}

void GameManager::Battle()
{
	while (isBattle)
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
}

bool GameManager::End()
{
	return isEnd;
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
		cout << " �������� ����մϴ�. " << endl << endl;
		player.UseItem();
	}
	else if (input[0] == '4')
	{
		PlayerRunAway();
	}
	CheckHp();
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
	CheckHp();
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

void GameManager::ItemSystem()
{
	cout << "����ǰ���� " << monster.GetItem().GetName() <<"�� ȹ���մϴ�." << endl;
	player.SetItem(monster.GetItem());

	cout << "player�� item ��Ȳ : " << player.GetItem().GetName();
}




bool GameManager::CheckHp()
{
	if (player.Death())
	{
		cout << "�÷��̾��� Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "GAME OVER" << endl;

		isBattle = false;
		return false;
	}
	else if (monster.Death())
	{
		cout << "������ Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "GAME WIN" << endl;
		ItemSystem();
		player.UseItem();
		isBattle = false;
		return false;
	}
	else if (isRunAway)
	{
		cout << "Player RunAway" << endl;

		isBattle = false;
		return false;
	}
	else
		return true;

}