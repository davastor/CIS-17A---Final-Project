#pragma once
#include <string>
using namespace std;

class Character
{
private:
	string _name;
	string _class;
	int _health;
	int _mana;
	int _attack;


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

	Character(string name, string playerClass, int startingHealth, int startingMana, int startingAttack);
	~Character();
};

