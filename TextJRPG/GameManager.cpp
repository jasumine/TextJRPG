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
	cout<< "플레이어의 HP : " << player.GetCurHp() << endl
		<< monster.GetName()<< "의 HP : " << monster.GetCurHp() << endl;
}

void GameManager::GameStart()
{
	cout << "1. 마을 2. 상점 3. 필드 4. 종료" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "마을에 갑니다." << endl;
		Town();
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
		Map();
	}
	else if (input[0] == '4')
	{
		cout << "게임을 종료합니다." << endl;
		isEnd = true;
		End();
	}
}

// ===============================Town=========================

void GameManager::Town()
{
	cout << "마을에서는 Hp, Mp가 회복됩니다." << endl;
	player.Recovery();
	
	cout << "1. 플레이어와 거래하기" << endl
		<< "2. 인벤토리 확인하기" << endl
		<<"3. 돌아가기" <<endl;
	input.clear();
	cin >> input;

	if (input[0] == '1')
	{
		cout << "다른 플레이어와 거래를 합니다." << endl;
		Trade();
	}
	if (input[0] == '2')
	{
		cout << "장비창과 인벤토리를 확인합니다." << endl;
		CheckInventory();
	}
	if (input[0] == '3')
	{
		cout << "돌아갑니다." << endl;
	}
}

void GameManager::Trade()
{
	player.SellItem();



}

void GameManager::CheckInventory()
{
	player.LoadInventory();

	cout << "1. 장비 장착하기" << endl
		<< "2. 장비 탈착하기" << endl
		<< "3. 돌아가기" << endl;
	input.clear();
	cin >> input;
	if (input[0] == '1')
	{
		cout << "장비를 장착합니다." << endl;
		player.SetEquipment();
	}
	else if (input[0] == '2')
	{
		cout << "장비를 탈착합니다." << endl;
		player.ReleaseEquipment();
	}
	else if (input[0] == '3')
	{
		cout << "돌아갑니다." << endl;
	}


}


// ================================Shop=========================

void GameManager::Shop()
{
	cout << "1. 구매 2. 판매" << endl;
	input.clear();
	cin >> input;
	if (input[0] == '1')
	{
		cout << "구매를 선택하셨습니다." << endl;
		BuySelect();
	}
	else if (input[0] == '2')
	{
		cout << "판매를 선택하셨습니다." << endl;
		player.SellItem();
	}
}

void GameManager::BuySelect()
{
	cout << "1. 잡화점 2. 무기점" << endl;
	input.clear();
	cin >> input;

	if (input[0] == '1')
	{
		cout << "잡화점을 선택하셨습니다." << endl;
		PotionShop();
	}
	else if (input[0] == '2')
	{
		cout << "무기점을 선택하셨습니다." << endl;
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
	cout << "구매하고싶은 아이템의 번호를 입력하세요." << endl;
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
	cout << "구매하고싶은 아이템의 번호를 입력하세요." << endl;
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
	cout << "맵을 선택해 주세요." << endl
		<< "1. 숲 속	 2. 무덤	 3. 던전" << endl;
	input.clear();
	cin >> input;
	
	if (input[0] == '1')
	{
		cout << "숲 속으로 갑니다." << endl;
		Player slime("슬라임", 1);
		Battle(slime);
	}
	else if (input[0] == '2')
	{
		cout << "무덤으로 갑니다." << endl;
		Player skeleton("해골", 5);
		Battle(skeleton);
	}
	else if (input[0] == '3')
	{
		cout << "던전으로 갑니다." << endl;
		Player boss("용가리", 10);
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
	cout << "플레이어의 차례입니다." << endl;
	CoutHP();

	input.clear();
	cout<< "1. 공격  2. 방어 3. 아이템 4. 도망가기" << endl;
	cin >> input;

	if (input[0] == '1')
	{
		cout << monster.GetName() <<"에게 " << player.GetAtk() << "만큼 공격을 합니다." << endl << endl;
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
	cout << monster.GetName()<<"의 차례입니다." << endl;
	CoutHP();
	cout << "플레이어에게 " << monster.GetAtk() << "만큼 공격을 합니다." << endl << endl;

	if (isDef)
	{
		cout << "플레이어가 방어한 만큼 차감되어 데미지가 들어갑니다."<<endl;
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
		cout << monster.GetName()<<"의 레벨이 높아 도망칠 수 없습니다..." << endl;
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
}




bool GameManager::CheckHp()
{
	if (player.Death())
	{
		cout << "플레이어의 Hp가 0이 되었습니다." << endl
			<< "GAME OVER" << endl;

		isBattle = false;
		isEnd = true;
		return End();
	}
	else if (monster.Death())
	{
		cout << monster.GetName()<<" 의 Hp가 0이 되었습니다." << endl
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