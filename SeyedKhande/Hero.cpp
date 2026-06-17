#include "Hero.h"


Hero::Hero(string name,int active, string role, long int HP, int energy, string sentence, bool isdead, int round, bool ishidden) : name(name),activespecialpower(active), role(role), HP(HP), energy(energy), sentence(sentence), rounds(round),maxHP(HP)
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

long int Hero::getHP()
{
	return HP;
}

string Hero::getname() const
{
	return name;
}

void Hero::countrounds()
{
	rounds++;
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

