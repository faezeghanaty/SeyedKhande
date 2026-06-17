#include "BigTaha.h"

BigTaha::BigTaha() : Hero("BigTaha",4,"Attacker",500,"In yeki baraye dadash kochikam bood..hala nobat toe")
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
	bool a;
	for (auto x : list)
	{
		if (x == name && x.getclassname() == "DrWhite" && x.isactive())
		{
			int p = x.applypercent(30);
			for (int y = 0; y < 3; y++)
			{
				c.target[y]->reducingHP(p);
			}
			a = true;
		}
	}
	if (!a)
	{
		for (int y = 0; y < 3; y++)
		{
			c.target[y]->reducingHP(30);
		}
	}
}

void BigTaha::ability2(Hero::context& c, vector<Effects>& list)
{
	c.target[c.targetindex]->reducingHP(90);
	ishidden = true;
}

bool BigTaha::special(Hero::context& c, vector<Effects>& list)
{
	if (rounds == activespecialpower)
	{
		return 0;
	}
	long int y = c.target[c.targetindex]->getHP();
	if (y < 360)
	{
		c.target[c.targetindex]->reducingHP(y);
	}
	else
	{
		c.target[c.targetindex]->reducingHP(200);
	}
	Effects e(name, c.target[c.targetindex]->getname(), 1, 360);
	return 1;
}
