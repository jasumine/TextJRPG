#include "GameManager.h"
#include "Item.h"

using namespace std;

int main()
{
	Player player;

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
