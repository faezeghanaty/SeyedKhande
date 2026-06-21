#include "Amin.h"

Amin::Amin() : Hero("AMINIMENI",3,"Attacker",500,"1 2 3 boom! che kasi mond? mohem nist")
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
			if (x.getclassname() == "DRWHITE" && name == x && x.isactive())
			{
				int f = x.applypercent(l);
				c.target[c.targetindex]->reducingHP(f,list);
				d = true;
			}
		}
	}
	
	if (!d)
	{
		c.target[c.targetindex]->reducingHP(l,list);
	}
	if (!c.target[c.targetindex]->isalive())
	{
		last *= 2;
	}

}

void Amin::ability2(Hero::context& c, vector<Effects>& list)
{
	c.team[c.teamindex]->reducingHP(25,list);
	heal(75,list);
	
}

void Amin::special(Hero::context& c, vector<Effects>& list)
{
	bool d = false;
	bool found = false;
	int s;
	for (int i = 0;i<3 && found == false;i++)
	{
		s = rm(1, 3) - 1;
		if (c.target[s]->candoaction()) 
		{
			found = true;
		}
	}
	if (found == false)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER.");
	}
	else
	{
		if (!list.empty())
		{
			for (auto x : list)
			{
				if (x.getclassname() == "DRWHITE" && name == x && x.isactive())
				{
					int f = x.applypercent(250);
					if (found)
					{
						c.target[s]->reducingHP(f, list);
					}
					
					for (int y = 0; y < 3; y++)
					{
						if (c.team[y]->getname() != name && c.team[y]->isalive())
						{
							c.team[y]->reducingHP(x.applypercent(30), list);
						}
					}
					d = true;

				}
			}
		}

		if (!d)
		{
			if (found)
			{
				c.target[s]->reducingHP(250, list);
			}
			
			for (int y = 0; y < 3; y++)
			{
				if (c.team[y]->getname() != name && c.team[y]->isalive())
				{
					c.team[y]->reducingHP(30, list);
				}
			}
		}

	}
	}
	
