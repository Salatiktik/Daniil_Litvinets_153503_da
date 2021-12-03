#include "pch.h"

TEST(Case1, Test2) {
	int N = 100;
	char* str = new char[N] {'a', ' ', 'a', ' ', 'a', ' ', 'a', ' ', 'a', ' ', 'a', ' ', 'a' };
  EXPECT_EQ(price_tg(str,N), 7);
}

TEST(Case2, Test2) {
	int N = 100;
	char* str = new char[N] {'a', 'a' };
	EXPECT_EQ(price_tg(str, N), 1);
}

TEST(Case3, Test2) {
	int N = 100;
	char* str = new char[N] { '\0' };
	EXPECT_EQ(price_tg(str, N), 1);
}