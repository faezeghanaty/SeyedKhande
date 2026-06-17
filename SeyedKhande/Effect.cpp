#include "Effect.h"

Effect::Effect(int percent, int round ,string name) : percent(percent),round(round),name(name)
{

}

int Effect::applypercent(int x)
{
    return x + ((x * percent) / 100);
}

void Effect::reducingrounds()
{
    round --;
}

bool Effect::isactive()
{
    return round == 0;
}

bool Effect::operator==(const string& other)
{
    return other == name;
}
