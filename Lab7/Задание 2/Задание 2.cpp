// Задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int c_bin(char*& num, int& dot)
{
    cin.getline(num, 100);
    int t = 0, int_len = 0;
    while (num[t] != '\0')
    {
        if (num[t] != '1' && num[t] != '0' && num[t] != ',')
            break;
        if (num[t] == ',')
        {
            dot = t;
            int_len = t;
        }
        if (num[t + 1] == '\0')
            if ((int_len) % 8 == 0 || (int_len == 0 && (t + 1) % 8 == 0))
            {
                return t + 1;
            }
        t++;
    }
    cout << "Некоректный ввод\n";
    c_bin(num, dot);
}

int main()
{
	int t=0,zn=0,n=1,dot,len;
    char* num = new char[100];
    len = c_bin(num,dot);
    if (num[0] == '1')
    {
        cout << num[0];
        for (int i = 1; i < len; i++)
        {
            if (num[i] == '1')
                cout << '0';
            else if (num[i] == '0')
                cout << '1';
            else
                cout << num[i];
        }
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            cout << num[i];
        }
    }
}
