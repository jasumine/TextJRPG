#include "Inventory.h"

Inventory::Inventory()
{ 
	Item item1 = Item("hp����(��)", 10, 100);
	Item item2 = Item("mp����(��)", 10, 100);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
}

Inventory::Inventory(string _name)
{
	name = _name;
	Item item1 = Item("hp����(��)", 10, 100);
	Item item2 = Item("hp����(��)", 50, 200);
	Item item3 = Item("hp����(��)", 100, 300);
	Item item4 = Item("mp����(��)", 10, 100);
	Item item5 = Item("mp����(��)", 50, 200);
	Item item6 = Item("mp����(��)", 100, 300);

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
		cout << "=====������ �ִ� ������ ����Ʈ=====" << endl;
		for (int i = 0; i < itemSlot.size(); i++)
		{
			cout << i + 1 << ". " << itemSlot[i].GetName();
		}
		cout << endl;
	}
	else
	{
		cout << "=====����=====" << endl;
		for (int i = 0; i < itemSlot.size(); i++)
		{
			cout << i + 1 << ". " << itemSlot[i].GetName();
		}
		cout << endl;
	}
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
