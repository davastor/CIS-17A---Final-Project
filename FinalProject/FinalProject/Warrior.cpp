#include "Warrior.h"



Warrior::Warrior(string name): Character(name, "Warrior", 150 , 30, 20)
{
}


Warrior::~Warrior()
{
}

int Warrior::getAbilityValue(char abilityChoice, int attack)
{
	if (abilityChoice == 'C')
		return (attack * 3);
	
	if(abilityChoice == 'W')
		return 50;
}

int Warrior::getManaCost(char abilityChoice)
{
	if (abilityChoice == 'C')
		return 25;
	else
		return 20;
}
