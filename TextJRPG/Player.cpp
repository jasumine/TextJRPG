#include "Player.h"

Player::Player()
{
	level = 1;
	exp = 0;
	maxExp = 10;
	curHp = maxHp;
	curMp = maxMp;
	atk = 10;
	def = 10;
}

// 몬스터 생성자
Player::Player(string _name = "monster",int _level = 1, int _hp = 10, int _atk = 5, int _exp = 10)
{
	name = _name;
	level = _level;
	exp = _exp;
	curHp = _hp;
	curMp = 0;
	atk = _atk;
	def = 0;
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

void Player::SetHp(int _hp)
{
	curHp += _hp;
}

int Player::GetHp()
{
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
	if (curHp == 0)
		return true;
	else
		return false;
}




