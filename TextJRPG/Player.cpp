#include "Player.h"

Player::Player()
{
	curHp = maxHp;
	curMp = maxMp;
}

// 몬스터 생성자
Player::Player(string _name,int _level, Item _item)
{
	name = _name;
	level = _level;
	curHp = 50;
	atk = 30;
	mItem = _item;
}

Player::~Player()
{
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
	if (exp == maxExp)
		level++;
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

void Player::SetHp(int _hp)
{
	curHp += _hp;
}

int Player::GetHp()
{
	if (curHp <= 0) curHp = 0;
	return curHp;
}

void Player::SetMp(int _mp)
{
	curMp += _mp;
}

int Player::GetMp()
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

void Player::SetItem(Item _item)
{
	mItem = _item;
	inventory.AddItem(_item);
}

Item Player::GetItem()
{
	return mItem;
}


void Player::ReleaseItem()
{
}

void Player::UseItem()
{
	inventory.LoadInventory();

	cout << "사용하고싶은 아이템의 번호를 입력하세요." << endl;
	string num;
	cin >> num;
	mItem = inventory.UseItem(stoi(num));

	curHp += mItem.GetValue();
}





