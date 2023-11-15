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

	Inventory shopInventory;
	Item shopItem;

public:
	GameManager();
	GameManager(Player);
	GameManager(Player, Player);
	~GameManager();

	void CoutHP();
	
	void GameStart();
	void Shop();
	void Battle();
	bool End();
	
	void PlayerTurn();
	void MonsterTurn();

	void PlayerRunAway();

	bool CheckHp();

	int CompareAtknDef(int, int);

	void ItemSystem();

};

