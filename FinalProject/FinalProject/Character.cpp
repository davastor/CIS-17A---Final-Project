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

	return 0;
}

int Character::getManaCost(char abilityChoice)
{
	return 0;
}

string Character::viewInventory()
{
	string str;

	for (auto item : inventory)
	{
		if(item->getItemName() != "Health Potion" && item->getItemName() != "Mana Potion")
			str += "\n" + item->getItemName() + " - Effect: +" + to_string(item->getAttackBuff()) + " Attack";
	}

	return str;
}

void Character::addItem(shared_ptr<Items> item)
{
	inventory.push_back(item);
}

void Character::setMysteriousAbilityTrue()
{
	mysteriousAbility = true;

}

void Character::setMysteriousAbilityFalse()
{
	mysteriousAbility = false;
}

bool Character::getMysteriousAbilityStatus()
{
	return mysteriousAbility;
}

int Character::getMysteriousEquipCounter()
{
	return mysteriousEquipCounter;
}

void Character::mysteriousAbilityIncrementor()
{
	mysteriousEquipCounter++;
}

int Character::useRecursiveAttack(int counter)
{
	if(counter > 0)
		return counter*useRecursiveAttack(counter-1);

	return 1;
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
	cout << "THE END!" << endl;
	system("PAUSE");
}


void Character::addHealth(int heal)
{
	_health += heal;
}


void Character::buffAttack(int buff)
{
	_attack += buff;
}

void Character::addMana(int mana)
{
	_mana += mana;
}
