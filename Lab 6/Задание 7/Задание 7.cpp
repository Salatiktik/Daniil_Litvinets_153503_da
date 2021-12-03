// Задание 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int i = 0, len_p, len = -1,ch=0;
    while (str[i] != '\0')//длинна строки
    {
        i++;
    }
    for (int z = 0; z < i/2; z++)
    {
        if (str[z]==str[i-1-z])
        {
            ch++;
        }
    }
    if (ch != i/2)
        cout << i;
    else
    {
        if (str[0] == str[i - 2])
            cout << "-1";
        else
            cout << i - 1;
    }
}
