#include "BigTaha.h"

BigTaha::BigTaha() : Hero("TAHABOZORGE",4,"Attacker",500,"In yeki baraye dadash kochikam bood..hala nobat toe")
{
	
}

Hero::targetorteamtype BigTaha::playerteam(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return nobody; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype BigTaha::playertarget(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return optional; break;
	case 3: return optional; break; 
	default: return nobody; break;
	}
}

int BigTaha::getenergy(int x)
{
	switch (x)
	{
	case 1: return 3; break;
	case 2: return 4; break;
	case 3: return 3; break;
	default: break;
	}
}

string BigTaha::getsentence()
{
	return sentence;
}

void BigTaha::ability1(Hero::context& c, vector<Effects>& list)
{
	bool a = false;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x == name && x.getclassname() == "DRWHITE" && x.isactive())
			{
				int p = x.applypercent(30);
				for (int y = 0; y < 3; y++)
				{
					if (c.target[y]->isalive())
					{
						c.target[y]->reducingHP(p,list);
					}
				}
				
				a = true;
			}
		}
	}
	
	if (!a)
	{
		for (int y = 0; y < 3; y++)
		{
			if (c.target[y]->isalive())
			{
				c.target[y]->reducingHP(30,list);
			}
		}
		
	}
}

void BigTaha::ability2(Hero::context& c, vector<Effects>& list)
{
	c.target[c.targetindex]->reducingHP(90,list);
	setishidden(true);
	Effects e(name, name, 1);
	list.emplace_back(e);
}

void BigTaha::special(Hero::context& c, vector<Effects>& list)
{
	long int y = c.target[c.targetindex]->getHP();
	if (y < 360)
	{
		c.target[c.targetindex]->reducingHP(y,list);
	}
	else
	{
		c.target[c.targetindex]->reducingHP(200,list);
	}
	Effects e(name, c.target[c.targetindex]->getname(), 1, 360);
	list.emplace_back(e);
}
