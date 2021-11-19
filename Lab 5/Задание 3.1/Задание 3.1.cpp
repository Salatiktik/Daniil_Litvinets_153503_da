// Лабораторная работа 5, Задание 3.1. Выполнил Литвинец Даниил Николаевич
/*Создать массив из элементов двумерного массива расположенных на гланой
диагонали матрицы с четным значением. Вычислить их произведение*/

#include <iostream>
#include "..\check_d\Header.h"

using namespace std;

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
}*/

int main()
{
	cout << "Введите размерность матрицы N x M\n";
	int N = c_nat(), M = c_nat();
	cout << "Введите элементы матрицы\n";

	int** mass = new int* [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new int[N];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = c_nat();
		}
	}

	int g;//наименьшее измерение
	if (N < M||N==M)
		g = N;
	else
		g = M;

	int* ans = new int[0];
	int p = 0;

	for (int i = 0; i < g; i++)//ввод
	{
		if (mass[i][i] % 2 == 0&&mass[i][i]!=0)
		{
			realloc(ans, sizeof(int) + sizeof(ans));
			ans[p] = mass[i][i];
			p++;
		}
	}

	cout << "Получившаяся матрица:\n";
	int pr = 1;
	for (int i = 0; i < p; i++)
	{
		pr *= ans[i];
		cout << ans[i] << " ";
	}
	cout << "\nПроизведение элементов \n" << pr;
}
