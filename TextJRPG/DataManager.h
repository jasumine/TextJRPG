#pragma once
#include "Item.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

class DataManager
{
	vector<Item> itemFactory;
	vector<Item> potionFactory;
	vector<Item> weaponFactory;

public:

	DataManager();
	~DataManager();

	void DataInit();
	void DataSave();
	void DataLoad();


	Item GetItem(int);



};

