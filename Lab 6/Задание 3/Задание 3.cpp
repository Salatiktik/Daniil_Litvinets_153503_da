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

void check_str(char*& str)
{
	int last_void, t_void = -1, summ = 0;
	for (int i = 0; i < 80; i++)
	{
		if ((int)str[i]== 32 || str[i] == '\0')
		{
			cout << i;
			last_void = t_void;
			t_void = i;
			for (int z = last_void + 1; z < t_void; z++)
			{
				summ += int(str[z]);
			}
			if (summ % 2 == 0)
			{
				for (int q = last_void+1; q <= (t_void + last_void) / 2; q++)
				{
					str[q] ^= str[(t_void - 1 - q)] ^= str[q] ^= str[t_void - 1 - q];
				}
			}
			summ = 0;
			if (str[i] == '\0')
			{

				break;
			}
		}
	}
}


int main()
{
	cout << "Введите размеры матрицы NxM:\n";
	int N = c_nat(), M = c_nat();
	cout << "Введите строки в матрицу(не более 80 символов на каждую строку)";
	char*** mass = new char** [N];
	for (int i = 0; i < N; i++)
	{
		mass[i] = new char* [M];
		for (int z = 0; z < M; z++)
		{
			mass[i][z] = new char;
			cin.ignore(33000, '\n');
			cin.clear();
			cin.getline(mass[i][z], 80);
			check_str(mass[i][z]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int z = 0; z < M; z++)
		{
			cout << mass[i][z];
		}
	}

}