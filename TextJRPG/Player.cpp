#include "Player.h"

Player::Player()
{
	curHp = maxHp;
	curMp = maxMp;
}

// ���� ������
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

	// ������ŭ �����ϴ� ��ġ�� �������ش�.
	for (int i = 1; i < _level; i++)
	{
		exp += 5;
		curHp += 5;
		atk += 1;
	}

	if (level < 5)
	{
		mItem = Item("hp����(��)", 10, 100);
	}
	else if (level >=5 && level < 10)
	{
		mItem = Item("hp����(��)", 30, 200);
	}
	else if(level >=10)
	{
		mItem = Item("hp����(��)", 50, 300);
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
	cout << "���� ���� : " << GetLevel() << endl
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

	cout << "����� �������� ��ȣ�� �Է��ϼ���." << endl;
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
		cout << "�������� �����ϰ� �����ʽ��ϴ�." << endl;
	}
	else
	{
		cout << "�Ǹ��� �������� ��ȣ�� �Է��ϼ���." << endl;
		string num;
		cin >> num;

		mItem = inventory.SellItem(stoi(num));
		inventory.DeleteItem(stoi(num));
	}
}



void Player::LoadInventory()
{
	cout << "===== ��� =====" << endl;
	equipment.LoadInventory();

	cout << "===== �κ��丮 =====" << endl;
	inventory.LoadInventory();
	
}

void Player::SetEquipment()
{

	if (inventory.EmptyInventory())
	{
		cout << "������ �������� ���� ������ �� �����ϴ�." << endl;
	}
	else
	{
		cout << "������ �������� ��ȣ�� �Է��ϼ���." << endl;
		string num;
		cin >> num;

		mItem = inventory.UseItem(stoi(num));
		inventory.DeleteItem(stoi(num));
		equipment.SetEquipment(mItem);
	}
}



