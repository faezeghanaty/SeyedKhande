#include "Amin.h"

Amin::Amin() : Hero("Amin",3,"Attacker",500,"1 2 3 boom! che kasi mond? mohem nist")
{
	last = false;
}

Hero::targetorteamtype Amin::playerteam(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return optional; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype Amin::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return nobody; break;
	case 3: return random; break;
	default: return nobody; break;
	}
}

int Amin::getenergy(int x)
{
	switch (x)
	{
	case 1: return 3; break;
	case 2: return 3; break;
	case 3: return 4; break;
	default: break;
	}
}

string Amin::getsentence()
{
    return sentence;
}

void Amin::ability1(Hero::context& c, vector<Effects>& list)
{
	int l = 55;
	bool d = false;
	if (last)
		l = 110;
	for (auto x : list)
	{
		if (x.getclassname() == "DrWhite" && name == x && x.isactive())
		{
			int f = x.applypercent(l);
			c.target[c.targetindex]->reducingHP(f);
			d = true;
		}
	}
	if (!d)
	{
		c.target[c.targetindex]->reducingHP(l);
	}
	if (!c.target[c.targetindex]->isalive())
	{
		last = true;
	}

}

void Amin::ability2(Hero::context& c, vector<Effects>& list)
{
	c.team[c.teamindex]->reducingHP(25);
	heal(75);
}

bool Amin::special(Hero::context& c, vector<Effects>& list)
{
	if (rounds == activespecialpower)
	{
		return 0;
	}
	bool d;
	int s = rm(1, 3) - 1;
	for (auto x : list)
	{
		if (x.getclassname() == "DrWhite" && name == x && x.isactive())
		{
			int f = x.applypercent(250);
			c.target[s]->reducingHP(f);
			d = true;
		}
	}
	if (!d)
	{
		c.target[s]->reducingHP(250);
	}
	for (int y = 0; y < 3; y++)
	{
		if (c.team[y]->getname() != name)
		{
			c.team[y]->reducingHP(30);
		}
	}
	return 1;
}
