#include "pch.h"

TEST(Case1, Test_a1) {
	int p = 1, q = 10;
  EXPECT_EQ(S_function(p, q), 46);
}

TEST(Case2, Test_a1) {
	int p = 10, q = 20;
	EXPECT_EQ(S_function(p, q), 48);
}

TEST(Case3, Test_a1) {
	int p = 30, q = 40;
	EXPECT_EQ(S_function(p, q), 52);
}