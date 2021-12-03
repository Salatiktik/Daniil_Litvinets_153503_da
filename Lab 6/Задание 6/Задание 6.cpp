// Задание 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

unsigned long long fact(int i)
{
    if (i == 1)
    {
        return 1;
    }
    else
        return i * fact(i - 1);
}

int main()
{
    string str;
    cin >> str;
    int i = 0,u;
    while (str[i] != 0)
    {
        i++;
    }
    u = i;
    for (int z = 0; z < i; z++)
    {
        if (str.find(str[z], z+1) + 1)
        {
            u--;
        }
    }
    cout << u;
    int* int_l = new int[u];
    for (int p = 0; p < u; p++)
    {
        int_l[p] = 1;
    }
    char* char_l = new char[u];
    int t = 0,ch=0;
    for (int z = 0; z < i; z++)
    {
        for (int q = 0; q < u; q++)
        {
            if (str[z] == char_l[q]) {
                ch++;
                int_l[q]++;
            }
        }
        if (ch == 0)
        {
            char_l[t] = str[z];
            t++;
        }
        ch = 0;
    }
    int y = 1;
    for (int r = 0; r < u; r++)
    {
        y *= fact(int_l[r]);
    }
    cout << fact(i) / y;
}
