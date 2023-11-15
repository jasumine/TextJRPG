#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

class Player
{
	string name;

	int level = 1;

	int exp = 0;
	int maxExp = 100;

	int maxHp = 100;
	int curHp;

	int maxMp = 100;
	int curMp;

	int atk = 30;
	int def = 10;

	Inventory inventory;
	Item mItem;

public:
	
	Player();
	Player(string _name, int _level, Item _item);
	~Player();

	void SetLevel(int);
	int GetLevel();

	void SetExp(int);
	int GetExp();

	void SetName(string);
	string GetName();

	void SetHp(int);
	int GetHp();

	void SetMp(int);
	int GetMp();

	void SetAtk(int);
	int GetAtk();

	void SetDef(int);
	int GetDef();

	bool Death();

	void SetItem(Item);
	Item GetItem();
	void ReleaseItem();
	void UseItem();
};
