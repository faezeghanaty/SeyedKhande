#pragma once
#include <string>
using namespace std;
class Heros
{
private:
	int activespecialpower;
	string role;
	long int HP;
	int energy;
	string sentence;
	bool isdead = false;
	int rounds;
public:
	Heros();
	virtual ~Heros() {}
	void isalive();
	void countrounds();
	void heal(long int x);
	long int reducingHP(long int x);
	int getenergy() const;
	virtual void ability1(Heros& target, Heros& team) = 0;
	virtual void ability2(Heros& target, Heros& team) = 0;
	virtual void special(Heros& target, Heros& team) = 0;
};



