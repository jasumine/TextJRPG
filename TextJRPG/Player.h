#include <iostream>
using namespace std;
class Player
{
	string name;

	int level;

	int exp;
	int maxExp;

	int maxHp = 100;
	int curHp;

	int maxMp = 100;
	int curMp;

	int atk;
	int def;


public:
	
	Player();
	Player(string _name, int _level, int _hp, int _atk, int _exp);
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
};
