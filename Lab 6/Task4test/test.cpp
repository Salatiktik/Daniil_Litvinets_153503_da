#include "pch.h"


TEST(Case1, Test1) {
	char* s = new char[100]{ 'l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','\0'};
	new_english(s, 0);
	EXPECT_STRCASEEQ(s,"l");
}

TEST(Case2, Test1) {
	char* s = new char[100]{'c','e','c','k'};
	new_english(s, 1);
	EXPECT_STRCASEEQ(s, "sek");
}

TEST(Case1, Test1) {
	char* s = new char[101]{ 'l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l','l' ,'\0' };
	new_english(s, 0);
	EXPECT_STRCASEEQ(s, "l");
}



