#include "DataManager.h"
#include <string>

DataManager::DataManager()
{
	potionFactory.clear();
	weaponFactory.clear();

}

DataManager::~DataManager()
{
}

void DataManager::DataInit()
{

	Item item1 = Item("hp포션(소)", Potion, 10, 100);
	Item item2 = Item("mp포션(소)", Potion, 10, 100);
	Item item3 = Item("hp포션(중)", Potion, 50, 200);
	Item item4 = Item("mp포션(중)", Potion, 50, 200);
	Item item5 = Item("hp포션(대)", Potion, 100, 300);
	Item item6 = Item("mp포션(대)", Potion, 100, 300);


	Item item7 = Item("낡은 검", Weapon, 10, 100);
	Item item8 = Item("낡은 갑옷", Cloth, 10, 100);
	Item item9 = Item("낡은 반지", Accessory, 10, 100);
	Item item10 = Item("본 소드", Weapon, 50, 200);
	Item item11 = Item("본 아머", Cloth, 50, 200);
	Item item12 = Item("본 링", Accessory, 50, 200);

	itemFactory.push_back(item1);
	itemFactory.push_back(item2);
	itemFactory.push_back(item3);
	itemFactory.push_back(item4);
	itemFactory.push_back(item5);
	itemFactory.push_back(item6);


	itemFactory.push_back(item7);
	itemFactory.push_back(item8);
	itemFactory.push_back(item9);
	itemFactory.push_back(item10);
	itemFactory.push_back(item11);
	itemFactory.push_back(item12);

}


void DataManager::DataSave()
{
	// 가진 정보를 파일에 쓰는 함수.

	// =======잡화점 save========
	ofstream file("potionFactory.txt");
	string line;

	if (file.is_open())
	{
		for (int i = 0; i <= 5; i++)
		{
			line = itemFactory[i].ToString();
			file << line << endl;
		}
	}
	else
	{
		cout << "파일을 열지 못했습니다." << endl;
	}
	file.close();

	// =======무기점 save========

	ofstream file2("weaponFactory.txt");

	if (file2.is_open())
	{
		for (int i = 6; i <=11 ; i++)
		{
			line = itemFactory[i].ToString();
			file2 << line << endl;
		}
	}
	else
	{
		cout << "파일을 열지 못했습니다." << endl;
	}
	file2.close();
}


void DataManager::DataLoad()
{
	// 파일을 읽어오는 함수
	// =============잡화점 load==============
	ifstream potionFile("potionFactory.txt");
	char line[100];

	if (potionFile.is_open())
	{
		cout << "잡화점" << endl;
		while (potionFile)
		{
			potionFile.getline(line, 100);
			//cout << line << endl;

			//cout << "********" << endl;
			Item loadItem(line);
			potionFactory.push_back(loadItem);
			cout << loadItem.ToString() << endl;
		}
	}
	else
	{
		cout << "unable to opne file";
	}

	potionFile.close();



	// =============무기점 load==============
	ifstream weaponFile("weaponFactory.txt");

	if (weaponFile.is_open())
	{
		cout << "무기점" << endl;
		while (weaponFile)
		{
			weaponFile.getline(line, 100);
			
			cout << line << endl;
		}
	}
	else
	{
		cout << "unable to opne file";
	}

}

Item DataManager::GetItem(int _idx)
{
	return itemFactory[_idx];
}
