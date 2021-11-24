#include "pch.h"

TEST(Case1, Test_a2) {
	unsigned long long k = 1234, n = 1234, t=4;
	EXPECT_EQ(pow_bin(k, n, pow(10, t)),736);
}

TEST(Case2, Test_a2) {
	unsigned long long k = 4, n = 99999, t = 9;
	EXPECT_EQ(pow_bin(k, n, pow(10, t)), 494777344);
}

TEST(Case3, Test_a2) {
	unsigned long long k = 888, n = 888, t = 8;
	EXPECT_EQ(pow_bin(k, n, pow(10, t)), 91255296);
}

TEST(Case4, Test_a2) {
	unsigned long long k = 2323, n = 99999999999, t = 8;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 39087387);
}

TEST(Case5, Test_a2) {
	unsigned long long k = 2323, n = INT_MAX, t = 8;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 60357147);
}

TEST(Case6, Test_a2) {
	unsigned long long k = 10000000000000000000-2, n = 10000000000000000000-2, t = 8;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 51872768);
}

TEST(Case7, Test_a2) {
	unsigned long long k = 10000000000000000000, n = 10000000000000000000, t = 9;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 0);
}
TEST(Case8, Test_a2) {
	unsigned long long k = 10000000000000000000-1, n = 10000000000000000000-1, t = 9;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 921859071);
}

TEST(Case9, Test_a2) {
	unsigned long long k = 1, n = 1, t = 1;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 1);
}

TEST(Case10, Test_a2) {
	unsigned long long k = 0, n = 0, t = 0;
	EXPECT_EQ(pow_bin(k, n, long long(pow(10, t))), 0);
}

