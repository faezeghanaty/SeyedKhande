#include "View.h"

View::View()
{
}

vector <string> View::change(vector <int> & heros)
{
	vector <string> name;
	for (auto x : heros)
	{
		switch (x)
		{
		case 0: name.emplace_back("DRWHITE"); break;
		case 1: name.emplace_back("TAHAKOCHIKE"); break;
		case 2: name.emplace_back("DANNYGOLANG"); break;
		case 3: name.emplace_back("AMINIMENI"); break;
		case 4: name.emplace_back("TAHABOZORGE"); break;
		case 5: name.emplace_back("AQASHAHRIYAR"); break;
		case 6: name.emplace_back("POUYAKAZHDOM"); break;
		}
	}
	return name;
}

vector<string> View::choosehero()
{
	int a, b, c;
	vector <int> heros;
	cout << "0=DRWHITE 1=TAHAKOCHIKE 2=DANNYGOLANG 3=AMINIMENI 4=TAHABOZORGE 5=AQASHAHRIYAR 6=POUYAKAZHDOM"  << endl;
	while (1)
	{
		cout << "Choose the fisrt hero" << endl;
		cin >> a;
		if ((0 < a && a< 7) || a == 0)
		{
			heros.emplace_back(a);
			break;
		}
	}
	while (1)
	{
		cout << "Choose the second hero" << endl;
		cin >> b;
		if (((0 < b && b< 7) || b == 0 ) && a!=b)
		{
			heros.emplace_back(b);
			break;
		}
	}
	while (1)
	{
		cout << "Choose the third hero" << endl;
		cin >> c;
		if (((0 < c  &&c< 7) || c == 0) && c != b && c!=a)
		{
			heros.emplace_back(c);
			break;
		}
	}
	;
	return change(heros);
}

void View::showround(int x,int y)
{
	cout << "WE ARE IN ROUND " << x << endl;
	cout << "YOU HAVE " << y << " ROUNDS TO USE SPECIAL ABILITY" << endl;
}

void View::showstatus(string name, long int HP,bool cando )
{
	cout << name << " HP: " << HP << " IS ACTIVE: " << cando << endl;
}

void View::showenergy(int x)
{
	cout << "Energy : " << x << endl;
}

void View::notenough()
{
	cout << "Energy is not enough!" << endl;
}

int View::whichherodoaction(vector <string> & name)
{
	int a;
	while (1)
	{
		cout << "Which one do atacke ? or 3=END OF ATTACKS?" << endl
			<< "0= " << name[0] << " 1= " << name[1] << " 2= " << name[2] << endl;
		cin >> a;
		if ((0 < a && a<4) || a == 0)
		{
			
			return a;
		}
	}
}

int View::whichability()
{
	int a;
	
	while (1)
	{
		cout << "Do What?" << endl << "1=ability1 2=ability2 3=special" << endl;
		cin >> a;
		if (0 < a && a<4)
		{
			return a;
		}
	}
}

void View::Showsentence(string sentence)
{
	cout << sentence << endl;
}

void View::special()
{
	cout << "Special ability is not active try somthing else" << endl;
	whichability();
}

void View::endofgame(int x)
{
	switch (x)
	{
	case 0:
	{
		cout << "FIRST TEAM WON!!!" << endl; break;
	}
	case 1:
	{
		cout << "SECOND TEAM WON!!!" << endl; break;
	}
	case 2:
	{
		cout << "TEAMS TIED!!!" << endl; break;
	}
	}
}

void View::nameofplayer(string name)
{
	cout << name << endl;
}

void View::nameofhero(string name)
{
	cout << name << endl;
}

int View::doactiononwho(vector<string>& s)
{
	int a;
	while (1)
	{
		cout << "Choose a player  : " << endl << "0= " << s[0] << " 1= " << s[1] << " 2= " << s[2] << endl;
		cin >> a;
		if ((a > 0 && a < 3) || a == 0)
		{
			break;
		}
	}
	return a;

}

string View::entername()
{
	cout << "Enter the name of player" << endl;
	cin >> p1;
	return p1;
}

void View::isdead(string name)
{
	cout << name << " is dead!" << endl;
}

