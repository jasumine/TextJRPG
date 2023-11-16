#pragma once
#include <iostream>
#include <random>
#include <string>
#include "Player.h"
#include "Inventory.h"
using namespace std;

class GameManager
{
	Player player;
	Player monster;

	int monsterType;

	string input;

	bool isRunAway = false;
	bool playerTurn = true;
	bool isDef = false;
	bool isBattle = false;
	bool isEnd = false;
	bool setPotionShop = false;
	bool setWeaponShop = false;

	Item shopItem;
	Inventory shopPotionInventory;
	Inventory shopWeaponInventory;

public:
	GameManager();
	GameManager(Player);
	~GameManager();

	void CoutHP();
	
	void GameStart();
	void Town();
	void Shop();
	void Battle(Player);
	bool End();

	void Trade();
	void CheckInventory();

	void BuySelect();
	void PotionShop();
	void WeaponShop();

	void Map();
	void PlayerTurn();
	void MonsterTurn();

	void PlayerRunAway();

	bool CheckHp();

	int CompareAtknDef(int, int);

	void ItemSystem();

};

