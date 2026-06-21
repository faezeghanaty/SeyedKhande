#include "GameManager.h"
#include <algorithm>
GameManager::GameManager()
{
	rounds = 0;
	specialrounds1 = 0;
	specialrounds2 = 0;
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
	specialrounds1++;
	specialrounds2++;
	if (!effectcplayer.empty())
	{
		auto it = effectcplayer.begin();
		while (it != effectcplayer.end())
		{
			if (!it->isactive())
			{
				if (it->getclassname() == "DANNYGOLANG")
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
				else if (it->getclassname() == "POUYAKAZHDOM" && it->gethp() == 0)
				{
					for (auto x : vecplayer1)
					{
						if (x->getname() == "POUYAKAZHDOM")
						{
							x->setishidden(false);
							int r1;
							bool found = false;
							for (int i = 0;i<3 && !found;i++)
							{
								r1 = rm(1, 3) - 1;
								if (vecplayer2[r1]->candoaction())
								{
									found = true;
									vecplayer2[r1]->reducingHP(450, effectcplayer);
									

								}
							}
							
						}

					}
					for (auto x : vecplayer2)
					{

						if (x->getname() == "POUYAKAZHDOM")
						{
							x->setishidden(false);
							int r1;
							bool found = false;
							for (int i = 0; i < 3 && !found; i++)
							{
								r1 = rm(1, 3) - 1;
								if (vecplayer1[r1]->candoaction())
								{
									found = true;
									vecplayer1[r1]->reducingHP(450, effectcplayer);
									
								}
							}
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
	
}

void GameManager::doatfirst() 
{
	if (!effectcplayer.empty())
	{
		for (auto x : effectcplayer)
		{
			if (x.getclassname() == "TAHAKOCHIKE")
			{
				for (auto y : vecplayer1)
				{
					if (y->getname() == x.getname())
					{
						y->heal(40, effectcplayer);
					}

				}
				for (auto y : vecplayer2)
				{
					if (y->getname() == x.getname())
					{
						y->heal(40, effectcplayer);
					}
				}
			}
			if (x.getclassname() == "DANNYGOLANG")
			{
				for (auto y : vecplayer1)
				{
					if (y->getname() == x.getname())
					{
						y->heal(x.getpercent(), effectcplayer);
					}

				}
				for (auto y : vecplayer2)
				{
					if (y->getname() == x.getname())
					{
						y->heal(x.getpercent(), effectcplayer);
					}
				}

			}
			if (x.getclassname() == "TAHABOZORGE")
			{
				if (x.getname() == "TAHABOZORGE")
				{
					for (auto y : vecplayer1)
					{
						if (y->getname() == "TAHABOZORGE")
						{
							y->setishidden(false);
							for (auto y : vecplayer2)
							{
								if (y->getname() == x.getname())
								{
									y->reducingHP(360, effectcplayer);
								}
							}
						}

					}
					for (auto y : vecplayer2)
					{
						if (y->getname() == "TAHABOZORGE")
						{
							y->setishidden(false);
							for (auto y : vecplayer1)
							{
								if (y->getname() == x.getname())
								{
									y->reducingHP(360, effectcplayer);
								}
							}
						}
					}
				}
				else
				{
					for (auto y : vecplayer1)
					{
						if (y->getname() == x.getname())
						{
							y->reducingHP(360, effectcplayer);
						}

					}
					for (auto y : vecplayer2)
					{
						if (y->getname() == x.getname())
						{
							y->reducingHP(360, effectcplayer);
						}
					}
				}

			}
			if (x.getclassname() == "POUYAKAZHDOM" && x.gethp() != 0)
			{
				for (auto y : vecplayer1)
				{
					y->setishidden(false);
					if (y->getname() == x.getname())
					{
						y->reducingHP(x.gethp(), effectcplayer);
					}

				}
				for (auto y : vecplayer2)
				{
					y->setishidden(false);
					if (y->getname() == x.getname())
					{
						y->reducingHP(x.gethp(), effectcplayer);
					}
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

void GameManager::creatclass(vector<string>& s,int b)
{
	if (b == 1)
	{
		for (int i = 0;i<3;i++)
		{
			if (s[i] == "DRWHITE")
			{
				vecplayer1.emplace_back(new DrWhite);
			}
			else if (s[i] == "TAHAKOCHIKE")
			{
				vecplayer1.emplace_back(new SmallTaha);
			}
			else if (s[i] == "DANNYGOLANG")
			{
				vecplayer1.emplace_back(new Danny);
			}
			else if (s[i] == "AMINIMENI")
			{
				vecplayer1.emplace_back(new Amin);
			}
			else if (s[i] == "TAHABOZORGE")
			{
				vecplayer1.emplace_back(new BigTaha);
			}
			else if (s[i] == "AQASHAHRIYAR")
			{
				vecplayer1.emplace_back(new Shahriyar);
			}
			else if (s[i] == "POUYAKAZHDOM")
			{
				vecplayer1.emplace_back(new Pouya);
			}
		}
	}
	if (b == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			if (s[i] == "DRWHITE")
			{
				vecplayer2.emplace_back(new DrWhite);

			}
			else if (s[i] == "TAHAKOCHIKE")
			{
				vecplayer2.emplace_back(new SmallTaha);
			}
			else if (s[i] == "DANNYGOLANG")
			{
				vecplayer2.emplace_back(new Danny);
			}
			else if (s[i] == "AMINIMENI")
			{
				vecplayer2.emplace_back(new Amin);
			}
			else if (s[i] == "TAHABOZORGE")
			{
				vecplayer2.emplace_back(new BigTaha);
			}
			else if (s[i] == "AQASHAHRIYAR")
			{
				vecplayer2.emplace_back(new Shahriyar);
			}
			else if (s[i] == "POUYAKAZHDOM")
			{
				vecplayer2.emplace_back(new Pouya);
			}
		}
	}
}

void GameManager::doaction1()
{
	vector <string> nameofhero1;
	vector <string> nameofhero2;
	try
	{
		while (energy1 > 0)
		{
			for (auto x : vecplayer2)
			{
				player.showstatus(x->getname(), x->getHP(),x->candoaction());
			}
			for (auto x : vecplayer1)
			{
				player.showstatus(x->getname(), x->getHP(),x->candoaction());
			}
			sortvector();
			for (auto x : vecplayer1)
			{
				nameofhero1.emplace_back(x->getname());
			}
			for (auto x : vecplayer2)
			{
				nameofhero2.emplace_back(x->getname());
			}

			player.showenergy(energy1);
			int z = player.whichherodoaction(nameofhero1);
			if (z == 3)
			{
				break;
			}
			if (!vecplayer1[z]->candoaction())
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
				if (specialrounds1 < vecplayer1[z]->countrounds())
				{
					player.special();
					continue;
				}
				if (vecplayer1[z]->playerteam(v) == Hero::targetorteamtype::optional)
				{
					while (1)
					{
						int m = player.doactiononwho(nameofhero1);
						if (vecplayer1[m]->candoaction())
						{
							c.teamindex = m;
							break;
						}
						player.isdead(vecplayer1[m]->getname());
					}
				}
				else if (vecplayer1[z]->playertarget(v) == Hero::targetorteamtype::optional)
				{

					while (1)
					{
						int m = player.doactiononwho(nameofhero2);
						if (vecplayer2[m]->candoaction())
						{
							c.targetindex = m;
							break;
						}
						player.isdead(vecplayer2[m]->getname());
					}
				}
				vecplayer1[z]->special(c, effectcplayer);
				player.Showsentence(vecplayer1[z]->getsentence());
				specialrounds1 -= vecplayer1[z]->countrounds();
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
					while (1)
					{
						int m = player.doactiononwho(nameofhero1);
						if (vecplayer1[m]->candoaction())
						{
							c.teamindex = m;
							break;
						}
						player.isdead(vecplayer1[m]->getname());
					}
				}
				else if (vecplayer1[z]->playertarget(v) == Hero::targetorteamtype::optional)
				{
					while (1)
					{
						int m = player.doactiononwho(nameofhero2);
						if (vecplayer2[m]->candoaction())
						{
							c.targetindex = m;
							break;
						}
						player.isdead(vecplayer2[m]->getname());
					}
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
		sortvector();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
}

void GameManager::doaction2()
{
	
	vector <string> nameofhero1;
	vector <string> nameofhero2;
	try {
		while (energy2 > 0)
		{
			for (auto x : vecplayer1)
			{
				player.showstatus(x->getname(), x->getHP(),x->candoaction());
			}
			for (auto x : vecplayer2)
			{
				player.showstatus(x->getname(), x->getHP(),x->candoaction());
			}
			sortvector();
			for (auto x : vecplayer1)
			{
				nameofhero1.emplace_back(x->getname());
			}
			for (auto x : vecplayer2)
			{
				nameofhero2.emplace_back(x->getname());
			}
			player.showenergy(energy2);

			int z = player.whichherodoaction(nameofhero2);
			if (z == 3)
			{
				break;
			}
			if (!vecplayer2[z]->candoaction())
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
				if (specialrounds2 < vecplayer2[z]->countrounds())
				{
					player.special();
					continue;
				}
				if (vecplayer2[z]->playerteam(v) == Hero::targetorteamtype::optional)
				{

					while (1)
					{
						int m = player.doactiononwho(nameofhero2);
						if (vecplayer2[m]->candoaction())
						{
							c.teamindex = m;
							break;
						}
						player.isdead(vecplayer2[m]->getname());
					}
				}
				else if (vecplayer2[z]->playertarget(v) == Hero::targetorteamtype::optional)
				{

					while (1)
					{
						int m = player.doactiononwho(nameofhero1);
						if (vecplayer1[m]->candoaction())
						{
							c.targetindex = m;
							break;
						}
						player.isdead(vecplayer1[m]->getname());
					}
				}
				vecplayer2[z]->special(c, effectcplayer);
				player.Showsentence(vecplayer2[z]->getsentence());
				specialrounds2 -= vecplayer2[z]->countrounds();
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
					while (1)
					{
						int m = player.doactiononwho(nameofhero2);
						if (vecplayer2[m]->candoaction())
						{
							c.teamindex = m;
							break;
						}
						player.isdead(vecplayer2[m]->getname());
					}


				}
				else if (vecplayer2[z]->playertarget(v) == Hero::targetorteamtype::optional)
				{

					while (1)
					{
						int m = player.doactiononwho(nameofhero1);
						if (vecplayer1[m]->candoaction())
						{
							c.targetindex = m;
							break;
						}
						player.isdead(vecplayer1[m]->getname());
					}
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
		sortvector();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	
}

bool GameManager::gameend()
{
	if ((!vecplayer1[0]->isalive() && !vecplayer1[1]->isalive() && !vecplayer1[2]->isalive())&&(!vecplayer2[0]->isalive() && !vecplayer2[1]->isalive() && !vecplayer2[2]->isalive()))
	{
		player.endofgame(2);
		return 1;
	}
	else if ((!vecplayer1[0]->isalive() && !vecplayer1[1]->isalive() && !vecplayer1[2]->isalive()))
	{
		player.endofgame(1);
		return 1;
	}
	else if ((!vecplayer2[0]->isalive() && !vecplayer2[1]->isalive() && !vecplayer2[2]->isalive()))
	{
		player.endofgame(0);
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
			player.endofgame(1);
		}
		else if (b > a)
		{
			player.endofgame(0);
		}
		else if (a == b)
		{
			player.endofgame(2);
		}
	}
	return 0;
}

void GameManager::sortvector() //
{
	sort(vecplayer1.begin(), vecplayer1.end(), [](Hero* a, Hero* b)
		{
			return a->getHP() < b->getHP();
		});
	sort(vecplayer2.begin(), vecplayer2.end(), [](Hero* a, Hero* b)
		{
			return a->getHP() < b->getHP();
		});

}


void GameManager::run() //
{
	bool end = false;
	int m = rm(1, 2);
	if (m == 1)
	{
		name1 = player.entername();
		name2 = player.entername();
		vector <string> n1 = player.choosehero();
		creatclass(n1, 1);
		vector <string> n2 = player.choosehero();
		creatclass(n2, 2);
	}
	if (m == 2)
	{
		name2 = player.entername();
		name1 = player.entername();
		vector <string> n2 = player.choosehero();
		creatclass(n2, 2);
		vector <string> n1 = player.choosehero();
		creatclass(n1, 1);
	}
	for (rounds = 1; rounds <= 15; rounds++)
	{
		if (rounds > 1)
		{
			doatfirst();
			nextround();
		}
		sortvector();
		
		manegmentenergy();
		player.nameofplayer(name1);
		player.showround(rounds, specialrounds1);
		
		doaction1();
		player.nameofplayer(name2);
		player.showround(rounds, specialrounds2);
		
		doaction2();

		
		if (gameend())
		{
			end = true;
			rounds = 15;
		}
	}
	for (auto x : vecplayer1)
	{
		delete x;
	}
	for (auto x : vecplayer2)
	{
		delete x;
	}
	if (!end)
	{
		gameend();
	}
}

