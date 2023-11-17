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
	cout <<endl<<"=========================" << endl <<endl;
}

void Inventory::SetPotionShopInventory()
{
	Item item1 = Item("hp����(��)", Potion, 10, 100);
	Item item2 = Item("mp����(��)", Potion, 10, 100);
	Item item3 = Item("hp����(��)", Potion, 50, 200);
	Item item4 = Item("mp����(��)", Potion, 50, 200);
	Item item5 = Item("hp����(��)", Potion, 100, 300);
	Item item6 = Item("mp����(��)", Potion, 100, 300);

	itemSlot.push_back(item1);
	itemSlot.push_back(item2);
	itemSlot.push_back(item3);
	itemSlot.push_back(item4);
	itemSlot.push_back(item5);
	itemSlot.push_back(item6);
}

void Inventory::SetWeaponShopInventory()
{
	Item item1 = Item("���� ��", Weapon, 10, 100);
	Item item2 = Item("���� ����", Cloth, 10, 100);
	Item item3 = Item("���� ����", Accessory, 10, 100);
	Item item4 = Item("�� �ҵ�", Weapon, 50, 200);
	Item item5 = Item("�� �Ƹ�", Cloth, 50, 200);
	Item item6 = Item("�� ��", Accessory, 50, 200);

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
	cout << "�κ��丮�� " << itemSlot[num-1].GetName() << "�� ���ŵǾ����ϴ�." << endl;


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
			cout << itemSlot.back().GetName() << "�� �����߽��ϴ�." << endl;

			return true;
		}
		else
		{
			cout << "����� �̹� �����Ǿ� �ֽ��ϴ�. Ż������ ���ּ���!!" << endl;

			return false;
		}
	}
	else if (_item.GetType() == 2)
	{
		if (setCloth == false)
		{
			itemSlot.push_back(_item);
			setCloth = true;
			cout << itemSlot.back().GetName() << "�� �����߽��ϴ�." << endl;

			return true;
		}
		else
		{
			cout << "������ �̹� �����Ǿ� �ֽ��ϴ�. Ż������ ���ּ���!!" << endl;

			return false;
		}
	}
	else if (_item.GetType() == 3)
	{
		if (setAccessory == false)
		{
			itemSlot.push_back(_item);
			setAccessory = true;
			cout << itemSlot.back().GetName() << "�� �����߽��ϴ�." << endl;

			return true;
		}
		else
		{
			cout << "�Ǽ��縮�� �̹� �����Ǿ� �ֽ��ϴ�. Ż������ ���ּ���!!" << endl;

			return false;
		}
	}
	else
	{
		cout << "������ �� ���� ������ �Դϴ�." << endl;
		return false;
	}
}

void Inventory::ReleasEquipment(Item _item)
{
	itemSlot.push_back(_item);

	cout << itemSlot.back().GetName() << "�� Ż���߽��ϴ�." << endl;
}


