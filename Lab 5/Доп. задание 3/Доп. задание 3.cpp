// Доп. задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int f_function(int n)
{
    if (n % 2 != 0)
    {
        return n;
    }
    else
    {
        f_function(n / 2);
    }
}

int s_function(int i)
{
    int s = 0;
    for (int z = 1; z <= i; z++)
    {
        s += f_function(z);
    }
    return s;
}

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

int main()
{
    int n = c_nat(), s=0;
    int* mass = new int[n];
    for (int z = 0; z < n; z++)
    {
        mass[z] = c_nat();
    }
    for (int z = 0; z < n; z++)
    {
        cout << s_function(z) << "\n";
    }
}