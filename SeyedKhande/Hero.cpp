#include "Hero.h"

void Heros::isalive()
{
	if (HP == 0)
	{
		isdead = true;
	}
}

void Heros::countrounds()
{
	rounds++;
}

void Heros::heal(long int x)
{
	if (!isdead)
	{
		HP = HP + x;
	}
}

long int Heros::reducingHP(long int x)
{
	HP = HP - x;
	isalive();
}

int Heros::getenergy() const
{
	return energy;
}
