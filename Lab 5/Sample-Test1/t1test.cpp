#include "pch.h"

// int sum_d(int* mass[], int N)

TEST(Case1, Task1) {
	int n = 3, m = 3;
	int** mass = new int*[n];
	mass[0] = new int[m] {1, 2, 3};
	mass[1] = new int[m] {4, 2, 9};
	mass[2] = new int[m] {1, 0, 3};
	EXPECT_EQ(sum_d(mass,n), 6);
}

TEST(Case2, Task1) {
	int n = 1, m = 1;
	int** mass = new int* [n];
	mass[0] = new int [m] {0};
	EXPECT_EQ(sum_d(mass, n), 0);
}

TEST(Case3, Task1) {
	int n = 10, m = 10;
	int** mass = new int* [n];
	mass[0] = new int [m] {1, 3, 4, 5, 2, 3, 5, 7, -1, 6};
	mass[1] = new int [m] {5, 3, 4, -6, 2, 9, 5, 2, -11, 6};
	mass[2] = new int [m] {6, 3, -23, -6, 2, 4, 5, 0, -11, 2};
	mass[3] = new int [m] {1, 2, 4, 5, 5, 3, 5, 0, -1, -8};
	mass[4] = new int [m] {5, 6, 8, 3, 2, 4, 5, 2, 0, 6};
	mass[5] = new int [m] {1, 3, 4, 5, 2, 3, 5, 7, -1, 6};
	mass[6] = new int [m] {5, 3, 4, -6, 2, 9, 5, 2, -11, 6};
	mass[7] = new int [m] {6, 3, -23, -6, 2, 4, 5, 0, -11, 2};
	mass[8] = new int [m] {1, 2, 4, 5, 5, 3, 5, 0, -1, -8};
	mass[9] = new int [m] {5, 6, 8, 3, 2, 4, 5, 2, 0, 6};
	EXPECT_EQ(sum_d(mass, n), 1);
}

TEST(Case4, Task1) {
	int n = 4, m = 4;
	int** mass = new int* [n];
	mass[0] = new int[m] {INT_MAX, 2, 3,5};
	mass[1] = new int[m] {4, INT_MAX, 9,7};
	mass[2] = new int[m] {1, 0, INT_MAX,0};
	mass[3] = new int[m] {2, 8, 3,INT_MAX};
	EXPECT_EQ(sum_d(mass, n), 4*INT_MAX);
}



