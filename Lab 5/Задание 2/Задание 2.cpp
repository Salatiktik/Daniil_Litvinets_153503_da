﻿#include <iostream>

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

int check(int str[], int st, int end, int& ch)
{
	int s = st;
	int e = end;
	if ((e == 0 && s== 0) || e - s == 0 || s - e == 0)
	{
		if (str[e] >= 20 || str[e] <= -10)
		{
			ch++;
			return 0;
		}
		else
		{
			return 0;
		}
	}
	{
		check(str, s, (e + s) / 2, ch);
		check(str, ((e + s) / 2)+1, e , ch);
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите размерность одномерного массива N\n";
	int N = c_nat();

	int* str = new int[N];
	for (int i = 0; i < N; i++)
	{
		str[i] = c_p();
	}

	int ch = 0;

	check(str, 0, N - 1, ch);
	if (ch != 0)
	{
		cout << "Условие не выполняется";
	}
	else
	{
		cout << "Условие выполняется";
	}

}
