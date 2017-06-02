#include "Monster.h"
#include <ctime>


string Monster::getMonsterName()
{
	return _name;
}

int Monster::getMonsterHealth()
{
	return _health;
}

int Monster::getMonsterAttack()
{
	return _attack;
}

void Monster::subtractDamage(int damage)
{
	_health -= damage;

}

Monster::Monster(int round)
{
	if (round == 1)
	{
		_name = "Goblin";
		_health = 60;
		_attack = 10;
	}
	else if (round == 2)
	{
		_name = "Skeleton";
		_health = 100;
		_attack = 15;
	}
	else if (round == 3)
	{
		_name = "Minotaur";
		_health = 150;
		_attack = 20;
	}
	 
	else if (round == 4)
	{
		_name = "Wyvern";
		_health = 200;
		_attack = 30;
	}
	else
	{
		_name = "Elder Lich";
		_health = 300;
		_attack = 40;
	}
	
}

Monster::~Monster()
{

}
