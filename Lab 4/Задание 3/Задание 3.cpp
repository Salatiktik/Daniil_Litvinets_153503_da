// Лабораторная работа №4, Задание 3 вариант 2. Выполнил: Литвинец Даниил Николаевич
/*возведение матрицы в степень*/

#include <iostream>

using namespace std;

double c_p()//проверка на ввод
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

int c_nat()//проверка на натуральность числа
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
    int N;
    cout << "Введите размер квадратной матрицы\n";
    N = c_nat();
    double** matrix = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix[i] = new double[N];
    }
    cout << "Введите элементы матрицы\n";
    for (int i = 0; i < N; i++)//ввод матрицы
    {
        cout << i+1 << "строка\n";
        for (int z = 0; z < N; z++)
        {
            matrix[i][z]= c_p();
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < N; z++)
        {
            cout << matrix[i][z] << " ";
        }
        cout << "]\n";
    }
    int K;
    cout << "Введите степень в которую хотите возвести степень \n";
    cin >> K;
    double** matrix2 = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix2[i] = new double[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            matrix2[i][z] = matrix[i][z];
        }
    }
    double** matrix3 = new double* [N]; //создание динамического массива. в данном случае ссылка на массив из N указателей
    for (int i = 0; i < N; i++) //создание того самого массива из указателей
    {
        matrix3[i] = new double[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            matrix3[i][z] = 0;
        }
    }

    for (int t = 2; t <= K; t++)//перемножение матриц
    { 
        for (int i = 0; i < N; i++)
        {
            for (int z = 0; z < N; z++)
            {
                for (int iq = 0; iq < N; iq++)
                {
                    matrix3[i][z] += matrix2[i][iq] * matrix[iq][z];
                }
                cout << matrix3[i][z] << endl;
            }
        }
        for (int i = 0; i < N; i++)//обнуление третьей и присваивание 2 матрицы
        {
            for (int z = 0; z < N; z++)
            {
                matrix2[i][z] = matrix3[i][z];
                matrix3[i][z] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << "[";
        for (int z = 0; z < N; z++)
        {
            cout << matrix2[i][z] << " ";
        }
        cout << "]\n";
    }
    
}

