#pragma once
#include "Hero.h"
class DrWhite : public Hero
{
public:
	DrWhite(int energy);
	virtual Hero::targetorteamtype playerteam(int x) override;
	virtual Hero::targetorteamtype playertarget(int x) override;
	virtual void ability1(Hero::context& c, vector <Effect>& list) override;
	virtual void ability2(Hero::context& c, vector <Effect>& list) override;
	virtual bool special(Hero::context& c, vector <Effect>& list) override; 
};

