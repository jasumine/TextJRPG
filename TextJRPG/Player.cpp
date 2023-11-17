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
		mItem = Item("hp����(��)", Potion, 10, 100);
	}
	else if (level >=5 && level < 10)
	{
		mItem = Item("hp����(��)", Potion, 30, 200);
	}
	else if(level >=10)
	{
		mItem = Item("hp����(��)", Potion, 50, 300);
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

void Player::SetAtk(int _atk)
{
	atk += _atk;
}

int Player::GetAtk()
{
	return atk;
}

void Player::SetDef(int _def)
{
	def += _def;
}

int Player::GetDef()
{
	return def;
}

void Player::SetGold(int _gold)
{
	gold += _gold;
}

int Player::GetGold()
{
	return gold;
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

bool Player::BuyItem(Item _item)
{
	cout << "���� ������ : " << gold <<endl
		<< "������ ���� : " << _item.GetPrice() << endl;
	if (gold >= _item.GetPrice())
	{	
		gold -= _item.GetPrice();
		cout << "���Ÿ� �Ϸ� �߽��ϴ�. " << endl
			<< "���� ������ : " << gold << endl;
		return true;
	}
	else
	{
		cout << "�������� �����ؼ� ���Ÿ� �� �� �����ϴ�." << endl;
		return false;
	}

}


Inventory Player::GetInventory()
{
	return inventory;
}


void Player::UseItem()
{
	inventory.LoadInventory();

	cout << "����� �������� ��ȣ�� �Է��ϼ���." << endl;
	string num;
	cin >> num;
	mItem = inventory.UseItem(stoi(num));
	inventory.DeleteItem(stoi(num));

	// =====������ �ɷ�ġ ����=====
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
		cout << "�������� ��ȣ�� �Է��ϼ���." << endl;
		string num;
		cin >> num;

		mItem = inventory.UseItem(stoi(num));
		inventory.DeleteItem(stoi(num));

		gold += mItem.GetPrice();
		cout << "���� ������ : " << GetGold() << endl;
		
	}
}



void Player::LoadInventory()
{
	cout << "********** ��� *********" ;
	equipment.LoadInventory();

	cout << "******* �κ��丮 *******";
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

		if (equipment.SetEquipment(mItem))
		{
			// ������ �����ϸ� �ڵ� ����
			inventory.DeleteItem(stoi(num));

			// ==== ��� �ɷ�ġ ���� ====

			if (mItem.GetType() == 1)
			{
				atk += mItem.GetValue();
			}
			else if (mItem.GetType() == 2)
			{
				def += mItem.GetValue();
			}
			else if (mItem.GetType() == 3)
			{
				maxHp += mItem.GetValue();
				curHp = maxHp;
			}
		}
	}
}

void Player::ReleaseEquipment()
{

	if (equipment.EmptyInventory())
	{
		cout << "������ �������� ���� Ż���� �� �����ϴ�." << endl;
	}
	else
	{
		cout << "Ż���� �������� ��ȣ�� �Է��ϼ���." << endl;
		string num;
		cin >> num;

		mItem = equipment.UseItem(stoi(num));
		equipment.DeleteItem(stoi(num));
		inventory.ReleasEquipment(mItem);

		// ==== ��� �ɷ�ġ ���� ====
		if (mItem.GetType() == 1)
		{
			atk -= mItem.GetValue();
		}
		else if (mItem.GetType() == 2)
		{
			def -= mItem.GetValue();
		}
		else if (mItem.GetType() == 3)
		{
			maxHp -= mItem.GetValue();
			curHp = maxHp;
		}
	}
}



