// Задание 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int n,tr;
    char* tr_m = new char[5];
    cin >> n;
    tr = n;
    for (int i = 4; i >= 0; i--)
    {
        tr_m[i] = tr % 3+ 48;
        if (tr > 2)
            tr /= 3;
        else
            tr = 0;
    }
    for (int i = 0; i <5; i++)
    {
        if(tr_m[i]!='2')
            cout << i + 1 << " раб умрет за " << char((int)tr_m[i]+1) << "-е сутки\n";
        else
            cout << i + 1 << " раб не умрет\n";
    }
}