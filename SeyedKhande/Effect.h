#pragma once
#include <string>
using namespace std;
class Effect
{
private:
	string name;
	int percent;
	int round;
public:
	Effect(int percent, int round,string name);
	int applypercent(int x);
	void reducingrounds();
	bool isactive();
	bool operator==(const string& other);
};

