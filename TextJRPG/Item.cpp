#include "Item.h"

Item::Item()
{

}

Item::Item(string _name, int _value, int _price)
{
	name = _name;
	iValue = _value;
	price = _price;
}

Item::~Item()
{

}

void Item::SetName(string _name)
{
	name = _name;
}

string Item::GetName()
{
	return name;
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
	return 0;
}
