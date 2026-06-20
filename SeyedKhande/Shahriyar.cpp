#include "Shahriyar.h"

Shahriyar::Shahriyar() : Hero("Shahriyar",4,"Joker",500,"Khob mishe bad...bad mishe khob...man ki hastam?..aqa shahriyar...boland tekrar konid")
{
}

Hero::targetorteamtype Shahriyar::playerteam(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return nobody; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype Shahriyar::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return optional; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

int Shahriyar::getenergy(int x)
{
	switch (x)
	{
	case 1: return 2; break;
	case 2: return 4; break;
	case 3: return 8; break;
	default: break;
	}
}

string Shahriyar::getsentence()
{
	return sentence;
}

void Shahriyar::ability1(Hero::context& c, vector<Effects>& list)
{
	bool z;
	int r = rm(1, 20);
	if (r != 1)
	{
		for (auto x : list)
		{
			if (x.getclassname() == "DrWhite" && name == x && x.isactive())
			{
				int a = x.applypercent(60);
				if (reverse)
				{
					c.target[c.targetindex]->heal(a);
				}
				else
				{
					c.target[c.targetindex]->reducingHP(a);
				}
				z = true;
			}
		}
		if (!z)
		{
			if (reverse)
			{
				c.target[c.targetindex]->heal(60);
			}
			else
			{
				c.target[c.targetindex]->reducingHP(60);
			}
		}
	}
}

void Shahriyar::ability2(Hero::context& c, vector<Effects>& list)
{
	int m;
	while (1)
	{
		int m = rm(1, 3) - 1;
		if (m != c.targetindex && c.target[m]->candoaction())
		{
			break;
		}
	}
	if (reverse)
	{
		c.target[m]->heal(100);
	}
	else
	{
		c.target[m]->reducingHP(100);
	}
}

void Shahriyar::special(Hero::context& c, vector<Effects>& list)
{
	Effects e(name, "", 2);
}
