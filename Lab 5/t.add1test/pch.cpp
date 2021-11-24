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

long long S_function( long long int p, long long int q)//сумма
{
	int qwe = 0;
	long long sum = 0;
	for (long long i = p; i <= q; i++)
	{
		if (qwe % 1000000000 == 0)
		{
			std::cout << (double)i / q*100 << "%\n";
		}
		sum += F_function(i);

		qwe++;
		if (i / q < 0)
		{
			return 0;
		}
	}
	return sum;
}
