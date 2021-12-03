#include "pch.h"

TEST(Case1, Test3) {
	int n = 100;
	char* str = new char[100]{ 'a','k','k','a','a',' ','k','a','k','a'};
	check_str(str);

	EXPECT_STREQ(str,"akkaa akak");
}

TEST(Case2, Test3) {
	int n = 101;
	char* str = new char[101]{ 'a','a','c','d','e','f','f', 'f', 'f', 'f',' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', ' ', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 'f', 0};
	check_str(str);

	EXPECT_STREQ(str, "fffffedcaa fffffffff fffffffff fffffffff fffffffff fffffffff fffffffff fffffffff fffffffff fffffffff");
}

TEST(Case3, Test3) {
	int n = 100;
	char* str = new char[100]{ };
	EXPECT_STREQ(str,"");
}