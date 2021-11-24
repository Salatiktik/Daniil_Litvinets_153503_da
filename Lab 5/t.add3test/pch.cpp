//
// pch.cpp
//

#include "pch.h"
long long f_function(int n)
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

long long s_function(int i)
{
    long long s = 0;
    for (long long z = 1; z <= i; z++)
    {

        s += f_function(z);
        if (s < 0)
            return 0;
    }
    return s;
}
