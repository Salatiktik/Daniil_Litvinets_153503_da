//
// pch.cpp
//

#include "pch.h"

int F_function(int n)
{
	if (n % 10 > 0)
	{
		return n % 10;
	}
	else if (n == 0)
	{
		return 0;
	}
	else if (n % 10 == 0)
	{
		return F_function(n / 10);
	}
}

int S_function(int p, int q)
{
	int  sum = 0;
	for (int i = p; i <= q; i++)
	{
		sum += F_function(i);
	}
	return sum;
}
