#pragma once
#include <iostream>

using namespace std;

enum ItemType
{
	Potion,
	Weapon,
	Cloth,
	Accessory
};


class Item
{
	string name;
	ItemType type;
	int iValue;
	int price;

public:

	Item();
	Item(string, ItemType, int, int);
	~Item();

	void SetName(string);
	string GetName();

	ItemType GetType();

	void SetValue(int);
	int GetValue();

	void SetPrice(int);
	int GetPrice();

};

