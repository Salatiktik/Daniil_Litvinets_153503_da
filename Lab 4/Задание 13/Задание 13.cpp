//Лабораторная работа №4, Задание 13. Выполнил Литвинец Даниил Николаевич
/*удлинители*/

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
    cout << "Введите количество удлинителей\n";
    int N = c_nat();
    int* mass = new int[N];
    cout << "Введите кол-во розеток\n";
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        cout << 1 + i << " удлинитель\n";
        mass[i] = c_nat();
        s += mass[i];

    }
    cout << "Количество розеток при оптимальном соединении = " << s - N + 1;
}