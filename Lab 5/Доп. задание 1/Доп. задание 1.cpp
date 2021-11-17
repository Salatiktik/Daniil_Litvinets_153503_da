#include <iostream>

using namespace std;

void c_nat(int& p, int& q)
{
	while (!(std::cin >> p) || !(std::cin >> q) || std::cin.peek() != '\n' || round(p) != p || round(q) != q || (p > 0 && q < 0) || (q > 0 && p < 0))
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
}

int F_function(int n)
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

int S_function(int p, int q)
{
	int  sum = 0;
	for (int i = p; i <= q; i++)
	{
		sum += F_function(i);
	}
	return sum;
}


int main()
{
	int p, q, i = 0;
	c_nat(p, q);
	long long** mass = new long long* [1];
	mass[0] = new long long[2];
	do
	{
		mass[i][0] = p;
		mass[i][1] = q;
		i++;
		realloc(mass, 2*i*sizeof(long long*));
		mass[i] = new long long[2];
		c_nat(p, q);

	} while (p >0 && q>0);
	for (int t = 0; t < i; t++)
	{
		p = mass[t][0];
		q = mass[t][1];
		cout << S_function(p, q) << endl;
	}

}