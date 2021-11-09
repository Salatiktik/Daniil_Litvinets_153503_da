//Лабораторная работа №4, Задание 5. Выполнил Литвинец Даниил Николаевич
/*Сглаживание*/

#include <iostream>
#include<iomanip>

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
            cout << setw(5) << matrix[i][z] << " ";
        }
        cout << "]\n";
    }

    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < M; z++)
        {
            //блок для угловых клеток
            if (i == 0 && z == 0)
                matrix2[i][z] = (matrix[i + 1][z] + matrix[i + 1][z + 1] + matrix[i][z + 1]) / 3;
            if (i == N - 1 && z == 0)
                matrix2[i][z] = (matrix[N - 2][0] + matrix[N - 2][1] + matrix[N - 1][1]) / 3;
            if (i == 0 && z == M - 1)
                matrix2[i][z] = (matrix[1][M - 2] + matrix[0][M - 2] + matrix[1][M - 1]) / 3;
            if (i == N - 1 && z == M - 1)
                matrix2[i][z] = (matrix[N - 2][M - 2] + matrix[N - 1][M - 2] + matrix[N - 2][M - 1]) / 3;
            //блок для пограничных строк и столбцов
            if (i == 0 && z != 0 && z != M - 1)
                matrix2[i][z] = (matrix[0][z - 1] + matrix[0][z + 1] + matrix[1][z - 1] + matrix[1][z] + matrix[1][z + 1]) / 5;
            if (i == N - 1 && z != 0 && z != M - 1)
                matrix2[i][z] = (matrix[N - 1][z - 1] + matrix[N - 1][z + 1] + matrix[N - 2][z - 1] + matrix[N - 2][z] + matrix[N - 2][z + 1]) / 5;
            if (z == 0 && i != 0 && i != N - 1)
                matrix2[i][z] = (matrix[i - 1][z] + matrix[i + 1][z] + matrix[i][z + 1] + matrix[i + 1][z + 1] + matrix[i - 1][z + 1]) / 5;
            if (z == M - 1 && i != 0 && i != N - 1)
                matrix2[i][z] = (matrix[i - 1][z] + matrix[i + 1][z] + matrix[i][z - 1] + matrix[i + 1][z - 1] + matrix[i - 1][z - 1]) / 5;
            //стандартные точки
            if (z != 0 && i != 0 && i != N - 1 && z != M - 1)
                matrix2[i][z] = (matrix[i - 1][z - 1] + matrix[i - 1][z] + matrix[i - 1][z + 1] + matrix[i][z - 1] + matrix[i][z + 1] + matrix[i + 1][z - 1] + matrix[i + 1][z] + matrix[i + 1][z + 1]) / 8;

        }
    }
    cout << "\n\nСглаженная матрицы\n\n";
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < M; z++)
        {
            cout << setw(5)<<  matrix2[i][z] << " ";
        }
        cout << "]\n";
    }

}