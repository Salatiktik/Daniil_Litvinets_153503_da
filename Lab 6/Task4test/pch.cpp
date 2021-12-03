//
// pch.cpp
//

#include "pch.h"
#include <string>

using namespace std;
void new_english(char*& massive, int i)
{
	string* mass = new string[i + 1];
	mass[i].assign(massive);
	int q = i;
	//ÄËß Ñ
	while ((mass[q].find("c", 0) + 1))
	{
		if (mass[q][mass[q].find("c", 0) + 1] == 'e' || mass[q][mass[q].find("c", 0) + 1] == 'i' || mass[q][mass[q].find("c", 0) + 1] == 'y')
		{
			mass[q].replace(mass[q].find("c", 0), 1, "s");
		}
		else
		{
			mass[q].replace(mass[q].find("c", 0), 1, "k");
		}
	}
	while ((mass[q].find("C", 0) + 1))
	{
		if (mass[q][mass[q].find("C", 0) + 1] == 'e' || mass[q][mass[q].find("C", 0) + 1] == 'i' || mass[q][mass[q].find("C", 0) + 1] == 'y')
		{
			mass[q].replace(mass[q].find("C", 0), 1, "S");
		}
		else
		{
			mass[q].replace(mass[q].find("C", 0), 1, "K");
		}
	}
	//ÄËß Q
	while (mass[q].find("q", 0) + 1)
	{
		if (mass[q][mass[q].find("q", 0) + 1] == 'u')
		{
			mass[q].replace(mass[q].find("q", 0) + 1, 1, "v");
		}
		mass[q].replace(mass[q].find("q", 0), 1, "k");
	}
	while (mass[q].find("Q", 0) + 1)
	{
		if (mass[q][mass[q].find("Q", 0) + 1] == 'u')
		{
			mass[q].replace(mass[q].find("Q", 0) + 1, 1, "v");
		}
		mass[q].replace(mass[q].find("Q", 0), 1, "K");
	}
	//ÄËß X
	while (mass[q].find("x", 0) + 1)
	{
		mass[q].replace(mass[q].find("x", 0), 2, "ks");
	}
	while (mass[q].find("X", 0) + 1)
	{
		mass[q].replace(mass[q].find("X", 0), 1, "Ks");
	}
	//ÄËß W
	while (mass[q].find("w", 0) + 1)
		mass[q].replace(mass[q].find("w", 0), 1, "v");
	while (mass[q].find("W", 0) + 1)
		mass[q].replace(mass[q].find("W", 0), 1, "V");
	//ÄËß PH
	while (mass[q].find("p", 0) + 1 && mass[q][mass[q].find("p", 0) + 1] == 'h')
		mass[q].replace(mass[q].find("w", 0), 2, "f");
	while (mass[q].find("P", 0) + 1 && mass[q][mass[q].find("P", 0) + 1] == 'h')
		mass[q].replace(mass[q].find("w", 0), 2, "F");
	//ÄËß YOU OO
	while (mass[q].find("you", 0) + 1)
		mass[q].replace(mass[q].find("you", 0), 3, "u");
	while (mass[q].find("You", 0) + 1)
		mass[q].replace(mass[q].find("You", 0), 3, "U");
	while (mass[q].find("oo", 0) + 1)
		mass[q].replace(mass[q].find("oo", 0), 2, "u");
	while (mass[q].find("Oo", 0) + 1)
		mass[q].replace(mass[q].find("Oo", 0), 2, "U");
	//ÄËß EE
	while (mass[q].find("ee", 0) + 1)
		mass[q].replace(mass[q].find("ee", 0), 2, "i");
	while (mass[q].find("Ee", 0) + 1)
		mass[q].replace(mass[q].find("Ee", 0), 2, "I");
	//ÄËß TH
	while (mass[q].find("th", 0) + 1)
		mass[q].replace(mass[q].find("th", 0), 2, "z");
	while (mass[q].find("Th", 0) + 1)
		mass[q].replace(mass[q].find("Th", 0), 2, "Z");
	//ÄËß ÏÎÂÒÎÐÎÂ
	int y = 0;
	string sogl = "bcdfghjklmnpqrstvwxz";
	string SOGL = "BCDFGHJKLMNPQRSTVWXZ";
	for (int y = 0; y < 101; y++)
	{
		if (mass[q][y] == '\0')
			break;
		while ((mass[q][y] == mass[q][y + 1] || (int)mass[q][y] + 32 == (int)mass[q][y + 1]) && ((sogl.find(mass[q][y], 0) + 1) || (SOGL.find(mass[q][y], 0) + 1)))
		{
			mass[q].replace(y + 1, 1, "\0");
		}
	}
	;
	for (int u = 0; u <= 101; u++)
	{
		if (mass[i][u] == '\0')
		{
			massive[u] = '\0';
			break;
		}

		massive[u] = mass[i][u];
	}
}
