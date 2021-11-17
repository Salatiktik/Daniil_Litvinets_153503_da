#include <iostream>



void c_nat(int& k, int& n, int& t)
{
	while (!(std::cin >> k) || !(std::cin >> n) || !(std::cin >> t) || std::cin.peek() != '\n' || round(k) != k || round(t) != t || round(n) != n || n<=0||k<=0||t<=0)
	{
		std::cin.clear();
		std::cin.ignore(100500, '\n');
		std::cout << "Некоректный ввод данных" << std::endl;
	}
}

int pow(int m, int t)
{
	if (t > 0)
	{
		return m * pow(m, t - 1);
	}
	else if (t > 0)
	{
		return 1;
	}
}

int F_function(int n, int r, int k)
{
	if (n == 0&&r == 0)
	{
		return 1;
	}
	else if (n > 0 && (r >= 0 && r < n * (k - 1) + 1))
	{
		int sum = 0;
		for (int i = 0; i <= k - 1; i++)
		{
			sum += F_function(n - 1, r - i, k);
		}
		return sum;
	}
	else
	{
		return 0;
	}
}

int x_function(int n, int k, int t)
{
	int sum = 0;
	for (int i = 0; i <= n * (k - 1); i++)
	{
		sum += F_function(n, i, k);
	}
	return sum % pow(10, t);
}

int main()
{
	int k, n, t;
	c_nat(k, n, t);
	std::cout << x_function(n, k, t);
}
