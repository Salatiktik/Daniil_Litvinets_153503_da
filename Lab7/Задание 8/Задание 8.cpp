// Задание 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

bool isbyn(unsigned long long& num)
{
	int c = num, cn = 0,q=0;
	while (c >= 1)
	{
		if (c % 10 != 1 && c % 10 != 0)
		{
			q--;
			break;
		}
		c /= 10;
		cn++;
	}
	if (q == -1)
	{
		return (pow(10, cn + 1) - (num % (int)pow(10, cn + 1)));;
	}
	return 0;
}

unsigned long long byn(unsigned long long num)
{
	if (num % 10 != 1)
	{
		return num+=1;
	}
	else
	{
		return byn(num / 10) * 10;
	}
}

/*int main()
{
	unsigned long long n,k=0,num=1,c,cn = 0,cn_n=0,num_d=1;
	cin >> n;
	while (n != k)
	{
		num_d = 0;
		c = num;
		num += isbyn(num);
		while (c >= 1)
		{
			if (c % 10 != 1 && c % 10 != 0)
			{
				cn = -5;
				break;
			}
			if (c % 10 == 1)
			{
				cn_n++;
			}
			c /= 10;
			cn++;
		}
		if (c == 1)
		{
			cn_n++;
		}
		if (cn == -5)
		{
			cn = 0;
			num++;
			continue;
		}
		c = num;
		for (int i = 0; i < cn; i++)
		{
			num_d += (c % 2) * pow(10, i);
			c /= 2;
		}
		if (num_d == num)
		{
			cout << k <<"\n";
			k++;
		}
		if (k == n)
		{
			break;
		}

		if (cn == cn_n)
		{
			num = pow(10, cn);
		}
		else
		{
			num++;
		}
		cn_n = 0;
		cn = 0;
	}
	cout << num;
}
*/

long long to_ten(long long num)
{
	int a = 0;
	while(num/pow(10,a)>=1)a++;
	return a;

}

void main()
{
	unsigned long long n, c, k = 0, num = 1,cn_r = 1, num_c, num_d = 0;
	cin >> n;
	while (1)
	{
		c = num;
		for (int i = 0; i < cn_r; i++)
		{
			num_d += (c % 2) * pow(10, i);
			c /= 2;
		}

		if (num == num_d)
		{
			k++;
			cout << k << " " << num << " " << to_ten(num) << "\n";

			if (k == n)
			{
				break;

			}
		}
		num_c = byn(num);
		if (num_c / num > 5)
		{
			cn_r++;
		}
		num = num_c;
		num_d = 0;
	}
	cout << num;
}

char* to_byn(char*& num, int len)
{
	char* byn = (char*)calloc(len, sizeof(char));
	for (int i = 0; i < len; i++)
	{
		byn[len - i] = (int)(atoi(num) / pow(2, i)) % 2 + 48;
	}
	return byn;
}

void rewrite(char* a, int len)
{
	for (int i = len - 1; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = '1';
}
void sum_1(char* num, int len, int& i)
{
	if (num[len - 1] == '0')
		num[len - 1] = '1';
	else
	{
		if (len != 1)
		{

			return sum_1(num, len - 1,i);

		}
		else
		{
			num[len - 1] = '0';
			i++;
			num = (char*)realloc(num, i * sizeof(char));
			return rewrite(num, i);
		}
	}
}

bool compare(char* a, char* b)
{
	int len_a = 0, len_b = 0;
	while (a[len_a] != '\0')len_a++;
	while (b[len_b] != '\0')len_b++;
	if (len_a != len_b)return false;
	else
		for (int i = 0; i < len_a; i++)
		{
			if (tolower(a[i]) != tolower(b[i]))
				return false;
		}

	return true;
}



void main1(){
	string s = "";
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		n = ((n - 9) * 2 + 10);
	}
	else
	{
		n = ((n - 9) * 2 + 9);
	}
	while (n > 0)
	{
		s = char((n % 2) + 48) + s;
		n /= 2;
	}
	cout << s << endl;

}

