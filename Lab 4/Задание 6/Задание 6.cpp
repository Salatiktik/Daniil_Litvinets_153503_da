//Лабораторная работа №4, Задание 6. Выполнил Литвинец Даниил Николаевич
/*Матрица с свойством элементов = максимальный из левых выше*/

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

double c_p()
{
    double x;
    while (!(std::cin >> x) || std::cin.peek() != '\n')
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
    int N, M;
    cout << "Введите количество строк N, количество столбцов M\n";
    N = c_nat();
    M = c_nat();
    double** matrix = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix[i] = new double[M];
    }
    double** matrix2 = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix2[i] = new double[M];
    }
    cout << "Введите матрицу\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " строка\n";
        for (int z = 0; z < M; z++)
        {
            matrix[i][z] = c_p();
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < M; z++)
        {
            cout << matrix[i][z] << " ";
        }
        cout << "]\n";
    }
    for (int i = 0; i < N; i++)//проверка на все верхние левые элементы
    {
        for (int z = 0; z < M; z++)
        {
            matrix2[i][z] = matrix[i][z];
            for (int i1= 0; i1 <= i; i1++)
            {
                for (int z1 = 0; z1 <= z; z1++)
                {
                    if (matrix2[i][z] < matrix[i1][z1])
                    {
                        matrix2[i][z] = matrix[i1][z1];
                    }
                }
            }
        }
    }
    cout << "Итог:\n";
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < M; z++)
        {
            cout << matrix2[i][z] << " ";
        }
        cout << "]\n";
    }

}
