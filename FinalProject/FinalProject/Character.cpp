#include "Character.h"
#include <iostream>


string Character::getName()
{
	return _name;
}

string Character::getClass()
{
	return _class;
}

void Character::addMana(int mana)
{
	_mana += mana;
}

void Character::restorePlayerMana()
{
	_mana += 30;
}

void Character::subtractDamage(int damage)
{
	_health -= damage;
}

void Character::subtractMana(int manaCost)
{
	_mana -= manaCost;
}

void Character::addHealth(int heal)
{
	_health += heal;
}

void Character::buffAttack(int buff)
{
	_attack += buff;
}

int Character::getHealth()
{
	return _health;
}

int Character::getMana()
{
	return _mana;
}

int Character::getAttack()
{
	return _attack;
}

int Character::getAbilityValue(char abilityChoice)
{
	return 0;
}

int Character::getAbilityValue(char abilityChoice, int attack)
{
	//_abilityName = "Punch";
	//_abilityDamage = 0;
	//_mana -= 0;
	//_abilityCost = 0;
	return 0;
}

int Character::getManaCost(char abilityChoice)
{
	return 0;
}

Character::Character(string name, string playerClass, int startingHealth, int startingMana, int startingAttack)
{
	_name = name;
	_class = playerClass;
	_health = startingHealth;
	_mana = startingMana;
	_attack = startingAttack;
}


Character::~Character()
{
	cout << "Until next time . . . farewell, challenger!" << endl;
	system("PAUSE");
}
