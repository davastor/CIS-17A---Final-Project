#pragma once
#include <string>
using namespace std;

class Items
{
private:
	string _itemName;
	int _hpInc = 0;
	int _mpInc = 0;
	int _attInc = 0;
	int _itemRand;

public:
	Items();
	string getItemName();
	int getManaInc();
	int getHealthInc();
	int getAttackBuff();
	~Items();
};

