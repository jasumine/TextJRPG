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
	cout<< "플레이어의 HP : " << player.GetHp() << endl
		<< "몬스터의 HP : " << monster.GetHp() << endl;
}

void GameManager::GameStart()
{
	cout << "1. 마을 2. 상점 3. 필드 4. 종료" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "마을은 아직 미구현입니다..." << endl;
	}
	else if (input[0] == '2')
	{
		cout << "상점에 갑니다." << endl;
		Shop();
	}
	else if (input[0] == '3')
	{
		cout << "필드에 갑니다." << endl;
		isBattle = true;
		Battle();
	}
	else if (input[0] == '4')
	{
		cout << "게임을 종료합니다." << endl;
		isEnd = true;
		End();
	}
}

void GameManager::Shop()
{
	shopInventory.LoadInventory();
	cout << "구매하고싶은 아이템의 번호를 입력하세요." << endl;
	string num;
	cin >> num;
	player.SetItem(shopInventory.BuyItem(stoi(num)));
	cout << player.GetItem().GetName() << "을 구매했습니다." << endl;
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
	cout << "플레이어의 차례입니다." << endl;
	CoutHP();

	input.clear();
	cout<< "1. 공격  2. 방어 3. 아이템 4. 도망가기" << endl;
	cin >> input;

	if (input[0] == '1')
	{
		cout << "몬스터에게 " << player.GetAtk() << "만큼 공격을 합니다." << endl << endl;
		monster.SetHp(-player.GetAtk());
	}
	else if (input[0] == '2')
	{
		cout << "방어를 합니다." << endl << endl;
		isDef = true;
	}
	else if (input[0] == '3')
	{
		cout << " 아이템을 사용합니다. " << endl << endl;
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
	cout << "몬스터의 차례입니다." << endl;
	CoutHP();
	cout << "플레이어에게 " << monster.GetAtk() << "만큼 공격을 합니다." << endl << endl;

	if (isDef)
	{
		cout << "플레이어가 방어한 만큼 차감되어 데미지가 들어갑니다.";
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
			cout << "도망치기에 성공했습니다!" << endl;
			isRunAway = true;
		}
		else
		{
			cout << "도망치기에 실패했습니다..." << endl;
			isRunAway = false;
		}
	}
	else
	{
		cout << "몬스터의 레벨이 높아 도망칠 수 없습니다..." << endl;
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
	cout << "전리품으로 " << monster.GetItem().GetName() <<"을 획득합니다." << endl;
	player.SetItem(monster.GetItem());

	cout << "player의 item 상황 : " << player.GetItem().GetName();
}




bool GameManager::CheckHp()
{
	if (player.Death())
	{
		cout << "플레이어의 Hp가 0이 되었습니다." << endl
			<< "GAME OVER" << endl;

		isBattle = false;
		return false;
	}
	else if (monster.Death())
	{
		cout << "몬스터의 Hp가 0이 되었습니다." << endl
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