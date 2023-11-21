#include "Item.h"

Item::Item()
{

}

Item::Item(string _line)
{
	string seperator = ",";
	int startIdx = 0;
	int endIdx;

	int variable = 0;

	while ((endIdx = _line.find(seperator, startIdx)) != string::npos)
	{
		int len = endIdx - startIdx;
		string result = _line.substr(startIdx, len);

		if (variable == 0)
		{
			name = result;
			startIdx = endIdx + 1;
			variable++;
		}
		else if (variable == 1)
		{
			if (result == "Potion")
			{
				type = Potion;
			}
			else if (result == "Weapon")
			{
				type = Weapon;
			}
			else if (result == "Cloth")
			{
				type = Cloth;
			}
			else if (result == "Accessory")
			{
				type == Accessory;
			}
			startIdx = endIdx + 1;
			variable++;
		}
		else if (variable == 2)
		{
			iValue = stoi(result);

			len = _line.size() - endIdx;
			result = _line.substr(endIdx + 1, len);

			price = stoi(result);

		}
		else
		{
			return;
		}
	}



}

Item::Item(string _name, ItemType _type, int _value, int _price)
{
	name = _name;
	type = _type;
	iValue = _value;
	price = _price;
}

Item::~Item()
{

}

string Item::ToString()
{
	string line;

	string strType;
	switch (type)
	{
		case 0:
			strType = "Potion";
			break;
		case 1:
			strType = "Weapon";
			break;
		case 2:
			strType = "Cloth";
			break;
		case 3:
			strType = "Accessory";
			break;

	};

	line = name + "," + strType + "," + to_string(iValue) + "," + to_string(price);

	return line;
}

void Item::SetName(string _name)
{
	name = _name;
}

string Item::GetName()
{
	return name;
}

ItemType Item::GetType()
{
	return type;
}

void Item::SetValue(int _value)
{
	iValue = _value;
}

int Item::GetValue()
{
	return iValue;
}

void Item::SetPrice(int _price)
{
	price = _price;
}

int Item::GetPrice()
{
	return price;
}
