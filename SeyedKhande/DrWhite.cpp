#include "DrWhite.h"

DrWhite::DrWhite() : Hero("DRWHITE", 4, "Healer", 550, "Biaridesh roy miz ... zende mimone age shanse biyare.")
{

}

Hero::targetorteamtype DrWhite::playerteam(int x)
{
	switch (x)
	{
	case 1: return random; break;
	case 2: return optional; break;
	case 3: return nobody; break;
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
	bool found = false;
	int u;
	for(int i = 0;i<3;i++)
	{
		u = rm(1, 3) - 1;
		if (c.team[u]->candoaction())
		{
			c.team[u]->heal(40, list);
			found = true;
			break;
		}
	}
	if (!found)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER");
	}
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x == name && x.getclassname() == "DRWHITE" && x.isactive())
			{
				int p = x.applypercent(40);
				
				c.target[c.targetindex]->reducingHP(p,list);
				a = true;
			}
		}
	}
	if (!a)
	{
		
		c.target[c.targetindex]->reducingHP(40,list);
		
	} 

}

void DrWhite::ability2(Hero::context& c, vector <Effects>& list)
{

	Effects drwhite(name, c.team[c.teamindex]->getname(), 2, 20);
	list.emplace_back(drwhite);

}

void DrWhite::special(Hero::context& c, vector <Effects>& list)
{
	bool found = false;
	for (int i = 0; i < 3 && !found; i++)
	{
		if (!c.team[i]->isalive() && c.team[i]->getname() != name)
		{
			int z = c.team[i]->getHP();
			c.team[i]->heal(-z + 200, list);
			found = true;
		}
	}
}
