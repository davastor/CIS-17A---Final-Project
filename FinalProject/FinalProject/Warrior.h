#pragma once
#include "Character.h"
class Warrior: public Character
{
public:
	Warrior(string name);
	~Warrior();
	int getAbilityValue(char abilityChoice, int attack);
	int getManaCost(char abilityChoice);
};

