#pragma once
#include <iostream>
#include <Vector>
#include "Item.h"

class Inventory
{
	vector<Item> itemSlot;
	string name;

public:
	Inventory();
	Inventory(string);
	~Inventory();

	void LoadInventory();
	void AddItem(Item);
	Item UseItem(int);
	Item BuyItem(int);
};

