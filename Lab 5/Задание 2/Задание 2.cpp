//лабораторная работа 5, задание 2. Выполнил Литвинец Даниил Николаевич
/*Для массива рекурсивно проверить условие -10<x^3<20*/

#include <iostream>
#include <Windows.h>

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

int check(int str[], int st, int end, int& ch)
{
	int s = st;
	int e = end;
	if ((e == 0 && s== 0) || e - s == 0 || s - e == 0)
	{
		if (pow(str[e],3) >= 20 || pow(str[e], 3) <= -10)
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
	HINSTANCE lib = LoadLibrary(L"check_d_dinamic.dll");
	typedef int (*f)();

	f c_nat = (f)GetProcAddress(lib, "c_nat");
	f c_p= (f)GetProcAddress(lib, "c_p");
	setlocale(LC_ALL, "RU");
	cout << "Введите размерность одномерного массива N\n";
	int N = c_nat();

	cout << "Введите элементы\n";

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
