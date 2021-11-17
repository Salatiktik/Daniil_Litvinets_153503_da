// Задание 3.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите размеры матрицы N x M\n";
	int N = c_nat(), M = c_nat();

	cout << "Введите элементы массива\n";
	int** mass = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new int[N];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = c_p();
		}
	}

	cout << "Нулевые элементы имеют координаты:";

	int ch = 0;

	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			if (mass[i][z] == 0)
			{
				cout << "(" << i+1 << ";" << z+1 << ") ";
				ch++;
			}
		}
	}

	cout << "Количество нулевых элементов равно " << ch << endl;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int z = M - 1; z >= 0; z--)
		{
			cout << mass[i][z] << " ";
		}
		cout << "\n";
	}

}
