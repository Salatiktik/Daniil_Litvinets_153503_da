#include "pch.h"

TEST(Case1, Task6) {
	string str = "aaaaaaaaaaaa";
	EXPECT_EQ(main1(str), 1);
}

TEST(Case2, Task6) {
	string str = "aaabbbcccddd";
	EXPECT_EQ(main1(str), 369600);
}

TEST(Case3, Task6) {
	string str = "qwertyuiopasdf";
	EXPECT_EQ(main1(str), 1278945280);
}