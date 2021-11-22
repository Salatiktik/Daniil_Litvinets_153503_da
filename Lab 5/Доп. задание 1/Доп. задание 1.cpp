//Лабораторная работа 5, задание доп 1. Выполнил Литвинец Даниил Николаевич
/*
Вычислить рекурсивную функцию(смотреть задание 1 дополнительно)
*/
#include <iostream>

using namespace std;

void c_nat(long long& p, long long& q)
{
	while (!(std::cin >> p) || !(std::cin >> q) || std::cin.peek() != '\n' || round(p) != p || round(q) != q || (p > 0 && q < 0) || (q > 0 && p < 0))
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
}

long long start(long long**& mass, long long& i, long long& p, long long& q) {
	do
	{
		mass[i][0] = p;
		mass[i][1] = q;
		i++;
		mass = (long long**)realloc(mass, (i + 1) * sizeof(long long*));
		mass[i] = new long long[2];
		c_nat(p, q);
	} while (p > 0 && q > 0);
	return 0;
}

int F_function(int n)//сама функция
{
	if (n % 10 > 0)
	{
		return n % 10;
	}
	else if (n == 0)
	{
		return 0;
	}
	else if(n%10==0)
	{
		return F_function(n / 10);
	}
}

long long S_function(int p, int q)//сумма
{
	int qwe = 0;
	int  long long sum = 0;
	for (int i = p; i <= q; i++)
	{
		sum += F_function(i);

		qwe++;
	}
	return sum;
}


int main()
{
	long long p, q, i = 0;
	c_nat(p, q);
	long long** mass = (long long**)malloc(sizeof( long long*));
	mass[0] = new long long[2];

	start(mass, i, p, q);//ввод элементов до -1 -1
	
	for (int t = 0; t < i; t++)
	{
		p = mass[t][0];
		q = mass[t][1];
		cout << S_function(p, q) << endl;
	}

}