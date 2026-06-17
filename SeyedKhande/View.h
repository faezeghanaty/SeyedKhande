#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class View
{
	
public:
	vector <int> heros;
	vector <string> name;
	enum heroo
	{
		DrWhite,SmallTaha,Danny,Amin,BigTaha
	};
	View();
	void change();
	vector <int> choosehero();
	void showround(int x);
	void showstatus(string name, long int HP);
	void showenergy(int x);
	int whichherodoaction();
	int whichability();
	void Showsentence(string sentence);
	void special();
	void endofgame(int x);


};

