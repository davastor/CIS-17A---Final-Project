#pragma once
#include "Character.h"
class Mage: public Character
{
public:
	Mage(string name);
	~Mage();
	virtual int getAbilityValue(char abilityChoice);
	virtual int getManaCost(char abilityChoice);
};

