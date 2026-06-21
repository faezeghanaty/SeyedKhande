#include "Shahriyar.h"

Shahriyar::Shahriyar() : Hero("AQASHAHRIYAR",4,"Joker",500,"Khob mishe bad...bad mishe khob...man ki hastam?..aqa shahriyar...boland tekrar konid")
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
	bool z=false;
	int r = rm(1, 20);
	if (r != 1)
	{
		if (!list.empty())
		{
			for (auto x : list)
			{
				if (x.getclassname() == "DRWHITE" && x == name && x.isactive())
				{
					int a = x.applypercent(60);
					c.target[c.targetindex]->reducingHP(a, list);
					z = true;
				}
			}
		}
		
		if (z == false)
		{
			c.target[c.targetindex]->reducingHP(60,list);
		}
	}
}

void Shahriyar::ability2(Hero::context& c, vector<Effects>& list)
{
	int m;
	bool found = false;
	for (int i = 0;i<3 && !found;i++)
	{
		m = rm(1, 3) - 1;
		if (m != c.targetindex && c.target[m]->candoaction())
		{
			c.target[m]->reducingHP(100, list);
			found = true;
			break;
		}
	}
	if (!found)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER");
	}
	
}

void Shahriyar::special(Hero::context& c, vector<Effects>& list)
{
	Effects e(name, "", 2);
	list.emplace_back(e);
}
