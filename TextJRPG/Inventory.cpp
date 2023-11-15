#include "Inventory.h"

Inventory::Inventory()
{ 
	Item item1 = Item("hp포션(소)", 10, 100);
	Item item2 = Item("mp포션(소)", 10, 100);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
}

Inventory::Inventory(string _name)
{
	name = _name;
	Item item1 = Item("hp포션(소)", 10, 100);
	Item item2 = Item("hp포션(중)", 50, 200);
	Item item3 = Item("hp포션(대)", 100, 300);
	Item item4 = Item("mp포션(소)", 10, 100);
	Item item5 = Item("mp포션(중)", 50, 200);
	Item item6 = Item("mp포션(대)", 100, 300);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}

Inventory::~Inventory()
{
}

Inventory::Inventory(int)
{
}

void Inventory::LoadInventory()
{
	cout << endl;
	if (name.empty()) 
	{
		cout << "=====가지고 있는 아이템 리스트=====" << endl;
		for (int i = 0; i < itemSlot.size(); i++)
		{
			cout << i + 1 << ". " << itemSlot[i].GetName();
		}
		cout << endl;
	}
	else
	{
		cout << "=====상점=====" << endl;
		for (int i = 0; i < itemSlot.size(); i++)
		{
			cout << i + 1 << ". " << itemSlot[i].GetName();
		}
		cout << endl;
	}
}

void Inventory::AddItem(Item _item)
{
	// 같은 아이템인지 확인하는 부분 추가하기.
	itemSlot.push_back(_item);

	cout <<  "인벤토리에 " << itemSlot.back().GetName() << "이 추가되었습니다." << endl;
}

Item Inventory::UseItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "을 사용합니다." << endl;

	return itemSlot[num - 1];
}

Item Inventory::BuyItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "을 구매합니다." << endl;

	return itemSlot[num - 1];
}
