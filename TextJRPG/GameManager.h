#pragma once
#include "Player.h"
#include <iostream>
#include <random>

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

public:
	GameManager(Player, Player);
	~GameManager();

	void CoutHP();
	void Battle();
	
	void PlayerTurn();
	void MonsterTurn();

	void PlayerRunAway();

	bool CheckHp();

	int CompareAtknDef(int, int);

};

