#include "GameManager.h"
#include "Item.h"
#include "DataManager.h"

using namespace std;

int main()
{
	Player player;
	DataManager dataManager;
	//dataManager.DataInit();
	//dataManager.DataSave();
	dataManager.DataLoad();

	bool isEnd = false;

	cout << "������ �����մϴ�." << endl;
	GameManager gameManager(player);


	while (isEnd == false)
	{
		gameManager.GameStart();
		isEnd = gameManager.End();

	}

}
