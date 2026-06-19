#include "SmallTaha.h"
SmallTaha::SmallTaha() : Hero("SmallTaha",3,"Healer",500,"Hame dar jay khod!in mantaqe alode ast")
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
	while (m < 3)
	{
		if (c.team[m]->candoaction())
		{
			if (reverse)
			{
				c.team[0]->reducingHP(20);
			}
			else
			{
				c.team[0]->heal(20);
			}
			
			break;
		}
		else
		{
			m++;
		}
	}
	
	bool f = false;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x.getclassname() == "DrWhite" && x == name && x.isactive())
			{
				int p = x.applypercent(30);
				if (reverse)
				{
					c.target[c.targetindex]->heal(p);
				}
				else
				{
					c.target[c.targetindex]->reducingHP(p);
				}
				
				f = true;
			}
		}
	}
	
	if (!f)
	{
		if (reverse)
		{
			c.target[c.targetindex]->heal(30);
		}
		else
		{
			c.target[c.targetindex]->reducingHP(30);
		}
		
	}

}

void SmallTaha::ability2(Hero::context& c, vector<Effects>& list)
{
	if (reverse)
	{
		c.team[c.teamindex]->reducingHP(40);
		Effects e("SmallTaha", c.team[c.teamindex]->getname(), 1, -40);
		list.emplace_back(e);
	}
	else
	{
		c.team[c.teamindex]->heal(40);
		Effects e("SmallTaha", c.team[c.teamindex]->getname(), 1, 40);
		list.emplace_back(e);
	}
	

}

void SmallTaha::special(Hero::context& c, vector<Effects>& list)
{
	int m = 0;
	while (m < 3)
	{
		if (c.team[m]->candoaction())
		{
			if (reverse)
			{
				c.team[0]->reducingHP(200);
			}
			else
			{
				c.team[0]->heal(200);
			}

			break;
		}
		else
		{
			m++;
		}
	}
	
}
