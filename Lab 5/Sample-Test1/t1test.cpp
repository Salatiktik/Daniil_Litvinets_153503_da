#include "pch.h"

// int sum_d(int* mass[], int N)

TEST(Case1, Task1) {
	int n = 3, m = 4;
	int** mass = new int*[n];
	mass[0] = new int[m] {1, 2, 3, 4};
	mass[1] = new int[m] {4, 2, 9, 4};
	mass[2] = new int[m] {1, 0, 3, 4};
	EXPECT_EQ(sum_d(mass,n), 6);
}

TEST(Case2, Task1) {
	int n = 3, m = 4;
	int** mass = new int* [n];
	mass[0] = new int[m] {1, 2, 3, 4};
	mass[1] = new int[m] {4, 2, 9, 4};
	mass[2] = new int[m] {1, 0, 3, 4};
	EXPECT_EQ(sum_d(mass, n), 6);
}