// Задание 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

bool isnum(char h)
{
	if ((int)h >= 48 && (int)h <= 57)
	{
		return 1;
	}
	return 0;
}

int main()
{
	string str;
	cin >> str;
	int i = 0, k = 0, g = 0, e = 0, zn = 1, st = 1;
	long long num_int = 0, num_dr = 0, num_e = 0;
	long double sum = 0;
	str.append("p\0");
	while (str[i] != '\0')
	{
		if (isnum(str[i]))
		{
			if(i!=0)
				if (str[i - 1] == '-')
				{
					zn *= -1;
				}
			while (isnum(str[i + k]))
			{

				k++;
			}
			for (int o = i; o <= i + k - 1; o++)
			{
				num_int += ((int)str[o] - 48) * pow(10, k - (o - i) - 1);
			}
			if ((int)str[i + k ] == 44)
			{
				i++;
				while (isnum(str[i + k + g]))
				{
					g++;
					if (str[i + k + 1 +g] == '\0')
					{
						break;
					}
				}
				for (int o = i+k; o <= i + k+g - 1; o++)
				{
					num_dr += double((int)str[o] - 48) * pow(10, g - (o - i-k) - 1);
				}
			}
			if (str[i + k + g] == 'e')
			{
				i++;
				if (str[i + k + g] == '-')
				{
					st *= -1;
					i++;
				}
				while (isnum(str[i + k + g + e]))
				{
					e++;
					if (str[i + k + 1+g+e] == '\0')
					{
						break;
					}
				}
				for (int o = i + k+g; o <= i + k + g+e - 1; o++)
				{
					num_e += double((int)str[o] - 48) * pow(10, e - (o - i - k - g) - 1);
				}
			}
			i += k + g + e;
			sum += zn*(num_int + num_dr/pow(10,g))*pow(10,st*num_e);
			k = 0; g = 0; e = 0; zn = 1; st = 1;
			num_int = 0; num_dr = 0; num_e = 0;
		}
		else
		{

		}
		i++;
	}
	cout << sum;
}
