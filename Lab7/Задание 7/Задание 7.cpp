// Задание 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int find_sym(char a, string str, int len)
{
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == a)
        {
            return i;
        }
    }
    return -1;
}

int add_one(string& str, int t, string str_tw, int& len)
{
    if (t != -1)
    {
        if (str[t] != '9')
        {
            str[t] = str_tw[find_sym(str[t], str_tw, 10) + 1];
            return 0;
        }
        else
        {
            str[t] = '0';
            add_one(str, t - 1, str_tw, len);
        }
    }
    else
    {
        t++;
        str = "1" + str;
        len++;
        return 1;
    }
}

int sum(string& str1, char a, int &len, string str_tn)
{
    std::cout << "str = " << str1 << " " << "a = " << a << " ";
    int t = len - 2;
    if (find_sym(str1[t], str_tn, 10) + find_sym(a, str_tn, 10) < 10)
        str1[t] = str_tn[find_sym(str1[t], str_tn, 10) + find_sym(a, str_tn, 10)];
    else
    {
        str1[t] = str_tn[find_sym(str1[t], str_tn, 10) + find_sym(a, str_tn, 10) - 10];
        return add_one(str1, t - 1, "0123456789", len);
    }
    return 0;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int n;
    cin >> n;
    int tr = 0, ts = 0, vn = 0;
    while (tr < n)
    {
        tr += 3;
    }
    if (tr == n)
    {
        cout << "Число делится на 3\n";
    }
    else
    {
        cout << "Число не делится на 3\n";
    }
    while (ts < n)
    {
        ts += 37;
    }
    if (ts == n)
    {
        cout << "Число делится на 37\n";
    }
    else
    {
        cout << "Число не делится на 37\n";
    }
    while (vn < n)
    {
        vn += 89;
    }
    if ( vn == n)
    {
        cout << "Число делится на 89\n";
    }
    else
    {
        cout << "Число не делится на 89\n";
    }
}
