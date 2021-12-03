//
// pch.cpp
//

#include "pch.h"

unsigned long long check(string s1, string s2, int L, int m)
{
    int len1 = 0, len2 = 0, ch = 0, a = 0;
    while (s1[len1] != '\0')
    {
        len1++;
    }
    while (s2[len2] != '\0')
    {
        len2++;
    }
    if (len1 + len2 <= L)
    {
        return((unsigned long long)(2 * pow(26, L - len1 - len2)) % m);
    }
    if (len1 + len2 > L)
    {
        for (int r = L - len2; r < len1; r++)
        {
            if (s1[r] == s2[r - L + len2])
            {
                ch++;
            }
        }
        if (ch == len1 - L + len2)
        {
            a++;
        }
        ch = 0;
        for (int r = L - len1; r < len2; r++)
        {
            if (s2[r] == s1[r - L + len1])
            {
                ch++;
            }
        }
        if (ch == len1 - L + len2)
        {
            a++;
        }
        ch = 0;
        return a ;
    }
}
