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
	EXPECT_EQ(pow_bin(k, n, pow(10, t)), 39087387);
}