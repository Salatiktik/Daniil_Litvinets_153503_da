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
    int n = 777;
    EXPECT_EQ(s_function(n), 201537);
}