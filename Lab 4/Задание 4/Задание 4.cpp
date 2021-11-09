//Лабораторная работа №4, Задание 4. Выполнил Литвинец Даниил Николаевич
/*Локальные минимумы. Их количество*/
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
    int N,M;
    cout << "Введите количество строк N, количество столбцов M\n";
    N= c_nat();
    M = c_nat();
    double** matrix = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix[i] = new double[M];
    }
    int ch = 0;
    cout << "Введите матрицу\n";
    for (int i = 0; i < N; i++)
    {
        cout << i+1 << " строка\n";
        for (int z = 0; z < M; z++)
        {
            matrix[i][z] = c_p();
        }
    }
    for (int i = 0; i < N; i++)//вывод матрицы
    {
        cout << "[";
        for (int z = 0; z < M; z++)
        {
            cout << matrix[i][z] << " ";
        }
        cout << "]\n";
    }

    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < M; z++)
        {
            //блок для угловых клеток
            if (i == 0 && z == 0 && matrix[i][z] < matrix[i+1][z] && matrix[i][z] < matrix[i+1][z+1] && matrix[i][z] < matrix[i][z+1])
                ch++;
            if (i == N - 1 && z == 0 && matrix[i][z] < matrix[N - 2][0] && matrix[i][z] < matrix[N - 2][1] && matrix[i][z] < matrix[N - 1][1])
                ch++;
            if (i == 0 && z == M - 1 && matrix[i][z] < matrix[1][M - 2] && matrix[i][z] < matrix[0][M - 2] && matrix[i][z] < matrix[1][M - 1])
                ch++;
            if (i == N - 1 && z == M - 1 && matrix[i][z] < matrix[N - 2][M - 2] && matrix[i][z] < matrix[N - 1][M - 2] && matrix[i][z] < matrix[N - 2][M - 1])
                ch++;
            //блок для пограничных строк и столбцов
            if (i==0 && z != 0 && z != M-1&&matrix[i][z] < matrix[0][z - 1] && matrix[i][z] < matrix[0][z + 1] && matrix[i][z] < matrix[1][z - 1] && matrix[i][z] < matrix[1][z] && matrix[i][z] < matrix[1][z + 1])
                ch++;
            if (i==N-1 && z != 0 && z != M-1&& matrix[i][z] < matrix[N - 1][z - 1] && matrix[i][z] < matrix[N - 1][z + 1] && matrix[i][z] < matrix[N - 2][z - 1] && matrix[i][z] < matrix[N - 2][z] && matrix[i][z] < matrix[N - 2][z + 1])
                ch++;
            if(z==0&&i!=0 && i != N-1&& matrix[i][z] < matrix[i - 1][z] && matrix[i][z] < matrix[i + 1][z] && matrix[i][z] < matrix[i][z + 1] && matrix[i][z] < matrix[i + 1][z + 1] && matrix[i][z] < matrix[i - 1][z + 1])
                ch++;
            if (z == M-1 && i!=0 && i!= N-1&& matrix[i][z] < matrix[i - 1][z] && matrix[i][z] < matrix[i + 1][z] && matrix[i][z] < matrix[i][z - 1] && matrix[i][z] < matrix[i + 1][z - 1] && matrix[i][z] < matrix[i - 1][z - 1])
                ch++;
            //стандартные точки
            if (z!=0&&i!=0&&i!=N-1&&z!=M-1&&matrix[i][z] < matrix[i - 1][z - 1] && matrix[i][z] < matrix[i - 1][z] && matrix[i][z] < matrix[i - 1][z + 1] && matrix[i][z] < matrix[i][z - 1] && matrix[i][z] < matrix[i][z + 1] && matrix[i][z] < matrix[i + 1][z - 1] && matrix[i][z] < matrix[i + 1][z] && matrix[i][z] < matrix[i + 1][z + 1])
                ch++;
        }
    }
    cout << ch << " локальных минимумов";
}