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

	Item item1 = Item("hp����(��)", Potion, 10, 100);
	Item item2 = Item("mp����(��)", Potion, 10, 100);
	Item item3 = Item("hp����(��)", Potion, 50, 200);
	Item item4 = Item("mp����(��)", Potion, 50, 200);
	Item item5 = Item("hp����(��)", Potion, 100, 300);
	Item item6 = Item("mp����(��)", Potion, 100, 300);


	Item item7 = Item("���� ��", Weapon, 10, 100);
	Item item8 = Item("���� ����", Cloth, 10, 100);
	Item item9 = Item("���� ����", Accessory, 10, 100);
	Item item10 = Item("�� �ҵ�", Weapon, 50, 200);
	Item item11 = Item("�� �Ƹ�", Cloth, 50, 200);
	Item item12 = Item("�� ��", Accessory, 50, 200);

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
	// ���� ������ ���Ͽ� ���� �Լ�.

	// =======��ȭ�� save========
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
		cout << "������ ���� ���߽��ϴ�." << endl;
	}
	file.close();

	// =======������ save========

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
		cout << "������ ���� ���߽��ϴ�." << endl;
	}
	file2.close();
}


void DataManager::DataLoad()
{
	// ������ �о���� �Լ�
	// =============��ȭ�� load==============
	ifstream potionFile("potionFactory.txt");
	char line[100];

	if (potionFile.is_open())
	{
		cout << "��ȭ��" << endl;
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



	// =============������ load==============
	ifstream weaponFile("weaponFactory.txt");

	if (weaponFile.is_open())
	{
		cout << "������" << endl;
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
