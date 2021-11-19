#include "pch.h"

TEST(Case1, Task2) {
	int ch = 0, N = 5;
	int* str = new int [N] {1, 0, -1, 1, 1};
	check(str, 0, N - 1, ch);
	EXPECT_EQ(ch, 0);
}

TEST(Case2, Task2) {
	int ch = 0, N = 4;
	int* str = new int [N] {1, 5, -20, 21};
	check(str, 0, N - 1, ch);
	EXPECT_EQ(ch, 3);
}

TEST(Case3, Task2) {
	int ch = 0, N = 7;
	int* str = new int [N] {4,7,1,0,2,1,6};
	check(str, 0, N - 1, ch);
	EXPECT_EQ(ch, 3);
}

TEST(Case4, Task2) {
	int ch = 0, N = 10;
	int* str = new int [N] {7, 1, 9, 5, -16, 98, 3, 8, 4, 2};
	check(str, 0, N - 1, ch);
	EXPECT_EQ(ch, 8);
}

TEST(Case5, Task2) {
	int ch = 0, N = 1;
	int* str = new int [N] {-100};
	check(str, 0, N - 1, ch);
	EXPECT_EQ(ch, 1);
}