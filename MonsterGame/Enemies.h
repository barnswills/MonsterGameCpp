#ifndef ENEMIES_H
#define ENEMIES_H

#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Enemies
{
public:
	Enemies(void);
	~Enemies(void);

	double enemyPower;
	int enemyChance;
	int enemyAction;
	double enemyHealth;
	double enemyShield;

	double damage;

	double playerShield;
	int playerPower;
	double playerHealth;

	int escapePercentage;
	int escapeChance;

	bool hasFled;
	bool haveBeenDefeated;

	string enemyName;
	double difficultyIncrease;

	int action;

	string enemyArray[4];

	int deathCount;

	void LaunchEnemy(double pHealth);
	void SmallGremlin();
	void GreaterGremlin();
	void Minotaur();
	void Dragon();
	void EnemyResponse(double h);
};

#endif

