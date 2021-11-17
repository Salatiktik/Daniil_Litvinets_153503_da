//
// pch.cpp
//

#include "pch.h"

int sum_d(int* mass[], int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += mass[i][i];
	}
	return sum;
}