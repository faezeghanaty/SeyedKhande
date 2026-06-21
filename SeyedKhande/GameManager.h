#pragma once
#include "Hero.h"
#include "View.h"
#include "Amin.h"
#include "Danny.h"
#include "DrWhite.h"
#include "BigTaha.h"
#include "SmallTaha.h"
#include "Shahriyar.h"
#include "Pouya.h"
using namespace std;
class GameManager
{
private:
	int rounds;
	int specialrounds1;
	int specialrounds2;
	int energy1;
	int energy2;
	string name1;
	string name2;
	View player;
	vector <Hero*> vecplayer1;
	vector <Hero*> vecplayer2;
	vector <Effects> effectcplayer;
	void nextround();
	void doatfirst();
	void manegmentenergy(); 
	void creatclass(vector <string>& s, int x);
	void doaction1();
	void doaction2();
	bool gameend();
	void sortvector();
	int rm(int min, int max);
public:
	GameManager();
	void run();
};

