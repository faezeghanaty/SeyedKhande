#pragma once
#include "Hero.h"
class SmallTaha : public Hero
{
	SmallTaha(int energy);
	virtual Hero::targetorteamtype playerteam(int x) override;
	virtual Hero::targetorteamtype playertarget(int x) override;
	virtual int getenergy(int x) override;
	virtual void ability1(Hero::context& c, vector <Effects>& list) override;
	virtual void ability2(Hero::context& c, vector <Effects>& list) override;
	virtual bool special(Hero::context& c, vector <Effects>& list) override;
};

