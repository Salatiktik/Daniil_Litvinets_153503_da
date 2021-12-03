#include "pch.h"
#include <string>

using namespace std;

TEST(Case1, Test7) {
	string str = "abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeqwewqedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcba\0";
	EXPECT_EQ(main1(str), 104);
}

TEST(Case2, Test7) {
	string str = "a";
	EXPECT_EQ(main1(str), -1);
}

TEST(Case3, Test7) {
	string str = "rbcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeqwewqedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcbaedcba\0";
	EXPECT_EQ(main1(str), 105);
}