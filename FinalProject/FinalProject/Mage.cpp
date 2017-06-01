#include "Mage.h"



Mage::Mage(string name): Character(name, "Mage", 80, 150, 8)
{
}


Mage::~Mage()
{
}

int Mage::getAbilityValue(char abilityChoice)
{
	if (abilityChoice == 'M')
		return 200;
	else
		return 80;
}

int Mage::getManaCost(char abilityChoice)
{
	if (abilityChoice == 'M')
		return 100;
	else
		return 50;
}
