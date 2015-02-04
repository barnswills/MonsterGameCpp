#include "Enemies.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Enemies::Enemies(void)
{
	haveBeenDefeated = false;
	deathCount = 3;
}

Enemies::~Enemies(void)
{

}

void Enemies::SmallGremlin()
{
	enemyName = "Small Gremlin";
	enemyHealth = 20;
	enemyPower = rand() % 10 + 5;
	enemyShield = 1.1;
}

void Enemies::GreaterGremlin()
{
	enemyName = "Greater Gremlin";
	enemyHealth = 20;
	enemyPower = rand() % 25 + 10;
	enemyShield = 0.9;
}

void Enemies::Minotaur()
{
	enemyName = "Minotaur";
	enemyHealth = 20;
	enemyPower = rand() % 45 + 30;
	enemyShield = 0.85;
}

void Enemies::Dragon()
{
	enemyName = "Dragon";
	enemyHealth = 20;
	enemyPower = rand() % 60 + 50;
	enemyShield = 0.8;
}

void Enemies::LaunchEnemy(double pHealth)
{
	system("cls");

	playerShield = 1.0;
	playerPower = 50;
	
	enemyChance = rand() % 100 + 1;
	
	if (enemyChance > 0 && enemyChance <= 50)
		SmallGremlin();

	if (enemyChance > 50 && enemyChance <= 80)
		GreaterGremlin();

	if (enemyChance > 80 && enemyChance <= 95)
		Minotaur();

	if (enemyChance > 95 && enemyChance <= 100)
		Dragon();

	cout << "A ";
	cout << enemyName;
	cout << " has appeared!\n\n";
	
	// start of battle loop
	while (enemyHealth > 0)
	{
		cout << "Your options:\n1. Attack\n2. Heal\n3. Raise Defense\n\n";
		cout << "Option: ";
		
		cin >> action;

		if (action == 1)
		{
			enemyHealth -= (playerPower * enemyShield);

			cout << "\nYou launched an attack!\n";
		}

		if (action == 2)
		{
			pHealth += 20;
			cout << "You raised your health!\n\n";
			cout << "You have " << pHealth << " health remaining!\n\n";
		}

		if (action == 3)
		{
			playerShield += 0.5;
			cout << "\nYou have increased your defence!\n\n";
		}

		if (enemyHealth > 0)
		{
			/*enemyAction = rand() % 2 + 1;*/
			enemyAction = 1;
			
			if (enemyAction == 1)
			{
				cout << "\nThe ";
				cout << enemyName;
				cout << " unleashed an attack!\n\n";
				
				damage = (enemyPower * playerShield);
				
				pHealth -= damage;
		
				cout << "The enemy did " << damage << " Damage!\n\n";
				cout << "You have " << pHealth << " remaining!\n";
			}

			if (enemyAction == 2)
			{
				cout << "The ";
				cout << enemyName;
				cout << " raised its defense!\n\n";
				
				enemyShield -= 0.5;
			}
		}

		else if (enemyHealth <= 0)
		{
			cout << enemyName;
			cout << " has been defeated!\n\n";
			deathCount--;

			if (deathCount == 0)
			{
				haveBeenDefeated = true;
			}
		}
	}
}