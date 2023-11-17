#include "GameManager.h"

GameManager::GameManager()
{
	
}

GameManager::GameManager(Player _player)
{
	player = _player;
}

GameManager::~GameManager()
{
}

void GameManager::CoutHP()
{
	cout<< "�÷��̾��� HP : " << player.GetCurHp() << endl
		<< monster.GetName()<< "�� HP : " << monster.GetCurHp() << endl;
}

void GameManager::GameStart()
{
	cout << "1. ���� 2. ���� 3. �ʵ� 4. ����" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "������ ���ϴ�." << endl;
		Town();
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
		Map();
	}
	else if (input[0] == '4')
	{
		cout << "������ �����մϴ�." << endl;
		isEnd = true;
		End();
	}
}

// ===============================Town=========================

void GameManager::Town()
{
	cout << "���������� Hp, Mp�� ȸ���˴ϴ�." << endl;
	player.Recovery();
	
	cout << "1. �÷��̾�� �ŷ��ϱ�" << endl
		<< "2. �κ��丮 Ȯ���ϱ�" << endl
		<<"3. ���ư���" <<endl;
	input.clear();
	cin >> input;

	if (input[0] == '1')
	{
		cout << "�ٸ� �÷��̾�� �ŷ��� �մϴ�." << endl;
		Trade();
	}
	if (input[0] == '2')
	{
		cout << "���â�� �κ��丮�� Ȯ���մϴ�." << endl;
		CheckInventory();
	}
	if (input[0] == '3')
	{
		cout << "���ư��ϴ�." << endl;
	}
}

void GameManager::Trade()
{
	player.SellItem();



}

void GameManager::CheckInventory()
{
	player.LoadInventory();

	cout << "1. ��� �����ϱ�" << endl
		<< "2. ��� Ż���ϱ�" << endl
		<< "3. ���ư���" << endl;
	input.clear();
	cin >> input;
	if (input[0] == '1')
	{
		cout << "��� �����մϴ�." << endl;
		player.SetEquipment();
	}
	else if (input[0] == '2')
	{
		cout << "��� Ż���մϴ�." << endl;
		player.ReleaseEquipment();
	}
	else if (input[0] == '3')
	{
		cout << "���ư��ϴ�." << endl;
	}


}


// ================================Shop=========================

void GameManager::Shop()
{
	cout << "1. ���� 2. �Ǹ�" << endl;
	input.clear();
	cin >> input;
	if (input[0] == '1')
	{
		cout << "���Ÿ� �����ϼ̽��ϴ�." << endl;
		BuySelect();
	}
	else if (input[0] == '2')
	{
		cout << "�ǸŸ� �����ϼ̽��ϴ�." << endl;
		player.SellItem();
	}
}

void GameManager::BuySelect()
{
	cout << "1. ��ȭ�� 2. ������" << endl;
	input.clear();
	cin >> input;

	if (input[0] == '1')
	{
		cout << "��ȭ���� �����ϼ̽��ϴ�." << endl;
		PotionShop();
	}
	else if (input[0] == '2')
	{
		cout << "�������� �����ϼ̽��ϴ�." << endl;
		WeaponShop();
	}

}

void GameManager::PotionShop()
{
	if (!setPotionShop)
	{
		shopPotionInventory.SetPotionShopInventory();
		setPotionShop = true;
	}

	shopPotionInventory.LoadInventory();
	cout << "�����ϰ���� �������� ��ȣ�� �Է��ϼ���." << endl;
	string num;
	cin >> num;

	if (player.BuyItem(shopPotionInventory.BuyItem(stoi(num))))
	{
		player.SetItem(shopPotionInventory.BuyItem(stoi(num)));
	}
	
}

void GameManager::WeaponShop()
{

	if (!setWeaponShop)
	{
		shopWeaponInventory.SetWeaponShopInventory();
		setWeaponShop = true;
	}

	shopWeaponInventory.LoadInventory();
	cout << "�����ϰ���� �������� ��ȣ�� �Է��ϼ���." << endl;
	string num;
	cin >> num;

	if (player.BuyItem(shopWeaponInventory.BuyItem(stoi(num))))
	{
		player.SetItem(shopWeaponInventory.BuyItem(stoi(num)));
	}
}


// ================================Battle=========================

void GameManager::Map()
{
	cout << "���� ������ �ּ���." << endl
		<< "1. �� ��	 2. ����	 3. ����" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "�� ������ ���ϴ�." << endl;
		Player slime("������", 1);
		Battle(slime);
	}
	else if (input[0] == '2')
	{
		cout << "�������� ���ϴ�." << endl;
		Player skeleton("�ذ�", 5);
		Battle(skeleton);
	}
	else if (input[0] == '3')
	{
		cout << "�������� ���ϴ�." << endl;
		Player boss("�밡��", 10);
		Battle(boss);
	}
}


void GameManager::Battle(Player _monster)
{
	monster = _monster;
	playerTurn = true;
	isRunAway = false;
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


void GameManager::PlayerTurn()
{
	cout << "�÷��̾��� �����Դϴ�." << endl;
	CoutHP();

	input.clear();
	cout<< "1. ����  2. ��� 3. ������ 4. ��������" << endl;
	cin >> input;

	if (input[0] == '1')
	{
		cout << monster.GetName() <<"���� " << player.GetAtk() << "��ŭ ������ �մϴ�." << endl << endl;
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
	cout << monster.GetName()<<"�� �����Դϴ�." << endl;
	CoutHP();
	cout << "�÷��̾�� " << monster.GetAtk() << "��ŭ ������ �մϴ�." << endl << endl;

	if (isDef)
	{
		cout << "�÷��̾ ����� ��ŭ �����Ǿ� �������� ���ϴ�."<<endl;
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
		cout << monster.GetName()<<"�� ������ ���� ����ĥ �� �����ϴ�..." << endl;
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
}




bool GameManager::CheckHp()
{
	if (player.Death())
	{
		cout << "�÷��̾��� Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "GAME OVER" << endl;

		isBattle = false;
		isEnd = true;
		return End();
	}
	else if (monster.Death())
	{
		cout << monster.GetName()<<" �� Hp�� 0�� �Ǿ����ϴ�." << endl
			<< "PLAYER WIN" << endl;
		player.SetExp(monster.GetExp());

		ItemSystem();

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


bool GameManager::End()
{
	return isEnd;
}