#ifndef TRAPS_H
#define TRAPS_H

class Traps
{
public:
	Traps(void);
	~Traps(void);

	int trapPower;
	int trapChance;

	void ActivateTrap(double h);
};

#endif

