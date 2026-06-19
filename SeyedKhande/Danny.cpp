#include "Danny.h"

Danny::Danny() : Hero("Danny",4,"Defender",600,"Hichkas iz in khat rad nemishe!")
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
				if (reverse)
				{
					c.target[c.targetindex]->heal(20 * d);
				}
				else
				{
					c.target[c.targetindex]->reducingHP(20 * d);
				}
				
				f = true;
			}
			else if (x.getclassname() == "DrWhite" && x == name && x.isactive())
			{
				int p = x.applypercent(20);
				if (reverse)
				{
					c.target[c.targetindex]->heal(p);
				}
				else
				{
					c.target[c.targetindex]->reducingHP(p);
				}
				f = true;
				Effects e(name, c.target[c.targetindex]->getname(), 1);
			}
		}
	}
	if (!f)
	{
		c.target[c.targetindex]->reducingHP(20);
		Effects e(name, c.target[c.targetindex]->getname(), 1);
	}
	

}

void Danny::ability2(Hero::context& c, vector<Effects>& list)
{
	bool a = false;
	int m = 2;
	if (!list.empty())
	{
		for (auto x : list)
		{
			if (x == name && x.getclassname() == "DrWhite" && x.isactive())
			{
				
				int p = x.applypercent(50);
				if (reverse)
				{
					
					while (m >=0)
					{
						if (c.target[m]->candoaction())
						{
							c.target[m]->heal(p);
							break;
						}
						else
						{
							m--;
						}
					}
					
					c.target[c.targetindex]->heal(p);
				}
				else
				{
					while (m >= 0)
					{
						if (c.target[m]->candoaction())
						{
							c.target[m]->reducingHP(p);
							break;
						}
						else
						{
							m--;
						}
					}
					c.target[c.targetindex]->reducingHP(p);
				}
				
				a = true;
			}
		}
	}
	if (!a)
	{
		if (reverse)
		{

			while (m >= 0)
			{
				if (c.target[m]->candoaction())
				{
					c.target[m]->heal(50);
					break;
				}
				else
				{
					m--;
				}
			}

			c.target[c.targetindex]->heal(50);
		}
		else
		{
			while (m >= 0)
			{
				if (c.target[m]->candoaction())
				{
					c.target[m]->reducingHP(50);
					break;
				}
				else
				{
					m--;
				}
			}
			c.target[c.targetindex]->reducingHP(50);
		}
	}
}

void Danny::special(Hero::context& c, vector<Effects>& list)
{
	if (reverse)
	{
		c.team[0]->reducingHP(250);
		Effects e(name, c.team[0]->getname(), 1, -250, c.team[0]->getHP());
		list.emplace_back(e);
	}
	else
	{
		c.team[0]->heal(250);
		Effects e(name, c.team[0]->getname(), 1, 250, c.team[0]->getHP());
		list.emplace_back(e);
	}
	
	
}
