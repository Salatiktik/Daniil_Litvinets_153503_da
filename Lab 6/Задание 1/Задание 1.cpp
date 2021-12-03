﻿// Лабораторная работа 6, задание 1 вариант 1. Выполнил Литвинец Даниил

#include <iostream>
#include <iomanip>

using namespace std;

int c_nat()
{
    int x;
    while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x <= 0)
    {
        std::cin.clear();
        std::cin.ignore(100500, '\n');
        std::cout << "Некоректный ввод данных" << std::endl;
    }
    return x;
}

int str_in(char*& str, int N, int& e)
{
    cin.getline(str,81);
    int ch = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] != '1' && str[i] != '0' && str[i] != ' '&&(int)str[i]!=-51)
        {
            ch++;
        }
        if (str[i] != 0)
        {
            ch--;
            e = i;
        }
        else
        {
            ch += i-1;
            break;
        }
    }
    return ch;
}

void shortest_group(char*& str, int& s, int& e, int& N)
{
    int shortest_s = s, shortest_e = e, last_void, t_void = -1;
    for (int i = 0; i <= e+1; i++)
    {
        if (((int)str[i] == 32)&&((int)str[i+1]!= 32))
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

int main()
{
    setlocale(LC_ALL, "RU");
    int N = 81;
    char* str = new char[N];
    int s = 0, e ;
    while(str_in(str, N, e))
    {
        delete[81]str;
        str = new char[N];
        s = 0;
        e = N - 1;
        cout << "Некоректный ввод";
    }
    shortest_group(str, s, e, N);
    std::cout << "Кратчайшая группа:\n";
    for (int i = s + 1; i < e; i++)
    {
        std::cout << str[i];
    }
}