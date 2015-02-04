#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "Traps.h"
#include "Enemies.h"
using namespace std;

void Arena(string n);
void Ending();

class Player
{
public:
	void setName(string x)
	{
		playerName = x;
	}
	string getName()
	{
		return playerName;
	}

private:
	string playerName;
};

void Initiate()
{
	string name;
	int playerHealth = 100;

	cout << "WELCOME TO THE ARENA\n";
	cout << "PLEASE ENTER YOUR NAME: ";

	cin >> name;

	Player p;
	p.setName(name);

	system("cls");
	cout << "HELLO " << name;
	cout << "\nBEING DEPLOYED INTO THE ARENA...\n";
	Arena(name);
}

void Arena(string n)
{
	int choice = 0;
	double playerHealth = 100;

	Traps traps;
	Enemies enemies;

	cout << n << ", YOU HAVE ENTERED THE ARENA!\n\n";

	while(playerHealth > 0 && enemies.haveBeenDefeated == false)
	{
		cout << "Its pitch black, what do you do?\n\n";
		cout << "1. Go Left\n2. Go Right\n3. Go Up\n4. Go Down\n\n";
		cout << "Your choice: ";
		cin >> choice;

		srand(time(0));
		int chance = rand()%100 + 1;

		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
		{
			if (chance > 0 && chance <= 50)
			{
				enemies.LaunchEnemy(playerHealth);
			}

			/*if (chance > 33 && chance <= 66)
			{
				traps.ActivateTrap(playerHealth);
			}
			*/

			if (chance > 50 && chance <= 100)
			{
				system("cls");
				cout << "Nothing happened.\n";
			}
		}
		else
		{
			system("cls");
			cout << "wrong input - 1, 2, 3 or 4 only!\n";
		}
	}

	system("cls");
	cout << "YOU HAVE CONQUERED THE ARENA!\nYOU ARE OUR CHAMPION!";
}

int main()
{
	Initiate();
	cin.ignore(2);
}