#include "SmallTaha.h"
SmallTaha::SmallTaha() : Hero("TAHAKOCHIKE",3,"Healer",500,"Hame dar jay khod!in mantaqe alode ast")
{

}
Hero::targetorteamtype SmallTaha::playerteam(int x)
{
	switch (x)
	{
	case 1: return lowest; break;
	case 2: return optional; break;
	case 3: return lowest; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype SmallTaha::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return nobody; break;
	case 3: return nobody; break;
	default: return nobody; break;

	}
}

int SmallTaha::getenergy(int x)
{
	switch (x)
	{
	case 1: return 2; break;
	case 2: return 4; break;
	case 3: return 4; break;
	default: break;
	}
}

string SmallTaha::getsentence()
{
	return sentence;
}

void SmallTaha::ability1(Hero::context& c, vector<Effects>& list)
{
	int m = 0;
	bool found = false;
	while (m < 3)
	{
		if (c.team[m]->candoaction())
		{
			c.team[0]->heal(20,list);
			found = true;
			break;
		}
		else
		{
			m++;
		}
	}
	if (!found)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER");
	}
	bool f = false;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x.getclassname() == "DRWHITE" && x == name && x.isactive())
			{
				int p = x.applypercent(30);
				c.target[c.targetindex]->reducingHP(p,list);
				f = true;
			}
		}
	}
	
	if (!f)
	{
		c.target[c.targetindex]->reducingHP(30,list);
	}

}

void SmallTaha::ability2(Hero::context& c, vector<Effects>& list)
{
	c.team[c.teamindex]->heal(40,list);
	Effects e(name, c.team[c.teamindex]->getname(), 1, 40);
	list.emplace_back(e);

}

void SmallTaha::special(Hero::context& c, vector<Effects>& list)
{
	int m = 0;
	bool found=false;
	while (m < 3)
	{
		if (c.team[m]->candoaction())
		{
			c.team[m]->heal(200,list);
			found = true;
			break;
		}
		else
		{
			m++;
		}
	}
	if (!found)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER");
	}
}
