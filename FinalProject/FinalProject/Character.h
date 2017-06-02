#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Items.h"
using namespace std;

class Character
{
private:
	vector <shared_ptr<Items>> inventory;
	string _name;
	string _class;
	int _health;
	int _mana;
	int _attack;
	bool mysteriousAbility = false;
	int mysteriousEquipCounter = 0;

public:
	string getName();
	string getClass();
	void addMana(int mana);
	void restorePlayerMana();
	void subtractDamage(int damage);
	void subtractMana(int manaCost);
	void addHealth(int heal);
	void buffAttack(int buff);
	int getHealth();
	int getMana();
	int getAttack();
	virtual int getAbilityValue(char abilityChoice);
	virtual int getAbilityValue(char abilityChoice, int attack);
	virtual int getManaCost(char abilityChoice);
	string viewInventory();
	void addItem(shared_ptr<Items> item);
	void setMysteriousAbilityTrue();
	void setMysteriousAbilityFalse();
	bool getMysteriousAbilityStatus();
	int useRecursiveAttack(int counter);
	int getMysteriousEquipCounter();
	void mysteriousAbilityIncrementor();



	Character(string name, string playerClass, int startingHealth, int startingMana, int startingAttack);
	~Character();
};

