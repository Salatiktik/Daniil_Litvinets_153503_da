//Лабораторная работа №4, Задание 1 вариант 2. Выполнил: Литвинец Даниил Николаевич
/*Расположить элементы массива в обратном порядке*/

#include <iostream>

using namespace std;

int main()
{
    int k[] = {1,2,3,4,5,6,7,8,9,10},size=sizeof(k)/4;//инициализация массива
    for (int i = 0; i < size; i++)//вывод
    {
        cout << k[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < size/2-1; i++)//замена двух переменных местами при помощи xor
    {
        k[i] ^= k[size - 1 - i];
        k[size - 1 - i] ^= k[i];
        k[i] ^= k[size - 1 - i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << k[i] << " ";
    }
    return 0;
}