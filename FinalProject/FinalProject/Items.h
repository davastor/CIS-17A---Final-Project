#pragma once
#include <string>
using namespace std;

class Items
{
private:
	string _itemName;
	int _hpInc;
	int _mpInc;
	int _attInc;
	int _itemRand;

public:
	Items();
	string getItemName();
	int getManaInc();
	int getHealthInc();
	int getAttackBuff();
	~Items();
};

