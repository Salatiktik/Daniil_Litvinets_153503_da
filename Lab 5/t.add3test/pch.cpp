//
// pch.cpp
//

#include "pch.h"
int f_function(int n)
{
    if (n % 2 != 0)
    {
        return n;
    }
    else
    {
        f_function(n / 2);
    }
}

int s_function(int i)
{
    int s = 0;
    for (int z = 1; z <= i; z++)
    {
        s += f_function(z);
    }
    return s;
}
