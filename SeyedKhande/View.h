#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class View
{
	
public:
	
	
	string p1;
	string p2;
	enum heroo
	{
		DrWhite,SmallTaha,Danny,Amin,BigTaha
	};
	View();
	vector <string> change(vector <int>& heros);
	vector <string> choosehero();
	void showround(int x,int y);
	void showstatus(string name, long int HP, bool cando);
	void showenergy(int x);
	void notenough();
	int whichherodoaction(vector <string>& name);
	int whichability();
	void Showsentence(string sentence);
	void special();
	void endofgame(int x);
	void nameofplayer(string name);
	void nameofhero(string name);
	int doactiononwho(vector<string> &s);
	string entername();
	void isdead(string name);


};

