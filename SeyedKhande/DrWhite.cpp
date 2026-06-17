#include "DrWhite.h"

DrWhite::DrWhite() : Hero("DrWhite", 4, "Healer", 550, "Biaridesh roy miz ... zende mimone age shanse biyare.")
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

int DrWhite::getenergy(int x)
{
	switch (x)
	{
	case 1: return 3; break;
	case 2: return 4; break;
	case 3: return 4; break;
	default: break;
	}
}

string DrWhite::getsentence()
{
	return sentence;
}

void DrWhite::ability1(Hero::context& c, vector <Effects>& list)
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
		if (x == c.target[c.targetindex]->getname() && x.getclassname()== "DrWhite" && x.isactive())
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
		
	} 

}

void DrWhite::ability2(Hero::context& c, vector <Effects>& list)
{

	Effects drwhite(name, c.team[c.teamindex]->getname(), 2, 20);
	list.emplace_back(drwhite);

}

bool DrWhite::special(Hero::context& c, vector <Effects>& list)
{
	if (rounds == activespecialpower)
	{
		return 0;
	}
	if (!c.team[c.teamindex]->isalive())
	{
		int z = c.team[c.teamindex]->getHP();
		c.team[c.teamindex]->heal(z + 200);
	}


	return 1;
}
