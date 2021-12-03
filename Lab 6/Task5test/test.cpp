#include "pch.h"

TEST(Case1, Test5) {
    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s2 = s1;
    int L = 1000000000;
    int m = 1000;
    EXPECT_EQ(check(s1, s2, L, m),615);
}

TEST(Case2, Test5) {
    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s2 = s1;
    int L = 1000000001;
    int m = 1001;
    EXPECT_EQ(check(s1, s2, L, m), 15);
}

TEST(Case3, Test5) {
    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s2 = s1;
    int L = 999999999;
    int m = 999;
    EXPECT_EQ(check(s1, s2, L, m), 159);
}
TEST(Case4, Test5) {
    string s1 = "a";
    string s2 = "b";
    int L = 1;
    int m = 10;
    EXPECT_EQ(check(s1, s2, L, m), 0);
}

TEST(Case5, Test5) {
    string s1 = "a";
    string s2 = "b";
    int L = 2;
    int m = 10;
    EXPECT_EQ(check(s1, s2, L, m), 2);
}