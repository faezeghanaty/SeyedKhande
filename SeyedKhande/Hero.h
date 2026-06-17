#pragma once
#include <string>
#include <vector>
#include <random>
#include "Effects.h"
using namespace std;
class Hero
{
protected:
	
	string name;
	string sentence;
	string role;
	int activespecialpower;
	int energy;
	int rounds;
	long int HP;
	long int maxHP;
	bool isdead ;
	bool ishidden ;
public:
	struct context {
		vector<Hero*>& team;
		vector<Hero*>& target;
		int targetindex = -1;
		int teamindex = -1;

	};
	enum targetorteamtype 
	{highest,optional,random,lowest,nobody};
	Hero(string name,int active,string role,long int HP,int energy,string sentence,bool isdead = false,int round = 0,bool ishidden = false);
	virtual ~Hero() {}
	bool isalive();
	long int getHP();
	string getname() const;
	void countrounds();
	void heal(long int x);
	void reducingHP(long int x);
	virtual int getenergy(int x) = 0;
	virtual void ability1(context & c,vector <Effects> & list) = 0;
	virtual void ability2(context& c, vector <Effects>& list) = 0;
	virtual bool special(context& c, vector <Effects>& list) = 0; //false = tedad dor ha kafi nist
	virtual targetorteamtype playerteam(int x) = 0;
	virtual targetorteamtype playertarget(int x) = 0;
	int rm(int min, int max);
	
};



