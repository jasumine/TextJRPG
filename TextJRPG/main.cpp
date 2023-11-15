#include "GameManager.h"
#include "Item.h"

using namespace std;

int main()
{
	Player player;

	Item _item = Item("HP포션(소)", 10, 100);
	Player slime = Player("Slime", 1, _item);

	bool isEnd = false;

	cout << "게임을 시작합니다." << endl;
	GameManager gameManager(player);


	while (isEnd == false)
	{
		gameManager.GameStart();
		isEnd = gameManager.End();

	}
	/*while (isBattle)
	{
		gameManager.Battle();
		isBattle = gameManager.CheckHp();
	}*/

}
