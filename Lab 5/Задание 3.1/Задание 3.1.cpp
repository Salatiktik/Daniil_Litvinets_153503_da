﻿// Задание 3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	int N = c_nat(), M = c_nat();

	int** mass = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new int[N];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = c_nat();
		}
	}

	int g;
	if (N < M||N==M)
		g = N;
	else
		g = M;

	int* ans = new int[0];
	int p = 0;

	for (int i = 0; i < g; i++)
	{
		if (mass[i][i] % 2 == 0&&mass[i][i]!=0)
		{
			realloc(ans, sizeof(int) + sizeof(ans));
			ans[p] = mass[i][i];
			p++;
		}
	}

	int pr = 1;
	for (int i = 0; i < p; i++)
	{
		pr *= ans[i];
		cout << ans[i] << " ";
	}
	cout << "\n" << pr;
}
