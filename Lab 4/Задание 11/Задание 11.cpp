//Лабораторная работа №4, Задание 11. Выполнил Литвинец Даниил Николаевич
/*диагонали матрицы*/

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

double d_max(double x, double y)
{
    if (x < y)
        return y;
    else
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
    srand(1);
    setlocale(LC_ALL, "RU");
    cout << "Введите размер ребра трехмерного массива\n";//создание массива
    int N = c_nat();
    double*** matrix = new double**[N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new double* [N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int n = 0; n < N; n++)
        {
            matrix[i][n] = new double[N];
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "Введите " << i + 1 << " матрицу\n";
        for (int z = 0; z < N; z++)
        {
            cout << z + 1 << " строка " << i + 1 << "матрицы\n";
            for (int q = 0; q < N; q++)
            {
                matrix[i][z][q] = rand()%3+1;
            }
        }
    }

    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 0; i < N; i++)
    {
        sum1 += matrix[i][i][i];
    }
    for (int i = 0; i < N; i++)
    {
        sum2 += matrix[N-1-i][i][i];
    }
    for (int i = 0; i < N; i++)
    {
        sum3 += matrix[i][N-1-i][i];
    }
    for (int i = 0; i < N; i++)
    {
        sum4 += matrix[N-1-i][N-1-i][i];
    }

    if (sum4 > sum3)
    {
        if (sum1 > sum2)
        {
            if (sum4 > sum1)
            {
                cout << "Диагональ с наибольшей суммой - matrix[" << N  << "->1][" << N  << "->1][1->" << N <<"]";
            }
            else
            {
                cout << "Диагональ с наибольшей суммой - matrix[1->" << N  << "][1->" << N  << "][1->" << N << "]";
            }
        }
        else
        {
            if (sum4 > sum2)
            {
                cout << "Диагональ с наибольшей суммой - matrix[" << N << "->1][" << N << "->1][1->" << N << "]";
            }
            else
            {
                cout << "Диагональ с наибольшей суммой - matrix[" << N << "->1][1->" << N << "][1->" << N << "]";
            }
        }
        
    }
    else
    {
        if (sum1 > sum2)
        {
            if (sum3 > sum1)
            {
                cout << "Диагональ с наибольшей суммой - matrix[1->" << N << "][" << N << "->1][1->" << N << "]";
            }
            else
            {
                cout << "Диагональ с наибольшей суммой - matrix[1->" << N << "][1->" << N << "][1->" << N << "]";
            }
        }
        else
        {
            if (sum3 > sum2)
            {
                cout << "Диагональ с наибольшей суммой - matrix[" << N << "->1][" << N << "->1][1->" << N << "]";
            }
            else
            {
                cout << "Диагональ с наибольшей суммой - matrix[" << N << "->1][1->" << N << "][1->" << N << "]";
            }
        }
    }
}