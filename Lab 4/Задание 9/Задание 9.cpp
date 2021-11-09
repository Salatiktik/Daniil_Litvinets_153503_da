//Лабораторная работа №4, Задание 9. Выполнил Литвинец Даниил Николаевич
/*В качестве входных данных поступают две целочисленные
матрицы A и B, которые имеют размер N и соответственно. Требуется найти
произведение матриц A*B. Выделение памяти через функции языка С.*/

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
    cout << "Введите разрядность матрицы\n";
    int N;
    N = c_nat();
    double** matrix = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(N * sizeof(double));
    }
    double** matrix2 = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix2[i] = (double*)malloc(N * sizeof(double));
    }
    double** matrix3 = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        matrix3[i] = (double*)malloc(N * sizeof(double));
    }
    cout << "Введите элементы матрицы\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " строка\n";
        for (int z = 0; z < N; z++)
        {
            matrix[i][z] = c_p();
        }
    }
    cout << "Введите элементы второй матрицы матрицы\n";
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " строка\n";
        for (int z = 0; z < N; z++)
        {
            matrix2[i][z] = c_p();
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            matrix3[i][z] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            for (int iq = 0; iq < N; iq++)
            {
                matrix3[i][z] += matrix[i][iq] * matrix2[iq][z];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < N; z++)
        {
            cout << matrix3[i][z] << " ";
        }
        cout << "]\n";
    }

}

