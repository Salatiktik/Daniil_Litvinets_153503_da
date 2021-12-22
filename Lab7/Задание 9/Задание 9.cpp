// Задание 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    int n,t=0;
    char* n_tr = new char[100];
    cin >> n;
    while (n > 3)
    {
        if (n % 3 != 0)
        {
            n_tr[t] = (n % 3)+48;
            n = (n-(n%3))/3;
        }
        else
        {
            n_tr[t] = '3';
            n -= 3;
            n /= 3;
        }
        t++;
    }
    n_tr[t] = n+48;
    for (int i = t; i >= 0; i--)
    {
        cout << n_tr[i];
    }
}
