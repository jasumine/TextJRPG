#include "Player.h"

Player::Player()
{
	curHp = maxHp;
	curMp = maxMp;
}

// 몬스터 생성자
Player::Player(string _name,int _level)
{
	name = _name;
	SetMonster(_level);
}

Player::~Player()
{
}

void Player::SetMonster(int _level)
{
	level = _level;
	exp = 10;
	curHp = 50;
	atk = 10;

	// 레벨만큼 증가하는 수치를 설정해준다.
	for (int i = 1; i < _level; i++)
	{
		exp += 5;
		curHp += 5;
		atk += 1;
	}

	if (level < 5)
	{
		mItem = Item("hp포션(소)", 10, 100);
	}
	else if (level >=5 && level < 10)
	{
		mItem = Item("hp포션(중)", 30, 200);
	}
	else if(level >=10)
	{
		mItem = Item("hp포션(대)", 50, 300);
	}
}

void Player::LevelUP()
{
	level++;

	cout << "*****Level UP*****" << endl;

	maxHp += 50;
	maxMp += 20;
	maxExp += 30;

	atk += 10;
	def += 10;

	CoutExp();
}



void Player::CoutExp()
{
	cout << "현재 레벨 : " << GetLevel() << endl
		<< exp << "/" << maxExp << endl;

}

void Player::SetLevel(int _level)
{
	level += _level;
}

int Player::GetLevel()
{
	return level;
}

void Player::SetExp(int _exp)
{
	exp += _exp;
	CoutExp();
	while (exp >= maxExp)
	{
		int temp = exp - maxExp;
		exp = temp;

		LevelUP();
	}

}

int Player::GetExp()
{
	return exp;
}

void Player::SetName(string _name)
{
	name = _name;
}

string Player::GetName()
{
	return name;
}

void Player::SetMaxHp(int _hp)
{
	maxHp += _hp;
}

void Player::SetHp(int _hp)
{
	curHp += _hp;
}

int Player::GetCurHp()
{
	if (curHp <= 0) curHp = 0;
	return curHp;
}

void Player::SetMaxMp(int _mp)
{
	maxMp += _mp;
}

void Player::SetMp(int _mp)
{
	curMp += _mp;
}

int Player::GetCurMp()
{
	return curMp;
}

void Player::SetAtk(int)
{
}

int Player::GetAtk()
{
	return atk;
}

void Player::SetDef(int)
{

}

int Player::GetDef()
{
	return def;
}

bool Player::Death()
{
	if (curHp <= 0)
		return true;
	else
		return false;
}

void Player::Recovery()
{
	curHp = maxHp;
	curMp = maxMp;

}

void Player::SetItem(Item _item)
{
	mItem = _item;
	inventory.AddItem(_item);
}

Item Player::GetItem()
{
	return mItem;
}

Inventory Player::GetInventory()
{
	return inventory;
}


void Player::ReleaseItem()
{
}


void Player::UseItem()
{
	inventory.LoadInventory();

	cout << "사용할 아이템의 번호를 입력하세요." << endl;
	string num;
	cin >> num;
	mItem = inventory.UseItem(stoi(num));
	inventory.DeleteItem(stoi(num));

	curHp += mItem.GetValue();
	if (curHp >= maxHp)
	{
		curHp = maxHp;
	}
}

void Player::SellItem()
{
	inventory.LoadInventory();

	if (inventory.EmptyInventory())
	{
		cout << "아이템을 소지하고 있지않습니다." << endl;
	}
	else
	{
		cout << "판매할 아이템의 번호를 입력하세요." << endl;
		string num;
		cin >> num;

		mItem = inventory.SellItem(stoi(num));
		inventory.DeleteItem(stoi(num));
	}
}



void Player::LoadInventory()
{
	cout << "===== 장비 =====" << endl;
	equipment.LoadInventory();

	cout << "===== 인벤토리 =====" << endl;
	inventory.LoadInventory();
	
}

void Player::SetEquipment()
{

	if (inventory.EmptyInventory())
	{
		cout << "소지한 아이템이 없어 장착할 수 없습니다." << endl;
	}
	else
	{
		cout << "장착할 아이템의 번호를 입력하세요." << endl;
		string num;
		cin >> num;

		mItem = inventory.UseItem(stoi(num));
		inventory.DeleteItem(stoi(num));
		equipment.SetEquipment(mItem);
	}
}



