#include "GameManager.h"

using namespace std;

int main()
{
	Player player;
	Player slime;
	Player zombie;
	Player skeleton;

	bool isBattle = true;

	cout << "게임을 시작합니다." << endl;

	GameManager gameManager(player, slime);
	while (isBattle)
	{
		gameManager.Battle();
		isBattle = gameManager.CheckHp();
	}

}
