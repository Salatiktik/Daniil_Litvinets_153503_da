#include "pch.h"

TEST(Case1, Test3_2) 
{
	int N = 3, M = 3,ch=0;
	double** mass = new double* [N];
	mass[0] = new double [M] { 3, 8, 1 };
	mass[1] = new double [M] { -5, 2.3, 1 };
	mass[2] = new double [M] { 6, 2, 5 };
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				ch++;
			}
		}
	}
  EXPECT_EQ(ch, 0);
}

TEST(Case2, Test3_2)
{
	int N = 1, M = 1, ch = 0;
	double** mass = new double* [N];
	mass[0] = new double [M] { 0};
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				ch++;
			}
		}
	}
	EXPECT_EQ(ch, 1);
}

TEST(Case3, Test3_2)
{
	int N = 5, M = 3, ch = 0;
	double** mass = new double* [N];
	mass[0] = new double [M] { 7, 5, 1 };
	mass[1] = new double [M] { -3, 2.3, -91 };
	mass[2] = new double [M] { 6, 0, 5 };
	mass[3] = new double [M] { 3, -6, 9 };
	mass[4] = new double [M] { 0, -3, 1 };
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				ch++;
			}
		}
	}
	EXPECT_EQ(ch, 2);
}

TEST(Case4, Test3_2)
{
	int N = 2, M = 3, ch = 0;
	double** mass = new double* [N];
	mass[0] = new double [M] { 7, 0, 1 };
	mass[1] = new double [M] { -3, 2.3, -91 };
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				ch++;
			}
		}
	}
	EXPECT_EQ(ch, 1);
}