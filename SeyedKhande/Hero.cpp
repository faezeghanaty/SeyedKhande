#include "Hero.h"


Hero::Hero(string name,int active, string role, long int HP, string sentence, bool isdead, bool ishidden) : name(name),activespecialpower(active), role(role), HP(HP), sentence(sentence),maxHP(HP)
{
}

bool Hero::isalive()
{
	if (HP <= 0)
	{
		isdead = true;
		return false;
	}
	return true;
}

void Hero::setishidden(bool x)
{
	ishidden = x;
}

bool Hero::candoaction()
{
	return !(isdead && ishidden);
}

bool Hero::reverse(vector<Effects>& list)
{
	if (list.empty())
	{
		return 0;
	}
	for (auto x : list)
	{
		if (x.getclassname() == "Shahriyar" && x.isactive())
		{
			return 1;
		}
	}
	return 0;
}

long int Hero::getHP()
{
	return HP;
}

void Hero::setHp(long int hp)
{
	HP = hp;
}

string Hero::getname() const
{
	return name;
}

int Hero::countrounds()
{
	return activespecialpower;
}

void Hero::heal(long int x)
{
	if (!isdead && (HP+x)<maxHP)
	{
		HP = HP + x;
	}
	else
	{
		HP = maxHP;
	}
}

void Hero::reducingHP(long int x)
{
	HP = HP - x;
	isalive();
	
}

int Hero::rm(int min, int max)
{
	
		static std::mt19937
			gen(std::random_device{}());
		std::uniform_int_distribution<int>
			dist(min, max);
		return dist(gen);
	
}

