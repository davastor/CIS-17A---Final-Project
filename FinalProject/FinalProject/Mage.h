#pragma once
#include "Character.h"
class Mage: public Character
{
public:
	Mage(string name);
	~Mage();
	int getAbilityValue(char abilityChoice);
	int getManaCost(char abilityChoice);
};

