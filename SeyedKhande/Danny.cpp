#include "Danny.h"

Danny::Danny() : Hero("Danny",4,"Defender",600,"Hichkas iz in khat rad nemishe!")
{
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
	for (auto x : list)
	{
		if (x.getclassname() == name && x == c.target[c.targetindex]->getname() && x.isactive())
		{
			c.target[c.targetindex]->reducingHP(32);
			f = true;
		}
		else if (x.getclassname() == "DrWhite" && x == c.target[c.targetindex]->getname() && x.isactive())
		{

			int p = x.applypercent(20);
			c.target[c.targetindex]->reducingHP(p);
			f = true;
			Effects e(name, c.target[c.targetindex]->getname(), 1);
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
}

bool Danny::special(Hero::context& c, vector<Effects>& list)
{
	return false;
}
