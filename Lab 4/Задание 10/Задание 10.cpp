//Лабораторная работа №4, Задание 10. Выполнил Литвинец Даниил Николаевич
/*Магический квадрат*/

#include <iostream>
#include <iomanip>
#include <ctime>

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

int print_mat(int* matrix[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            cout << setw(3) << matrix[i][z] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int** cub_nech(int N)
{
    int** matrix = (int**)malloc(N * sizeof(int*));//создание массива
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }
    int is = (N / 2), zs = (N / 2) + 1, i1 = is, z1 = zs;//инициализация переменных и стартовых точек
    int ch = 1;
    int start = 1;
    for (int q = 0; q < N; q++)//прогон каждой диагонали
    {
        for (int w = 0; w < N; w++)//вставка элементов в диагонали
        {
            if (z1 >= N)//если диагональ переходит за край то перескок
                z1 = 0;
            if (i1 <= -1)
                i1 = N - 1;
            matrix[i1][z1] = start;
            start += ch;
            z1++;
            i1--;
        }
        is++;
        if (is >= N)
            is = 0;
        zs++;
        if (zs >= N)
            zs = 0;
        i1 = is;//каждый раз новая диагональ начинается с координаты ++ к каждой
        z1 = zs;
    }
    return (matrix);
}

int cub_ch(int N)
{
    int** matrix1 = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N / 2; i++) {
        matrix1[i] = (int*)malloc(N * sizeof(int));
    }
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }
    int f = 0, g = 0, der = 0;
    matrix1 = cub_nech(N / 2);
    for (int t = 0; t < 2; t++)//заполнение квадратов квадратами поменьше
    {
        for (int i = 0; i < N / 2; i++)
            for (int z = 0; z < N / 2; z++)
                matrix[i + f][z + g] = matrix1[i][z] + der;
        f = N / 2;
        der = 3*N * N / 4 ;
        for (int i = 0; i < N / 2; i++)
            for (int z = 0; z < N / 2; z++)
                matrix[i + f][z + g] = matrix1[i][z] + der;
        g = N/2;
        der = N * N / 4;
        for (int i = 0; i < N / 2; i++)
            for (int z = 0; z < N / 2; z++)
                matrix[i + f][z + g] = matrix1[i][z] + der;
        f = 0;
        der = N * N / 2;
        for (int i = 0; i < N / 2; i++)
            for (int z = 0; z < N / 2; z++)
                matrix[i + f][z + g] = matrix1[i][z] + der;
    }
    for (int i = 0; i < N/2; i++)
    {
        if (i != 0 && i != (N/2) - 1)
        {
            matrix[i][1] ^= matrix[i+N/2][1] ^=matrix[i][1]^=matrix[1+N/2][1];
        }
        else
        {
            matrix[i][0] ^= matrix[N / 2 + i][0] ^= matrix[i][0] ^= matrix[N / 2 + i][0];
        }
    }
    int z =N/2-((N - 2) / 4 - 1);
    if (N == 6)
    {
        print_mat(matrix, N);
    }
    else
    {
        for (int m = ((N - 2) / 4 - 1)*2; m >= 0; m--);
        {
            cout << z << endl;
            for (int i = 0; i < N / 2; i++)
            {
                matrix[i][z] ^= matrix[N / 2 + i][z] ^= matrix[i][z] ^= matrix[N / 2 + i][z];
            }
            z++;
            
        }
        print_mat(matrix, N);
    }
    return 0;
}

int cub_ch_ch(int N)
{
    int** matrix = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(N * sizeof(int));
    }
    int zn = 1, z1,z2,z3,z4;
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            matrix[i][z] = zn;
            zn++;
        }
        cout << "\n";
    }
    for (int i = 0; i < N/2; i++)
    {
        z1 = N - 1 - i;
        z2 = N / 2;
        matrix[z1][z1] ^= matrix[i][i] ^= matrix[z1][z1] ^= matrix[i][i];

        matrix[i][z2+i] ^= matrix[z1][z2 - i-1] ^= matrix[i][z2 + i]^=matrix[z1][z2 - 1 - i];

        matrix[i][z1] ^= matrix[z1][i] ^= matrix[i][z1] ^= matrix[z1][i];

        matrix[i][z2 - i - 1] ^= matrix[N - 1 - i][z2 + i] ^= matrix[i][z2 - i - 1] ^= matrix[N - 1 - i][z2 + i];
    }
    print_mat(matrix, N);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    cout << "Введите разрядность квадрата\n";
    int N = c_nat();
    //переход к функциям построения
    if (N % 4 == 0)
        cub_ch_ch(N);
    else if (N % 2 == 0)
        cub_ch(N);
    else
    {
        int start = clock();
        int** matrix = cub_nech(N);
        int end = clock();
        print_mat(matrix, N);
        int end1 = clock();
        cout << setprecision(100);
        cout << start << endl;
        cout << end << endl;
        cout << end1 << endl;
        cout << ((end1*1000000000000 - start*1000000000000)/(end*1000000000000-start*1000000000000));
    }
}