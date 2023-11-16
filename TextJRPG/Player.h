#include <iostream>
#include <string>
#include "Inventory.h"

using namespace std;

class Player
{
	string name;

	int level = 1;

	int exp = 0;
	int maxExp = 10;

	int maxHp = 100;
	int curHp;

	int maxMp = 100;
	int curMp;

	int atk = 30;
	int def = 10;

	Inventory inventory;
	Inventory equipment;
	Item mItem;

public:
	
	Player();
	Player(string _name, int _level);
	~Player();

	void SetMonster(int);
	void LevelUP();

	void CoutExp();
	void SetLevel(int);
	int GetLevel();

	void SetExp(int);
	int GetExp();

	void SetName(string);
	string GetName();

	void SetMaxHp(int);
	void SetHp(int);
	int GetCurHp();

	void SetMaxMp(int);
	void SetMp(int);
	int GetCurMp();

	void SetAtk(int);
	int GetAtk();

	void SetDef(int);
	int GetDef();

	bool Death();

	void Recovery();

	void SetItem(Item);
	Item GetItem();
	Inventory GetInventory();
	void ReleaseItem();
	void UseItem();
	void SellItem();

	void LoadInventory();
	void SetEquipment();
};
