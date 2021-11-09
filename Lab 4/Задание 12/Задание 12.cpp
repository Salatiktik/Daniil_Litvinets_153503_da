//Лабораторная работа №4, Задание 12. Выполнил Литвинец Даниил Николаевич
/*Написать функцию которая будет удалять дубликаты элементов
из массива. Входные параметры: массив, длинна массива. Выходные
параметры: новый массив, новый размер.*/

#include <iostream>

using namespace std;

double c_p()
{
    double x;
    while (!(std::cin >> x) || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(100500, '\n');
        std::cout << "Некоректный ввод данных" << std::endl;
    }
    return x;
}

double* mas_dell(double mass[], int x)
{
    int ch = 0,h = 1;
    double* mas1 = new double[x];
    mas1[0] = mass[0];
    for (int i = 0; i < x; i++)
    {
        for (int z = 0; z < h; z++)
        {
            if(mass[i]==mas1[z])
                {
                    ch++;
                }
        }
        if (ch == 0)
        {
            mas1[h]=mass[i];
            h++;
        }
        ch = 0;
    }
    double* mas = new double[h];
    for (int i = 0; i < h; i++)
    {
        mas[i] = mas1[i];
    }
    return(mas);
}

int mas_l(double mass[], int x)
{
    int ch = 0, h = 1;
    double* mas1 = new double[x];
    mas1[0] = mass[0];
    for (int i = 0; i < x; i++)
    {
        for (int z = 0; z < h; z++)
        {
            if (mass[i] == mas1[z])
            {
                ch++;
            }
        }
        if (ch == 0)
        {
            mas1[h] = mass[i];
            h++;
        }
        ch = 0;
    }
    return h;
}



int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите длину массива\n";
	int x;
    cin >> x;
    cout << "Введите сам массив\n";
	double* mas = new double[x];
	for (int i = 0; i < x; i++)
	{
		mas[i] = c_p();
	}
    double* mass = mas_dell(mas,x);
    x = mas_l(mas, x);
    cout << "[";
    for (int i = 0; i < x; i++)
    {
        cout << mass[i] << " ";
    }
    cout << "]";
}
