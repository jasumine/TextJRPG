#include "GameManager.h"
#include "Item.h"

using namespace std;

int main()
{
	Player player;

	Item _item = Item("HP����(��)", 10, 100);
	Player slime = Player("Slime", 1, _item);

	bool isEnd = false;

	cout << "������ �����մϴ�." << endl;
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
