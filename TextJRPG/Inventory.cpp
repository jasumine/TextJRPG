#include "Inventory.h"

Inventory::Inventory()
{ 
}

Inventory::~Inventory()
{
}

void Inventory::LoadInventory()
{
	cout << endl;
	cout << "===== 아이템 리스트 =====" << endl;
	for (int i = 0; i < itemSlot.size(); i++)
	{
		cout << " " << i + 1 << ". " << itemSlot[i].GetName();
	}
	cout <<endl<<"=======================" << endl;
}

void Inventory::SetPotionShopInventory()
{
	Item item1 = Item("hp포션(소)", 10, 100);
	Item item2 = Item("mp포션(소)", 10, 100);
	Item item3 = Item("hp포션(중)", 100, 300);
	Item item4 = Item("mp포션(중)", 10, 100);
	Item item5 = Item("hp포션(대)", 50, 200);
	Item item6 = Item("mp포션(대)", 100, 300);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}

void Inventory::SetWeaponShopInventory()
{
	Item item1 = Item("낡은 검", 10, 100);
	Item item2 = Item("낡은 갑옷", 10, 100);
	Item item3 = Item("낡은 반지", 10, 100);
	Item item4 = Item("본 소드", 50, 200);
	Item item5 = Item("본 아머", 50, 200);
	Item item6 = Item("본 링", 50, 200);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
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

Item Inventory::SellItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "을 판매합니다." << endl;

	return itemSlot[num - 1];
}

bool Inventory::EmptyInventory()
{
	if (itemSlot.empty())
		return true;
	else
		return false;
}

void Inventory::DeleteItem(int num)
{
	itemSlot.erase(itemSlot.begin() + num - 1);
}

void Inventory::SetEquipment(Item _item)
{
	itemSlot.push_back(_item);

	cout <<itemSlot.back().GetName() << "을 장착했습니다." << endl;
}


