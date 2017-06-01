#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include "Monster.h"
#include "Character.h"
#include "Items.h"
#include "Warrior.h"
#include "Mage.h"
//#include "Abilities.h"

using namespace std;

void CharacterCreation(string &name, char &prof);
void Rounds(shared_ptr <Character> player);
bool Combat(shared_ptr<Monster> &monster, shared_ptr<Character> &player);
//int Ability(shared_ptr<Character> &character, shared_ptr<Monster> &monster);
void collectLoot(shared_ptr<Character> &character, shared_ptr<Monster> monster);

int main()
{
	string name = "";
	char prof = 'a';
	CharacterCreation(name, prof);

	if (prof == 'W')
		Rounds(make_shared <Warrior>(name));
	else
		Rounds(make_shared <Mage>(name));

	return 0;
}

void CharacterCreation(string &name, char &prof)
{
	cout << "Welcome to the arena!  What is your name challenger?" << endl;
	getline(cin, name);
	cout << "\nWhat is your profession? A (W)arrior? Perhaps a (M)age?" << endl;
	cin >> prof;
	prof = toupper(prof);
}

void Rounds(shared_ptr<Character> character)
{
	system("cls");
	cout << "\nPrepare for battle challenger!  Survive 5 rounds and you shall be victorious!" << endl;
	cout << "Each round you will be restored 30 mana.  Good luck . . ." << endl;

	bool death = false;
	for (int round = 1; round <= 5; round++)
	{
		cout << "\nRound: " << round << endl;
		auto monster = make_shared<Monster>(round);
		cout << "A " << monster->getMonsterName() << " appears!\n" << endl;
		death = Combat(monster, character);

		if (death == true)
		{
			cout << "You have died! Perhaps you will prevail in your next life! " << endl;
			break;
		}
	}

	if (death == false)
		cout << "\nCongratulations, challenger!  You have bested the monsters of the arena.  Consider your life a gift to commemorate your victory . . . HA HA HA! " << endl;
}

bool Combat(shared_ptr<Monster> &monster, shared_ptr<Character> &character)
{
	system("cls");
	character->restorePlayerMana();
	char action;
	while (monster->getMonsterHealth() > 0)
	{
		cout << left << setw(24) << character->getClass() + ": " + character->getName() << monster->getMonsterName() << endl;
		cout << "Health: " << left << setw(16) << character->getHealth() << "Health: " << monster->getMonsterHealth() << endl;
		cout << "Mana: " << left << setw(18) << character->getMana() << "Attack: " << monster->getMonsterAttack() << endl;
		cout << "Attack: " << character->getAttack() << endl;

		cout << "\nWhat will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		if (toupper(action) == 'M')
		{
			monster->subtractDamage(character->getAttack());
			cout << "\nYou deal " << character->getAttack() << " damage." << endl;
		}

		else
		{
			//Ability(character, monster);
		}

		if (monster->getMonsterHealth() > 0)
		{
			cout << "The " + monster->getMonsterName() + " hits you for "
				<< monster->getMonsterAttack() << " damage.\n" << endl;
			character->subtractDamage(monster->getMonsterAttack());
		}

		if (character->getHealth() <= 0)
		{
			return true;
		}
	}

	cout << "\nYou have defeated the " << monster->getMonsterName() << "." << endl;
	if (monster->getMonsterName() != "Elder Lich")
		collectLoot(character, monster);

	return false;
}

void collectLoot(shared_ptr <Character> &character, shared_ptr <Monster> monster)
{
	Items item = Items();
	string itemName = item.getItemName();

	cout << "\nYou have obtained a " << itemName << " from the corpse of the " << monster->getMonsterName() << "." << endl;

	if (itemName == "Mysterious Amulet")
	{
		cout << "You have gained " << item.getAttackBuff() << " attack." << endl;
		character->buffAttack(item.getAttackBuff());
	}
	else if (itemName == "Health Potion")
	{
		cout << "You have gained " << item.getHealthInc() << " health." << endl;
		character->addHealth(item.getHealthInc());
	}
	else
	{
		cout << "You have gained " << item.getManaInc() << " mana." << endl;
		character->addMana(item.getManaInc());
	}
}

/*int Ability(Character &character, Monster &monster)
{
char choice;
int damage;
int heal;

system("cls");

cout << "\nWhat ability will you use?" << endl;
if (character.getClass() == "Warrior")
{
cout << "\n(C)leave (2x damage, -25 MP)" << endl;
cout << "(W)ar Cry (+50 HP, -20 MP)" << endl;
cin >> choice;
choice = toupper(choice);
Abilities ability = Abilities(choice, character.getAttack());

while (character.getMana()-ability.getManaCost() < 0)
{
cout << "\nYou attempted to cast your ability but failed. " << endl;
return 0;
}

if (choice == 'C')
{
damage = ability.getAbilityDamage(choice, character.getAttack());
cout << "\nYou deal " << damage << " damage. " << endl;
monster.subtractDamage(damage);
}
else
{
heal = ability.getHealAmt();
cout << "\nYou healed for " << heal << "." << endl;
character.addHealth(heal);
}

character.subtractMana(ability.getManaCost());
}

if (character.getClass() == "Mage")
{
cout << "\n(M)ana Bomb (200 damage, -100 MP)" << endl;
cout << "(H)eal (+120 HP, -50 MP)" << endl;
cin >> choice;
choice = toupper(choice);
Abilities ability = Abilities(choice, character.getAttack());

while (character.getMana() - ability.getManaCost() < 0)
{
cout << "\nYou attempted to cast your ability but failed. " << endl;
return 0;
}

if (choice == 'M')
{
damage = ability.getAbilityDamage(choice, character.getAttack());
cout << "\nYou deal " << damage << " damage." << endl;
monster.subtractDamage(damage);
}
else
{
heal = ability.getHealAmt();
cout << "You healed for " << heal << "." << endl;
character.addHealth(heal);
}

character.subtractMana(ability.getManaCost());
}

return 0;
}

*/