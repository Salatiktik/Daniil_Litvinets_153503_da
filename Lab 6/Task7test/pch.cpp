//
// pch.cpp
//

#include "pch.h"

#include <string>

using namespace std;

int main1(string str)
{
    int i = 0, len_p, len = -1, ch = 0;
    while (str[i] != '\0')//длинна строки
    {
        i++;
    }
    if (i == 1)
    {
        return -1;
    }
    for (int z = 0; z < i / 2; z++)
    {
        if (str[z] == str[i - 1 - z])
        {
            ch++;
        }
    }
    if (ch != i / 2)
        return i;
    else
    {
        if (str[0] == str[i - 2])
            return-1;
        else
            return i - 1;
    }
}
