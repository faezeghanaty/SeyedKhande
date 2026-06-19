#pragma once
#include "Hero.h"
class SmallTaha : public Hero
{
public:
	SmallTaha();
	virtual Hero::targetorteamtype playerteam(int x) override;
	virtual Hero::targetorteamtype playertarget(int x) override;
	virtual int getenergy(int x) override;
	virtual string getsentence();
	virtual void ability1(Hero::context& c, vector <Effects>& list) override;
	virtual void ability2(Hero::context& c, vector <Effects>& list) override;
	virtual void special(Hero::context& c, vector <Effects>& list) override;
};

