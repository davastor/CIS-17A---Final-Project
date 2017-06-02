#include "Items.h"
#include <ctime>


Items::Items()
{
	srand((unsigned int)time(NULL));
	_itemRand = rand() % 4;

	if (_itemRand == 0)
	{
		_itemName = "Mysterious Amulet";
		_attInc = 15;
	}
	else if (_itemRand == 1)
	{
		_itemName = "Health Potion";
		_hpInc = 100;
	}
	else if (_itemRand == 2)
	{
		_itemName = "Mana Potion";
		_mpInc = 100;
	}
	else
	{
		_itemName = "Mysterious Ring";
		_attInc = 1;
	}
}

string Items::getItemName()
{
	return _itemName;
}

int Items::getManaInc()
{
	return _mpInc;
}

int Items::getHealthInc()
{
	return _hpInc;
}

int Items::getAttackBuff()
{
	return _attInc;
}


Items::~Items()
{
}
