#pragma once
#include <iostream>
#include <Vector>
#include "Item.h"

class Inventory
{
	vector<Item> itemSlot;

	bool setWeapon = false;
	bool setCloth = false;
	bool setAccessory = false;

public:
	Inventory();
	~Inventory();

	void SetPotionShopInventory();
	void SetWeaponShopInventory();

	void LoadInventory();
	void AddItem(Item);
	Item UseItem(int);
	Item BuyItem(int);
	Item SellItem(int);
	void DeleteItem(int);

	bool EmptyInventory();

	bool SetEquipment(Item);
	void ReleasEquipment(Item);


};

