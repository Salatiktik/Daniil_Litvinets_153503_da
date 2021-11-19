//Лабораторная работа 5, задание 3.3. Выполнил Литвинец Даниил Николаевич
/*Создатб массив из нечетных элементов в четных столбцах матрицы
Вычислить среднее арифметическое*/
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

void nech(int**& mass, int*& ans, int N, int M,int& ch, int& s)//поиск нечетных
{
    for (int i = 0; i < N; i++)
    {
        for (int z = 1; z < M; z += 2)
        {
            if (mass[i][z] % 2 != 0)
            {
                ans[ch] = mass[i][z];
                ch++;
                ans = (int*)realloc(ans, sizeof(ans) + sizeof(int));
                s += mass[i][z];
                cout << mass[i][z] << " ";
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    cout << "Введите размерность массива N x M\n";
    int N = c_nat(), M = c_nat();

    int** mass = new int* [N];
    for (int i = 0; i < N; i++)
    {
        mass[i] = new int[M];
        for (int z = 0; z < M; z++)
        {
            mass[i][z] = c_nat();
        }
    }

    int ch = 0,s=0;
    double sr = 0;

    int* ans = (int*)malloc(sizeof(int)*1);

    cout << "\nМассив нечетных чисел в четных столбцах:\n[";

    nech(mass, ans, N, M, ch, s);

    cout << "]\n\n";

    if (ch == 0)
    {
        sr = 0;
    }
    else
    {
        sr = (double)s / ch;
    }

    cout << "Среднее арифметическое полученного массива = " << sr;

}
