#include "GameManager.h"
#include <algorithm>
GameManager::GameManager()
{
	rounds = 0;
	specialrounds = 0;
	energy1 = 0;
	energy2 = 0;
}
int GameManager::rm(int min, int max)
{
	static std::mt19937
		gen(std::random_device{}());
	std::uniform_int_distribution<int>
		dist(min, max);
	return dist(gen);
}

void GameManager::nextround()
{
	specialrounds++;
	auto it = effectcplayer.begin();
	while (it != effectcplayer.end())
	{
		if (!it->isactive())
		{
			if (it->getclassname() == "Danny")
			{
				for (auto x : vecplayer1)
				{
					if (x->getname() == it->getname() && x->getHP() > it->gethp())
					{
						x->setHp(it->gethp());
					}
				}
				for (auto x : vecplayer2)
				{
					if (x->getname() == it->getname() && x->getHP() > it->gethp())
					{
						x->setHp(it->gethp());
					}
				}
			}
			it = effectcplayer.erase(it);
		}
		else
		{

			it->reducingrounds();
			it++;
		}
	}
	
}

void GameManager::doatfirst()
{
	for (auto x : effectcplayer)
	{
		if (x.getclassname() == "SmallTaha")
		{
			for (auto y : vecplayer1)
			{
				if (y->getname() == x.getname())
				{
					y->heal(40);
				}
					
			}
			for (auto y : vecplayer2)
			{
				if (y->getname() == x.getname())
				{
					y->heal(40);
				}
			}
		}
		if (x.getclassname() == "Danny")
		{
			for (auto y : vecplayer1)
			{
				if (y->getname() == x.getname())
				{
					y->heal(250);
				}

			}
			for (auto y : vecplayer2)
			{
				if (y->getname() == x.getname())
				{
					y->heal(250);
				}
			}

		}
		if (x.getclassname() == "BigTaha")
		{
			for (auto y : vecplayer1)
			{
				if (y->getname() == x.getname())
				{
					y->reducingHP(360);
				}

			}
			for (auto y : vecplayer2)
			{
				if (y->getname() == x.getname())
				{
					y->reducingHP(360);
				}
			}
		}
	}
}

void GameManager::manegmentenergy()
{
	if (rounds == 1)
	{
		energy1 = 5;
		energy2 = 8;
	}
	else if (rounds == 2)
	{
		energy1 = 8;
		energy2 = 9;
	}
	else if (rounds == 3)
	{
		energy1 = 9;
		energy2 = 10;
	}
	else
	{
		energy1 = 10;
		energy2 = 10;
	}
}

void GameManager::creatclass(vector<string>& s,int x)
{
	if (x == 1)
	{
		for (auto x : s)
		{
			if (x == "DRWHITE")
			{
				vecplayer1.emplace_back(new DrWhite);
			}
			else if (x == "TAHAKOCHIKE")
			{
				vecplayer1.emplace_back(new SmallTaha);
			}
			else if (x == "DANNYGOLANG")
			{
				vecplayer1.emplace_back(new Danny);
			}
			else if (x == "AMINIMENI")
			{
				vecplayer1.emplace_back(new Amin);
			}
			else if (x == "TAHABOZORGE")
			{
				vecplayer1.emplace_back(new BigTaha);
			}
		}
	}
	if (x == 2)
	{
		for (auto x : s)
		{
			if (x == "DRWHITE")
			{
				vecplayer2.emplace_back(new DrWhite);

			}
			else if (x == "TAHAKOCHIKE")
			{
				vecplayer2.emplace_back(new SmallTaha);
			}
			else if (x == "DANNYGOLANG")
			{
				vecplayer2.emplace_back(new Danny);
			}
			else if (x == "AMINIMENI")
			{
				vecplayer2.emplace_back(new Amin);
			}
			else if (x == "TAHABOZORGE")
			{
				vecplayer2.emplace_back(new BigTaha);
			}
		}
	}
}

void GameManager::doaction1()
{
	
	while (energy1 > 0)
	{
		player.showenergy(energy1);
		int z = player.whichherodoaction();
		if (z == 3)
		{
			break;
		}
		if (!vecplayer1[z]->isalive())
		{
			player.isdead(vecplayer1[z]->getname());
			continue;
		}
		int v = player.whichability();
		Hero::context c{ vecplayer1,vecplayer2 };
		if (v == 3)
		{
			if (vecplayer1[z]->getenergy(v) > energy1)
			{
				player.notenough();
				continue;
			}
			if (specialrounds < vecplayer1[z]->countrounds())
			{
				player.special();
				continue;
			}
			if (vecplayer1[z]->playerteam(v) == Hero::targetorteamtype::optional)
			{
				c.teamindex = player.doactiononwho(nameofhero1);
			}
			else if (vecplayer1[z]->playertarget(v) == Hero::targetorteamtype::optional)
			{
				c.targetindex = player.doactiononwho(nameofhero2);
			}
			vecplayer1[z]->special(c, effectcplayer);
			player.Showsentence(vecplayer1[z]->getsentence());
			specialrounds -= vecplayer1[z]->countrounds();
			energy1 -= vecplayer1[z]->getenergy(v);
				
		}
		else
		{
			if (vecplayer1[z]->getenergy(v) > energy1)
			{
				player.notenough();
				continue;
			}
			if (vecplayer1[z]->playerteam(v) == Hero::targetorteamtype::optional)
			{
				c.teamindex = player.doactiononwho(nameofhero1);
			}
			else if (vecplayer1[z]->playertarget(v) == Hero::targetorteamtype::optional)
			{
				c.targetindex = player.doactiononwho(nameofhero2);
			}
			if (v == 1)
			{
				energy1 -= vecplayer1[z]->getenergy(v);
				vecplayer1[z]->ability1(c, effectcplayer);
			}
			else
			{
				energy1 -= vecplayer1[z]->getenergy(v);
				vecplayer1[z]->ability2(c, effectcplayer);
			}
		}
		
	}
}

void GameManager::doaction2()
{
	player.showenergy(energy2);
	while (energy2 > 0)
	{
		int z = player.whichherodoaction();
		if (z == 3)
		{
			break;
		}
		if (!vecplayer2[z]->isalive())
		{
			player.isdead(vecplayer2[z]->getname());
			continue;
		}
		int v = player.whichability();
		Hero::context c{ vecplayer2,vecplayer1 };
		if (v == 3)
		{
			if (vecplayer2[z]->getenergy(v) > energy2)
			{
				player.notenough();
				continue;
			}
			if (specialrounds < vecplayer2[z]->countrounds())
			{
				player.special();
				continue;
			}
			if (vecplayer2[z]->playerteam(v) == Hero::targetorteamtype::optional)
			{
				c.teamindex = player.doactiononwho(nameofhero2);
			}
			else if (vecplayer2[z]->playertarget(v) == Hero::targetorteamtype::optional)
			{
				c.targetindex = player.doactiononwho(nameofhero1);
			}
			vecplayer2[z]->special(c, effectcplayer);
			player.Showsentence(vecplayer2[z]->getsentence());
			specialrounds -= vecplayer2[z]->countrounds();
			energy2 -= vecplayer2[z]->getenergy(v);
		}
		else
		{
			if (vecplayer2[z]->getenergy(v) > energy2)
			{
				player.notenough();
				continue;
			}
			if (vecplayer2[z]->playerteam(v) == Hero::targetorteamtype::optional)
			{
				c.teamindex = player.doactiononwho(nameofhero2);
			}
			else if (vecplayer2[z]->playertarget(v) == Hero::targetorteamtype::optional)
			{
				c.targetindex = player.doactiononwho(nameofhero1);
			}
			if (v == 1)
			{
				energy2 -= vecplayer2[z]->getenergy(v);
				vecplayer2[z]->ability1(c, effectcplayer);
			}
			else
			{
				energy2 -= vecplayer2[z]->getenergy(v);
				vecplayer2[z]->ability2(c, effectcplayer);
			}
		}

	}
}

bool GameManager::gameend()
{
	if (!(vecplayer1[0]->isalive() && vecplayer1[1]->isalive() && vecplayer1[2]->isalive())&&!(vecplayer2[0]->isalive() && vecplayer2[1]->isalive() && vecplayer2[2]->isalive()))
	{
		player.endofgame(2);
		return 1;
	}
	else if (!(vecplayer1[0]->isalive() && vecplayer1[1]->isalive() && vecplayer1[2]->isalive()))
	{
		player.endofgame(0);
		return 1;
	}
	else if (!(vecplayer2[0]->isalive() && vecplayer2[1]->isalive() && vecplayer2[2]->isalive()))
	{
		player.endofgame(1);
		return 1;
	}
	else if (rounds == 15)
	{
		int a = 0;
		int b = 0;
		for (auto x : vecplayer1)
		{
			if (!x->isalive())
			{
				a++;
			}
		}
		for (auto x : vecplayer2)
		{
			if (!x->isalive())
			{
				b++;
			}
		}
		if (a > b)
		{
			player.endofgame(0);
		}
		else if (b > a)
		{
			player.endofgame(1);
		}
		else if (a == b)
		{
			player.endofgame(2);
		}
	}

}


void GameManager::run()
{
	bool end = false;
	int m = rm(1, 2);
	if (m == 1)
	{
		name1 = player.entername();
		name2 = player.entername();
		vector <string> nameofhero1 = player.choosehero();
		creatclass(nameofhero1, 1);
		vector <string> nameofhero2 = player.choosehero();
		creatclass(nameofhero2, 2);
	}
	if (m == 2)
	{
		name2 = player.entername();
		name1 = player.entername();
		vector <string> nameofhero2 = player.choosehero();
		creatclass(nameofhero2, 2);
		vector <string> nameofhero1 = player.choosehero();
		creatclass(nameofhero1, 1);
	}
	for (rounds = 1; rounds < 15; rounds++)
	{
		
		doatfirst();

		player.showround(rounds,specialrounds);
		manegmentenergy();
		player.nameofplayer(name1);
		for (auto x : vecplayer2)
		{
			player.showstatus(x->getname(),x->getHP());
		}
		doaction1();
		player.nameofplayer(name2);
		for (auto x : vecplayer1)
		{
			player.showstatus(x->getname(), x->getHP());
		}
		doaction2();

		nextround();
		if (gameend())
		{
			end = true;
			rounds = 15;
		}
	}
	for (auto x : vecplayer1)
	{
		x->~Hero();
	}
	for (auto x : vecplayer2)
	{
		x->~Hero();
	}
	if (!end)
	{
		gameend();
	}
}

