#include "SmallTaha.h"
SmallTaha::SmallTaha(int energy) : Hero("SmallTaha",3,"Healer",500,energy,"Hame dar jay khod!in mantaqe alode ast")
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

void SmallTaha::ability1(Hero::context& c, vector<Effects>& list)
{
	c.team[0]->heal(20);
	bool f = false;
	for (auto x : list)
	{
		if (x.getclassname() == "DrWhite" && x == name && x.isactive())
		{
			int p = x.applypercent(30);
			c.team[c.targetindex]->reducingHP(p);
			f = true;
		}
	}
	if (!f)
	{
		c.team[c.targetindex]->reducingHP(30);
	}

}

void SmallTaha::ability2(Hero::context& c, vector<Effects>& list)
{
	c.team[c.teamindex]->heal(40);
	Effects e("SmallTaha", c.team[c.teamindex]->getname(), 1, 40);
	list.emplace_back(e);

}

bool SmallTaha::special(Hero::context& c, vector<Effects>& list)
{
	if (rounds == activespecialpower)
	{
		return 0;
	}
	c.team[0]->heal(200);
	return 1;
}
