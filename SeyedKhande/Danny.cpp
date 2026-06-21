#include "Danny.h"

Danny::Danny() : Hero("DANNYGOLANG",4,"Defender",600,"Hichkas iz in khat rad nemishe!")
{
	d = 1;
}

Hero::targetorteamtype Danny::playerteam(int x)
{
	switch (x)
	{
	case 1: return nobody; break;
	case 2: return nobody; break;
	case 3: return lowest; break;
	default: return nobody; break;
	}
}

Hero::targetorteamtype Danny::playertarget(int x)
{
	switch (x)
	{
	case 1: return optional; break;
	case 2: return optional; break;
	case 3: return nobody; break;
	default: return nobody; break;
	}
}

int Danny::getenergy(int x)
{
	switch (x)
	{
	case 1: return 2; break;
	case 2: return 4; break;
	case 3: return 4; break;
	default: break;
	}
}

string Danny::getsentence()
{
	return sentence;
}

void Danny::ability1(Hero::context& c, vector<Effects>& list)
{
	bool f = false;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x.getclassname() == name && x == c.target[c.targetindex]->getname() && x.isactive())
			{
				d *= 1.6;
				c.target[c.targetindex]->reducingHP(20 * d,list);
				f = true;
			}
			else if (x.getclassname() == "DRWHITE" && x == name && x.isactive())
			{
				int p = x.applypercent(20);
				c.target[c.targetindex]->reducingHP(p,list);
				f = true;
				Effects e(name, c.target[c.targetindex]->getname(), 1);
				list.emplace_back(e);
			}
		}
	}
	if (!f)
	{
		c.target[c.targetindex]->reducingHP(20,list);
		Effects e(name, c.target[c.targetindex]->getname(), 1);
		list.emplace_back(e);
	}
	

}

void Danny::ability2(Hero::context& c, vector<Effects>& list)
{
	bool a = false;
	bool found = false;
	int m = 2;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x == name && x.getclassname() == "DRWHITE" && x.isactive())
			{
				
				int p = x.applypercent(50);
				while (m >= 0)
				{
					if (c.target[m]->candoaction())
					{
						c.target[m]->reducingHP(p,list);
						found = true;
						break;
					}
					else
					{
						m--;
					}
				}
				c.target[c.targetindex]->reducingHP(p, list);
				if (!found)
				{
					throw runtime_error("THERE IS NO ACTIVE PLAYER");
				}
				
				a = true;
			}
		}
	}
	if (!a)
	{
		while (m >= 0)
		{
			if (c.target[m]->candoaction())
			{
				c.target[m]->reducingHP(50,list);
				found = true;
				break;
			}
			else
			{
				m--;
			}
		}
		c.target[c.targetindex]->reducingHP(50, list);
		if (!found) 
		{
			throw runtime_error("THERE IS NO ACTIVE PLAYER");
		}
		
		
	}
}

void Danny::special(Hero::context& c, vector<Effects>& list)
{
	bool found = false;
	for (int i = 0; i < 3 && !found; i++)
	{
		if (c.team[i]->candoaction())
		{
			c.team[i]->heal(250, list);
			Effects e(name, c.team[i]->getname(), 1, 250, c.team[i]->getHP());
			list.emplace_back(e);
			found = true;
		}
	}
	if (!found)
	{
		throw runtime_error("THERE IS NO ACTIVE PLAYER");
	}
}
