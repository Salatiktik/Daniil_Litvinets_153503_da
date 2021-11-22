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
    int n = INT_MAX-1;
    EXPECT_EQ(s_function(n), 1537228670661645654);
}

TEST(Case4, Task_a3) {
    int n = INT_MAX;
    EXPECT_EQ(s_function(n), 1537228672809129301);
}

TEST(Case5, Task_a3) {
    int n = INT_MAX+1;
    EXPECT_EQ(s_function(n), 0);
}

