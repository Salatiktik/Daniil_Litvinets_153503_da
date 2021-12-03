//
// pch.cpp
//

#include "pch.h"
double price_tg(char* str, int N)
{

	int ch = 0;
	for (int i = 0; i < N; i++)
	{
		if (str[i] == ' ')
		{
			ch++;
		}
	}
	return ch + 1;
}
