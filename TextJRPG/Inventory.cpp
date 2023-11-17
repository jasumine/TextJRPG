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
	cout <<endl<<"=========================" << endl <<endl;
}

void Inventory::SetPotionShopInventory()
{
	Item item1 = Item("hp포션(소)", Potion, 10, 100);
	Item item2 = Item("mp포션(소)", Potion, 10, 100);
	Item item3 = Item("hp포션(중)", Potion, 50, 200);
	Item item4 = Item("mp포션(중)", Potion, 50, 200);
	Item item5 = Item("hp포션(대)", Potion, 100, 300);
	Item item6 = Item("mp포션(대)", Potion, 100, 300);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}

void Inventory::SetWeaponShopInventory()
{
	Item item1 = Item("낡은 검", Weapon, 10, 100);
	Item item2 = Item("낡은 갑옷", Cloth, 10, 100);
	Item item3 = Item("낡은 반지", Accessory, 10, 100);
	Item item4 = Item("본 소드", Weapon, 50, 200);
	Item item5 = Item("본 아머", Cloth, 50, 200);
	Item item6 = Item("본 링", Accessory, 50, 200);

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
	cout << "인벤토리에 " << itemSlot[num-1].GetName() << "이 제거되었습니다." << endl;


	if (itemSlot[num - 1].GetType() == 1)
	{
		setWeapon = false;
	}
	if (itemSlot[num - 1].GetType() == 2)
	{
		setCloth = false;
	}
	if (itemSlot[num - 1].GetType() == 3)
	{
		setAccessory = false;
	}



	itemSlot.erase(itemSlot.begin() + num - 1);
}

bool Inventory::SetEquipment(Item _item)
{
	if (_item.GetType() == 1)
	{
		if (setWeapon == false)
		{
			itemSlot.push_back(_item);
			setWeapon = true;
			cout << itemSlot.back().GetName() << "을 장착했습니다." << endl;

			return true;
		}
		else
		{
			cout << "무기는 이미 장착되어 있습니다. 탈착부터 해주세요!!" << endl;

			return false;
		}
	}
	else if (_item.GetType() == 2)
	{
		if (setCloth == false)
		{
			itemSlot.push_back(_item);
			setCloth = true;
			cout << itemSlot.back().GetName() << "을 장착했습니다." << endl;

			return true;
		}
		else
		{
			cout << "갑옷은 이미 장착되어 있습니다. 탈착부터 해주세요!!" << endl;

			return false;
		}
	}
	else if (_item.GetType() == 3)
	{
		if (setAccessory == false)
		{
			itemSlot.push_back(_item);
			setAccessory = true;
			cout << itemSlot.back().GetName() << "을 장착했습니다." << endl;

			return true;
		}
		else
		{
			cout << "악세사리는 이미 장착되어 있습니다. 탈착부터 해주세요!!" << endl;

			return false;
		}
	}
	else
	{
		cout << "장착할 수 없는 아이템 입니다." << endl;
		return false;
	}
}

void Inventory::ReleasEquipment(Item _item)
{
	itemSlot.push_back(_item);

	cout << itemSlot.back().GetName() << "을 탈착했습니다." << endl;
}


