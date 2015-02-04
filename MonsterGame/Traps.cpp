#include "Traps.h"

#include <iostream>
using namespace std;

Traps::Traps(void)
{
}


Traps::~Traps(void)
{
}

void Traps::ActivateTrap(double h)
{
	system("cls");

	cout << "You activated a trap!\n";
	cout << "You lost 5 points of health!\n";
	h -= 5;

	cout << "Your remaining health is: " << h << endl;
}
