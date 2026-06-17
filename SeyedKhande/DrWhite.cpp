#include "DrWhite.h"

DrWhite::DrWhite(int energy) : Hero("DrWhite", 4, "Healer", 550, energy, "Biaridesh roy miz ... zende mimone age shanse biyare.")
{

}

Hero::targetorteamtype DrWhite::playerteam(int x)
{
	switch (x)
	{
	case 1: return random; break;
	case 2: return optional; break;
	case 3: return optional; break;
	default: return nobody; break;

	}
}

Hero::targetorteamtype DrWhite::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return nobody; break;
	case 3: return nobody; break;
	default: return nobody; break;

	}
}

void DrWhite::ability1(Hero::context& c, vector <Effect>& list)
{
	bool a = false;
	int u;
	while (1)
	{
		u = rm(1, 3) - 1;
		if (c.team[a]->isalive())
		{
			break;
		}
	}
	for (auto x : list)
	{
		if (x == name && !x.isactive())
		{
			int p = x.applypercent(40);
			c.team[u]->heal(p);
			c.target[c.targetindex]->reducingHP(p);
			a = true;
		}
	}
	if (!a)
	{
		c.team[u]->heal(40);
		c.target[c.targetindex]->reducingHP(40);
		reducingenergy(3);
	} 
}

void DrWhite::ability2(Hero::context& c, vector <Effect>& list)
{

	Effect drwhite(20, 2,(c.team[c.teamindex])->getname());
	list.emplace_back(drwhite);
	reducingenergy(4);
}

bool DrWhite::special(Hero::context& c, vector <Effect>& list)
{
	if (rounds == activespecialpower)
	{
		return 0;
	}
	bool a = false;
	for (auto x : list)
	{
		if (x == name && !x.isactive())
		{
			
			if (!c.team[c.teamindex]->isalive())
			{
				int z = x.applypercent((c.team[c.teamindex]->getHP() + 200));
				c.team[c.teamindex]->heal(z);
			}
			reducingenergy(4);
			a = true;
		}
	}
	if (!a)
	{
		if (!c.team[c.teamindex]->isalive())
		{
			int z = c.team[c.teamindex]->getHP();
			c.team[c.teamindex]->heal(z + 200);
		}
		reducingenergy(4);
	}
	return 1;
}
