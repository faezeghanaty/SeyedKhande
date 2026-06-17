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
	int getpercent();
	string getclassname();
	int applypercent(int x);
	bool operator==(const string& other);

};

