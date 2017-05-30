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
	if (round != 5)
	{
		srand((unsigned int)time(NULL));
		_monsterRand = rand() % 3;

		if (_monsterRand == 0)
		{
			_name = "Minotaur";
			_health = 200;
			_attack = 20;
		}
		else if (_monsterRand == 1)
		{
			_name = "Goblin";
			_health = 60;
			_attack = 10;
		}
		else
		{
			_name = "Wyvern";
			_health = 150;
			_attack = 30;
		}
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
