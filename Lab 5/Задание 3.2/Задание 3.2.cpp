// Лабораторная работа 5, Задание 3.2. Выполнил Литвинец Даниил Николаевич
/*Найти нулевые элементы в массиве, вывести их. Переставить в обратном порядке весь массив*/

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

int c_p()
{
	int x;
	while (!(std::cin >> x) || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
	return x;
}

void find_zero(double* mass[], int& ch, int N, int M)//поиск нуля
{
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				cout << "(" << i + 1 << ";" << z + 1 << ") ";
				ch++;
			}
		}
	}
}

void reverse_mat(double** mass,int N,int M)
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int z = M - 1; z >= 0; z--)
		{
			cout << mass[i][z] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите размеры матрицы N x M\n";
	int N = c_nat(), M = c_nat();

	cout << "Введите элементы массива\n";
	double** mass = new double* [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new double[N];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = c_p();
		}
	}

	cout << "Нулевые элементы имеют координаты:";

	int ch = 0;

	find_zero(mass, ch, N, M);

	cout << "Количество нулевых элементов равно " << ch << endl;

	reverse_mat(mass, N, M);
}
