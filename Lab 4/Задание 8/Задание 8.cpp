//Лабораторная работа №4, Задание 8. Выполнил Литвинец Даниил Николаевич
/*Заменить нулями все элементы, которые находятся в ячейках
между минимальным и максимальным элементами (не включая их).
Изначально все элементы в массиве различные. Если после данного действия
большая часть массива будет содержать нули, то удалить все нулевые
элементы из массива (c сохранением порядка следования остальных
элементов).*/

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
    int N;
    cout << "Введите количество элементов N\n";
    N = c_nat();
    double* matrix = new double [N]; //создание динамического массива. 
    cout << "Введите матрицу\n";
    for (int i = 0; i < N; i++)
    {
        matrix[i] = c_p();
    }
    int ch = 0;
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            if (matrix[i] == matrix[z] && i != z)
                ch++;
        }
    }

    while (ch != 0)
    {
        ch = 0;
        cout << "Введена неверная матрица. Элементы не могут повторяться! Попробуйте ещё разок\n";
        for (int i = 0; i < N; i++)
        {
            matrix[i] = c_p();
        }
        for (int i = 0; i < N; i++)
        {
            for (int z = 0; z < N; z++)
            {
                if (matrix[i] == matrix[z] && i != z)
                    ch++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << "[";
        cout << matrix[i] << " ";
        cout << "]\n";
    }
    double min = matrix[0], max = matrix[0];
    int min_i = 0, max_i = 0;
    for (int i = 0; i < N; i++)//нахождение максимальногго и минимального элементов
    {
        if (matrix[i] < min)
        {
            min = matrix[i];
            min_i = i;
        }
        if (matrix[i] > max)
        {
            max = matrix[i];
            max_i = i;
        }
    }
    if (min_i > max_i)//замена местами(так удобнее)
    {
        min_i ^= max_i;
        max_i ^= min_i;
        min_i ^= max_i;
    }
    ch = 0;
    for (int i = min_i + 1; i < max_i; i++)
    {
        matrix[i] = 0;
        ch++;
    }
    int iq = 0;
    if (ch > N/2)
    {
        double* matrix2 = new double[N - ch];
        for (int i = 0; i < N; i++)
        {
            if (matrix[i] != 0)
            {
                matrix2[iq] = matrix[i];
                iq++;
            }
            else
            {
                continue;
            }
        }
        cout << "[";
        for (int i = 0; i < N-ch; i++)
        {
            cout << matrix2[i] << " ";
        }
        cout << "]\n";
    }
    else
    {
        cout << "[";
        for (int i = 0; i < N; i++)
        {
            cout << matrix[i] << " ";
        }
        cout << "]\n";
    }
}

