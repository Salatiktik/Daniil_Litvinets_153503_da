#include "pch.h"

TEST(Case1, Test_a1) {
	int p = 1, q = 1;
  EXPECT_EQ(S_function(p, q), 1);
}

TEST(Case2, Test_a1) {
	int p = 10, q = 20;
	EXPECT_EQ(S_function(p, q), 48);
}

TEST(Case3, Test_a1) {
	int p = 30, q = 40;
	EXPECT_EQ(S_function(p, q), 52);
}

TEST(Case4, Test_a1) {
	long int p = 1, q = INT_MAX-1;
	EXPECT_EQ(S_function(p, q), 10737418151);
}

TEST(Case5, Test_a1) {
	long int p = 1, q = INT_MAX;
	EXPECT_EQ(S_function(p, q), 10737418158);
}

TEST(Case6, Test_a1) {
	long int p = 1, q = INT_MAX+1;
	EXPECT_EQ(S_function(p, q), 0);
}