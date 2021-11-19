#include "pch.h"

TEST(Case1, Test3_3) {
    int N = 1, M = 1;
    int** mass = new int* [N];
    mass[0] = new int [M] {2};

    int ch = 0, s = 0;
    double sr = 0;

    int* ans = (int*)malloc(sizeof(int) * 1);


    for (int i = 0; i < N; i++)
    {
        for (int z = 1; z < M; z += 2)
        {
            if (mass[i][z] % 2 != 0)
            {
                ans[ch] = mass[i][z];
                ch++;
                ans = (int*)realloc(ans, sizeof(ans) + sizeof(int));
                s += mass[i][z];
            }
        }
    }

    if (ch == 0)
    {
        sr = 0;
    }
    else
    {
        sr = (double)s / ch;
    }
    EXPECT_DOUBLE_EQ(sr, 0);

}

TEST(Case2, Test3_3) {
    int N = 2, M = 2;
    int** mass = new int* [N];
    mass[0] = new int [M] {2,1};
    mass[1] = new int [M] {2, 3};

    int ch = 0, s = 0;
    double sr = 0;

    int* ans = (int*)malloc(sizeof(int) * 1);


    for (int i = 0; i < N; i++)
    {
        for (int z = 1; z < M; z += 2)
        {
            if (mass[i][z] % 2 != 0)
            {
                ans[ch] = mass[i][z];
                ch++;
                ans = (int*)realloc(ans, sizeof(ans) + sizeof(int));
                s += mass[i][z];
            }
        }
    }

    if (ch == 0)
    {
        sr = 0;
    }
    else
    {
        sr = (double)s / ch;
    }
    EXPECT_DOUBLE_EQ(sr, 2);

}

TEST(Case3, Test3_3) {
    int N = 4, M = 4;
    int** mass = new int* [N];
    mass[0] = new int [M] {2, 2,2,2};
    mass[1] = new int [M] {2, 2,2,2};
    mass[2] = new int [M] {2, 2, 2, 2};
    mass[3] = new int [M] {2, 2, 2, 2};

    int ch = 0, s = 0;
    double sr = 0;

    int* ans = (int*)malloc(sizeof(int) * 1);


    for (int i = 0; i < N; i++)
    {
        for (int z = 1; z < M; z += 2)
        {
            if (mass[i][z] % 2 != 0)
            {
                ans[ch] = mass[i][z];
                ch++;
                ans = (int*)realloc(ans, sizeof(ans) + sizeof(int));
                s += mass[i][z];
            }
        }
    }

    if (ch == 0)
    {
        sr = 0;
    }
    else
    {
        sr = (double)s / ch;
    }
    EXPECT_DOUBLE_EQ(sr, 0);

}

TEST(Case4, Test3_3) {
    int N = 4, M = 4;
    int** mass = new int* [N];
    mass[0] = new int [M] {2, 3, 2, 1};
    mass[1] = new int [M] {2, 2, 2, 1};
    mass[2] = new int [M] {2, 1, 2, 2};
    mass[3] = new int [M] {2, 2, 2, 5};

    int ch = 0, s = 0;
    double sr = 0;

    int* ans = (int*)malloc(sizeof(int) * 1);


    for (int i = 0; i < N; i++)
    {
        for (int z = 1; z < M; z += 2)
        {
            if (mass[i][z] % 2 != 0)
            {
                ans[ch] = mass[i][z];
                ch++;
                ans = (int*)realloc(ans, sizeof(ans) + sizeof(int));
                s += mass[i][z];
            }
        }
    }

    if (ch == 0)
    {
        sr = 0;
    }
    else
    {
        sr = (double)s / ch;
    }
    EXPECT_DOUBLE_EQ(sr, 2.2);

}



