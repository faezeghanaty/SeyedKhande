#include "Pouya.h"

Pouya::Pouya() : Hero("POUYAKAZHDOM",3,"Attacker",550,"Nisham ro didi? na ? khob ... dige hichvaqt nemibini")
{
}

Hero::targetorteamtype Pouya::playerteam(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return nobody; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype Pouya::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return optional; break;
	case 3: return random; break;
	default: return nobody; break;
	}
}

int Pouya::getenergy(int x)
{
	switch (x)
	{
	case 1: return 2; break;
	case 2: return 4; break;
	case 3: return 5; break;
	default: break;
	}
}

string Pouya::getsentence()
{
	return sentence;
}

void Pouya::ability1(Hero::context& c, vector<Effects>& list)
{
	bool z=false;
	if (!list.empty())
	{
		for (auto & x : list)
		{
			if (x.getclassname() == "DRWHITE" && name == x && x.isactive())
			{
				int a = x.applypercent(40);
				c.target[c.targetindex]->reducingHP(a, list);
				z = true;
			}
			if (x.getclassname() == name && x == c.target[c.targetindex]->getname() && x.isactive())
			{
				x.sethp(60);
			}
		}
	}
	
	if (!z)
	{
		c.target[c.targetindex]->reducingHP(40,list);
	}

}

void Pouya::ability2(Hero::context& c, vector<Effects>& list)
{
	Effects e(name, c.target[c.targetindex]->getname(), 15, 0, 20);
	list.emplace_back(e);
	
	
}

void Pouya::special(Hero::context& c, vector<Effects>& list)
{
	
	Effects e(name,"", 3);
	list.emplace_back(e);
	ishidden = true;
}
