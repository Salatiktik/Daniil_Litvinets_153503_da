#include "pch.h"

TEST(Case1, Task_a3) {
    int n = 7;
    EXPECT_EQ(s_function(n), 21);
}

TEST(Case2, Task_a3) {
    int n = 1;
    EXPECT_EQ(s_function(n), 1);
}

TEST(Case3, Task_a3) {
    int n = 1000000000-1;
    EXPECT_EQ(s_function(n), 333333333332228101);
}

TEST(Case4, Task_a3) {
    int n = 1000000000;
    EXPECT_EQ(s_function(n), 333333333334181226);
}

TEST(Case5, Task_a3) {
    int n = 1000000000+1;
    EXPECT_EQ(s_function(n), 333333334334181227);
}

