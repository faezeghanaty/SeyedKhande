#include "Effects.h"

Effects::Effects(string classname,string name, int rounds, int percent,long int HP ) : classname(classname),name(name),rounds(rounds),HP(HP),percent(percent)
{
}

void Effects::reducingrounds()
{
	rounds--;
}

bool Effects::isactive()
{
	return rounds != 0;
}

long int Effects::gethp()
{

	return HP;
}

void Effects::sethp(long int h)
{ 
	HP = h;
}

int Effects::getpercent()
{
	return percent;
}

string Effects::getclassname()
{
	return classname;
}

string Effects::getname()
{
	return name;
}

int Effects::applypercent(int x)
{
	return x + ((x * percent) / 100);
}

bool Effects::operator==(const string& other)
{
	return other == name;
}

