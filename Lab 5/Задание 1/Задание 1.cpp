//Лабораторная работа 5, задание 1. Выполнил Литвинец Даниил Николаевич
//Сформировать два двумерных динамических массива а и б размером нхн. заполнение по условию. вывод: сумма диагоналей

#include <iostream>
#include "..\check_d\Header.h"

using namespace std;

int sum_d(int* mass[], int N)//сумма диагоналей
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += mass[i][i];
	}
	return sum;
}

/*int c_nat()
{
	int x;
	while (!(std::cin >> x) || std::cin.peek() != '\n' || round(x) != x || x <= 0)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
	return x;
}*/

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите размерность квадратной матрицы N*N\n";
	int N = c_nat();

	int** mass_a = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass_a[i] = new int[N];
	}

	int** mass_b = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass_b[i] = new int[N];
	}
	for (int i = 0; i < N; i++)//заполнение массивов в соответствии с условием
	{
		for (int z = 0; z < N; z++)
		{
			mass_a[i][z] = 3 * i * z - 3;
			mass_b[i][z] = 2 * i * z - 2;
		}
	}
	int sum_a = sum_d(mass_a, N),sum_b=sum_d(mass_b,N);
	cout << "Сумма диагоналей матрицы а = " << sum_a << "; Сумма диагоналей матрицы b = " << sum_b;
}
