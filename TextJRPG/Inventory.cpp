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
	cout << "===== ������ ����Ʈ =====" << endl;
	for (int i = 0; i < itemSlot.size(); i++)
	{
		cout << " " << i + 1 << ". " << itemSlot[i].GetName();
	}
	cout <<endl<<"=======================" << endl;
}

void Inventory::SetPotionShopInventory()
{
	Item item1 = Item("hp����(��)", 10, 100);
	Item item2 = Item("mp����(��)", 10, 100);
	Item item3 = Item("hp����(��)", 100, 300);
	Item item4 = Item("mp����(��)", 10, 100);
	Item item5 = Item("hp����(��)", 50, 200);
	Item item6 = Item("mp����(��)", 100, 300);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}

void Inventory::SetWeaponShopInventory()
{
	Item item1 = Item("���� ��", 10, 100);
	Item item2 = Item("���� ����", 10, 100);
	Item item3 = Item("���� ����", 10, 100);
	Item item4 = Item("�� �ҵ�", 50, 200);
	Item item5 = Item("�� �Ƹ�", 50, 200);
	Item item6 = Item("�� ��", 50, 200);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}



void Inventory::AddItem(Item _item)
{
	// ���� ���������� Ȯ���ϴ� �κ� �߰��ϱ�.
	itemSlot.push_back(_item);

	cout <<  "�κ��丮�� " << itemSlot.back().GetName() << "�� �߰��Ǿ����ϴ�." << endl;
}

Item Inventory::UseItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "�� ����մϴ�." << endl;

	return itemSlot[num - 1];
}

Item Inventory::BuyItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "�� �����մϴ�." << endl;

	return itemSlot[num - 1];
}

Item Inventory::SellItem(int num)
{
	cout << itemSlot[num - 1].GetName() << "�� �Ǹ��մϴ�." << endl;

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

	cout <<itemSlot.back().GetName() << "�� �����߽��ϴ�." << endl;
}


