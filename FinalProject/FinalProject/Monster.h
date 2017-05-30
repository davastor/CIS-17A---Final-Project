#pragma once
#include <string>
using namespace std;

class Monster
{
private:
	int _monsterRand;
	string _name;
	int _health;
	int _attack;

public:
	string getMonsterName();
	int getMonsterHealth();
	int getMonsterAttack();
	void subtractDamage(int damage);
	Monster(int round);
	~Monster();
};

