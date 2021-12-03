// Задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
double c_p()
{
	double x;
	while (!(std::cin >> x) || std::cin.peek() != '\n'||x<=0)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
	return x;
}

double price_tg(char* str, int N)
{

	int ch = 0;
	for (int i = 0; i < N; i++)
	{
		if (str[i] == ' ')
		{
			ch++;
		}
	}
	return ch+1;
}

int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите цену одного слова в формате n.m где n - рубли, m - копейки:";
	double T = c_p();
	cout << "Введите длинну телеграммы в символах(учитывая пробелы):";
	int N = c_nat();
	cout << "Введите саму телеграмму (Не более "<< N <<" символов)\n";
	char* str = new char[N+1];
	cin.ignore(33000, '\n');
	cin.clear();
	cin.getline(str, N);
	cout << "Данная телеграмма обойдется вам в " << price_tg(str, N) * T;
}
