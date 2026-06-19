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
	Hero(string name,int active,string role,long int HP,string sentence,bool isdead = false,bool ishidden = false);
	virtual ~Hero() {}
	bool isalive();
	void setishidden(bool x);
	bool candoaction();
	bool reverse(vector <Effects>& list);
	long int getHP();
	void setHp(long int hp);
	string getname() const;
	int countrounds();
	void heal(long int x);
	void reducingHP(long int x);
	virtual int getenergy(int x) = 0;
	virtual string getsentence() = 0;
	virtual void ability1(context & c,vector <Effects> & list) = 0;
	virtual void ability2(context& c, vector <Effects>& list) = 0;
	virtual void special(context& c, vector <Effects>& list) = 0; //false = tedad dor ha kafi nist
	virtual targetorteamtype playerteam(int x) = 0;
	virtual targetorteamtype playertarget(int x) = 0;
	int rm(int min, int max);
	
};



