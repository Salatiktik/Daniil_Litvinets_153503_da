//Лабораторная работа №4, Задание 15. Выполнил Литвинец Даниил 
/*координаты элемента в матрице*/

#include <iostream>
#include <iomanip>

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

int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Введите натуральное число:";
	int M = c_nat(),zn =2,i=0;
    int N = int(sqrt(M)) + 1;
    int** matrix = new  int*[N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int [N];
    }
    i=0;
    matrix[0][0] = 1;
    if(M==1)
        cout << "Координаты числа: строка" << 1 << "; столбец" << 1 << endl;
    for (int z = 1; z < N; z++)
    {
        do
        {
            matrix[i][z] = zn;
            if (zn == M)
                cout << "Координаты числа: строка " << i+1 << "; столбец " << z+1 << endl;
            zn++;
            i++;
        } while (i < z);
        
        for (int q = z; q >= 0; q--)
        {
            matrix[i][q] = zn;
            if (zn == M)
                cout << "Координаты числа: строка " << i+1 << "; столбец " << q+1 << endl;
            zn++;
        }
        i = 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int z = 0; z < N; z++)
        {
            cout << setw(3) << matrix[i][z] << " ";
        }
        cout << "\n";
    }
}
