//Лабораторная работа №4, Задание 7. Выполнил Литвинец Даниил Николаевич
/*цифра с разрядом*/

#include <iostream>

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

int main()
{
    setlocale(LC_ALL, "RU");
    int a = c_nat(), b = a;
    int N = 0;

    while (b >= 1)//количество цифр
    {
        b /= 10;
        N++;
    }
    double* matrix = new double[N];
    for (int i = 0; i < N; i++)//занесение цифр в массив
    {
        int q = (a / pow(10, N - i));
        matrix[i] = int((a / pow(10, N - i - 1)) - q * 10);
    }

    int i = c_nat();
    cout << "Цифра под номером " << i << " = " << matrix[N-1-i];

}