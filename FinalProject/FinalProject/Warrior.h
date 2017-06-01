#pragma once
#include "Character.h"
class Warrior: public Character
{
public:
	Warrior(string name);
	~Warrior();
	int getAbilityDamage(char abilityChoice, int attack);
	virtual int getManaCost(char abilityChoice);
};

