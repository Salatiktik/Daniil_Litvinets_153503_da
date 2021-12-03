//
// pch.cpp
//

#include "pch.h"

void shortest_group(char*& str, int& s, int& e)
{
    int shortest_s = s, shortest_e = e, last_void, t_void = -1;
    for (int i = 0; i <= e + 1; i++)
    {
        if (((int)str[i] == 32) && ((int)str[i + 1] != 32))
        {
            last_void = t_void;
            t_void = i;
            if (t_void - last_void < shortest_e - shortest_s)
            {
                shortest_s = last_void;
                shortest_e = t_void;
            }
        }
    }
    s = shortest_s;
    e = shortest_e;
}
