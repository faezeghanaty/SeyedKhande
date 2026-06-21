#pragma once
#include <string>
using namespace std;
class Effects
{
public:
	string name;
	string classname;
	int rounds;
	int percent;
	long int HP;
	Effects(string classname,string name, int rounds, int percent = 0,long int HP = 0);
	void reducingrounds();
	bool isactive();
	long int gethp();
	void sethp(long int h); 
	int getpercent();
	string getclassname();
	string getname();
	int applypercent(int x);
	bool operator==(const string& other);

};

