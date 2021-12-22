// Задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

char* input(int& zn, int&len,int&dot)
{
    char* x = new char[100];
    cin.getline(x, 100);
    while (x[len] != '\0')
    {
        len++;
    }
    int ch = 0;
    for (int i = 0; i < len; i++)
    {
        if (int(x[i]) < 47 || int(x[i]) > 54)
        {
            ch++;
        }
        if (x[i] == ',')
        {
            ch--;
            dot = i;
        }
        if (x[i] == '-')
        {
            ch--;
            zn = -1;
        }
    }
    while (ch != 0)
    {
        len = 0;
        cout << "Некоректный ввод, введите число в 7-ричной системе счисления:";
        cin >> x;
        ch = 0;
        while (x[len] != '\0')
        {
            len++;
        }
        int ch = 0;
        for (int i = 0; i < len; i++)
        {
            if (int(x[i]) < 47 || int(x[i]) > 55)
            {
                ch++;
            }
            if (x[i] == '-')
            {
                ch--;
                zn = -1;
            }
        }
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int zn = 0, len = 0,dot=0,st;
    char* s_num = input(zn,len,dot);
    long double tn = 0;
    int t = 0;
    st = dot - (0 - zn) - 1;
    for (int i = 0 - zn; i < len; i++)
    {
        if (i == dot&&dot!=0)
            continue;
        tn += ((int)s_num[i] - 48) * pow(7,st--);
    }

    cout << len << " " << dot << " " << zn;
    cout << tn << "\n";

    int tn_int = (int)tn;

    long double a = (tn - tn_int);

    while (tn_int >= 12)
    {
        if (tn_int % 12 < 10)
        {
            s_num[t] = tn_int % 12 + 48;
        }
        else if (tn_int % 12==10)
        {
            s_num[t] = 'A';
        }
        else if (tn_int % 12 == 11)
        {
            s_num[t] = 'B';
        }
        t++;
        tn_int = tn_int/12;
        
    }
    if (tn_int < 10)
    {
        s_num[t] = tn_int + 48;
    }
    else if (tn_int == 10)
    {
        s_num[t] = 'A';
    }
    else if (tn_int == 11)
    {
        s_num[t] = 'B';
    }
    if (zn == -1)
    {
        cout << "-";
    }
    for (int i = t; i >= 0; i--)
    {
        cout << s_num[i];
    }
    if (a != 0)
    {
        cout << ',';
        char* str_dr = new char[100];
        t = -1;
        do
        {
            t++;
            a *= 12;
            if ((int)a <= 9)
            {
                str_dr[t] = (int)a+48;
            }
            else if ((int)a == 10)
            {
                str_dr[t] = 'A';
            }
            else if ((int)a == 11)
            {
                str_dr[t] = 'B';
            }
            a -= (int)a;
            cout << str_dr[t];
        } while (t!=5);
    }    
}