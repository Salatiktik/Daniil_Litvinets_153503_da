//
// pch.cpp
//

#include "pch.h"

int check(int str[], int st, int end, int& ch)
{
	int s = st;
	int e = end;
	if ((e == 0 && s == 0) || e - s == 0 || s - e == 0)
	{
		if (pow(str[e], 3) >= 20 || pow(str[e], 3) <= -10)
		{
			ch++;
			return 0;
		}
		else
		{
			return 0;
		}
	}
	{
		check(str, s, (e + s) / 2, ch);
		check(str, ((e + s) / 2) + 1, e, ch);
	}
	return 0;
}
