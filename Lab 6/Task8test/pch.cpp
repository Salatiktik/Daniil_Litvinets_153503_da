//
// pch.cpp
//

#include "pch.h"

bool sosed(string s, string t, int start, int i, int len_t)
{
    while (s[start + 1] == t[i])
    {
        if (i == len_t)
            return 1;
        start++;
        i++;
    }
    while (s[start - 1] == t[i])
    {
        if (i == len_t)
            return 1;
        start--;
        i++;
    }
    return 0;
}

int main1(string s, string t)
{
    int len_t = 0;
    int start = 0;
    while (t[len_t] != '\0')
    {
        len_t++;
    }
    len_t--;
    while (s.find(t[0], start) + 1)
    {
        start = s.find(t[0], start);
        if (len_t == 0)
        {
            return 1;
            break;
        }
        if (sosed(s, t, start, 1, len_t))
        {
            return 1;
            break;
        }
        else
            return -1;
        start++;
    }
    if (s.find(t[0], start) == -1)
    {
        return -1;
    }
}
