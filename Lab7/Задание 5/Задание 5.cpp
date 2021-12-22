// Задание 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
int c_nat()
{
    int x;
    while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x >3999|| x<=0)
    {
        std::cin.clear();
        std::cin.ignore(100500, '\n');
        std::cout << "Некоректный ввод данных" << std::endl;
    }
    return x;
}

int main()
{
    int N = c_nat();
    string rim;
    for (int i = 0; i < N / 1000;i++)
    {
        rim += 'M';
    }
    if (N - (int(N / 1000)) * 1000 >= 500)
    {
        if (N - (int(N / 1000)) * 1000 >= 900)
            rim += "CM";
        else
        {
            rim += "D";
            for (int i = 0; i < (N - (int(N / 1000)) * 1000 - 500) / 100; i++)
            {
                rim += "C";
            }
        }
    }
    else { 
        if (N - (int(N / 1000)) * 1000 >= 400)
            rim += "CD";
        else for (int i = 0; i < (N - (int(N / 1000)) * 1000) / 100; i++)
        {
            rim += "C";
        }
    }

    if (N - (int(N / 100)) * 100 >= 50)
    {
        if (N - (int(N / 100)) * 100  >= 90)
            rim += "XC";
        else
        {
            rim += "L";
            for (int i = 0; i < (N - (int(N / 100)) * 100 - 50) / 10; i++)
            {
                rim += "X";
            }
        }
    }
    else
    {
        if (N - (int(N / 100)) * 100 >= 40)
            rim += "XL";
        else
        {
            for (int i = 0; i < (N - (int(N / 100)) * 100) / 10; i++)
            {
                rim += "X";
            }
        }
    }
    if (N % 10 >= 5)
    {
        if (N % 10 == 9)
        {
            rim += "IX";
        }
        else
        {
            rim += "V";
            for (int i = 0; i < N % 10 - 5; i++)
            {
                rim += "I";
            }
        }
    }
    else
    {
        if (N % 10 == 4)
        {
            rim += "IV";
        }
        else
        {
            for (int i = 0; i < N % 10 ; i++)
            {
                rim += "I";
            }
        }
    }

    cout << rim;
}