// Задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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

void reverse_str(char*& str, int last_void, int t_void)
{
	int summ = 0;
	for (int z = last_void + 1; z < t_void; z++)
	{
		summ += int(str[z]);
	}
	if (summ % 2 == 0)
	{
		if ((t_void - last_void) % 2 == 0)
		{
			for (int q = last_void + 1; q < (t_void + last_void) / 2; q++)
			{
				str[q] ^= str[(t_void - (q - last_void))] ^= str[q] ^= str[(t_void - (q - last_void))];
			}
		}
		else
		{
			for (int q = last_void + 1; q <= (t_void + last_void) / 2; q++)
			{
				str[q] ^= str[(t_void - (q - last_void))] ^= str[q] ^= str[(t_void - (q - last_void))];
			}
		}

	}
	summ = 0;

}

void check_str(char*& str)
{
	int last_void, t_void = -1, summ = 0;

	for (int i = 0; i < 80; i++)
	{
		if ((int)str[i]== 32 || (int)str[i] == 0|| (int)str[i] == 46 || (int)str[i] == 63 || (int)str[i] == 44 || (int)str[i] == 58 || (int)str[i] == 33 || (int)str[i] == 94 || (int)str[i] == 45 || (int)str[i] == 43 || (int)str[i] == 61 || (int)str[i] == 92 || (int)str[i] == 47 || (int)str[i] == 40 || (int)str[i] == 41)
		{
			last_void = t_void;
			t_void = i;
			reverse_str(str, last_void, t_void);
			if (str[i] == '\0' || str[i] == '\n')
			{
				str[i] = '\0';
			}
		}
	}
}


int main()
{

	cout << "Enter size of matrix NxM:\n";
	int N = c_nat(), M = c_nat();
	cout << "Enter strings(max = 80):\n";
	char*** mass = new char** [N];
	cin.ignore(1, '\n');
	for (int i = 0; i < N; i++)
	{
		mass[i] = new char* [M];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = new char[80];

			cin.getline(mass[i][z], 80);
			
			check_str(mass[i][z]);
		}
	}
	int q = 0;
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			while ((int)mass[i][z][q] != 0)
			{
				cout << mass[i][z][q];
				q++;
			}
			q = 0;
			cout << "\n";
		}
	}

}