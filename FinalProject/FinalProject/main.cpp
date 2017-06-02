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
int Ability(shared_ptr<Character> &character, shared_ptr<Monster> &monster);
void collectLoot(shared_ptr<Character> &character, shared_ptr<Monster> monster);

int main()
{
	string name = "";
	char prof = 'a';
	CharacterCreation(name, prof);

	try
	{
		if (prof == 'W')
			Rounds(make_shared <Warrior>(name));
		else if (prof == 'M')
			Rounds(make_shared <Mage>(name));
		else
			throw string("\nDo you lack the intellect to answer me?  This arena has no need for you! Die!\n");
	}
	catch (string str)
	{
		cout << str << endl;
	}

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
	cout << "Prepare for battle challenger!  Survive 5 rounds and you shall be victorious!" << endl;
	cout << "Each round you will be restored 30 mana.  Good luck . . ." << endl;

	bool death = false;
	for (int round = 1; round <= 5; round++)
	{
		char choice = 'a';
		
		if (character->getMysteriousEquipCounter() > 0)
			character->setMysteriousAbilityTrue();
		if (round != 1)
		{
			while (toupper(choice) != 'S')
			{
				system("cls");
				cout << "What will you do now challenger?" << endl;
				cout << "(S)tart the next round?  (V)iew your inventory?" << endl;
				cin >> choice;
				system("cls");
				if (toupper(choice) == 'V')
				{
					cout << character->viewInventory() << endl;
					system("pause");
				}
			}
		}

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
	
	character->restorePlayerMana();
	char action;
	while (monster->getMonsterHealth() > 0)
	{
		system("pause");
		system("cls");
		cout << left << setw(24) << character->getClass() + ": " + character->getName() << monster->getMonsterName() << endl;
		cout << "Health: " << left << setw(16) << character->getHealth() << "Health: " << monster->getMonsterHealth() << endl;
		cout << "Mana: " << left << setw(18) << character->getMana() << "Attack: " << monster->getMonsterAttack() << endl;
		cout << "Attack: " << character->getAttack() << endl;

		cout << "\nWhat will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		try
		{
			if (toupper(action) == 'M')
			{
				monster->subtractDamage(character->getAttack());
				cout << "\nYou deal " << character->getAttack() << " damage." << endl;
			}
			else if (toupper(action) == 'A')
			{
				Ability(character, monster);
			}
			else
				throw string("Challenger, why do you just stand there? Do something or die!\n");
		}
		catch (string str)
		{
			cout << str << endl;
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

	auto item = make_shared<Items>();
	string itemName = item->getItemName();

	cout << "\nYou have obtained a " << itemName << " from the corpse of the " << monster->getMonsterName() << "." << endl;

	if (itemName == "Mysterious Amulet")
	{
		cout << "You have gained " << item->getAttackBuff() << " attack and a mysterious ability." << endl;
		character->mysteriousAbilityIncrementor();
		character->buffAttack(item->getAttackBuff());
	}
	else if (itemName == "Mysterious Ring")
	{
		cout << "You have gained " << item->getAttackBuff() << " attack and a mysterious ability." << endl;
		character->mysteriousAbilityIncrementor();
		character->buffAttack(item->getAttackBuff());
	}
	else if (itemName == "Health Potion")
	{
		cout << "You have gained " << item->getHealthInc() << " health." << endl;
		character->addHealth(item->getHealthInc());
	}
	else
	{
		cout << "You have gained " << item->getManaInc() << " mana." << endl;
		character->addMana(item->getManaInc());
	}
	character->addItem(item);
	
	system("pause");
}

int Ability(shared_ptr<Character> &character, shared_ptr<Monster> &monster)
{
	char choice;
	int damage;
	int heal;

	//system("cls");

	cout << "\nWhat ability will you use?" << endl;
	if (character->getClass() == "Warrior")
	{
		cout << "\n(C)leave (3x attack damage, -25 MP)" << endl;
		cout << "(W)ar Cry (+50 HP, -20 MP)" << endl;
		if (character->getMysteriousAbilityStatus() == true)
			cout << "(R)ecursive Attack (Can only be once per battle!)" << endl;
		cin >> choice;
		choice = toupper(choice);
	//Abilities ability = Abilities(choice, character.getAttack());

		try 
		{
			if (character->getMana() - character->getManaCost(choice) < 0)
			{
				cout << "\nYou attempted to cast your ability but failed. " << endl;
				return 0;
			}

			if (choice == 'C')
			{
				damage = character->getAbilityValue(choice, character->getAttack());
				cout << "\nYou deal " << damage << " damage. " << endl;
				monster->subtractDamage(damage);
			}
			else if (choice == 'W')
			{
				heal = character->getAbilityValue(choice, 0);
				cout << "\nYou healed for " << heal << "." << endl;
				character->addHealth(heal);
			}
			else if (choice == 'R' && character->getMysteriousAbilityStatus() == true)
			{
				damage = character->useRecursiveAttack(character->getMysteriousEquipCounter()) * 10;
				cout << "\nYou deal " << damage << " damage. " << endl;
				monster->subtractDamage(damage);
				character->setMysteriousAbilityFalse();
			}
			else
				throw string("Are you asleep challenger? Do something!\n");
		}
		catch (string str)
		{
			cout << str << endl;
		}


		character->subtractMana(character->getManaCost(choice));
	}

	if (character->getClass() == "Mage")
	{
		cout << "\n(M)ana Bomb (200 damage, -100 MP)" << endl;
		cout << "(H)eal (+120 HP, -50 MP)" << endl;
		if (character->getMysteriousAbilityStatus() == true)
			cout << "(R)ecursive Attack (Can only be once per battle!)" << endl;

		cin >> choice;
		choice = toupper(choice);

		try
		{
			if (character->getMana() - character->getManaCost(choice) < 0)
			{
				cout << "\nYou attempted to cast your ability but failed. " << endl;
				return 0;
			}

			if (choice == 'M')
			{
				damage = character->getAbilityValue(choice);
				cout << "\nYou deal " << damage << " damage. " << endl;
				monster->subtractDamage(damage);
			}
			else if (choice == 'H')
			{
				heal = character->getAbilityValue(choice);
				cout << "\nYou healed for " << heal << "." << endl;
				character->addHealth(heal);
			}
			else if (choice == 'R' && character->getMysteriousAbilityStatus() == true)
			{
				damage = character->useRecursiveAttack(character->getMysteriousEquipCounter()) * 10;
				cout << "\nYou deal " << damage << " damage. " << endl;
				monster->subtractDamage(damage);
				character->setMysteriousAbilityFalse();
			}
			else
				throw string("Are you asleep challenger? Do something!\n");
		}
		catch (string str)
		{
			cout << str << endl;
		}

		character->subtractMana(character->getManaCost(choice));
	}

	return 0;
}

