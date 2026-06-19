#include "Amin.h"

Amin::Amin() : Hero("Amin",3,"Attacker",500,"1 2 3 boom! che kasi mond? mohem nist")
{
	last = 1;
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
	int l = 55 * last;
	bool d = false;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x.getclassname() == "DrWhite" && name == x && x.isactive())
			{
				int f = x.applypercent(l);
				if (reverse)
				{
					c.target[c.targetindex]->heal(f);
				}
				else
				{
					c.target[c.targetindex]->reducingHP(f);
				}
				
				d = true;
			}
		}
	}
	
	if (!d)
	{
		if (reverse)
		{
			c.target[c.targetindex]->heal(l);
		}
		else
		{
			c.target[c.targetindex]->reducingHP(l);
		}
	}
	if (!c.target[c.targetindex]->isalive())
	{
		last *= 2;
	}

}

void Amin::ability2(Hero::context& c, vector<Effects>& list)
{
	if (reverse)
	{
		c.team[c.targetindex]->heal(25);
		reducingHP(75);
	}
	else
	{
		c.team[c.teamindex]->reducingHP(25);
		heal(75);
	}
}

void Amin::special(Hero::context& c, vector<Effects>& list)
{
	bool d = false;
	
	int s;
	while (1)
	{
		s = rm(1, 3) - 1;
		if (c.target[s]->candoaction())
		{
			break;
		}
	}
	
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x.getclassname() == "DrWhite" && name == x && x.isactive())
			{
				int f = x.applypercent(250);
				if (reverse)
				{
					c.target[s]->heal(f);
					for (int y = 0; y < 3; y++)
					{
						if (c.team[y]->getname() != name && c.team[y]->isalive())
						{
							c.team[y]->heal(30);
						}
					}
				}
				else
				{
					c.target[s]->reducingHP(f);
					for (int y = 0; y < 3; y++)
					{
						if (c.team[y]->getname() != name && c.team[y]->isalive())
						{
							c.team[y]->reducingHP(30);
						}
					}
				}
				d = true;
				
			}
		}
	}
	
	if (!d)
	{
		if (reverse)
		{
			c.target[s]->heal(250);
			for (int y = 0; y < 3; y++)
			{
				if (c.team[y]->getname() != name && c.team[y]->isalive())
				{
					c.team[y]->heal(30);
				}
			}
		}
		else
		{
			c.target[s]->reducingHP(250);
			for (int y = 0; y < 3; y++)
			{
				if (c.team[y]->getname() != name && c.team[y]->isalive())
				{
					c.team[y]->reducingHP(30);
				}
			}
		}
	}
	
}
