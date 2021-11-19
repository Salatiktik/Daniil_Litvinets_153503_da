#include <iostream>
#include <cmath>

void c_nat(long long& k, long long& n, long long& t)
{
	while (!(std::cin >> k) || !(std::cin >> n) || !(std::cin >> t) || std::cin.peek() != '\n' || round(k) != k || round(t) != t || round(n) != n ||n<0||k<0||t<0)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
}

long long start(long long**& mass, long long& i,long long& k,long long& n, long long& t) {
	int ch = 0;
	while (ch != 1)
	{
		mass[i][0] = k;
		mass[i][1] = n;
		mass[i][2] = t;
		i++;
		mass = (long long**)realloc(mass, (i + 1) * sizeof(long long*));
		mass[i] = new long long[3];
		c_nat(k, n, t);
		if (k == 0 || t == 0 || n == 0)
			return 0;
	} 
}

long long pow_bin(long long x,long long t,long long m)//бинарное возведение в степени или возведение в степень по модулю ресурс https://ru.wikipedia.org/wiki/Возведение_в_степень_по_модулю
{
	if (t == 0)
		return 1 % m;
	if (t % 2 == 0)
		return(pow_bin(x, t / 2, m) * pow_bin(x, t / 2, m) % m);
	if (t % 2 == 1)
		return((x * pow_bin(x, t / 2, m) * pow_bin(x, t / 2, m) % m) % m);
}

int main()
{
	setlocale(LC_ALL, "RU");
	long long k, n, t,i=0;

	std::cout << "Введите данные в соответствии с условием\n";

	long long** mass = (long long**)malloc(sizeof(long long*));
	mass[0] = new long long[3];

	c_nat(k, n, t);

	start(mass, i, k, n, t);

	for (int z = 0; z < i; z++)
	{
		std::cout << "\ncase" << z+1 << ": " << pow_bin(mass[z][0], mass[z][1], pow(10, mass[z][2]));
	}
}
