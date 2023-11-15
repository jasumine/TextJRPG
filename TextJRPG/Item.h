#pragma once
#include <iostream>

using namespace std;

class Item
{
	string name;
	int iValue;
	int price;


public:

	Item();
	Item(string, int, int);
	~Item();

	void SetName(string);
	string GetName();

	void SetValue(int);
	int GetValue();

	void SetPrice(int);
	int GetPrice();

};

